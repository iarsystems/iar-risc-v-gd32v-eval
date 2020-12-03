/*!
    \file  main.c
    \brief Flashes the EVAL board LEDs
    
    \version 20200710
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

#define LONG_DELAY     (175)            // ms
#define EXTRA_DELAY    (3 * LONG_DELAY) // ms
#define SHORT_DELAY    (LONG_DELAY/2)   // ms
#define SHORTER_DELAY  (LONG_DELAY/4)   // ms

typedef enum {
    RIGHT = 1,
    LEFT = -1,
} direction_t;

/* function prototypes */
void perform_kitt_sequence(void);

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
    
    /* initialize the LEDs */
    for (led_t i = LED1; i <= LED5; i++)
    {
        gd_eval_led_init(i);
    }
    
    while(1)
    {
        perform_kitt_sequence();
       
    }
}

/*!
    \brief      performs the K.I.T.T. LED sequence
    \param[in]  none
    \param[out] none
    \retval     none
*/
void perform_kitt_sequence(void)
{
    /* physical LED sequence on the board: 3-2-1-4-5 */
    uint8_t seq[5];
    /* previous LED */
    int8_t prev;
    /* direction is kept between function calls */
    static direction_t dir = RIGHT;
    
    /* invert the LED sequence whenever necessary */
    if (dir == RIGHT)
    {
        seq[0] = LED3;
        seq[1] = LED2;
        seq[2] = LED1;
        seq[3] = LED4;
        seq[4] = LED5;
    }
    else 
    {
        seq[0] = LED5;
        seq[1] = LED4;
        seq[2] = LED1;
        seq[3] = LED2;
        seq[4] = LED3;       
    }  
    /* first LED in the current sequence */
    gd_eval_led_on((led_t)seq[0]);
    delay_1ms(EXTRA_DELAY + (2 * dir * LONG_DELAY));
    gd_eval_led_off((led_t)seq[0]);
    
    for (uint8_t i = 1; i <= 3; i++)
    {
        prev = (RIGHT == dir) ? i - dir : i + dir;
        gd_eval_led_on((led_t)seq[i]);       
        gd_eval_led_on((led_t)seq[prev]);
        delay_1ms(SHORTER_DELAY);
        gd_eval_led_off((led_t)seq[prev]);
        delay_1ms(SHORT_DELAY);
        gd_eval_led_off((led_t)seq[i]);
    }   
    /* last LED in the current sequence */
    gd_eval_led_on((led_t)seq[4]);
    delay_1ms(EXTRA_DELAY - (2 * dir * LONG_DELAY));
    gd_eval_led_off((led_t)seq[4]);
    
    /* flip the direction */
    dir = -dir;
}