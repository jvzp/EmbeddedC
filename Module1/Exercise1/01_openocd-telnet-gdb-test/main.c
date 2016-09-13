/*
 * main.c
 *
 *  Created on: 14 Feb 2013
 *      Author: Maxime Vincent
 * Description: Virtually the most simple demo that can be run on an ARM MCU.
 *              The target is barely running - all clocks are off, the core is
 *              just executing a few simple instructions.
 *
 *     Purpose: Purpose is to demonstrate an openocd-gdb setup to flash and 
 *              step through code on the target.
 *
 *     Context: Written in the context of the Embedded C course by TASS Belgium.
 */


/* Defines */
#define STACK_TOP   0x20000800   // just a tiny stack for demo
#define EVER        (;;)

/* Prototypes */
int reset_handler(void);
static void nmi_handler(void);
static void hardfault_handler(void);

/* Exception vector table */
/* -- See http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0471c/Cihbffg3.html */
unsigned int * exception_vectors[4]
__attribute__ ((section("vectors"))) = {
    (unsigned int *) STACK_TOP,         // Stack pointer
    (unsigned int *) reset_handler,     // Reset exception
    (unsigned int *) nmi_handler,       // NMI exception
    (unsigned int *) hardfault_handler  // HardFault exception
};

//static int a = 10;

/* Reset exception handler */
int reset_handler(void)
{
    int i=0;

    for EVER
    {
        i++;
    }
}

/* Non-Maskable Interrupt handler */
void nmi_handler(void)
{
    for EVER;
}

/* HardFault handler */
void hardfault_handler(void)
{
    for EVER;
}

