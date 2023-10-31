/**
 ******************************************************************************
 * @file           : hmc5883l_def.h
 * @author         : Gonzalo Gabriel Fernandez
 * @brief          : HMC5883L types definition
 ******************************************************************************
 * @note
 *
 * HMC5883L types and structures definition.
 *
 ******************************************************************************
 */

#ifndef __HMC5883L_DEF_H
#define __HMC5883L_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief HMC5883L Status structure definition
 */
typedef enum {
    HMC5883L_OK = 0x00U,
    HMC5883L_ERROR = 0x01U

} hmc5883l_status_t;

/**
 * @brief   HMC5883L I2C slave 8-bit read address
 */
#define HMC5883L_I2C_ADDRESS_READ 0x3D

/**
 * @brief   HMC5883L I2C slave 8-bit write address
 */
#define HMC5883L_I2C_ADDRESS_WRITE 0x3C

/**
 * @brief HMC5883L handle structure definition
 */
typedef struct {
    void *i2c_handle;     /*!< I2C handle */
    uint32_t i2c_timeout; /*!< I2C timeout        */

} hmc5883l_t;

#ifdef __cplusplus
}
#endif

#endif /* __HMC5883L_DEF_H */
