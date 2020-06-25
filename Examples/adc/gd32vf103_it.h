/*!
    \file  gd32vf103_it.h
    \brief Header file for the interrupt service routines
    
    \version 20200625
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#ifndef GD32VF103_IT_H
#define GD32VF103_IT_H

#include "gd32vf103.h"

/* function declarations */
/* handler for the USART1 interrupt */
void USART1_IRQHandler(void);
/* handler for the ADC interrupt */
void ADC0_1_IRQHandler(void);


#endif /* GD32VF103_IT_H */
