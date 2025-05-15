[org 0x7c00]
[bits 16]

; Constants
KERNEL_OFFSET equ 0x1000
STACK_BASE equ 0x9000

start:
    ; Set up segments and stack
    cli                     ; Disable interrupts during setup
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, STACK_BASE
    sti                     ; Re-enable interrupts

    ; Save boot drive number
    mov [boot_drive], dl

    ; Print loading message
    mov si, msg_loading
    call print_string

    ; Reset disk system
    xor ah, ah
    mov dl, [boot_drive]
    int 0x13
    jc disk_error

    ; Load kernel
    mov bx, KERNEL_OFFSET
    mov ah, 0x02           ; BIOS read sector function
    mov al, 32             ; Number of sectors to read
    mov ch, 0              ; Cylinder number
    mov cl, 2              ; Sector number (1 is boot sector)
    mov dh, 0              ; Head number
    mov dl, [boot_drive]   ; Drive number
    int 0x13
    jc disk_error

    ; Switch to protected mode
    cli                     ; 1. Disable interrupts
    lgdt [gdt_descriptor]   ; 2. Load GDT descriptor
    mov eax, cr0           ; 3. Enable protected mode
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:init_pm   ; 4. Far jump to 32-bit code

disk_error:
    mov si, msg_disk_error
    call print_string
    jmp $

; Print string in SI
print_string:
    pusha
    mov ah, 0x0e
.loop:
    lodsb
    test al, al
    jz .done
    int 0x10
    jmp .loop
.done:
    popa
    ret

[bits 32]
init_pm:
    ; Set up segment registers
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; Set up stack
    mov ebp, STACK_BASE
    mov esp, ebp

    ; Clear screen
    mov edi, 0xb8000
    mov ecx, 2000
    mov ax, 0x0720
    rep stosw

    ; Jump to kernel
    call KERNEL_OFFSET
    
    ; Should never get here
    jmp $

; Data
boot_drive: db 0
msg_loading: db 'Loading kernel...', 13, 10, 0
msg_disk_error: db 'Disk error!', 13, 10, 0

; GDT
gdt_start:
    dd 0x0, 0x0           ; Null descriptor

gdt_code:                 ; Code segment descriptor
    dw 0xffff             ; Limit (0-15)
    dw 0x0                ; Base (0-15)
    db 0x0                ; Base (16-23)
    db 10011010b          ; Access byte
    db 11001111b          ; Flags + Limit (16-19)
    db 0x0                ; Base (24-31)

gdt_data:                 ; Data segment descriptor
    dw 0xffff             ; Limit (0-15)
    dw 0x0                ; Base (0-15)
    db 0x0                ; Base (16-23)
    db 10010010b          ; Access byte
    db 11001111b          ; Flags + Limit (16-19)
    db 0x0                ; Base (24-31)

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1  ; GDT size (16 bits)
    dd gdt_start                 ; GDT address (32 bits)

; Define GDT segment selectors
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

; Padding and magic number
times 510-($-$$) db 0
dw 0xaa55 