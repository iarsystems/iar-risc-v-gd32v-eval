/*!
    \file  gd32vf103_it.h
    \brief Header file for the interrupt service routines
    
    \version 20200806
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#ifndef GD32VF103_IT_H
#define GD32VF103_IT_H

#include "gd32vf103.h"

/* function declarations */
/* handlers for external lines 5 to 9 interrupt requests */
void EXTI5_9_IRQHandler(void);
/* handlers for external lines 10 to 15 interrupt requests */
void EXTI10_15_IRQHandler(void);


#endif /* GD32VF103_IT_H */
