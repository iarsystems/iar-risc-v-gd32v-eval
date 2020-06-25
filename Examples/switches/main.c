/*!
    \file  main.c
    \brief Switches toggle the LEDs

    \version 20200625
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

#define DELAY 250

/* Local functions */
static void sw_processing(key_typedef_enum num);

/* Global variables */
volatile uint8_t sw_current_state[3];
         uint8_t sw_previous_state[3];

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    SystemInit();
    
    /* enable the LEDs */
    gd_eval_led_init(LED1);
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
    
    /* set LEDs initial state */
    gpio_bit_reset(LED1_GPIO_PORT, LED1_PIN);
    gpio_bit_reset(LED2_GPIO_PORT, LED2_PIN);
    gpio_bit_reset(LED3_GPIO_PORT, LED3_PIN);
           
    /* initialize the keys */
    gd_eval_key_init(KEY_A, KEY_MODE_GPIO);
    gd_eval_key_init(KEY_B, KEY_MODE_GPIO);
    gd_eval_key_init(KEY_C, KEY_MODE_GPIO);
    
    while (1) 
    {
        sw_processing(KEY_A);
        sw_processing(KEY_B);
        sw_processing(KEY_C);
    }
}

/*!
    \brief      Performs keypressing evaluation
    \param[in]  key_num: specify the key to be configured
      \arg        KEY_A: S1 key
      \arg        KEY_B: S2 key
      \arg        KEY_C: S3 key
      \arg        KEY_D: S4 key
      \arg        KEY_E: S5 key
    \param[out] none
    \retval     none
*/
static void sw_processing(key_typedef_enum key_num)
{
    sw_current_state[key_num] = gd_eval_key_state_get(key_num);
    if (sw_current_state[key_num] != sw_previous_state[key_num]) 
    {
        gd_eval_led_toggle((led_typedef_enum)key_num);
        delay_1ms(DELAY);
    }
    sw_previous_state[key_num] = sw_current_state[key_num];
}