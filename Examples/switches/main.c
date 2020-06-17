/*!
    \file  main.c
    \brief Switches toggle the LEDs

    \version 2020-06-17, V1.0.0 
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "gd32vf103.h"
#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

typedef enum {
    KEY_PRESSED = 0,
    KEY_NOT_PRESSED = 1
} key_pressed_t;

volatile uint8_t key_a_state,
                 key_b_state,
                 key_c_state,
                 key_d_state;

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    
        
    /* enable the LEDs  */
    gd_eval_led_init(LED1);
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
    gd_eval_led_init(LED4);
           
    /* initialize the keys */
    gd_eval_key_init(KEY_A, KEY_MODE_GPIO);
    gd_eval_key_init(KEY_B, KEY_MODE_GPIO);
    gd_eval_key_init(KEY_C, KEY_MODE_GPIO);
    gd_eval_key_init(KEY_D, KEY_MODE_GPIO);

    
    while (1) 
    {
        key_a_state = gd_eval_key_state_get(KEY_A);
        key_b_state = gd_eval_key_state_get(KEY_B);
        key_c_state = gd_eval_key_state_get(KEY_C);
        key_d_state = gd_eval_key_state_get(KEY_D);
        
        delay_1ms(200);
        
        if (KEY_PRESSED == key_a_state) 
        {
            gd_eval_led_toggle(LED1);
        }
        if (KEY_PRESSED == key_b_state) 
        {
            gd_eval_led_toggle(LED2);
        }
        if (KEY_PRESSED == key_c_state) 
        {
            gd_eval_led_toggle(LED3);
        }
        if (KEY_PRESSED == key_d_state) 
        {
            gd_eval_led_toggle(LED4);
        }
    }
}