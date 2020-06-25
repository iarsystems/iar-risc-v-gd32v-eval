/*!
    \file  main.c
    \brief USART transmit and receive interrupt

    \version 20200625 
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include <stdio.h>

#include "iar-risc-v-gd32v-eval.h"

#define ARRAYNUM(arr_name)      (uint32_t)(sizeof(arr_name) / sizeof(*(arr_name)))
#define TRANSMIT_SIZE           (ARRAYNUM(txbuffer) - 1)

/* Global variables */
uint8_t txbuffer[] = "\n\rUSART interrupt test\n\r";
uint8_t rxbuffer[32];
uint8_t tx_size = TRANSMIT_SIZE;
uint8_t rx_size = 32;
__IO uint8_t txcount = 0; 
__IO uint16_t rxcount = 0; 

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void main(void)
{
    SystemInit();
    
    /* EVAL_COM1 interrupt configuration */
    eclic_global_interrupt_enable();
    eclic_priority_group_set(ECLIC_PRIGROUP_LEVEL3_PRIO1);
    eclic_irq_enable(USART1_IRQn, 1, 0);
    
    /* configure IAR RISC-V GD32V EVAL COM1*/
    gd_eval_com_init(EVAL_COM1);
    
    /* enable EVAL_COM1 TBE interrupt */  
    usart_interrupt_enable(EVAL_COM1, USART_INT_TBE);
    
    /* wait until the transmit buffer is sent to EVAL_COM1 */
    while (txcount < tx_size);
    
    while (RESET == usart_flag_get(EVAL_COM1, USART_FLAG_TC));
    
    usart_interrupt_enable(EVAL_COM1, USART_INT_RBNE);
    
    /* wait until EVAL_COM1 receives the receive buffer */
    while (rxcount < rx_size);
    
    if (rxcount == rx_size)
    {
        /* Prints on the Terminal I/O */
        /* Enable it on View -> Terminal I/O */
        printf("\n\rUSART data received successfully!\n\r");
    }
    
    while(1);
}