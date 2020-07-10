/*!
    \file  gd32vf103_it.c
    \brief Interrupt service routines

    \version 20200710
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
    if(RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_RBNE)){
        /* read one byte from the receive data register */
        rxbuffer[rx_counter++] = (uint8_t)usart_data_receive(USART1);
        
        /* echo a dot */
        snprintf((char *)txbuffer, 2, "..");
        tx_counter = 0;
        nbr_data_to_send = 2;
        usart_interrupt_enable(USART1, USART_INT_TBE);

        if(rx_counter >= nbr_data_to_read)
        {
            /* disable the USART1 receive interrupt */
            usart_interrupt_disable(USART1, USART_INT_RBNE);
        }
    }
       
    if(RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_TBE)){
        /* write one byte to the transmit data register */
        usart_data_transmit(USART1, txbuffer[tx_counter]);
        tx_counter++;

        if(tx_counter >= nbr_data_to_send)
        {
            /* disable the USART1 transmit interrupt */
            usart_interrupt_disable(USART1, USART_INT_TBE);
        }
    }
}



