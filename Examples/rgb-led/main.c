/*!
    \file  main.c
    \brief Toggles the RGB LED
    
    \version 2020-06-17 
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

#define DELAY 250 // ms

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
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