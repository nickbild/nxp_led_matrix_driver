/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v6.0
processor: MIMXRT1011xxxxx
package_id: MIMXRT1011DAE5A
mcu_data: ksdk2_0
processor_version: 6.0.0
board: MIMXRT1010-EVK
power_domains: {NVCC_GPIO: '3.3'}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '59', peripheral: GPIO1, signal: 'gpiomux_io, 15', pin_signal: GPIO_AD_01, direction: OUTPUT, gpio_init_state: 'false', slew_rate: Fast, speed: MHZ_200,
    pull_keeper_select: Pull, pull_keeper_enable: Disable}
  - {pin_num: '58', peripheral: GPIO1, signal: 'gpiomux_io, 16', pin_signal: GPIO_AD_02, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '57', peripheral: GPIO1, signal: 'gpiomux_io, 17', pin_signal: GPIO_AD_03, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '56', peripheral: GPIO1, signal: 'gpiomux_io, 18', pin_signal: GPIO_AD_04, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '55', peripheral: GPIO1, signal: 'gpiomux_io, 19', pin_signal: GPIO_AD_05, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '52', peripheral: GPIO1, signal: 'gpiomux_io, 20', pin_signal: GPIO_AD_06, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '51', peripheral: GPIO1, signal: 'gpiomux_io, 21', pin_signal: GPIO_AD_07, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '48', peripheral: GPIO1, signal: 'gpiomux_io, 23', pin_signal: GPIO_AD_09, direction: OUTPUT, speed: MHZ_200, drive_strength: R0_4, pull_keeper_select: Pull,
    pull_keeper_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm}
  - {pin_num: '47', peripheral: GPIO1, signal: 'gpiomux_io, 24', pin_signal: GPIO_AD_10, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, drive_strength: R0_4,
    pull_keeper_select: Pull, pull_keeper_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: '43', peripheral: GPIO1, signal: 'gpiomux_io, 28', pin_signal: GPIO_AD_14, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '11', peripheral: GPIO1, signal: 'gpiomux_io, 02', pin_signal: GPIO_02, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '3', peripheral: GPIO1, signal: 'gpiomux_io, 09', pin_signal: GPIO_09, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
  - {pin_num: '2', peripheral: GPIO1, signal: 'gpiomux_io, 10', pin_signal: GPIO_10, direction: OUTPUT, slew_rate: Fast, speed: MHZ_200, pull_keeper_select: Pull,
    pull_keeper_enable: Disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* iomuxc clock (iomuxc_clk_enable): 0x03U */

  /* GPIO configuration of I2C1_SCL on GPIO_02 (pin 11) */
  gpio_pin_config_t I2C1_SCL_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_02 (pin 11) */
  GPIO_PinInit(GPIO1, 2U, &I2C1_SCL_config);

  /* GPIO configuration of UART1_RXD on GPIO_09 (pin 3) */
  gpio_pin_config_t UART1_RXD_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_09 (pin 3) */
  GPIO_PinInit(GPIO1, 9U, &UART1_RXD_config);

  /* GPIO configuration of UART1_TXD on GPIO_10 (pin 2) */
  gpio_pin_config_t UART1_TXD_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_10 (pin 2) */
  GPIO_PinInit(GPIO1, 10U, &UART1_TXD_config);

  /* GPIO configuration of ADC12_1 on GPIO_AD_01 (pin 59) */
  gpio_pin_config_t ADC12_1_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_01 (pin 59) */
  GPIO_PinInit(GPIO1, 15U, &ADC12_1_config);

  /* GPIO configuration of ADC12_2 on GPIO_AD_02 (pin 58) */
  gpio_pin_config_t ADC12_2_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_02 (pin 58) */
  GPIO_PinInit(GPIO1, 16U, &ADC12_2_config);

  /* GPIO configuration of LPSPI1_SDI on GPIO_AD_03 (pin 57) */
  gpio_pin_config_t LPSPI1_SDI_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_03 (pin 57) */
  GPIO_PinInit(GPIO1, 17U, &LPSPI1_SDI_config);

  /* GPIO configuration of LPSPI1_SDO on GPIO_AD_04 (pin 56) */
  gpio_pin_config_t LPSPI1_SDO_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_04 (pin 56) */
  GPIO_PinInit(GPIO1, 18U, &LPSPI1_SDO_config);

  /* GPIO configuration of LPSPI1_PCS0 on GPIO_AD_05 (pin 55) */
  gpio_pin_config_t LPSPI1_PCS0_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_05 (pin 55) */
  GPIO_PinInit(GPIO1, 19U, &LPSPI1_PCS0_config);

  /* GPIO configuration of LPSPI1_SCK on GPIO_AD_06 (pin 52) */
  gpio_pin_config_t LPSPI1_SCK_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_06 (pin 52) */
  GPIO_PinInit(GPIO1, 20U, &LPSPI1_SCK_config);

  /* GPIO configuration of ADC12_3 on GPIO_AD_07 (pin 51) */
  gpio_pin_config_t ADC12_3_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_07 (pin 51) */
  GPIO_PinInit(GPIO1, 21U, &ADC12_3_config);

  /* GPIO configuration of ADC12_4 on GPIO_AD_09 (pin 48) */
  gpio_pin_config_t ADC12_4_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_09 (pin 48) */
  GPIO_PinInit(GPIO1, 23U, &ADC12_4_config);

  /* GPIO configuration of ADC12_5 on GPIO_AD_10 (pin 47) */
  gpio_pin_config_t ADC12_5_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_10 (pin 47) */
  GPIO_PinInit(GPIO1, 24U, &ADC12_5_config);

  /* GPIO configuration of ADC12_6 on GPIO_AD_14 (pin 43) */
  gpio_pin_config_t ADC12_6_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_14 (pin 43) */
  GPIO_PinInit(GPIO1, 28U, &ADC12_6_config);

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_02_GPIOMUX_IO02,            /* GPIO_02 is configured as GPIOMUX_IO02 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_09_GPIOMUX_IO09,            /* GPIO_09 is configured as GPIOMUX_IO09 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_10_GPIOMUX_IO10,            /* GPIO_10 is configured as GPIOMUX_IO10 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_01_GPIOMUX_IO15,         /* GPIO_AD_01 is configured as GPIOMUX_IO15 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_02_GPIOMUX_IO16,         /* GPIO_AD_02 is configured as GPIOMUX_IO16 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_03_GPIOMUX_IO17,         /* GPIO_AD_03 is configured as GPIOMUX_IO17 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_04_GPIOMUX_IO18,         /* GPIO_AD_04 is configured as GPIOMUX_IO18 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_05_GPIOMUX_IO19,         /* GPIO_AD_05 is configured as GPIOMUX_IO19 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_06_GPIOMUX_IO20,         /* GPIO_AD_06 is configured as GPIOMUX_IO20 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_07_GPIOMUX_IO21,         /* GPIO_AD_07 is configured as GPIOMUX_IO21 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_09_GPIOMUX_IO23,         /* GPIO_AD_09 is configured as GPIOMUX_IO23 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_10_GPIOMUX_IO24,         /* GPIO_AD_10 is configured as GPIOMUX_IO24 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_14_GPIOMUX_IO28,         /* GPIO_AD_14 is configured as GPIOMUX_IO28 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 &
    (~(IOMUXC_GPR_GPR26_GPIO_SEL_MASK)))      /* Mask bits to zero which are setting */
      | IOMUXC_GPR_GPR26_GPIO_SEL(0x00U)      /* Select GPIO1 or GPIO2: 0x00U */
    );
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_02_GPIOMUX_IO02,            /* GPIO_02 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_09_GPIOMUX_IO09,            /* GPIO_09 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_10_GPIOMUX_IO10,            /* GPIO_10 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_01_GPIOMUX_IO15,         /* GPIO_AD_01 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_02_GPIOMUX_IO16,         /* GPIO_AD_02 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_03_GPIOMUX_IO17,         /* GPIO_AD_03 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_04_GPIOMUX_IO18,         /* GPIO_AD_04 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_05_GPIOMUX_IO19,         /* GPIO_AD_05 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_06_GPIOMUX_IO20,         /* GPIO_AD_06 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_07_GPIOMUX_IO21,         /* GPIO_AD_07 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_09_GPIOMUX_IO23,         /* GPIO_AD_09 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_10_GPIOMUX_IO24,         /* GPIO_AD_10 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_14_GPIOMUX_IO28,         /* GPIO_AD_14 PAD functional properties : */
      0x20E1U);                               /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/4
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
