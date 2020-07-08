/*!
\file  main.c
\brief Accelerometer example for the IAR RISC-V GD32V Eval board

\version 20200708
*/

/*
Copyright (c) 2020, IAR Systems AB.

See LICENSE.md for detailed license information.
*/

#include <stdio.h>

#include "iar-risc-v-gd32v-eval.h"
#include "gd32vf103_libopt.h"
#include "systick.h"
#include "i2c.h"
#include "mma8652.h"

/* tilt threshold in G's */
#define TILT_THRESHOLD (0.1000f) 

typedef enum {
    LEFT,
    RIGHT,
    CENTER 
} direction_t;

uint8_t txbuffer[] = "\n\n\r---\n\r3-axis accelerometer example\n\r    X     Y     Z\n";

/* function prototypes */
void rcu_config(void);
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
    SystemInit();
    
    /* RCU config */
    rcu_config();
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
    /* LED sequence on the board 3-2-(1)-4-5 */
    static uint8_t current_led = 3;
    
    switch (LorRorC)
    {
    case LEFT:
        --current_led;
        if (current_led < 1)
        { current_led = 1; }
        break;
    case RIGHT:
        ++current_led;
        if (current_led > 5)
        { current_led = 5; }
        break; 
    case CENTER:
        if (current_led < 3)
        { ++current_led; }
        else if (current_led > 3)
        { --current_led; }
        break;
    default:
        break;
    }
    
    /* turn off LEDs */
    for (led_typedef_enum i = LED1; i <= LED5; i++)
    {
        gd_eval_led_off(i);
    }
    
    /* translate LEDs to the board sequence */
    switch(current_led)
    {
    case 1:
        gd_eval_led_on(LED3);
        break;
    case 2:
        gd_eval_led_on(LED2);
        break;
    case 3:
        gd_eval_led_on(LED1);
        break;
    case 4:
        gd_eval_led_on(LED4);
        break;
    case 5:
        gd_eval_led_on(LED5);
        break;
    default:
        break;
    }
}
/*!
\brief      setup GPIO
\param[in]  none
\param[out] none
\retval     none
*/
void gpio_config(void)
{
    /* initialize and turn off LEDs */
    for (led_typedef_enum i = LED1; i <= LED5; i++)
    {
        gd_eval_led_init(i);
        gd_eval_led_off(i);
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

/*!
\brief      enable the clock line to the peripherals
\param[in]  none
\param[out] none
\retval     none
*/
void rcu_config(void)
{
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOC);
    
    /* enable I2C0 clock */
    rcu_periph_clock_enable(RCU_I2C0);
    rcu_periph_clock_enable(RCU_AF);
}
