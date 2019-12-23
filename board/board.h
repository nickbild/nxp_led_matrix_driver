/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Modified by Nick Bild for:
 * NXP MIMXRT1010-EVK LED Matrix Driver
 * https://github.com/nickbild/nxp_led_matrix_driver
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "clock_config.h"
#include "fsl_common.h"
#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The board name */
#define BOARD_NAME "MIMXRT1010-EVK"

/* The UART to use for debug messages. */
#define BOARD_DEBUG_UART_TYPE kSerialPort_Uart
#define BOARD_DEBUG_UART_BASEADDR (uint32_t) LPUART1
#define BOARD_DEBUG_UART_INSTANCE 1U

#define BOARD_DEBUG_UART_CLK_FREQ BOARD_DebugConsoleSrcFreq()

#define BOARD_UART_IRQ LPUART1_IRQn
#define BOARD_UART_IRQ_HANDLER LPUART1_IRQHandler

#ifndef BOARD_DEBUG_UART_BAUDRATE
#define BOARD_DEBUG_UART_BAUDRATE (115200U)
#endif /* BOARD_DEBUG_UART_BAUDRATE */

/* @Brief Board accelerator sensor configuration */
#define BOARD_ACCEL_I2C_BASEADDR LPI2C1
#define BOARD_ACCEL_I2C_CLOCK_SOURCE_SELECT (0U)
#define BOARD_ACCEL_I2C_CLOCK_SOURCE_DIVIDER (5U)
#define BOARD_ACCEL_I2C_CLOCK_FREQ (CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8 / (BOARD_ACCEL_I2C_CLOCK_SOURCE_DIVIDER + 1U))

#define BOARD_CODEC_I2C_BASEADDR LPI2C1
#define BOARD_CODEC_I2C_INSTANCE 1U
#define BOARD_CODEC_I2C_CLOCK_SOURCE_SELECT (0U)
#define BOARD_CODEC_I2C_CLOCK_SOURCE_DIVIDER (5U)
#define BOARD_CODEC_I2C_CLOCK_FREQ (10000000U)

/*! @brief The USER_LED used for board */
#define LOGIC_LED_ON (0U)
#define LOGIC_LED_OFF (1U)
#ifndef BOARD_USER_GPIO
#define BOARD_USER_GPIO GPIO1
#endif
#ifndef BOARD_USER_AD1_GPIO_PIN
#define BOARD_USER_AD1_GPIO_PIN (15U)
#endif
#ifndef BOARD_USER_AD2_GPIO_PIN
#define BOARD_USER_AD2_GPIO_PIN (16U)
#endif
#ifndef BOARD_USER_AD3_GPIO_PIN
#define BOARD_USER_AD3_GPIO_PIN (17U)
#endif
#ifndef BOARD_USER_AD4_GPIO_PIN
#define BOARD_USER_AD4_GPIO_PIN (18U)
#endif
#ifndef BOARD_USER_AD5_GPIO_PIN
#define BOARD_USER_AD5_GPIO_PIN (19U)
#endif
#ifndef BOARD_USER_AD6_GPIO_PIN
#define BOARD_USER_AD6_GPIO_PIN (20U)
#endif
#ifndef BOARD_USER_AD7_GPIO_PIN
#define BOARD_USER_AD7_GPIO_PIN (21U)
#endif
#ifndef BOARD_USER_AD9_GPIO_PIN
#define BOARD_USER_AD9_GPIO_PIN (23U)
#endif
#ifndef BOARD_USER_AD10_GPIO_PIN
#define BOARD_USER_AD10_GPIO_PIN (24U)
#endif
#ifndef BOARD_USER_AD14_GPIO_PIN
#define BOARD_USER_AD14_GPIO_PIN (28U)
#endif
#ifndef BOARD_USER_2_GPIO_PIN
#define BOARD_USER_2_GPIO_PIN (2U)
#endif
#ifndef BOARD_USER_9_GPIO_PIN
#define BOARD_USER_9_GPIO_PIN (9U)
#endif
#ifndef BOARD_USER_10_GPIO_PIN
#define BOARD_USER_10_GPIO_PIN (10U)
#endif
#ifndef BOARD_USER_1_GPIO_PIN
#define BOARD_USER_1_GPIO_PIN (1U)
#endif

/*! @brief Define the port interrupt number for the board switches */
#ifndef BOARD_USER_BUTTON_GPIO
#define BOARD_USER_BUTTON_GPIO GPIO2
#endif
#ifndef BOARD_USER_BUTTON_GPIO_PIN
#define BOARD_USER_BUTTON_GPIO_PIN (5U)
#endif
#define BOARD_USER_BUTTON_IRQ GPIO2_Combined_0_15_IRQn
#define BOARD_USER_BUTTON_IRQ_HANDLER GPIO2_Combined_0_15_IRQHandler
#define BOARD_USER_BUTTON_NAME "SW4"

