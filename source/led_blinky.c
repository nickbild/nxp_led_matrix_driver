/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_LED_GPIO BOARD_USER_LED_GPIO
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D1_GPIO_PIN			// J56, 14
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D2_GPIO_PIN			// J56, 16
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D3_GPIO_PIN			// J57, 10
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D4_GPIO_PIN			// J57, 8
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D5_GPIO_PIN			// J57, 6
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D6_GPIO_PIN			// J57, 12
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D7_GPIO_PIN			// J26, 2
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D9_GPIO_PIN			// J26, 4
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D10_GPIO_PIN			// J26, 6
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_D14_GPIO_PIN			// J26, 8
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_2_GPIO_PIN			// J57, 20
//#define EXAMPLE_LED_GPIO_PIN BOARD_USER_9_GPIO_PIN			// J56, 2
#define EXAMPLE_LED_GPIO_PIN BOARD_USER_10_GPIO_PIN				// J56, 4

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint32_t g_systickCounter;
/* The PIN status */
volatile bool g_pinSet = false;

/*******************************************************************************
 * Code
 ******************************************************************************/
void SysTick_Handler(void)
{
    if (g_systickCounter != 0U)
    {
        g_systickCounter--;
    }
}

void SysTick_DelayTicks(uint32_t n)
{
    g_systickCounter = n;
    while (g_systickCounter != 0U)
    {
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Board pin init */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Set systick reload value to generate 1ms interrupt */
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
        while (1)
        {
        }
    }

    while (1)
    {
        /* Delay 1000 ms */
        SysTick_DelayTicks(100U);
        if (g_pinSet)
        {
            GPIO_PinWrite(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, 0U);
            g_pinSet = false;
        }
        else
        {
            GPIO_PinWrite(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, 1U);
            g_pinSet = true;
        }
    }
}
