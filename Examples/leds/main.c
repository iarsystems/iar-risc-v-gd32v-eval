/*!
    \file  main.c
    \brief Flashes the EVAL board LEDs
    
    \version 20200625
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void main(void)
{
    SystemInit();
    
    /* enable the LED clock */
    rcu_periph_clock_enable(LED1_GPIO_CLK);
    rcu_periph_clock_enable(LED2_GPIO_CLK);
    rcu_periph_clock_enable(LED3_GPIO_CLK);
    rcu_periph_clock_enable(LED4_GPIO_CLK);
    rcu_periph_clock_enable(LED5_GPIO_CLK);
    
    /* configure LED GPIO port */
    gpio_init(LED1_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED1_PIN);
    gpio_init(LED2_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED2_PIN);
    gpio_init(LED3_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED3_PIN);
    gpio_init(LED4_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED4_PIN);
    gpio_init(LED5_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED5_PIN);

    /* set LEDs initial state */
    gpio_bit_reset(LED1_GPIO_PORT, LED1_PIN);
    gpio_bit_reset(LED2_GPIO_PORT, LED2_PIN);
    gpio_bit_reset(LED3_GPIO_PORT, LED3_PIN);
    gpio_bit_reset(LED4_GPIO_PORT, LED4_PIN);
    gpio_bit_reset(LED5_GPIO_PORT, LED5_PIN);
    
    while(1)
    {
        /* turn on LED5, turn off LED3 */
        gpio_bit_set(LED5_GPIO_PORT, LED5_PIN);
        gpio_bit_reset(LED3_GPIO_PORT, LED3_PIN);
        delay_1ms(500);
        
        /* turn on LED4, turn off LED5 */
        gpio_bit_set(LED4_GPIO_PORT, LED4_PIN);
        gpio_bit_reset(LED5_GPIO_PORT, LED5_PIN);
        delay_1ms(500);
        
        /* turn on LED1, turn off LED4 */
        gpio_bit_set(LED1_GPIO_PORT, LED1_PIN);
        gpio_bit_reset(LED4_GPIO_PORT, LED4_PIN);
        delay_1ms(500);

        /* turn on LED2, turn off LED1 */
        gpio_bit_set(LED2_GPIO_PORT, LED2_PIN);
        gpio_bit_reset(LED1_GPIO_PORT, LED1_PIN);
        delay_1ms(500);

        /* turn on LED3, turn off LED2 */
        gpio_bit_set(LED3_GPIO_PORT, LED3_PIN);
        gpio_bit_reset(LED2_GPIO_PORT, LED2_PIN);
        delay_1ms(500);
    }
}