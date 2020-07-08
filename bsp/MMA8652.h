/*!
    \file    MMA8652.h
    \brief   MMA8652 3-axis accelerometer header

    \version 20200708
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#ifndef _MMA8652_H
#define _MMA8652_H

#include <stdint.h>

#define MMA8652_I2C_ADDR               (0x1D)

#define MMA8652_STATUS                  0x00
#define MMA8652_OUT_X_MSB               0x01
#define MMA8652_WHO_AM_I                0x0D
#define MMA8652_XYZ_DATA_CFG            0x0E
#define MMA8652_CTRL_REG1               0x2A
#define MMA8652_CTRL_REG2               0x2B
#define MMA8652_WHO_AM_I_VALUE          0x4A
#define MMA8652_OFF_X_REG               0x2F    	
#define MMA8652_OFF_Y_REG               0x30
#define MMA8652_OFF_Z_REG               0x31


/* MMA8652FC sensitivity */
#define MMA8652_SENSITIVITY_2G		    1024
#define MMA8652_SENSITIVITY_4G		    512
#define MMA8652_SENSITIVITY_8G		    256
#define MMA8652_SENSITIVITY             MMA8652_SENSITIVITY_2G

/* function prototypes */
void mma8652_init(void);
void mma8652_getxyz(float *x, float *y, float *z);

#endif