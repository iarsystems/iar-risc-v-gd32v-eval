/*!
    \file  main.c
    \brief SHT3x Temp/Hum sensor example for the IAR RISC-V GD32V Eval board
    
    \version 20200709
*/

/*
Copyright (c) 2020, IAR Systems AB.

See LICENSE.md for detailed license information.
*/

#include <stdio.h>

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"
#include "sht3x.h"

#define TEMP_LOW_THRESHOLD     (24500)
#define TEMP_MEDIUM_THRESHOLD  (25000)

#define HUM_LOW_THRESHOLD      (33000)
#define HUM_MEDIUM_THRESHOLD   (38000)

typedef enum {
    TEMP_LOW,
    TEMP_MEDIUM,
    TEMP_HIGH 
} temp_t;

typedef enum {
    HUM_LOW,
    HUM_MEDIUM,
    HUM_HIGH 
} hum_t;

/* function prototypes */
void gpio_config(void);
void i2c_config(void);
void red_alert(void);
void update_terminal_io(int32_t *, int32_t *);
void update_humidity_bar(hum_t);
void update_temperature_led(temp_t);

/* global variables */
uint8_t txbuffer[] = "\n\n\r---\n\rTemperature and humidity sensor example\n\r";

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
    sensirion_i2c_init();
    delay_1ms(250);
    
    /* probe the SHT3x sensor */
    while (STATUS_OK != sht3x_probe()) 
    {
        /* blink LEDR as long as probing fails */
        red_alert();
    }
    
    int32_t temperature, humidity;
    hum_t hum_level;
    temp_t temp_level;
    
    /* print the example title to the (View -> Terminal I/O) */
    printf("%s\r\n", txbuffer);
    
    while(1)
    {
        /*   measure temperature/humidity   */
        /* (each output multiplied by 1000) */
        int8_t ret = sht3x_measure_blocking_read(&temperature, &humidity);
        
        if (STATUS_OK == ret) 
        {
            /* check the humidity level */
            if (humidity <= HUM_LOW_THRESHOLD) 
            {
                hum_level = HUM_LOW;
            } 
            else if (humidity > HUM_LOW_THRESHOLD &&
                     humidity <= HUM_MEDIUM_THRESHOLD)
            {
                hum_level = HUM_MEDIUM;
            }
            else
            {
                hum_level = HUM_HIGH;
            }
            /* update the humidity LED bar */
            update_humidity_bar(hum_level);

            /* check the temperature level */
            if (temperature <= TEMP_LOW_THRESHOLD) 
            {
                temp_level = TEMP_LOW;
            } 
            else if (temperature > TEMP_LOW_THRESHOLD && 
                     temperature <= TEMP_MEDIUM_THRESHOLD)
            {
                temp_level = TEMP_MEDIUM;
            }
            else
            {
                temp_level = TEMP_HIGH;
            }
            /* update the temperature RGB LED */
            update_temperature_led(temp_level);
            
        } else {
            /* error */
            red_alert();
        }
        
        /* print the updated values to the (View -> Terminal I/O) */
        update_terminal_io(&temperature, &humidity);
        
        /* wait 3 seconds */
        delay_1ms(3000);
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
    /* initialize and turn off the LEDs */
    for (led_t i = LED1; i <= LEDB; i++)
    {
        gd_eval_led_init(i);
        gd_eval_led_on(i);
        delay_1ms(250);
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
    
    /* enable I2C0 clock */
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

/*!
    \brief      emmits a warning using LEDR
    \param[in]  none
    \param[out] none
    \retval     none
*/
void red_alert(void)
{
    for (uint8_t i = 0; i < 5; i++)
    {
        gd_eval_led_toggle(LEDR);
        delay_1ms(500);
    }
}

/*!
    \brief      updates the (View -> Terminal I/O) data
    \param[in]  temp: pointer to the temperature data
    \param[out] hum: pointer to the humidity data
    \retval     none
*/
void update_terminal_io(int32_t *temp, int32_t *hum)
{
    printf("Temperature: %0.2f'C, "
           "Rel.Humidity: %0.2f%%\n",
            *temp / 1000.0f,
            *hum  / 1000.0f); 
}

/*!
    \brief      the humidity LED bar uses LED3,LED2 and LED1
    \param[in]  hum
      \arg        HUM_LOW
      \arg        HUM_MEDIUM
      \arg        HUM_HIGH
    \param[out] none
    \retval     none
*/
void update_humidity_bar(hum_t hum)
{
    /* LED sequence on the board 3-2-1 */
    switch (hum)
    {
    case HUM_LOW:
        gd_eval_led_on (LED3);
        gd_eval_led_off(LED2);
        gd_eval_led_off(LED1);
        break;
    case HUM_MEDIUM:
        gd_eval_led_on (LED3);
        gd_eval_led_on (LED2);
        gd_eval_led_off(LED1);
        break; 
    case HUM_HIGH:
        gd_eval_led_on(LED3);
        gd_eval_led_on(LED2);
        gd_eval_led_on(LED1);
        break;
    default:
        break;
    }
}

/*!
    \brief      the RGB led is used to express temperature
    \param[in]  temp
      \arg        TEMP_LOW
      \arg        TEMP_MEDIUM
      \arg        TEMP_HIGH
    \param[out] none
    \retval     none
*/
void update_temperature_led(temp_t temp)
{
    switch (temp)
    {
    case TEMP_LOW:
        gd_eval_led_off(LEDR);
        gd_eval_led_off(LEDG);
        gd_eval_led_on(LEDB);
        break;
    case TEMP_MEDIUM:
        gd_eval_led_off(LEDR);
        gd_eval_led_on(LEDG);
        gd_eval_led_off(LEDB);
        break; 
    case TEMP_HIGH:
        gd_eval_led_on(LEDR);
        gd_eval_led_off(LEDG);
        gd_eval_led_off(LEDB);
        break;
    default:
        break;
    }
}