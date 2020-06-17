/*!
    \file  main.c
    \brief 
    
    \version 2020-05-21, V1.0.0, GD32VF103 firmware for IAR
*/

/*
    Copyright (c) 2020, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#include "gd32vf103.h"
#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
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