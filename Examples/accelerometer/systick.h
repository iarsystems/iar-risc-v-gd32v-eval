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

#include <stdint.h>

#include "gd32vf103.h"

/* delay a time in milliseconds */
void delay_1ms(uint32_t count);

#endif /* SYSTICK_H */
