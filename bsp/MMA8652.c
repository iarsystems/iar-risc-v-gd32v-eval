/*!
\file    MMA8652.c
\brief   MMA8652 3-axis accelerometer basic functions 

\version 20200707
*/

/*
Copyright (c) 2020, IAR Systems AB.

See LICENSE.md for detailed license information.
*/

#include "MMA8652.h"
#include "i2c.h"

static void mma8652_calibration(void)
{
    int16_t  x_out,    y_out,    z_out;
    int8_t   x_offset, y_offset, z_offset;
    uint8_t  mma8652_rxbuffer[7];
    
    // 0x00 to MMA8652_CTRL_REG1 to place MMA8652 into standby.
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_CTRL_REG1, 0x00);
    
    i2c0_read((uint8_t)MMA8652_I2C_ADDR, (uint8_t *) mma8652_rxbuffer, sizeof(mma8652_rxbuffer));
    
    x_out = ((int16_t)(mma8652_rxbuffer[1] << 8 | mma8652_rxbuffer[2])) >> 4; // 12-bit X-axis acceleration output value
    y_out = ((int16_t)(mma8652_rxbuffer[3] << 8 | mma8652_rxbuffer[4])) >> 4; // 12-bit Y-axis acceleration output value
    z_out = ((int16_t)(mma8652_rxbuffer[5] << 8 | mma8652_rxbuffer[6])) >> 4; // 12-bit Z-axis acceleration output value
    
    /* compute the offset corrections */
  	x_offset = x_out / 2 * (-1);		
  	y_offset = y_out / 2 * (-1);		
  	z_offset = (z_out - MMA8652_SENSITIVITY_2G) / 2 * (-1);		
    
    /* apply the offset corrections */
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_OFF_X_REG, x_offset);
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_OFF_Y_REG, y_offset);
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_OFF_Z_REG, z_offset);
    
    /* 0x11 to MMA8652_CTRL_REG1 activate */
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_CTRL_REG1, 0x39);
}

void mma8652_init(void)
{
    /* 0x00 to MMA8652_CTRL_REG1 to place MMA8652 into standby */
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_CTRL_REG1, 0x00);
    
    /* high-resolution mode */
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_CTRL_REG2, 0x02);
    
    /*
    * Write 0000 0001 = 0x01 to XYZ_DATA_CFG register to set g range
    * [7-5]: reserved=000
    * [4]: HPF_OUT=0
    * [3-2]: reserved=00
    * [1-0]: FS=01 for +/-4g: 512 counts / g = 8192 counts / g after 4 bit left shift
    */
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_XYZ_DATA_CFG, 0x01);
    
    /*
    * write 0000 0010 = 0x02 to MMA8652_CTRL_REG2 to set MODS bits
    * [7]: ST=0: self test disabled
    * [6]: RST=0: reset disabled
    * [5]: unused
    * [4-3]: SMODS=00
    * [2]: SLPE=0: auto sleep disabled
    * [1-0]: mods=10 for high resolution (maximum over sampling)
    */
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_CTRL_REG2, 0x02);
    
    /*
    * write 0001 0001 = 0x11 to MMA8652_CTRL_REG1
    * [7-6]: aslp_rate=00
    * [5-3]: dr=010 for 200Hz data rate
    * [2]: unused=0
    * [1]: f_read=0 for normal 16 bit reads
    * [0]: active=1 to take the part out of standby and enable sampling
    */
    i2c_reg8_write(MMA8652_I2C_ADDR, MMA8652_CTRL_REG1, 0x39);
    
    /* performs the MMA8652 calibration */
    mma8652_calibration();
}

void mma8652_getxyz(float *x, float *y, float *z)
{
    uint8_t mma8652_rxbuffer[7];
    int16_t x_out, y_out, z_out;
    
    i2c0_read((uint8_t)MMA8652_I2C_ADDR, (uint8_t *) mma8652_rxbuffer, sizeof(mma8652_rxbuffer));
    
    x_out = ((int16_t)(mma8652_rxbuffer[1] << 8 | mma8652_rxbuffer[2])) >> 4; // 12-bit X-axis acceleration output value
    y_out = ((int16_t)(mma8652_rxbuffer[3] << 8 | mma8652_rxbuffer[4])) >> 4; // 12-bit Y-axis acceleration output value
    z_out = ((int16_t)(mma8652_rxbuffer[5] << 8 | mma8652_rxbuffer[6])) >> 4; // 12-bit Z-axis acceleration output value
    
    *x = ((float) x_out) / MMA8652_SENSITIVITY_2G; // X-axis output value in g's
    *y = ((float) y_out) / MMA8652_SENSITIVITY_2G; // X-axis output value in g's
    *z = ((float) z_out) / MMA8652_SENSITIVITY_2G; // X-axis output value in g's
}
