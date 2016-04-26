/*
 * Copyright 2016 Nils van Mulekom.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file
 * @defgroup df_helper Data filter helper functions
 * @{
 * @ingroup lib
 *
 * @brief Data filter to filter functions.
 *
 */

#ifndef INCLUDE_DATAFILTERFUNCTIONS_H_
#define INCLUDE_DATAFILTERFUNCTIONS_H_


/**
 * @brief Initializes the data filter by setting
 * the first measure point in system time.
 */
void datafilter_init();


/**
 * @brief Uses the G-forces gathered by the sensor to
 * calculate the speed. Also calculates the height of the
 * shoe and uses this to determine when the data is useful.
 * @param XGforce the G-force in the forward direction.
 * @param ZGforce the G-force in the upward direction.
 * @return speed (when data is useful).
 * @retval FFFFFFFF (when data is not useful).
 */
int32_t datafilter_main(uint16_t XGforce, uint16_t ZGforce);

#endif /* INCLUDE_DATAFILTERFUNCTIONS_H_ */
