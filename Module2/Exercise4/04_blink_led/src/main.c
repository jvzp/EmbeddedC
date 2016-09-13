/*
 * main.c
 *
 *  Created on: 14 Feb 2013
 *      Author: Maxime Vincent
 * Description: Framework to get a LED to blink
 *
 *     Purpose: Purpose is to demonstrate the configuration of a peripheral
 *              on the STM32F4 MCU
 *
 *     Context: Written in the context of the Embedded C course by TASS Belgium.
 */

/* Includes */
#include <stdint.h>
#include "main.h"
#include "stm32f4xx.h"

static void delay(void);
static void reset_GPIO(GPIO_TypeDef * PORT);
static void set_pin(GPIO_TypeDef * PORT, uint16_t pin_number);
static void reset_pin(GPIO_TypeDef * PORT, uint16_t pin_number);

/* main C entry point - should never return */
void main(void)
{
    /* Enable peripheral clocks */
    RCC->AHB1ENR = RCC_AHB1ENR_GPIODEN;
    
    /* Reset the GPIO registers to clean it up! */
    reset_GPIO(GPIOD);
    
    /*Configure the IO PORT*/
    GPIOD->MODER = 0x40000000;      //01 -> general purpose output mode for port 15
    GPIOD->OTYPER = 0x00000000;     //High bytes are reserved, low bites are 1 for open drain output or 0 for push pull configuration
    GPIOD->OSPEEDR = 0x00000000;    //00 for "low" #LOL speed (2MHz switching frequency)
    GPIOD->PUPDR = 0x00000000;      //00 for no pullup or no pulldown this is not necessary since the pins are outputs

    while (1)
    {
        static uint8_t led_val = 0;

        /* toggle the led */
        if (led_val)
        {
            led_val = 0;
            reset_pin(GPIOD, 15);
        }
        else
        {
            led_val = 1;
            set_pin(GPIOD, 15);
        }

        /* wait a bit */
        delay();
    }
}

static void reset_pin(GPIO_TypeDef * PORT, uint16_t pin_number) {
    
    PORT->BSRRH = (1<<pin_number);
    
}

static void set_pin(GPIO_TypeDef * PORT, uint16_t pin_number) {
    
    PORT->BSRRL = (1<<pin_number);
    
}

static void reset_GPIO(GPIO_TypeDef * PORT) {
    
    //reset all of the registers
    PORT->MODER = 0x00000000;
    PORT->OTYPER = 0x00000000;
    PORT->OSPEEDR = 0x00000000;
    PORT->PUPDR = 0x00000000;
    PORT->ODR = 0x00000000;
    PORT->BSRRL = 0x0000;
    PORT->BSRRH = 0x0000;
    PORT->LCKR = 0x00000000;
    PORT->AFR[0] = 0x00000000;
    PORT->AFR[1] = 0x00000000;
    
}

static void delay(void)
{
    uint32_t i = 0;
    while (i < 3200000) /* waste some clocks */
    { i++; }
}
