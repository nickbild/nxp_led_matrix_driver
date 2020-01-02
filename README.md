# NXP i.MX RT1010 EVK RGB LED Matrix Driver

Drive a 32x32 RGB LED matrix with the NXP [i.MX RT1010 EVK](http://nxp.com/imxrt1010evk).  Any matrix that is drop-in compatible with the [Adafruit 1484](https://www.adafruit.com/product/1484) will work.

<p align="center">
<img src="https://raw.githubusercontent.com/nickbild/nxp_led_matrix_driver/master/media/matrix.gif">
</p>

# Media

High resolution video available on [YouTube](https://www.youtube.com/watch?v=qah41zP-ang).

Top view of the EVK.  The strange looking wires are standard 22AWG copper wires wrapped in aluminum foil.  The i.MX RT1010 EVK GPIOs switch *very* fast, so EMI shielding was a must to prevent spurious signals from producing unwanted visual artifacts on the matrix.  That took more than a little debugging to sort out.  :)

![EVK Top](https://github.com/nickbild/nxp_led_matrix_driver/raw/master/media/mimxrt1010-evk_top_sm.jpg)

EVK connected to LED matrix:

![EVK connected](https://github.com/nickbild/nxp_led_matrix_driver/raw/master/media/mimxrt1010-evk_connected_sm.jpg)

EVK driving the matrix:

![EVK driving matrix](https://github.com/nickbild/nxp_led_matrix_driver/raw/master/media/nxp_matrix_sm.jpg)

Some sample images.  Taking images of an illuminated LED matrix is very difficult.  It definitely looks better in person.

<p align="center">
<img src="https://github.com/nickbild/nxp_led_matrix_driver/raw/master/media/mona_lisa_sm.jpg">
</p>

<p align="center">
<img src="https://github.com/nickbild/nxp_led_matrix_driver/raw/master/media/mario_sm.jpg">
</p>

<p align="center">
<img src="https://github.com/nickbild/nxp_led_matrix_driver/raw/master/media/hackster_sm.jpg">
</p>

# Use

1. Connect the GPIO pins to your LED matrix per the comments in [source/led_matrix_driver.c](https://github.com/nickbild/nxp_led_matrix_driver/blob/master/source/led_matrix_driver.c):

```c
// GPIO pin mappings.							// Header, Pin Number
#define pinR1 BOARD_USER_AD1_GPIO_PIN			  // J56, 14
#define pinG1 BOARD_USER_AD2_GPIO_PIN			  // J56, 16
#define pinB1 BOARD_USER_AD3_GPIO_PIN			  // J57, 10
#define pinR2 BOARD_USER_AD4_GPIO_PIN			  // J57, 8
#define pinG2 BOARD_USER_AD5_GPIO_PIN			  // J57, 6
#define pinB2 BOARD_USER_AD6_GPIO_PIN			  // J57, 12
#define pinOE BOARD_USER_AD7_GPIO_PIN			  // J26, 2
#define latch BOARD_USER_AD9_GPIO_PIN			  // J26, 4
#define pinClk BOARD_USER_AD10_GPIO_PIN			  // J26, 6
#define selectA BOARD_USER_AD14_GPIO_PIN		  // J26, 8
#define selectB BOARD_USER_2_GPIO_PIN			  // J57, 20
#define selectC BOARD_USER_9_GPIO_PIN			  // J56, 2
#define selectD BOARD_USER_10_GPIO_PIN			   // J56, 4
```

2. Generate C data structure files containing graphic data.  [See details here](#create-graphics).

3. Prepare graphic data:

```bash
python3 data_generator/data_generator.py [data_file_1.c] ... [data_file_N.c]
```

1+ files may be supplied.  If >1 files are supplied, an animation will be displayed on the matrix.  The animation will cycle through images in the order they are given.

The script will produce output similar to this:

```c
#define numImages 1  // >1 means animation.
#define changeImageFrames -1  // Animation control. Set to -1 to display a single image.  Larger number == longer delay between image changes.

__RODATA(Flash2) const unsigned short int brightnessR[numImages][32][32] = {{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {23, 23, 23, 0, 0, 0, 0, 0, 0, 23, 23, 12, 12, 0, 0, 0, 0, 0, 0, 0, 6, 6, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0}, {23, 23, 23, 23, 0, 0, 0, 0, 0, 23, 23, 12, 12, 0, 0, 0, 0, 0, 0, 0, 6, 6, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0}, {23, 23, 23, 23, 23, 0, 0, 0, 0, 23, 23, 12, 12, 0, 0, 0, 0, 0, 0, 0, 6, 6, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0}, {23, 23, 23, 23, 23, 23, 0, 0, 0, 23, 23, 12, 12, 0, 0, 0, 0, 0, 0, 0, 6, 6, 14, 0, 0, 0, 0, 0, 14, 14, 14, 14}, {23, 23, 23, 23, 23, 23, 23, 0, 0, 23, 23, 12, 12, 12, 0, 0, 0, 0, 0, 6, 6, 6, 14, 0, 0, 0, 0, 0, 14, 14, 14, 14}, {23, 23, 23, 0, 23, 23, 23, 23, 0, 23, 23, 23, 23, 12, 12, 0, 0, 0, 6, 6, 14, 14, 14, 0, 0, 0, 0, 0, 14, 14, 14, 14}, {23, 23, 23, 0, 0, 23, 23, 23, 23, 23, 23, 23, 23, 12, 12, 0, 0, 0, 6, 6, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0}, {23, 23, 23, 0, 0, 0, 23, 23, 23, 23, 23, 23, 12, 12, 0, 0, 0, 0, 0, 6, 6, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0}, {23, 23, 23, 0, 0, 0, 0, 23, 23, 23, 23, 12, 12, 12, 0, 0, 0, 0, 0, 6, 6, 6, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0}, {23, 23, 23, 0, 0, 0, 0, 0, 23, 23, 23, 12, 12, 0, 0, 0, 0, 0, 0, 0, 6, 6, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {23, 23, 23, 0, 0, 0, 0, 0, 0, 23, 23, 12, 12, 0, 0, 0, 0, 0, 0, 0, 6, 6, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {23, 23, 23, 0, 0, 0, 0, 0, 0, 23, 23, 12, 12, 0, 0, 0, 0, 0, 0, 0, 6, 6, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 40, 40, 40, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {36, 0, 0, 0, 0, 0, 36, 0, 0, 36, 36, 0, 0, 36, 36, 36, 36, 36, 0, 36, 36, 0, 0, 0, 36, 0, 36, 0, 0, 0, 36, 0}, {36, 36, 0, 0, 0, 36, 36, 0, 36, 0, 0, 36, 0, 0, 0, 36, 0, 0, 0, 36, 0, 36, 0, 0, 36, 0, 0, 36, 0, 36, 0, 0}, {36, 0, 36, 0, 36, 0, 36, 0, 36, 0, 0, 36, 0, 0, 0, 36, 0, 0, 0, 36, 0, 0, 36, 0, 36, 0, 0, 0, 36, 0, 0, 0}, {36, 0, 0, 36, 0, 0, 36, 0, 36, 36, 36, 36, 0, 0, 0, 36, 0, 0, 0, 36, 0, 36, 0, 0, 36, 0, 0, 0, 36, 0, 0, 0}, {36, 0, 0, 0, 0, 0, 36, 0, 36, 0, 0, 36, 0, 0, 0, 36, 0, 0, 0, 36, 36, 0, 0, 0, 36, 0, 0, 0, 36, 0, 0, 0}, {36, 0, 0, 0, 0, 0, 36, 0, 36, 0, 0, 36, 0, 0, 0, 36, 0, 0, 0, 36, 0, 36, 0, 0, 36, 0, 0, 36, 0, 36, 0, 0}, {36, 0, 0, 0, 0, 0, 36, 0, 36, 0, 0, 36, 0, 0, 0, 36, 0, 0, 0, 36, 0, 0, 36, 0, 36, 0, 36, 0, 0, 0, 36, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}};

__RODATA(Flash2) const unsigned short int brightnessG[numImages][32][32] = {{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {11, 11, 11, 0, 0, 0, 0, 0, 0, 11, 11, 7, 7, 11, 0, 0, 0, 0, 0, 11, 7, 7, 19, 19, 19, 19, 19, 19, 19, 0, 0, 0}, {11, 11, 11, 11, 0, 0, 0, 0, 0, 11, 11, 7, 7, 11, 0, 0, 0, 0, 0, 11, 7, 7, 19, 19, 19, 19, 19, 19, 19, 19, 0, 0}, {11, 11, 11, 11, 11, 0, 0, 0, 0, 11, 11, 7, 7, 11, 11, 0, 0, 0, 11, 11, 7, 7, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0}, {11, 11, 11, 11, 11, 11, 0, 0, 0, 11, 11, 7, 7, 11, 11, 11, 0, 11, 11, 11, 7, 7, 19, 0, 0, 0, 0, 0, 19, 19, 19, 19}, {11, 11, 11, 11, 11, 11, 11, 0, 0, 11, 11, 7, 7, 7, 11, 11, 11, 11, 11, 7, 7, 7, 19, 0, 0, 0, 0, 0, 19, 19, 19, 19}, {11, 11, 11, 0, 11, 11, 11, 11, 0, 11, 11, 11, 11, 7, 7, 11, 11, 11, 7, 7, 19, 19, 19, 0, 0, 0, 0, 0, 19, 19, 19, 19}, {11, 11, 11, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 7, 7, 11, 11, 11, 7, 7, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0}, {11, 11, 11, 0, 0, 0, 11, 11, 11, 11, 11, 11, 7, 7, 11, 11, 11, 11, 11, 7, 7, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0, 0}, {11, 11, 11, 0, 0, 0, 0, 11, 11, 11, 11, 7, 7, 7, 11, 11, 0, 11, 11, 7, 7, 7, 19, 19, 19, 19, 19, 19, 19, 0, 0, 0}, {11, 11, 11, 0, 0, 0, 0, 0, 11, 11, 11, 7, 7, 11, 11, 0, 0, 0, 11, 11, 7, 7, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {11, 11, 11, 0, 0, 0, 0, 0, 0, 11, 11, 7, 7, 11, 0, 0, 0, 0, 0, 11, 7, 7, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {11, 11, 11, 0, 0, 0, 0, 0, 0, 11, 11, 7, 7, 11, 0, 0, 0, 0, 0, 11, 7, 7, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {30, 0, 0, 0, 0, 0, 30, 0, 0, 30, 30, 0, 0, 30, 30, 30, 30, 30, 0, 30, 30, 0, 0, 0, 30, 0, 30, 0, 0, 0, 30, 0}, {30, 30, 0, 0, 0, 30, 30, 0, 30, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 30, 0, 30, 0, 0, 30, 0, 0, 30, 0, 30, 0, 0}, {30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 30, 0, 0, 30, 0, 30, 0, 0, 0, 30, 0, 0, 0}, {30, 0, 0, 30, 0, 0, 30, 0, 30, 30, 30, 30, 0, 0, 0, 30, 0, 0, 0, 30, 0, 30, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0}, {30, 0, 0, 0, 0, 0, 30, 0, 30, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 30, 30, 0, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0}, {30, 0, 0, 0, 0, 0, 30, 0, 30, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 30, 0, 30, 0, 0, 30, 0, 0, 30, 0, 30, 0, 0}, {30, 0, 0, 0, 0, 0, 30, 0, 30, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 30, 0, 0, 30, 0, 30, 0, 30, 0, 0, 0, 30, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}};

__RODATA(Flash2) const unsigned short int brightnessB[numImages][32][32] = {{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 5, 5, 32, 0, 0, 0, 0, 0, 32, 4, 4, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 5, 5, 32, 0, 0, 0, 0, 0, 32, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0}, {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 5, 5, 32, 32, 0, 0, 0, 32, 32, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 5, 5, 32, 32, 32, 0, 32, 32, 32, 4, 4, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 5, 5, 5, 32, 32, 32, 32, 32, 4, 4, 4, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3}, {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 5, 5, 32, 32, 32, 4, 4, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 32, 32, 32, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0}, {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 5, 32, 32, 32, 32, 32, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0}, {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 5, 5, 5, 32, 32, 0, 32, 32, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 5, 5, 32, 32, 0, 0, 0, 32, 32, 4, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 5, 5, 32, 0, 0, 0, 0, 0, 32, 4, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 5, 5, 32, 0, 0, 0, 0, 0, 32, 4, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}};
```

4. Copy the above output into [source/led_matrix_driver.c](https://github.com/nickbild/nxp_led_matrix_driver/blob/master/source/led_matrix_driver.c), between the comments:

```c
/*******************************************************************************
 * Data to Display - Paste graphics data BELOW this comment.
 ******************************************************************************/

[**** INSERT OUTPUT HERE ****]

/*******************************************************************************
 * END of Data to Display - Paste graphics data ABOVE this comment.
 ******************************************************************************/
```

5. Transfer the code to the i.MX RT1010 EVK.  NXP has some great documentation if needed:

https://www.nxp.com/document/guide/getting-started-with-i-mx-rt1010-evaluation-kit:GS-MIMXRT1010-EVK

# Create Graphics

# About the Author

[Nick A. Bild, M.S.](https://nickbild79.firebaseapp.com/#!/)

# Software License

3-Clause BSD License

Copyright 2019 Nick Bild

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
