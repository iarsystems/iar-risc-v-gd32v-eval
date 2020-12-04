/*!
    \file  main.c
    \brief Read the potentiometer value
    
    \version 20201111
*/

/*
Copyright (c) 2020, IAR Systems AB.

See LICENSE.md for detailed license information.
*/

#include <stdio.h> 

#include "iar-risc-v-gd32v-eval.h"
#include "systick.h"

/* global variables */
uint16_t adcResult;

/* function prototypes */
void gd_eval_adc_init(void);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void main(void)
{
    /* initialize the system  */
    SystemInit();
    
    /* configure the ADC for the board Potentiometer */
    gd_eval_adc_init();

    /* print a welcome message in the Terminal I/O */
    printf("---\n\rPotentiometer example\n\r");
    
    while(1)
    {
        /* perform ADC software-triggered conversion */
        adc_software_trigger_enable(ADC1, ADC_REGULAR_CHANNEL);
        
        /* wait for previous ADC conversion to end */
        while( SET == adc_flag_get(ADC1, ADC_INT_EOC) );
        
        /* print the ADC conversion result */
        printf("\n\rValue: %4u", adcResult);
        
        /* delay a sec */
        delay_1ms(1000);
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
    /* interrupt configuration */
    eclic_global_interrupt_enable();
    eclic_priority_group_set(ECLIC_PRIGROUP_LEVEL3_PRIO1);
    eclic_irq_enable(ADC0_1_IRQn, 1, 0); 
    
    /* configure the ADC GPIO port */
    gpio_init(GPIOA, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1);
    gpio_init(GPIOB, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    gpio_init(GPIOC, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
    
    /* set ADC clock prescaler */
    rcu_adc_clock_config(RCU_CKADC_CKAPB2_DIV8);
    
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
    
    /* ADC channel configuration */
    adc_regular_channel_config(ADC1, 0, ADC_CHANNEL_1, ADC_SAMPLETIME_55POINT5);

    /* enable ADC end-of-group-conversion interrupt */
    adc_interrupt_enable(ADC1, ADC_INT_EOC); 
    
    /* dummy software-triggered ADC conversion */
    adc_software_trigger_enable(ADC1, ADC_REGULAR_CHANNEL);
}

