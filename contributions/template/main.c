/*!
    \file  main.c
    \brief Template for starting new projects

    \version 20200818
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "iar-risc-v-gd32v-eval.h"
#include "i2c.h"
#include "mma8652.h"
#include "sht3x.h"
#include "systick.h"


/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void main(void)
{
    SystemInit();

    while(1)
    {
        delay_1ms(1000);
    }
}
