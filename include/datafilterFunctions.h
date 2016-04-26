/*
 * datafilterFunctions.h
 *
 *  Created on: Mar 31, 2016
 *      Author: bart
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
