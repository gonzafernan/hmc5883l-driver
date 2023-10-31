/**
 ******************************************************************************
 * @file           : hmc5883l_port_i2c.h
 * @author         : Gonzalo Gabriel Fernandez
 * @brief          : HMC5883L Driver I2C port header
 ******************************************************************************
 * @attention
 *
 * HMC5883L Driver I2C port header, hardware independant.
 *
 ******************************************************************************
 */

#ifndef __HMC5883L_PORT_I2C_H
#define __HMC5883L_PORT_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "hmc5883l_def.h"

hmc5883l_status_t hmc5883l_i2c_init(void *hi2c);

hmc5883l_status_t hmc5883l_i2c_reg_read(void *hi2c, uint16_t slave_address, uint8_t reg_address,
                                        uint8_t *pdata, uint32_t timeout);
hmc5883l_status_t hmc5883l_i2c_burst_read(void *hi2c, uint16_t slave_address, uint8_t reg_address,
                                          uint8_t *pdata, uint16_t data_amont, uint32_t timeout);
hmc5883l_status_t hmc5883l_i2c_reg_write(void *hi2c, uint16_t slave_address, uint8_t reg_address,
                                         uint8_t *pdata, uint32_t timeout);
hmc5883l_status_t hmc5883l_i2c_read_dma(void *hi2c, uint16_t slave_address, uint8_t reg_address,
                                        uint8_t *pdata, uint16_t data_amount);

#ifdef __cplusplus
}
#endif

#endif /* __HMC5883L_PORT_I2C_H */
