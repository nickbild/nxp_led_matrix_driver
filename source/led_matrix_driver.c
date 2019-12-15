/*
 * Nick Bild
 * NXP MIMXRT1010-EVK LED Matrix Driver
 * https://github.com/nickbild/nxp_led_matrix_driver
 *
 * Project initialized with NXP's "led_blinky" demo app code.
 */

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define pinR1 BOARD_USER_AD1_GPIO_PIN			// J56, 14
#define pinG1 BOARD_USER_AD2_GPIO_PIN			// J56, 16
#define pinB1 BOARD_USER_AD3_GPIO_PIN			// J57, 10
#define pinR2 BOARD_USER_AD4_GPIO_PIN			// J57, 8
#define pinG2 BOARD_USER_AD5_GPIO_PIN			// J57, 6
#define pinB2 BOARD_USER_AD6_GPIO_PIN			// J57, 12
#define pinOE BOARD_USER_AD7_GPIO_PIN			// J26, 2
#define latch BOARD_USER_AD9_GPIO_PIN			// J26, 4
#define pinClk BOARD_USER_AD10_GPIO_PIN			// J26, 6
#define selectA BOARD_USER_AD14_GPIO_PIN		// J26, 8
#define selectB BOARD_USER_2_GPIO_PIN			// J57, 20
#define selectC BOARD_USER_9_GPIO_PIN			// J56, 2
#define selectD BOARD_USER_10_GPIO_PIN			// J56, 4

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

    /* Main program loop */
    while (1)
    {
        /* Delay 1000 ms */
        SysTick_DelayTicks(100U);

        if (g_pinSet)
        {
            GPIO_PinWrite(BOARD_USER_GPIO, pinG1, 0U);
            g_pinSet = false;
        }
        else
        {
            GPIO_PinWrite(BOARD_USER_GPIO, pinG1, 1U);
            g_pinSet = true;
        }

    }

}
