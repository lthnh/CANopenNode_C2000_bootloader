/*!
 * SPDX-License-Identifier: Apache-2.0
 *
 * \file eeprom.h
 * \copyright Copyright (c) 2026 Sicris Rey Embay
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef EEPROM_H
#define EEPROM_H

#include "autoconf.h"

#if CONFIG_HAS_EEPROM
#include "stdint.h"
#include "CO_driver_target.h"   // uint8_t definition

typedef enum {
    EEPROM_OK = 0,         /*!< No Error */
    EEPROM_INVALID_ARG,    /*!< Invalid function argument */
    EEPROM_INVALID_STATE,  /*!< Invalid State */
    EEPROM_INVALID_ADDR,   /*!< Invalid Memory Address */
    EEPROM_ERROR           /*!< Error */
} EEPROM_RET_T;


void EEPROM_init(void);

/*!
 * <PRE>EEPROM_RET_T EEPROM_read(uint16_t address, uint16_t * pBuf, uint16_t len);</PRE>
 *
 * \fn EEPROM_RET_T EEPROM_read(uint16_t address, uint16_t * pBuf, uint16_t len)
 *
 * This function reads from EEPROM memory location to Buffer.
 *
 * \param address       EEPROM Memory Start Address
 * \param pBuf          Pointer to Buffer
 * \param len           Number of bytes to read
 *
 * \return refer to ::EEPROM_RET_T
 */
EEPROM_RET_T EEPROM_read(const uint16_t address, uint8_t * pBuf, const uint16_t len);

/*!
 * <PRE>EEPROM_RET_T EEPROM_write(const uint16_t address, uint16_t * pBuf, const uint16_t len);</PRE>
 *
 * \fn EEPROM_RET_T EEPROM_write(const uint16_t address, uint16_t * pBuf, const uint16_t len)
 *
 * This function writes to EEPROM memory location.
 *
 * \param address       EEPROM Memory Start Address
 * \param pBuf          Pointer to Buffer
 * \param len           Number of bytes to write
 *
 * \return refer to ::EEPROM_RET_T
 */
EEPROM_RET_T EEPROM_write(const uint16_t address, uint16_t * pBuf, const uint16_t len);

#endif /* CONFIG_HAS_EEPROM */
#endif /* EEPROM_H */

