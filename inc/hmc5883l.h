/**
 ******************************************************************************
 * @file           : hmc5883l.h
 * @author         : Gonzalo Gabriel Fernandez
 * @brief          : HMC5883L Driver headers
 ******************************************************************************
 * @attention
 *
 * HMC5883L C Driver public functions and variables.
 *
 ******************************************************************************
 */

#ifndef __HMC5883L_H
#define __HMC5883L_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "hmc5883l_def.h"

hmc5883l_status_t hmc5883l_init(hmc5883l_t *hhmc, void *hi2c);
void hmc5883l_rxcallback(void);

#ifdef __cplusplus
}
#endif

#endif /* __HMC5883L_H */
