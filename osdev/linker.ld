OUTPUT_FORMAT("elf32-i386")
ENTRY(kmain)

SECTIONS
{
    /* Kernel is loaded at 1MB by the bootloader */
    . = 0x1000;

    /* First put the multiboot header, as it is required to be put very early
       in the image or the bootloader won't recognize the file format.
       Next we'll put the .text section. */
    .text ALIGN(4K) : {
        *(.text.boot)
        *(.text)
        *(.rodata)
    }

    /* Read-write data (initialized) */
    .data ALIGN(4K) : {
        *(.data)
    }

    /* Read-write data (uninitialized) and stack */
    .bss ALIGN(4K) : {
        *(COMMON)
        *(.bss)
    }
} 