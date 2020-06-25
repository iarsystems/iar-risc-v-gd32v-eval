/*!
    \file  main.c
    \brief running led
    
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
    
    /* enable the LED1 clock */  
    rcu_periph_clock_enable(RCU_GPIOA);
    
    /* configure LED1 GPIO port */   
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);
    
    gpio_bit_reset(GPIOA, GPIO_PIN_9);

    while(1)
    {
        /* turn on LED1 */       
        gpio_bit_set(GPIOA, GPIO_PIN_9);
        delay_1ms(500);
        
        /* turn off LED1 */
        gpio_bit_reset(GPIOA, GPIO_PIN_9);
        delay_1ms(500);
    }
}
