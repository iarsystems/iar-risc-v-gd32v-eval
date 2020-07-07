/*!
    \file    i2c.c
    \brief   BSP I2C functions

    \version 20200707
*/

/*
    Copyright (c) 2020, IAR Systems AB.

    See LICENSE.md for detailed license information.
*/

#include "i2c.h"

uint8_t i2c0_write(uint8_t i2c_dev_addr, uint8_t *data, uint8_t count)
{
    if (count < 1) return -1;
    
    uint8_t i = count;
    
    /* wait until I2C bus is idle */
    while (i2c_flag_get(I2C0, I2C_FLAG_I2CBSY));
    /* send a start condition to I2C bus */
    i2c_start_on_bus(I2C0);
    /* wait until SBSEND bit is set */
    while (!i2c_flag_get(I2C0, I2C_FLAG_SBSEND));
    /* send slave address to I2C bus */
    i2c_master_addressing(I2C0, i2c_dev_addr, I2C_TRANSMITTER);
    /* wait until ADDSEND bit is set */
    while (!i2c_flag_get(I2C0, I2C_FLAG_ADDSEND));
    /* clear ADDSEND bit */
    i2c_flag_clear(I2C0, I2C_FLAG_ADDSEND);
    /* wait until the transmit data buffer is empty */
    while (!i2c_flag_get(I2C0, I2C_FLAG_TBE));
    
    while (i)
    {
        /* data transmission */
        i2c_data_transmit(I2C0, *data);
        /* wait until the TBE bit is set */
        while (!i2c_flag_get(I2C0, I2C_FLAG_TBE));
        data++;
        --i;
    }
    
    /* send a stop condition to I2C bus */
    i2c_stop_on_bus(I2C0);
    /* wait until stop condition generate */
    while (I2C_CTL0(I2C0)&0x0200);
     
    return 0; // reserved for status handling
}

/*!
    \brief      write to a i2c slave 8-bit register
    \param[in]  reg: internal register
    \param[in]  value: the 8-bit value to write 
    \param[out] none
    \retval     status
*/
uint8_t i2c_reg8_write(uint8_t i2c_dev_addr, uint8_t reg, uint8_t value)
{
        uint8_t txbuffer[2] = {reg, value};

        i2c0_write(i2c_dev_addr, (uint8_t*) txbuffer, sizeof(txbuffer));
        
        return 0; // reserved for status handling
}

uint8_t i2c0_read(uint8_t i2c_dev_addr, uint8_t * data, uint8_t count)
{
    if (count < 1) return -1;
    
    int i;
    
    i2c_ackpos_config(I2C0, I2C_ACKPOS_NEXT);
    /* wait until I2C bus is idle */
    while (i2c_flag_get(I2C0, I2C_FLAG_I2CBSY));
    /* send a start condition to I2C bus */
    i2c_start_on_bus(I2C0);
    /* wait until SBSEND bit is set */
    while (!i2c_flag_get(I2C0, I2C_FLAG_SBSEND));
    /* send slave address to I2C bus */
    i2c_master_addressing(I2C0, i2c_dev_addr, I2C_RECEIVER);
    /* disable ACK before clearing ADDSEND bit */
    while (!i2c_flag_get(I2C0, I2C_FLAG_ADDSEND));
    /* clear ADDSEND bit */
    i2c_flag_clear(I2C0, I2C_FLAG_ADDSEND);
      
    if (count >= 3) {
        for(i=0; i<count; i++){
            if((count - 3) == i){
                /* wait until the second last data byte is received into the shift register */
                while (!i2c_flag_get(I2C0, I2C_FLAG_BTC));
                /* disable acknowledge */
                i2c_ack_config(I2C0, I2C_ACK_DISABLE);
            }
            /* wait until the RBNE bit is set */
            while (!i2c_flag_get(I2C0, I2C_FLAG_RBNE));
            /* read a data from I2C_DATA */
            data[i] = i2c_data_receive(I2C0);
        }
    }
    else if (count == 2) {
        /* Wait until the last data byte is received into the shift register */
        while (!i2c_flag_get(I2C0, I2C_FLAG_BTC));
        /* wait until the RBNE bit is set */
        while (!i2c_flag_get(I2C0, I2C_FLAG_RBNE));
        
        /* read a data from I2C_DATA */
        data[i++] = i2c_data_receive(I2C0);
        /* wait until the RBNE bit is set */
        while (!i2c_flag_get(I2C0, I2C_FLAG_RBNE));
        /* read a data from I2C_DATA */
        data[i] = i2c_data_receive(I2C0);
    }
    else {  // count == 1
        /* Wait until the last data byte is received into the shift register */
        while (!i2c_flag_get(I2C0, I2C_FLAG_BTC));
        /* wait until the RBNE bit is set */
        while (!i2c_flag_get(I2C0, I2C_FLAG_RBNE));
        
        /* read a data from I2C_DATA */
        data[i] = i2c_data_receive(I2C0);
    }
    
    /* send a stop condition */
    i2c_stop_on_bus(I2C0);
    /* wait until stop condition generate */
    while (I2C_CTL0(I2C0)&0x0200);
    i2c_ackpos_config(I2C0, I2C_ACKPOS_CURRENT);
    /* enable acknowledge */
    i2c_ack_config(I2C0, I2C_ACK_ENABLE);  
    
    return 0; // reserved for status handling
}

/*!
    \brief      read from a i2c slave 8-bit register
    \param[in]  reg: internal register
    \param[in]  *value: pointer to the 8-bit variable which will hold the value 
    \param[out] none
    \retval     status
*/
uint8_t i2c_reg8_read(uint8_t i2c_dev_addr, uint8_t reg, uint8_t *value)
{
        i2c0_write(i2c_dev_addr, (uint8_t*)reg, 1);

        i2c0_read(i2c_dev_addr, value, 1);
        
        return 0; // reserved for status handling
}