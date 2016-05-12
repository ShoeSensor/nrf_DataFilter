/*
 * Copyright 2016 Nils van Mulekom
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

#include <stdbool.h>
#include <stdint.h>
#include "os_thread.h"


#include "datafilter.h"

static uint32_t timeDiff;

typedef struct {

	int16_t prevSpeed;
	int16_t prevDis;

	int16_t curAcc;
	int16_t curSpeed;
	int16_t curDis;

} vector_t;

vector_t X;
vector_t Z;

static uint16_t calcDistance() {
	Z.prevDis = Z.curDis;
	Z.curDis = (timeDiff * Z.curSpeed) + Z.prevDis;
	return Z.curDis;
}
void setTimeDiff() {
    timeDiff = os_timerGetMs();
}

int16_t calcSpeed(int16_t Xacc, int16_t Zacc, int16_t *distance) {
    timeDiff = os_timerGetMs() - timeDiff;
	X.curAcc = Xacc;
	Z.curAcc = Zacc;

	X.prevSpeed = X.curSpeed;
	Z.prevSpeed = Z.curSpeed;

	X.curSpeed = (timeDiff * X.curAcc) + X.prevSpeed;
	Z.curSpeed = (timeDiff * Z.curAcc) + Z.prevSpeed;
	*distance = calcDistance();
	return X.curSpeed;

}


