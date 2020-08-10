/*!
    \file  systick.h
    \brief Systick configuration header

    \version 20200625
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/


#ifndef SYSTICK_H
#define SYSTICK_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

#include "gd32vf103.h"

/* delay in milliseconds */
void delay_1ms(uint32_t ms);
/* delay in microseconds */
void delay_1us(uint32_t us);

#ifdef __cplusplus
 }
#endif

#endif /* SYSTICK_H */
