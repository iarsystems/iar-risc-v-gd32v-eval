/*!
    \file    i2c.c
    \brief   BSP I2C header

    \version 20200810
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/
#ifndef BSP_I2C_H
#define BSP_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gd32vf103.h"

typedef enum
{
    BSP_I2C_OK,
    BSP_I2C_FAIL
} i2c_state_t;

i2c_state_t bsp_i2c0_write(uint8_t addr, uint8_t * data, uint8_t count);
i2c_state_t bsp_i2c0_reg8_write(uint8_t i2c_dev_addr, uint8_t reg, uint8_t value);

i2c_state_t bsp_i2c0_read(uint8_t addr, uint8_t * data, uint8_t count);
i2c_state_t bsp_i2c0_reg8_read(uint8_t i2c_dev_addr, uint8_t reg, uint8_t *value);

#ifdef __cplusplus
}
#endif

#endif /* BSP_I2C_H */