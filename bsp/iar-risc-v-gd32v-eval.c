/*!
    \file    iar-risc-v-gd32v-eval.c
    \brief   definitions for IAR RISC-V GD32V Eval board hardware resources

    \version 20200709
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"

/* private variables */
static uint32_t GPIO_PORT[LEDn] =            {LED1_GPIO_PORT,
                                              LED2_GPIO_PORT,
                                              LED3_GPIO_PORT,
                                              LED4_GPIO_PORT,
                                              LED5_GPIO_PORT,
                                              LEDR_GPIO_PORT,
                                              LEDG_GPIO_PORT,
                                              LEDB_GPIO_PORT,
};
static uint32_t GPIO_PIN[LEDn] =             {LED1_PIN,
                                              LED2_PIN,
                                              LED3_PIN,
                                              LED4_PIN,
                                              LED5_PIN,
                                              LEDR_PIN,
                                              LEDG_PIN,
                                              LEDB_PIN,
};
static rcu_periph_enum COM_CLK[COMn] =       {EVAL_COM0_CLK,
                                              EVAL_COM1_CLK,
};
static uint32_t COM_TX_PIN[COMn] =           {EVAL_COM0_TX_PIN,
                                              EVAL_COM1_TX_PIN,
};
static uint32_t COM_RX_PIN[COMn] =           {EVAL_COM0_RX_PIN,
                                              EVAL_COM1_RX_PIN,
};
static uint32_t COM_GPIO_PORT[COMn] =        {EVAL_COM0_GPIO_PORT,
                                              EVAL_COM1_GPIO_PORT,
};
static rcu_periph_enum COM_GPIO_CLK[COMn] =  {EVAL_COM0_GPIO_CLK,
                                              EVAL_COM1_GPIO_CLK,
};
static rcu_periph_enum GPIO_CLK[LEDn] =      {LED1_GPIO_CLK,
                                              LED2_GPIO_CLK,
                                              LED3_GPIO_CLK,
                                              LED4_GPIO_CLK,
                                              LED5_GPIO_CLK,
                                              LEDR_GPIO_CLK,
                                              LEDG_GPIO_CLK,
                                              LEDB_GPIO_CLK,
};
static uint32_t SW_PORT[Sn] =                {S1_GPIO_PORT,
                                              S2_GPIO_PORT,
                                              S3_GPIO_PORT,
                                              S4_GPIO_PORT,
                                              S5_GPIO_PORT,
};
static uint32_t SW_PIN[Sn] =                 {S1_PIN,
                                              S2_PIN,
                                              S3_PIN,
                                              S4_PIN,
                                              S5_PIN,
};
static rcu_periph_enum SW_CLK[Sn] =          {S1_GPIO_CLK,
                                              S2_GPIO_CLK,
                                              S3_GPIO_CLK,
                                              S4_GPIO_CLK,
                                              S5_GPIO_CLK,
};
static exti_line_enum SW_EXTI_LINE[Sn] =     {S1_EXTI_LINE,
                                              S2_EXTI_LINE,
                                              S3_EXTI_LINE,
                                              S4_EXTI_LINE,
                                              S5_EXTI_LINE,
};
static uint8_t SW_PORT_SOURCE[Sn] =          {S1_EXTI_PORT_SOURCE,
                                              S2_EXTI_PORT_SOURCE,
                                              S3_EXTI_PORT_SOURCE,
                                              S4_EXTI_PORT_SOURCE,
                                              S5_EXTI_PORT_SOURCE,
};
static uint8_t SW_PIN_SOURCE[Sn] =           {S1_EXTI_PIN_SOURCE,
                                              S2_EXTI_PIN_SOURCE,
                                              S3_EXTI_PIN_SOURCE,
                                              S4_EXTI_PIN_SOURCE,
                                              S5_EXTI_PIN_SOURCE,
};
static uint8_t SW_IRQn[Sn] =                 {S1_EXTI_IRQn,
                                              S2_EXTI_IRQn,
                                              S3_EXTI_IRQn,
                                              S4_EXTI_IRQn,
                                              S5_EXTI_IRQn,
};

/*!
    \brief      configure LED GPIO
    \param[in]  lednum: specify the LED to be configured
      \arg        LEDx: LED1..LEDB
    \param[out] none
    \retval     none
*/
void gd_eval_led_init(led_t lednum)
{
    /* enable the LED clock */
    rcu_periph_clock_enable(GPIO_CLK[lednum]);
    /* configure LED GPIO port */
    gpio_init(GPIO_PORT[lednum], GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN[lednum]);

    GPIO_BC(GPIO_PORT[lednum]) = GPIO_PIN[lednum];
}
/*!
    \brief      turn on selected LED
    \param[in]  lednum: specify the LED to be turned on
      \arg        LEDx: LED1..LEDB
    \param[out] none
    \retval     none
*/
void gd_eval_led_on(led_t lednum)
{
    GPIO_BOP(GPIO_PORT[lednum]) = GPIO_PIN[lednum];
}

