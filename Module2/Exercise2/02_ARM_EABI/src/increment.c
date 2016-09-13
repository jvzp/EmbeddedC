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

/* Prototypes */
unsigned char increment(unsigned char val);
unsigned char testfunc(void);


unsigned char increment(unsigned char val)
{
    unsigned char i=1;
    return val + i;
}

unsigned char testfunc() {

    return 27;

}

