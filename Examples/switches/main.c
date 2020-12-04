/*!
    \file  main.c
    \brief Switches toggle the board LEDs

    \version 20200806
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

#define DEBOUNCE_DELAY    10  // ms

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
    /* initialize the system  */
    SystemInit();
    
    /* GPIO config */
    gpio_config();
    /* switches config */
    switches_config();
    
    while (1) 
    {
        sw_processing();
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
        gd_eval_sw_init(s, SW_MODE_GPIO);
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
    static sw_status_t Sx_current[SW_AMT];
    static sw_status_t Sx_previous[SW_AMT];
    
    /* performs processing for S1, S2 and S3 */
    for (sw_t s = S1; s <= S3; s++)
    {
        Sx_previous[s] = Sx_current[s];
        Sx_current[s] = gd_eval_sw_state_get(s);
    
        if (SW_PRESSED == Sx_current[s])
        {
            if (Sx_current[s] == Sx_previous[s])
            {
                /* debouncing */
                delay_1ms(DEBOUNCE_DELAY);
                break;
            }
            else 
            {
                gd_eval_led_toggle((led_t)s);
            }
        }
    }
}