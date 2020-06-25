/*!
    \file  systick.c
    \brief Systick configuration module 

    \version 20200625 
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "systick.h"

/*!
    \brief      delay in milliseconds
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void delay_1ms(uint32_t count)
{
    uint64_t start_mtime, delta_mtime;
    uint64_t tmp = get_timer_value(); // don't start measuruing until we see an mtime tick
    
    do
    {
        start_mtime = get_timer_value();
    }
    while (start_mtime == tmp);

    do
    {
        delta_mtime = get_timer_value() - start_mtime;
    } while (delta_mtime < (SystemCoreClock/4000.0 * count));
}
