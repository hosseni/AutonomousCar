/******************************************************************************
 *
 * Linker Command File for Texas Instruments TM4C123GE6PM Microcontroller
 *
 * This linker command file is intended to control how the program's various
 * sections are allocated within the memory space of the TM4C123GE6PM
 * microcontroller.
 *
 *****************************************************************************/

--retain=g_pfnVectors

/* Memory Mapping */
MEMORY
{
    FLASH (RX) : origin = 0x00000000, length = 0x00020000
    SRAM (RWX) : origin = 0x20000000, length = 0x00008000
}

/* Compiler Options (These can be set in the CCS project settings) */

//--heap_size=0
//--stack_size=256
//--library=rtsv7M4_T_le_eabi.lib


/* Section Placement in Memory */

SECTIONS
{
    /* Section for Interrupt Vectors */
    .intvecs : > 0x00000000

    /* Section for Executable Code */
    .text :> FLASH

    /* Section for Constant Data */
    .const :> FLASH

    /* Section for Initialized Data */
    .cinit :> FLASH

    /* Section for Pre-Initialized Data */
    .pinit : > FLASH

    /* Section for Initialization Arrays */
    .init_array : > FLASH

    /* Section for Virtual Function Table (Possibly) */
    .vtable : > 0x20000000

    /* Section for Initialized Global and Static Variables */
    .data : > SRAM

    /* Section for Uninitialized Variables (BSS) */
    .bss : > SRAM

    /* Section for System-Specific Memory */
    .sysmem : > SRAM

    /* Section for the Program Stack */
    .stack : > SRAM
}

/* Calculate the Top of the Stack */
__STACK_TOP = __stack + 512;
