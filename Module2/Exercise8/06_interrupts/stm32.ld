/* This will work with STM32 type of microcontrollers.    *
 * The sizes of RAM and flash are specified smaller than  *
 * what most of the STM32 provide to ensure that the demo *
 * program will run on ANY STM32.                         */

/* Entry Point */
ENTRY(main)

/* Highest address of the user mode stack */
_estack = 0x20020000;    /* end of 128K RAM on AHB bus*/

MEMORY
{
    RAM 	  (rwx) : ORIGIN = 0x20000000, LENGTH = 192K
    FLASH 	  (rx)  : ORIGIN = 0x08000000, LENGTH = 1024K
}

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(512);
        __isr_vector_load  = LOADADDR(.isr_vector);
        __isr_vector_start = .;
        KEEP(*(.isr_vector)) /* Vector table in RAM and FLASH */
        . = ALIGN(4);
        __isr_vector_end = .;
    } >RAM AT >FLASH

    .text :
    {
        *(.text)             /* Program code */
        *(.text*)            /* Program code */
        *(.rodata)           /* Read only data */
        *(.rodata*)          /* Read only data */
    } >FLASH

    _sidata = LOADADDR(.data);
     
    .data : 
    {
        . = ALIGN(4);
        _sdata = .;     /* Global symbol at data start */
        *(.data)        /* Data memory */
        *(.data*)       /* Data memory */
        . = ALIGN(4);
        _edata = .;     /* End of initialized data */
    } >RAM AT >FLASH 

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;     /* Global symbol at start of bss */
        __bss_start__ = _sbss;    
        *(.bss)       /* Zero-filled run time allocate data memory */
        *(.bss*)       /* Zero-filled run time allocate data memory */
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;     /* Global symbol at end of bss */
        __bss_end__ = _ebss;    
        _end = .;
        PROVIDE (end = .);
    } >RAM 
}

