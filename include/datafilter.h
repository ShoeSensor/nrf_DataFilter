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

#ifndef DATAFILTER_H
#define	DATAFILTER_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

// Z is the upwards motion
// X is the forwards motion

/**
 * @brief sets the first measure point in system time.
 */
void setTimeDiff();

/**
 * @brief calculates the forward speed and the height of the shoe
 * @param Xacc is the forward acceleration
 * @param Zacc is the upwards acceleration
 * @param[out] distance is the height of the shoe
 * @return the forward speed
 */
int16_t calcSpeed(int16_t Xacc, int16_t Zacc, int16_t *distance);

#ifdef	__cplusplus
}
#endif

#endif	/* DATAFILTER_H */
