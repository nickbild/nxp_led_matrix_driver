/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_01 (number 59), ADC12_1/J26[10]/J56[14] */
#define BOARD_ADC12_1_PERIPHERAL                                           GPIO1   /*!< Device name: GPIO1 */
#define BOARD_ADC12_1_SIGNAL                                          gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_ADC12_1_CHANNEL                                                15U   /*!< GPIO1 gpiomux_io channel: 15 */

/* GPIO_AD_02 (number 58), ADC12_2/J26[12]/J56[16] */
#define BOARD_ADC12_2_PERIPHERAL                                           GPIO1   /*!< Device name: GPIO1 */
#define BOARD_ADC12_2_SIGNAL                                          gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_ADC12_2_CHANNEL                                                16U   /*!< GPIO1 gpiomux_io channel: 16 */

/* GPIO_AD_03 (number 57), LPSPI1_SDI/J57[10]/U27[2] */
#define BOARD_LPSPI1_SDI_PERIPHERAL                                        GPIO1   /*!< Device name: GPIO1 */
#define BOARD_LPSPI1_SDI_SIGNAL                                       gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_LPSPI1_SDI_CHANNEL                                             17U   /*!< GPIO1 gpiomux_io channel: 17 */

/* GPIO_AD_04 (number 56), LPSPI1_SDO/J57[8]/U27[5] */
#define BOARD_LPSPI1_SDO_PERIPHERAL                                        GPIO1   /*!< Device name: GPIO1 */
#define BOARD_LPSPI1_SDO_SIGNAL                                       gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_LPSPI1_SDO_CHANNEL                                             18U   /*!< GPIO1 gpiomux_io channel: 18 */

/* GPIO_AD_05 (number 55), LPSPI1_PCS0/INT1_COMBO/J56[6]/J57[6]/U26[11]/U27[1] */
#define BOARD_LPSPI1_PCS0_PERIPHERAL                                       GPIO1   /*!< Device name: GPIO1 */
#define BOARD_LPSPI1_PCS0_SIGNAL                                      gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_LPSPI1_PCS0_CHANNEL                                            19U   /*!< GPIO1 gpiomux_io channel: 19 */

/* GPIO_AD_06 (number 52), LPSPI1_SCK/INT2_COMBO/J56[8]/J57[12]/U26[9]/U27[6] */
#define BOARD_LPSPI1_SCK_PERIPHERAL                                        GPIO1   /*!< Device name: GPIO1 */
#define BOARD_LPSPI1_SCK_SIGNAL                                       gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_LPSPI1_SCK_CHANNEL                                             20U   /*!< GPIO1 gpiomux_io channel: 20 */

/* GPIO_AD_07 (number 51), ADC12_3/J26[2] */
#define BOARD_ADC12_3_PERIPHERAL                                           GPIO1   /*!< Device name: GPIO1 */
#define BOARD_ADC12_3_SIGNAL                                          gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_ADC12_3_CHANNEL                                                21U   /*!< GPIO1 gpiomux_io channel: 21 */

/* GPIO_AD_09 (number 48), ADC12_4/JTAG_TDO/J55[6]/J26[4] */
#define BOARD_ADC12_4_PERIPHERAL                                           GPIO1   /*!< Device name: GPIO1 */
#define BOARD_ADC12_4_SIGNAL                                          gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_ADC12_4_CHANNEL                                                23U   /*!< GPIO1 gpiomux_io channel: 23 */

/* GPIO_AD_10 (number 47), ADC12_5/JTAG_TDI/J55[8]/J26[6] */
#define BOARD_ADC12_5_PERIPHERAL                                           GPIO1   /*!< Device name: GPIO1 */
#define BOARD_ADC12_5_SIGNAL                                          gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_ADC12_5_CHANNEL                                                24U   /*!< GPIO1 gpiomux_io channel: 24 */

/* GPIO_AD_14 (number 43), ADC12_6/J26[8] */
#define BOARD_ADC12_6_PERIPHERAL                                           GPIO1   /*!< Device name: GPIO1 */
#define BOARD_ADC12_6_SIGNAL                                          gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_ADC12_6_CHANNEL                                                28U   /*!< GPIO1 gpiomux_io channel: 28 */

/* GPIO_02 (number 11), I2C1_SCL/U10[17]/J57[20]/U26[4] */
#define BOARD_I2C1_SCL_PERIPHERAL                                          GPIO1   /*!< Device name: GPIO1 */
#define BOARD_I2C1_SCL_SIGNAL                                         gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_I2C1_SCL_CHANNEL                                                2U   /*!< GPIO1 gpiomux_io channel: 02 */

/* GPIO_09 (number 3), LPUART1_RXD/J56[2] */
#define BOARD_UART1_RXD_PERIPHERAL                                         GPIO1   /*!< Device name: GPIO1 */
#define BOARD_UART1_RXD_SIGNAL                                        gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_UART1_RXD_CHANNEL                                               9U   /*!< GPIO1 gpiomux_io channel: 09 */

/* GPIO_10 (number 2), LPUART1_TXD/J56[4] */
#define BOARD_UART1_TXD_PERIPHERAL                                         GPIO1   /*!< Device name: GPIO1 */
#define BOARD_UART1_TXD_SIGNAL                                        gpiomux_io   /*!< GPIO1 signal: gpiomux_io */
#define BOARD_UART1_TXD_CHANNEL                                              10U   /*!< GPIO1 gpiomux_io channel: 10 */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
