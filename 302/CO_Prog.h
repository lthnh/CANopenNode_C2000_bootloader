/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * \file CO_Prog.h
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
#ifndef CO_PROG_H
#define CO_PROG_H

#include "301/CO_driver.h"
#include "301/CO_ODinterface.h"

#define CO_CONFIG_PROG_ENABLE   1

#ifndef CO_CONFIG_PROG
#define CO_CONFIG_PROG (CO_CONFIG_PROG_ENABLE)
#endif

#if ((CO_CONFIG_PROG) & CO_CONFIG_PROG_ENABLE)

/**
 * Program Download object
 */
typedef struct {
    OD_extension_t OD_1F50_extensions;
    OD_extension_t OD_1F51_extensions;
    OD_extension_t OD_2000_extensions;
    CO_CANmodule_t * CANmodule;
} CO_Program_t;

/**
 * Initialize Program Download object.
 *
 * Function must be called in the communication reset section.
 *
 * @param ProgObj This object will be initialized.
 * @param Prog_CANdevRx CAN device for Program Download reception.
 * @param Prog_CANdevTx CAN device for Program Download transmission.
 *
 * @return #CO_ReturnError_t CO_ERROR_NO or CO_ERROR_ILLEGAL_ARGUMENT.
 */
CO_ReturnError_t CO_Prog_init(CO_Program_t * ProgObj,
                              OD_entry_t * OD_1F50_ProgramDownloadData,
                              OD_entry_t * OD_1F51_ProgramControl,
                              OD_entry_t * OD_2000_Bootloader,
                              ODR_t OD_write_1F50(OD_stream_t * stream,
                                                  const void * buf,
                                                  OD_size_t count,
                                                  OD_size_t * countWritten),
                              ODR_t OD_write_1F51(OD_stream_t * stream,
                                                  const void * buf,
                                                  OD_size_t count,
                                                  OD_size_t * countWritten),
                              ODR_t OD_write_2000(OD_stream_t * stream,
                                                  const void * buf,
                                                  OD_size_t count,
                                                  OD_size_t * countWritten));

#endif /* CO_CONFIGS_PROG & CO_CONFIG_PROG_ENABLE */
#endif /* CO_PROG_H */

