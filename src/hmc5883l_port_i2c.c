/**
 ******************************************************************************
 * @file           : hmc5883l_port_i2c.c
 * @author         : Gonzalo Gabriel Fernandez
 * @brief          : HMC5883L Driver I2C port for STM32F1XX and STM32F4XX
 ******************************************************************************
 * @attention
 *
 * HMC5883L Driver I2C port for STM32F1XX and STM32F4XX.
 * Tested on STM32F103C8T6.
 *
 ******************************************************************************
 */

#include <assert.h>

#ifdef STM32F103xB
#include "stm32f1xx_hal.h"
#elif STM32F429xx
#include "stm32f4xx_hal.h"
#endif

#include "hmc5883l.h"
#include "hmc5883l_port_i2c.h"

/**
 * @brief I2C init function
 * @retval hmc5883l_status_t
 */
hmc5883l_status_t hmc5883l_i2c_init(void *hi2c) { return HMC5883L_OK; }

/**
 * @brief I2C read register
 * @param slave_address: I2C slave address
 * @param reg_address: Address of register to read
 * @param pdata: Pointer to buffer where the register value will be stored
 * @retval hmc5883l_status_t
 */
hmc5883l_status_t hmc5883l_i2c_reg_read(void *hi2c, uint16_t slave_address, uint8_t reg_address,
                                        uint8_t *pdata, uint32_t timeout) {
    if (HAL_I2C_Mem_Read(hi2c, slave_address, reg_address, sizeof(uint8_t), pdata, sizeof(uint8_t),
                         timeout) != HAL_OK)
        return HMC5883L_ERROR;
    return HMC5883L_OK;
}

/**
 * @brief I2C burst read
 * @note Read multiple registers in burst mode with I2C
 * @param slave_address: I2C slave address
 * @param reg_address: Addres of first register to read
 * @param pdata: Pointer to buffer where the data received is stored
 * @param data_amount: Amount of data to read
 * @retval hmc5883l_status_t
 */
hmc5883l_status_t hmc5883l_i2c_burst_read(void *hi2c, uint16_t slave_address, uint8_t reg_address,
                                          uint8_t *pdata, uint16_t data_amont, uint32_t timeout) {
    if (HAL_I2C_Mem_Read(hi2c, slave_address, reg_address, sizeof(uint8_t), pdata,
                         sizeof(uint8_t) * data_amont, timeout) != HAL_OK)
        return HMC5883L_ERROR;
    return HMC5883L_OK;
}

/**
 * @brief I2C write register
 * @param slave_address: I2C slave address
 * @param reg_address: Addres of register to write
 * @param pdata: Pointer to buffer with value to write
 * @retval hmc5883l_status_t
 */
hmc5883l_status_t hmc5883l_i2c_reg_write(void *hi2c, uint16_t slave_address, uint8_t reg_address,
                                         uint8_t *pdata, uint32_t timeout) {
    if (HAL_I2C_Mem_Write(hi2c, slave_address, reg_address, sizeof(uint8_t), pdata, sizeof(uint8_t),
                          timeout) != HAL_OK)
        return HMC5883L_ERROR;
    return HMC5883L_OK;
}

/**
 * @brief I2C non-blocking read through DMA
 * @param slave_address: I2C slave address
 * @param reg_address: Addres of register to write
 * @param pdata: Pointer to buffer with value to write
 * @param data_amount: Amount of data to write
 * @retval hmc5883l_status_t
 */
hmc5883l_status_t hmc5883l_i2c_read_dma(void *hi2c, uint16_t slave_address, uint8_t reg_address,
                                        uint8_t *pdata, uint16_t data_amount) {
    if (HAL_I2C_Mem_Read_DMA(hi2c, slave_address, reg_address, sizeof(uint8_t), pdata,
                             data_amount) != HAL_OK)
        return HMC5883L_ERROR;
    return HMC5883L_OK;
}

// /**
//  * @brief I2C Rx completed callback
//  */
// void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c) { hmc5883l_rxcallback(); }
