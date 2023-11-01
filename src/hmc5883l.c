/**
 ******************************************************************************
 * @file           : hmc5883l.c
 * @author         : Gonzalo Gabriel Fernandez
 * @brief          : HMC5883L Driver
 ******************************************************************************
 * @attention
 *
 * HMC5883L C Driver private and public functions and variables.
 *
 ******************************************************************************
 */

#include "hmc5883l.h"
#include "hmc5883l_port_i2c.h"

#include <assert.h>
#include <stdbool.h>

// /**
//  * @brief   HMC5883L user-defined error callback
//  * @param   hhmc: HMC5883L handle
//  */
// __weak void hmc5883l_error_callback(hmc5883l_t *hhmc) {
//     /**
//      * NOTE: This function should be implemented in the user file
//      */
// }

/**
 * @brief   Read HMC5883L register
 * @param   hhmc: Pointer to HMC5883L handle
 * @param   reg_address: Address of register to read
 * @param   pdata: Pointer to buffer where value will be stored
 * @retval  hmc5883l_status_t
 */
static hmc5883l_status_t hmc5883l_reg_read(hmc5883l_t *hhmc, uint8_t reg_address, uint8_t *pdata) {
    /* HMC5883L register read wrapper */
    return hmc5883l_i2c_reg_read(hhmc->i2c_handle, (uint16_t)HMC5883L_I2C_ADDRESS_READ, reg_address,
                                 pdata, hhmc->i2c_timeout);
}

/**
 * @brief   Burst read HMC5883L registers
 * @param   reg_address: Address of first register to read
 * @param   pdata: Pointer to buffer where data will be stored
 * @param   data_amount: Amount of data to read
 * @retval  hmc5883l_status_t
 */
static hmc5883l_status_t hmc5883l_burst_read(hmc5883l_t *hhmc, uint8_t reg_address, uint8_t *pdata,
                                             uint16_t data_amount) {
    /* HMC5883L register read wrapper */
    return hmc5883l_i2c_burst_read(hhmc->i2c_handle, (uint16_t)HMC5883L_I2C_ADDRESS_READ,
                                   reg_address, pdata, data_amount, hhmc->i2c_timeout);
}

/**
 * @brief   Write HMC5883L register
 * @param   reg_address: Address of register to write
 * @param   pdata: Pointer to buffer with value to write
 * @retval  hmc5883l_status_t
 */
static hmc5883l_status_t hmc5883l_reg_write(hmc5883l_t *hhmc, uint8_t reg_address, uint8_t *pdata) {
    /* HMC5883L register write wrapper */
    return hmc5883l_i2c_reg_write(hhmc->i2c_handle, (uint16_t)HMC5883L_I2C_ADDRESS_WRITE,
                                  reg_address, pdata, hhmc->i2c_timeout);
}

/**
 * @brief   HMC5883L callback for data ready
 */
void hmc5883l_rxcallback(void) {}

/**
 * @brief   Initialize HMC5883L device
 * @retval  hmc5883l_status_t
 */
hmc5883l_status_t hmc5883l_init(hmc5883l_t *hhmc, void *hi2c) {
    /* I2C initialization */
    hhmc->i2c_timeout = 100;
    hhmc->i2c_handle = hi2c;
    if (hmc5883l_i2c_init(hi2c) != HMC5883L_OK)
        return HMC5883L_ERROR;
    return HMC5883L_OK;
}
