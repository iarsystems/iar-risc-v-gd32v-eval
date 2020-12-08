/*!
    \file    main.c
    \brief   SPI flash example
    
    \version 20201208
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include <stdio.h>
#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"
#include "LE25Uxx.h"

typedef ErrStatus status_t;

#define BUFFER_SIZE                           (0x100)
#define TX_BUFFER_SIZE                        BUFFER_SIZE
#define RX_BUFFER_SIZE                        BUFFER_SIZE
#define LINEFEED16(x)                         ({ if (15 == (x % 16)) printf("\r\n"); })

/* global variables */
uint32_t flash_id = 0;
uint16_t i = 0;
uint8_t  count;
uint8_t  txbuffer[TX_BUFFER_SIZE] = "\n\n\r---\n\rSPI Flash example\n\r";;
uint8_t  rxbuffer[RX_BUFFER_SIZE];
uint8_t  read_is_successful = ERROR;

/* function prototypes */
status_t mem_compare(uint8_t *, uint8_t *, size_t);
void fill_buffer(uint8_t *, size_t);
void display_buffer(uint8_t *, size_t);


/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none    
*/
int main(void)
{
    /* initialize the system */
    SystemInit();
    
    /* USART interrupt configuration */
    eclic_global_interrupt_enable();
    eclic_priority_group_set(ECLIC_PRIGROUP_LEVEL3_PRIO1);
    eclic_irq_enable(USART1_IRQn, 2, 0);
    
    /* initialize SPI Flash */
    spi_flash_init();
    
    /* initialize COM1 */
    gd_eval_com_init(EVAL_COM1);
    
    /* transmit the welcome message */  
    printf("%s", txbuffer);
    
    /* get SPI flash ID */
    flash_id = spi_flash_read_id();
    printf("\n\rSPI Flash ID: 0x%X\n\r",flash_id);
    
    /* SPI flash ID is correct */
    if (SFLASH_ID == flash_id)
    {
        printf("SPI Flash ID matches LE25U20AMB-AH.\n\r\n\r");
        
        fill_buffer(txbuffer, TX_BUFFER_SIZE);
        
        /* erases the specified SPI flash sector */
        spi_flash_sector_erase(FLASH_WRITE_ADDRESS);
        /* write txbuffer data to the SPI flash */ 
        spi_flash_buffer_write(txbuffer, FLASH_WRITE_ADDRESS, TX_BUFFER_SIZE);
        
        delay_1ms(10);
        
        printf("\n\r\n\rRead from rxbuffer:\n\r");
        
        /* read a block of data from the SPI flash to rxbuffer */
        spi_flash_buffer_read(rxbuffer, FLASH_READ_ADDRESS, RX_BUFFER_SIZE);
        /* display the receive buffer via printf() */
        display_buffer(rxbuffer, RX_BUFFER_SIZE);
        
        read_is_successful = mem_compare(txbuffer, rxbuffer, BUFFER_SIZE);
        if (ERROR == read_is_successful)
        {
            printf("Error: reading back data does not match.\n\r");
        }
        else 
        {
            printf("\n\rSPI Flash: LE25U20 test passed!\n\r");
        }
    }
    else
    {
        /* SPI flash read id fail */
        printf("\n\rSPI Flash LE25U20: reading ID failed!\n\r");
    }
    
    while (1)
    {
        /* infinite loop */
    }
}

/*!
    \brief      fill a buffer with a counter based on length
    \param[in]  buffer: pointer to the buffer
    \param[in]  length: size of the buffer
    \param[out] none
    \retval     ch
*/
void fill_buffer(uint8_t *buffer, size_t length)
{
    size_t i = 0;
    
    while (length--)
    {
        *buffer = i;
        printf("0x%02X ", *buffer);
        LINEFEED16(i);
        i++;
        buffer++;
    }
}

/*!
    \brief      display a buffer via printf()
    \param[in]  buffer: pointer to the buffer
    \param[in]  length: size of the buffer
    \param[out] none
    \retval     none
*/
void display_buffer(uint8_t *buffer, size_t length)
{
    size_t i = 0;
    
    while (length--)
    {
        printf("0x%02X ", (uint8_t*)(*(buffer++)));
        LINEFEED16(i);
        i++;
    }
}

/*!
    \brief      compares 2 memory segments of equal size 
    \param[in]  seg1: source data pointer
    \param[in]  seg2: destination data pointer
    \param[in]  length: the data length to compare
    \param[out] none
    \retval     status_t: ERROR || SUCCESS
*/
status_t mem_compare(uint8_t* seg1, uint8_t* seg2, size_t length) 
{
    while(length--)
    {
        if(*seg1++ != *seg2++)
        {
            return ERROR;
        }
    }
    return SUCCESS;
}

/*!
    \brief      retarget the C library printf() function to the EVAL_COM1 
    \param[in]  ch: character
    \param[out] none
    \retval     ch
*/
int _put_char(int ch)
{
    usart_data_transmit(EVAL_COM1, (uint8_t)ch);
    while (usart_flag_get(EVAL_COM1, USART_FLAG_TBE) == RESET)
        ;    
    return ch;
}

size_t __write(int handle, const unsigned char *buf, size_t bufSize)
{
    size_t nChars = 0;
    
    if (handle == -1) return 0;
    
    for (; bufSize > 0; --bufSize)
    {
        _put_char((uint8_t) *buf);
        ++buf;
        ++nChars;
    }
    
    return nChars;
}