/*! @brief The flash size */
#define BOARD_FLASH_SIZE (0x1000000U)

/* USB PHY condfiguration */
#define BOARD_USB_PHY_D_CAL (0x0CU)
#define BOARD_USB_PHY_TXCAL45DP (0x06U)
#define BOARD_USB_PHY_TXCAL45DM (0x06U)

#define BOARD_ARDUINO_INT_IRQ (GPIO1_Combined_16_31_IRQn)
#define BOARD_ARDUINO_I2C_IRQ (LPI2C1_IRQn)
#define BOARD_ARDUINO_I2C_INDEX (1)

/*! @brief The WIFI-QCA shield pin. */
#define BOARD_INITSILEX2401SHIELD_PWRON_GPIO GPIO1                    /*!< GPIO device name: GPIO */
#define BOARD_INITSILEX2401SHIELD_PWRON_PORT 1U                       /*!< PORT device index: 1 */
#define BOARD_INITSILEX2401SHIELD_PWRON_GPIO_PIN 8U                   /*!< PIO1 pin index: 8 */
#define BOARD_INITSILEX2401SHIELD_PWRON_PIN_NAME GPIO1_08             /*!< Pin name */
#define BOARD_INITSILEX2401SHIELD_PWRON_LABEL "PWRON"                 /*!< Label */
#define BOARD_INITSILEX2401SHIELD_PWRON_NAME "PWRON"                  /*!< Identifier name */
#define BOARD_INITSILEX2401SHIELD_PWRON_DIRECTION kGPIO_DigitalOutput /*!< Direction */

#define BOARD_INITSILEX2401SHIELD_IRQ_GPIO GPIO1                   /*!< GPIO device name: GPIO */
#define BOARD_INITSILEX2401SHIELD_IRQ_PORT 1U                      /*!< PORT device index: 1 */
#define BOARD_INITSILEX2401SHIELD_IRQ_GPIO_PIN 4U                  /*!< PIO1 pin index: 4 */
#define BOARD_INITSILEX2401SHIELD_IRQ_PIN_NAME GPIO1_04            /*!< Pin name */
#define BOARD_INITSILEX2401SHIELD_IRQ_LABEL "IRQ"                  /*!< Label */
#define BOARD_INITSILEX2401SHIELD_IRQ_NAME "IRQ"                   /*!< Identifier name */
#define BOARD_INITSILEX2401SHIELD_IRQ_DIRECTION kGPIO_DigitalInput /*!< Direction */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/
uint32_t BOARD_DebugConsoleSrcFreq(void);

void BOARD_InitDebugConsole(void);
void BOARD_ConfigMPU(void);
#if defined(SDK_I2C_BASED_COMPONENT_USED) && SDK_I2C_BASED_COMPONENT_USED
void BOARD_InitDebugConsole(void);
void BOARD_LPI2C_Init(LPI2C_Type *base, uint32_t clkSrc_Hz);
status_t BOARD_LPI2C_Send(LPI2C_Type *base,
                          uint8_t deviceAddress,
                          uint32_t subAddress,
                          uint8_t subaddressSize,
                          uint8_t *txBuff,
                          uint8_t txBuffSize);
status_t BOARD_LPI2C_Receive(LPI2C_Type *base,
                             uint8_t deviceAddress,
                             uint32_t subAddress,
                             uint8_t subaddressSize,
                             uint8_t *rxBuff,
                             uint8_t rxBuffSize);
void BOARD_Accel_I2C_Init(void);
status_t BOARD_Accel_I2C_Send(uint8_t deviceAddress, uint32_t subAddress, uint8_t subaddressSize, uint32_t txBuff);
status_t BOARD_Accel_I2C_Receive(
    uint8_t deviceAddress, uint32_t subAddress, uint8_t subaddressSize, uint8_t *rxBuff, uint8_t rxBuffSize);
void BOARD_Codec_I2C_Init(void);
status_t BOARD_Codec_I2C_Send(
    uint8_t deviceAddress, uint32_t subAddress, uint8_t subAddressSize, const uint8_t *txBuff, uint8_t txBuffSize);
status_t BOARD_Codec_I2C_Receive(
    uint8_t deviceAddress, uint32_t subAddress, uint8_t subAddressSize, uint8_t *rxBuff, uint8_t rxBuffSize);
#endif /* SDK_I2C_BASED_COMPONENT_USED */
#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
