/*!
    \file  main.c
    \brief Switches toggle the board LEDs

    \version 20200709
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

/* switch delay */
#define SW_DELAY 250

/* function prototypes */
void gpio_config(void);
void switches_config(void);
static void sw_processing(sw_t);

/* global variables */
         sw_status_t sw_previous_state[3];
volatile sw_status_t sw_current_state[3] =   {SW_RELEASE,
                                              SW_RELEASE,
                                              SW_RELEASE,
};
         
         

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
        sw_processing(S1);
        sw_processing(S2);
        sw_processing(S3);
    }
}

/*!
    \brief      initialize board LEDs
    \param[in]  none
    \param[out] none
    \retval     none
*/
void gpio_config(void)
{
    for (led_t i = LED1; i <= LEDB; i++)
    {
        gd_eval_led_init(i);
    }
}

/*!
    \brief      initialize the board switches
    \param[in]  none
    \param[out] none
    \retval     none
*/
void switches_config(void)
{
    gd_eval_sw_init(S1, SW_MODE_GPIO);
    gd_eval_sw_init(S2, SW_MODE_GPIO);
    gd_eval_sw_init(S3, SW_MODE_GPIO);
}

/*!
    \brief      performs keypressing evaluation
    \param[in]  sw_num: specify the switch to be configured
      \arg        Sx: S1..S5 switch
    \param[out] none
    \retval     none
*/
static void sw_processing(sw_t sw_num)
{
    sw_current_state[sw_num] = gd_eval_sw_state_get(sw_num);
    if (sw_current_state[sw_num] != sw_previous_state[sw_num]) 
    {
        gd_eval_led_toggle((led_t)sw_num);
        delay_1ms(SW_DELAY);
    }
    sw_previous_state[sw_num] = sw_current_state[sw_num];
}