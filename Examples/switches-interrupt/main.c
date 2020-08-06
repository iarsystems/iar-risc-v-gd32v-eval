/*!
    \file  main.c
    \brief Interrupt-driven switches example

    \version 20200806
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

#define DEBOUNCE_DELAY    25  // ms
#define PROGRAM_DELAY    200  // ms

/* global variables */
volatile sw_status_t Sx_pressed[SW_AMT];

/* function prototypes */
static void gpio_config(void);
static void switches_config(void);  
static void sw_processing(void);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    SystemInit();
    
    /* GPIO config */
    gpio_config();
    /* switches config */
    switches_config();
    
    while (1)
    {
        sw_processing();
        
        delay_1ms(PROGRAM_DELAY);
    }
}

/*!
    \brief      initialize LEDs LED1..LED3
    \param[in]  none
    \param[out] none
    \retval     none
*/
static void gpio_config(void)
{
    for (led_t l = LED1; l <= LED3; l++)
    {
        gd_eval_led_init(l);
    }
}
/*!
    \brief      initialize switches S1..S3
    \param[in]  none
    \param[out] none
    \retval     none
*/
static void switches_config(void)
{
    for (sw_t s = S1; s <= S3; s++)
    {
        gd_eval_sw_init(s, SW_MODE_EXTI);
        Sx_pressed[s] = SW_RELEASE;
    }
}

/*!
    \brief      performs keypressing evaluation
    \param[in]  none
    \param[out] none
    \retval     none
*/
static void sw_processing(void)
{
    /* performs processing for S1, S2 and S3 */
    for (sw_t s = S1; s <= S3; s++)
    {
        if (SW_PRESSED == Sx_pressed[s])
        {            
            gd_eval_led_toggle((led_t)s);            
            delay_1ms(DEBOUNCE_DELAY);
            Sx_pressed[s] = SW_RELEASE;
        }
    }
}
