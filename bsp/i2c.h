/*!
    \file    i2c.c
    \brief   BSP I2C header

    \version 20200707
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/
#ifndef I2C_H
#define I2C_H

#include "gd32vf103.h"

uint8_t i2c0_write(uint8_t addr, uint8_t * data, uint8_t count);
uint8_t i2c_reg8_write(uint8_t i2c_dev_addr, uint8_t reg, uint8_t value);

uint8_t i2c0_read(uint8_t addr, uint8_t * data, uint8_t count);
uint8_t i2c_reg8_read(uint8_t i2c_dev_addr, uint8_t reg, uint8_t *value);

#endif /* I2C_H */