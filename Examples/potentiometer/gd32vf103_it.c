/*!
    \file  gd32vf103_it.c
    \brief Interrupt service routines

    \version 20201111
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "gd32vf103_it.h"

extern uint16_t adcResult;

/*!
    \brief      ISR for the ADC0_1 peripheral 
    \param[in]  none
    \param[out] none
    \retval     none
*/
void ADC0_1_IRQHandler(void)
{ 
    /* read the potentiometer value */
    adcResult = adc_regular_data_read(ADC1);

    /* clear the ADC interrupt flag */
    adc_flag_clear(ADC1, ADC_FLAG_EOC);
}
