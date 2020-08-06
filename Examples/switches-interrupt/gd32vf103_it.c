/*!
\file  gd32vf103_it.c
\brief Interrupt service routines

\version 20200806
*/

/*
Copyright (c) 2020, IAR Systems AB.

See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "gd32vf103_it.h"

extern sw_status_t Sx_pressed[];

/*!
\brief      ISR for the EXTI5_9_IRQ
\param[in]  none
\param[out] none
\retval     none
*/
void EXTI5_9_IRQHandler(void)
{
	if (RESET != exti_interrupt_flag_get(S2_EXTI_LINE))
	{
		exti_interrupt_flag_clear(S2_EXTI_LINE);
        Sx_pressed[S2] = gd_eval_sw_state_get(S2);
    }
    if (RESET != exti_interrupt_flag_get(S3_EXTI_LINE))
	{
		exti_interrupt_flag_clear(S3_EXTI_LINE);
        Sx_pressed[S3] = gd_eval_sw_state_get(S3);
    }
}

/*!
\brief      ISR for the EXTI10_15_IRQ 
\param[in]  none
\param[out] none
\retval     none
*/
void EXTI10_15_IRQHandler(void)
{
    if (RESET != exti_interrupt_flag_get(S1_EXTI_LINE))
	{
        exti_interrupt_flag_clear(S1_EXTI_LINE);
        Sx_pressed[S1] = gd_eval_sw_state_get(S1);
    }
}