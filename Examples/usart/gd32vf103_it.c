/*!
    \file  gd32vf103_it.c
    \brief Interrupt service routines

    \version 20201013
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "gd32vf103_it.h"
#include <stdio.h>

extern uint8_t txbuffer[];
extern uint8_t rxbuffer[];
extern size_t nbr_data_to_read, nbr_data_to_send;
extern uint16_t tx_counter, rx_counter;

/*!
    \brief      ISR for the USART1 peripheral with TX/RX handling
    \param[in]  none
    \param[out] none
    \retval     none
*/
void USART1_IRQHandler(void)
{
    if (RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_RBNE))
    {
        /* read 1 byte from the receive data register */
        rxbuffer[rx_counter++] = (uint8_t)usart_data_receive(USART1);

        /* when 1 byte is received, set "dot" to be transmitted as visual feedback */
        USART_DATA(USART1) = USART_DATA_DATA & '.';

        if (rx_counter < nbr_data_to_read)
        {
            /* echo a "dot" for visual feedback */
            usart_interrupt_enable(USART1, USART_INT_TBE);
        }
        else
        {
            /* disable the USART1 receive interrupt */
            usart_interrupt_disable(USART1, USART_INT_RBNE);
        }
    }

    if (RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_TBE))
    {
        if (tx_counter < nbr_data_to_send)
        {
            /* write 1 byte to the transmit data register */
            USART_DATA(USART1) = USART_DATA_DATA & txbuffer[tx_counter];
            tx_counter++;
        }
        else
        {
            /* disable the USART1 transmit interrupt */
            usart_interrupt_disable(USART1, USART_INT_TBE);
        }
    }
}



