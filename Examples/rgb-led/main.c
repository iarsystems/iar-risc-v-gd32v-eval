/*!
    \file  main.c
    \brief Toggles the RGB LED
    
    \version 2020-06-17 
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

#define DELAY 250 // ms

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void main(void)
{
    /* enable the RGB LED clock */
    rcu_periph_clock_enable(LEDR_GPIO_CLK);
    rcu_periph_clock_enable(LEDG_GPIO_CLK);
    rcu_periph_clock_enable(LEDB_GPIO_CLK);
    
    /* configure RGB LED GPIO port */
    gpio_init(LEDR_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LEDR_PIN);
    gpio_init(LEDG_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LEDG_PIN);
    gpio_init(LEDB_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LEDB_PIN);

    /* set RGB LED initial state */
    gpio_bit_reset(LEDR_GPIO_PORT, LEDR_PIN);
    gpio_bit_reset(LEDG_GPIO_PORT, LEDG_PIN);
    gpio_bit_reset(LEDB_GPIO_PORT, LEDB_PIN);
    
    while(1)
    {
        /* R = 1, G = 1, B = 1 */
        gpio_bit_set  (LEDR_GPIO_PORT, LEDR_PIN);
        gpio_bit_set  (LEDG_GPIO_PORT, LEDG_PIN);
        gpio_bit_set  (LEDB_GPIO_PORT, LEDB_PIN);
        delay_1ms(DELAY);
        
        /* R = 1, G = 1, B = 0 */
        gpio_bit_set  (LEDR_GPIO_PORT, LEDR_PIN);
        gpio_bit_set  (LEDG_GPIO_PORT, LEDG_PIN);
        gpio_bit_reset(LEDB_GPIO_PORT, LEDB_PIN);
        delay_1ms(DELAY);
        
        /* R = 1, G = 0, B = 1 */
        gpio_bit_set  (LEDR_GPIO_PORT, LEDR_PIN);
        gpio_bit_reset(LEDG_GPIO_PORT, LEDG_PIN);
        gpio_bit_set  (LEDB_GPIO_PORT, LEDB_PIN);
        delay_1ms(DELAY);
        
        /* R = 1, G = 0, B = 0 */
        gpio_bit_set  (LEDR_GPIO_PORT, LEDR_PIN);
        gpio_bit_reset(LEDG_GPIO_PORT, LEDG_PIN);
        gpio_bit_reset(LEDB_GPIO_PORT, LEDB_PIN);
        delay_1ms(DELAY);
        
        /* R = 0, G = 1, B = 1 */
        gpio_bit_reset(LEDR_GPIO_PORT, LEDR_PIN);
        gpio_bit_set  (LEDG_GPIO_PORT, LEDG_PIN);
        gpio_bit_set  (LEDB_GPIO_PORT, LEDB_PIN);
        delay_1ms(DELAY);
        
        /* R = 0, G = 1, B = 0 */
        gpio_bit_reset(LEDR_GPIO_PORT, LEDR_PIN);
        gpio_bit_set  (LEDG_GPIO_PORT, LEDG_PIN);
        gpio_bit_reset(LEDB_GPIO_PORT, LEDB_PIN);
        delay_1ms(DELAY);
        
        /* R = 0, G = 0, B = 1 */
        gpio_bit_reset(LEDR_GPIO_PORT, LEDR_PIN);
        gpio_bit_reset(LEDG_GPIO_PORT, LEDG_PIN);
        gpio_bit_set  (LEDB_GPIO_PORT, LEDB_PIN);
        delay_1ms(DELAY);
        
        /* R = 0, G = 0, B = 0 */
        gpio_bit_reset(LEDR_GPIO_PORT, LEDR_PIN);
        gpio_bit_reset(LEDG_GPIO_PORT, LEDG_PIN);
        gpio_bit_reset(LEDB_GPIO_PORT, LEDB_PIN);
        delay_1ms(DELAY);
    }
}