/*!
    \brief      turn off selected the board's LED
    \param[in]  lednum: specify the LED to be turned off
      \arg        LEDx: LED1..LEDB
    \param[out] none
    \retval     none
*/
void gd_eval_led_off(led_t lednum)
{
    GPIO_BC(GPIO_PORT[lednum]) = GPIO_PIN[lednum];
}

/*!
    \brief      toggle selected LED
    \param[in]  lednum: specify the LED to be toggled
      \arg        LEDx: LED1..LEDB
    \param[out] none
    \retval     none
*/
void gd_eval_led_toggle(led_t lednum)
{
    gpio_bit_write(GPIO_PORT[lednum], GPIO_PIN[lednum],
        (bit_status)(1-gpio_input_bit_get(GPIO_PORT[lednum], GPIO_PIN[lednum])));
}

/*!
    \brief      configure the board's switches
    \param[in]  sw_num: specify the switch to be configured
      \arg        Sx: S1..S5 switch
    \param[in]  sw_mode: specify button mode
      \arg        KEY_MODE_GPIO: switch will be used as simple IO
      \arg        KEY_MODE_EXTI: switch will be connected to EXTI line with interrupt
    \param[out] none
    \retval     none
*/
void gd_eval_sw_init(sw_t sw_num, sw_mode_t sw_mode)
{
    /* enable the switch clock */
    rcu_periph_clock_enable(SW_CLK[sw_num]);
    rcu_periph_clock_enable(RCU_AF);

    /* configure button pin as input */
    gpio_init(SW_PORT[sw_num], GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, SW_PIN[sw_num]);

    if (SW_MODE_EXTI == sw_mode)
    {
        /* enable and set switch EXTI interrupt to the lowest priority */
        eclic_global_interrupt_enable();
        eclic_irq_enable(SW_IRQn[sw_num], 1, 1);

        /* connect switch EXTI line to switch GPIO pin */
        gpio_exti_source_select(SW_PORT_SOURCE[sw_num], SW_PIN_SOURCE[sw_num]);

        /* configure switch EXTI line */
        exti_init(SW_EXTI_LINE[sw_num], EXTI_INTERRUPT, EXTI_TRIG_FALLING);
        exti_interrupt_flag_clear(SW_EXTI_LINE[sw_num]);
    }
}

/*!
    \brief      check the selected switch state
    \param[in]  sw_num: specify the switch to be checked
      \arg        Sx: S1..S5 switch
    \param[out] none
    \retval     the switch's pressed/release status
*/
sw_status_t gd_eval_sw_state_get(sw_t sw_num)
{
    return (sw_status_t)gpio_input_bit_get(SW_PORT[sw_num], SW_PIN[sw_num]);
}

/*!
    \brief      configure the board COM port
    \param[in]  com: communication port
      \arg        EVAL_COMx: EVAL_COM0..EVAL_COM1 port
    \param[out] none
    \retval     none
*/
void gd_eval_com_init(com_t com)
{
    uint32_t com_id = (EVAL_COM0 == com) ? 0 : 1;

    /* enable GPIO clock */
    rcu_periph_clock_enable(COM_GPIO_CLK[com_id]);
    /* enable USART clock */
    rcu_periph_clock_enable(COM_CLK[com_id]);
    /* connect port to USARTx_Tx */
    gpio_init(COM_GPIO_PORT[com_id], GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, COM_TX_PIN[com_id]);
    /* connect port to USARTx_Rx */
    gpio_init(COM_GPIO_PORT[com_id], GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, COM_RX_PIN[com_id]);
    /* USART configure */
    usart_deinit(com);
    usart_baudrate_set(com, 115200U);
    usart_word_length_set(com, USART_WL_8BIT);
    usart_stop_bit_set(com, USART_STB_1BIT);
    usart_parity_config(com, USART_PM_NONE);
    usart_hardware_flow_rts_config(com, USART_RTS_DISABLE);
    usart_hardware_flow_cts_config(com, USART_CTS_DISABLE);
    usart_receive_config(com, USART_RECEIVE_ENABLE);
    usart_transmit_config(com, USART_TRANSMIT_ENABLE);
    usart_enable(com);
}

/*!
    \brief      USART transmit data function
    \param[in]  com: communication port
      \arg        EVAL_COMx: EVAL_COM0..EVAL_COM1 port
    \param[in]  data: pointer to the data to transmit
    \param[out] none
    \retval     none
*/
void gd_eval_usart_data_transmit(com_t com, uint8_t *data)
{
    usart_interrupt_enable(com, USART_INT_TBE);
    usart_data_transmit(com, *data);
    while (RESET == usart_flag_get(com, USART_FLAG_TC));
}