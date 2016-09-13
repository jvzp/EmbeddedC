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

static uint32_t static_var = 0x1234;
static uint32_t static_zero_var;

/* main C entry point - should never return */
void main(void)
{
    uint32_t i=0x1234;
    uint32_t j=0;

    for EVER
    {
        i++;
        j = static_var;
    }
}

