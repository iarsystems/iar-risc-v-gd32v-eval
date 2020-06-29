/*!
\file  main.c
\brief Exercise the ADC using the potentiometer

\version 20200625
*/

/*
Copyright (c) 2020, IAR Systems AB.

See LICENSE.md for detailed license information.
*/

#include <stdio.h> 

#include "iar-risc-v-gd32v-eval.h"
#include "gd32vf103_libopt.h"
#include "systick.h"

#define ARRAYNUM(arr_name)      (uint32_t)(sizeof(arr_name) / sizeof(*(arr_name)))
#define TRANSMIT_SIZE           (ARRAYNUM(txbuffer) - 1)

/* Global variables */
/*! USART1 */
uint8_t txbuffer[] = "ADC Example for the IAR RISC-V GD32V Eval board\n\r";
uint8_t tx_size = TRANSMIT_SIZE;
__IO uint8_t txcount = 0; 
/*! ADC */
uint16_t adcResult;

/* Function prototypes */
void gd_eval_adc_init(void);
void gd_eval_usart_data_transmit(uint32_t usart_periph, uint8_t *data);

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
    eclic_irq_enable(USART1_IRQn, 2, 0);
    eclic_irq_enable(ADC0_1_IRQn, 1, 0);
    
    /* configure IAR RISC-V GD32V EVAL COM1 UART */
    gd_eval_com_init(EVAL_COM1);        
    
    /* configure the ADC GPIO port */
    gpio_init(GPIOA, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_0|GPIO_PIN_1);
    gpio_init(GPIOB, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    gpio_init(GPIOC, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
    
    /* configure the ADC for the board Potentiometer */
    gd_eval_adc_init();
    adc_regular_channel_config(ADC1, 0, ADC_CHANNEL_1, ADC_SAMPLETIME_55POINT5);
    adc_software_trigger_enable(ADC1, ADC_REGULAR_CHANNEL);
    adc_interrupt_enable(ADC1, ADC_INT_EOC); 
    adc_software_trigger_enable(ADC1, ADC_REGULAR_CHANNEL);
    
    /* Transmit Example's welcome message */  
    gd_eval_usart_data_transmit(EVAL_COM1, txbuffer);
    
    while(1)
    {
        /* Read the Potentiometer value */
        adcResult = adc_regular_data_read(ADC1);
        
        /* Format the string to be sent to USART */
        sprintf((char*)txbuffer, "\n\rPot. value: %u", adcResult);
        
        /* Transmit Potentiometer value */
        gd_eval_usart_data_transmit(EVAL_COM1, txbuffer);
        
        delay_1ms(2000);
    }
}

/*!
    \brief      Configure the ADC for the Eval board
    \param[in]  none
    \param[in]  none
    \param[out] none
    \retval     none
*/
void gd_eval_adc_init(void)
{
    /* enable ADC1 clock */
    rcu_periph_clock_enable(RCU_ADC1);  
    
    /* reset ADC */
    adc_deinit(ADC0);
    adc_deinit(ADC1);
    
    /* ADC mode config */
    adc_mode_config(ADC_DAUL_REGULAL_PARALLEL); 
    
    /* ADC data alignment config */
    adc_data_alignment_config(ADC1, ADC_DATAALIGN_RIGHT);  
    
    /* ADC channel length config */
    adc_channel_length_config(ADC1, ADC_REGULAR_CHANNEL, 1);
    
    /* ADC trigger config */
    adc_external_trigger_source_config(ADC1, ADC_REGULAR_CHANNEL, ADC0_1_EXTTRIG_REGULAR_NONE);
    
    /* ADC external trigger enable */
    adc_external_trigger_config(ADC1, ADC_REGULAR_CHANNEL, ENABLE);    
    
    /* enable ADC interface */
    adc_enable(ADC1);
    
    /* ADC calibration and reset calibration */    
    adc_calibration_enable(ADC1);    
}

/*!
    \brief      USART transmit data function
    \param[in]  usart_periph: USARTx(x=0,1,2)/UARTx(x=3,4)
    \param[in]  data: pointer to the data to transmit
    \param[out] none
    \retval     none
*/
void gd_eval_usart_data_transmit(uint32_t usart_periph, uint8_t *data)
{
    usart_interrupt_enable(usart_periph, USART_INT_TBE);
    usart_data_transmit(usart_periph, data[0]);
    while (RESET == usart_flag_get(usart_periph, USART_FLAG_TC));
}