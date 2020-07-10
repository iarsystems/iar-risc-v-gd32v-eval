/*!
    \file  main.c
    \brief USART transmit and receive interrupt

    \version 20200710
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "iar-risc-v-gd32v-eval.h"

#define BUFFER_SIZE (48)

typedef enum 
{
    CORRECT  = 0,
    MISTYPED = 1,
    CAPS_ON  = 2,
    
} verify_err_t;

/* global variables */
uint8_t* dictionary[] =                      {"banana",
                                              "orange",
                                              "apple",
                                              "lime",
                                              "watermelon",
                                              "blueberry",
                                              "grapefruit",
                                              "peach",
                                              "pineapple",
                                              "strawberry",
                                              "coconut",
                                              "bacon",
                                              "pear",
                                              "apricot",
                                              "avocado",
                                              "blackberry",
                                              "mango",
                                              "kiwi",
                                              "beef",
                                              "plum",
                                              "pomegranate",
                                              "papaya",
                                              "fig",
                                              "tangerine",
                                              "passion fruit",
};
uint8_t *message[5] =                        {"\n\rWell done!\n\r",
                                              "\n\rTry again!\n\r",
                                              "\n\rTurn off Caps Lock!!\n\r",
                                              "\n\n\r---\n\rUSART example\n\r",
                                              "\r\nType: ",
};
uint8_t txbuffer[BUFFER_SIZE];
uint8_t rxbuffer[BUFFER_SIZE];
__IO uint16_t tx_counter = 0, rx_counter = 0;
size_t nbr_data_to_read, nbr_data_to_send;
verify_err_t typed = MISTYPED; 

/* function prototypes */
verify_err_t verify_word(uint8_t* src, uint8_t* dst, uint16_t length);
void gd_eval_usart_int_transmit(com_t, uint8_t const *, size_t);
void gd_eval_usart_int_receive(com_t, uint8_t *, size_t);
void init_com(void);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    SystemInit();
    
    /* initialize COM port */
    init_com();
    
    /* initiate the PRNG */
    srand(time(NULL)); 
    
    /* transmit welcome message */  
    gd_eval_usart_int_transmit(EVAL_COM1, message[3], BUFFER_SIZE);
    
    while(1)
    {
        typed = MISTYPED;
        
        /* select a new word from the dictionary */
        uint8_t *selected_word = dictionary[rand()%25];
        
        /* transmit the selected word to be typed */
        uint8_t new_word[BUFFER_SIZE];
        snprintf((char *)new_word, BUFFER_SIZE, "%s%s\n\r", message[4], selected_word);
        gd_eval_usart_int_transmit(EVAL_COM1, new_word, strlen((char const *)new_word));
        
        while(CORRECT != typed) 
        {
            /* receive the typed word */  
            gd_eval_usart_int_receive(EVAL_COM1, rxbuffer, strlen((char const *)selected_word));
            /* verify the typed word */  
            typed = verify_word(selected_word, rxbuffer, strlen((char const *)selected_word));
            
            /* transmit the result */
            gd_eval_usart_int_transmit(EVAL_COM1, message[typed], strlen((char const *)message[typed]));
        }
    }
}

/*!
    \brief      checks if the word has been typed correctly
    \param[in]  src: selected word
    \param[in]  dst: typed word
    \param[in]  length: the compare data length
    \param[out] none
    \retval     verify_err_t 
*/
verify_err_t verify_word(uint8_t* src, uint8_t* dst, uint16_t length) 
{
    while(length--)
    {
        if (*dst >= 'A' && *dst <= 'Z') return CAPS_ON;
            
        if (*src++ != *dst++)
        {
            return MISTYPED;
        }
    }
    return CORRECT;
}

/*!
    \brief      USART interrupt-driven transmit data function
    \param[in]  com: communication port
      \arg        EVAL_COMx: EVAL_COM0..EVAL_COM1 port
    \param[in]  data: pointer to the data to transmit
    \param[out] none
    \retval     none
*/
void gd_eval_usart_int_transmit(com_t com, uint8_t const *data, size_t buffer_sz)
{
    memset(&txbuffer,'\0',sizeof(txbuffer));
    snprintf((char *)txbuffer, sizeof(txbuffer), (char const*)data);
    tx_counter = 0;
    nbr_data_to_send = buffer_sz;
    /* enable COM transmit interrupt */
    usart_interrupt_enable(com, USART_INT_TBE);
    while(tx_counter < buffer_sz);
}

/*!
    \brief      USART interrupt-driven receive data function
    \param[in]  com: communication port
      \arg        EVAL_COMx: EVAL_COM0..EVAL_COM1 port
    \param[in]  data: pointer to the variable which will hold the data
    \param[out] none
    \retval     none
*/
void gd_eval_usart_int_receive(com_t com, uint8_t *data, size_t buffer_sz)
{
    memset(&rxbuffer,0x00,sizeof(rxbuffer));
    rx_counter = 0;
    nbr_data_to_read = buffer_sz;
    /* enable COM receive interrupt */
    usart_interrupt_enable(com, USART_INT_RBNE);
    while(rx_counter < buffer_sz);
}

/*!
    \brief      initialize communication port
    \param[in]  none
    \param[out] none
    \retval     none
*/
void init_com(void)
{
    /* enable the global interrupt */
    eclic_global_interrupt_enable();
    eclic_priority_group_set(ECLIC_PRIGROUP_LEVEL3_PRIO1);
    eclic_irq_enable(USART1_IRQn, 1, 0);
    
    /* configure EVAL_COM1 */
    gd_eval_com_init(EVAL_COM1);
}