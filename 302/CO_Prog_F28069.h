/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * \file CO_Prog_F28335.h
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
#ifndef CO_PROG_F28335_H
#define CO_PROG_F28335_H

#include "CO_Prog.h"

#if (CO_CONFIG_PROG & CO_CONFIG_PROG_ENABLE) || defined CO_DOXYGEN

CO_ReturnError_t CO_Prog_F28335_init(CO_CANmodule_t * CANmodule);
bool CheckAppCrc();
bool CheckAppAndJump();

#endif /* (CO_CONFIG_PROG & CO_CONFIG_PROG_ENABLE) */
#endif /* CO_PROG_F28335_H */
