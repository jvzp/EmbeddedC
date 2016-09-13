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

/* Includes */
#include "main.h"
#include <stdint.h>

/* Defines */
#define EVER        (;;)

static uint32_t some_static_var = 0xbeef;

int32_t aVariable = 4;

/* main C entry point - should never return */
void main(void)
{
    int32_t i=0;
    int32_t j=3;


    for EVER
    {
        static uint16_t static_local = 0x1337;

    	int32_t anotherVariable;
    	static int32_t staticVariable = 9;

        i++;
        j = static_local;
    }
}

