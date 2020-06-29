/*!
    \file  gd32vf103_it.c
    \brief Interrupt service routines

    \version 20200625
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "gd32vf103_it.h"

extern uint8_t txbuffer[];
extern uint8_t tx_size;
extern __IO uint8_t txcount;

/*!
    \brief      ISR for the USART1 peripheral with TX handling
    \param[in]  none
    \param[out] none
    \retval     none
*/
void USART1_IRQHandler(void)
{
    if (RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_TBE))
    {
        /* transmit data */
        usart_data_transmit(USART1, txbuffer[txcount++]);
        
        if ((txcount >= tx_size) || (txbuffer[txcount] == 0))
        {
            usart_interrupt_disable(USART1, USART_INT_TBE);
            txcount = 0;
        }
    }
}

/*!
    \brief      ISR for the ADC0_1 peripheral 
    \param[in]  none
    \param[out] none
    \retval     none
*/
void ADC0_1_IRQHandler(void)
{
    /* clear the ADC interrupt flag */
    adc_flag_clear(ADC1, ADC_FLAG_EOC);

    /* re-enable the ADC software trigger */
    adc_software_trigger_enable(ADC1, ADC_REGULAR_CHANNEL);
}