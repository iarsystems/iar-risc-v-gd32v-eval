/*!
    \file  main.c
    \brief Accelerometer example for the IAR RISC-V GD32V Eval board

    \version 20201208
*/

/*
Copyright (c) 2020, IAR Systems AB.

See LICENSE.md for detailed license information.
*/

#include <stdio.h>

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"
#include "i2c.h"
#include "MMA8652.h"

/* tilt threshold in G's */
#define TILT_THRESHOLD (0.1500f)

typedef enum {
    LEFT,
    RIGHT,
    CENTER
} direction_t;

typedef enum {
    LED_IDX_NULL,
    LED_IDX1,
    LED_IDX2,
    LED_IDX3,
    LED_IDX4,
    LED_IDX5
} led_idx_t;

/* global variables */
uint8_t txbuffer[] = "\n\n\r---\n\r3-axis accelerometer example\n\r    X     Y     Z\n";
/* LED sequence on the board */
const uint8_t led_onboard_idx[LED_AMT] = { NULL, LED3, LED2, LED1, LED4, LED5 };

/* function prototypes */
void gpio_config(void);
void i2c_config(void);
void tilt(direction_t LorR);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void main(void)
{
    /* initialize the system  */
    SystemInit();

    /* GPIO config */
    gpio_config();
    /* I2C config */
    i2c_config();
    /* initialize the I2C 3-axis accelerometer */
    mma8652_init();
    delay_1ms(250);

    float x, y, z;
    direction_t current_tilt;

    /* print the example title to the (View -> Terminal I/O) */
    printf("%s\r\n", txbuffer);

    while(1)
    {
        /* get the current X-,Y-,Z-axis acceleration */
        mma8652_getxyz(&x, &y, &z);

        /* print the X-,Y-,Z-axis acceleration (in g's) to the (View -> Terminal I/O) */
        printf ("%2.3f  %2.3f  %2.3f\n", x, y, z);

        /* check the tilt threshold */
        if (x < -TILT_THRESHOLD)
        {
            current_tilt = RIGHT;
        }
        else if (x > TILT_THRESHOLD)
        {
            current_tilt = LEFT;
        }
        else
        {
            current_tilt = CENTER;
        }

        /* tilt the LEDs whenever needed */
        tilt(current_tilt);

        /* wait */
        delay_1ms(100);
    }
}

/*!
    \brief      simple LED bar tilt function
    \param[in]  LorRorC: LEFT, RIGHT or CENTER
    \param[out] none
    \retval     none
*/
void tilt(direction_t LorRorC)
{
    /* starts in the middle */
    static led_idx_t led_idx = LED_IDX3;

    /* turn off LED1..LED5 */
    for (led_t L = LED1; L <= LED5; L++)
    {
        gd_eval_led_off(L);
    }

    /* update LED to be lit according to the tilt */
    switch (LorRorC)
    {
    case LEFT:
        --led_idx;
        if (led_idx < LED_IDX1)
        {
            /* reached the leftmost LED */
            led_idx = LED_IDX1;
        }
        break;
    case RIGHT:
        ++led_idx;
        if (led_idx > LED_IDX5)
        {
            /* reached the rightmost LED */
            led_idx = LED_IDX5;
        }
        break;
    case CENTER:
        /* back to the middle */
        if (led_idx < LED_IDX3)
        { ++led_idx; }
        else if (led_idx > LED_IDX3)
        { --led_idx; }
        break;
    default:
        break;
    }

    /* turn on current LED */
    gd_eval_led_on((led_t)led_onboard_idx[led_idx]);
}

/*!
    \brief      setup GPIO
    \param[in]  none
    \param[out] none
    \retval     none
*/
void gpio_config(void)
{
    /* initialize and turn off LEDs (board index) */
    for (led_idx_t i = LED_IDX1; i <= LED_IDX5; i++)
    {
        gd_eval_led_init((led_t)led_onboard_idx[i]);
        gd_eval_led_on((led_t)led_onboard_idx[i]);
        delay_1ms(250);
        gd_eval_led_off((led_t)led_onboard_idx[i]);
    }
}

/*!
    \brief      setup I2C0
    \param[in]  none
    \param[out] none
    \retval     none
*/
void i2c_config(void)
{
    /* MCU device address for mastering the I2C bus */
    const uint8_t I2C0_OWN_ADDRESS7 = 0x72;

    rcu_periph_clock_enable(RCU_I2C0);
    rcu_periph_clock_enable(RCU_AF);

    /* connect PB8 to I2C0_SCL */
    /* connect PB9 to I2C0_SDA */
    gpio_init(GPIOB, GPIO_MODE_AF_OD, GPIO_OSPEED_50MHZ, GPIO_PIN_9 | GPIO_PIN_8);
    gpio_pin_remap_config(GPIO_I2C0_REMAP, ENABLE);

    /* I2C clock configure */
    i2c_clock_config(I2C0, 400000, I2C_DTCY_2);
    /* I2C address configure */
    i2c_mode_addr_config(I2C0, I2C_I2CMODE_ENABLE, I2C_ADDFORMAT_7BITS, I2C0_OWN_ADDRESS7);
    /* enable I2C0 */
    i2c_enable(I2C0);
    /* enable acknowledge */
    i2c_ack_config(I2C0, I2C_ACK_ENABLE);
}
