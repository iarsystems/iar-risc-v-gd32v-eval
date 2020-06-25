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
extern uint8_t rxbuffer[];
extern uint8_t tx_size;
extern uint8_t rx_size;
extern __IO uint8_t txcount;
extern __IO uint16_t rxcount;

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
        /* receive data */
        rxbuffer[rxcount++] = usart_data_receive(USART1);
        
        if (rxcount == rx_size)
        {
          usart_interrupt_disable(USART1, USART_INT_RBNE);
        }
    }
    
    if (RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_TBE))
    {
        /* transmit data */
        usart_data_transmit(USART1, txbuffer[txcount++]);
        
        if ((txcount == tx_size) || (txbuffer[txcount] == 0))
        {
            usart_interrupt_disable(USART1, USART_INT_TBE);
        }
    }
}



