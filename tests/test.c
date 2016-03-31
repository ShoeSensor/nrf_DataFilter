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

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "nrf_mma8453q.h"
#include "datafilter.h"
#include "os_thread.h"
#include "os_timer.h"
#include "nrf_uartDriver.h"

os_threadHandle_t threadHandle;
char *uartBuf;

int16_t XGforce;
int16_t ZGforce;

int16_t maxSize = 20;

int16_t Xacc;
int16_t Zacc;

int16_t distance;
int16_t speed;
int16_t freq;
uint8_t state;

static void mainThread(void *args)
{
    setTimeDiff();
    while (1) {
        //get data
        //getting data should trigger a flag
        //if flag == 1 then
        Xacc = XGforce * 9.81;
        Zacc = (ZGforce - 1) * 9.81;
        speed = calcSpeed(Xacc, Zacc, &distance);
        uartBuf = "test";
        uart_write(uartBuf, strlen(uartBuf));
        if (distance < 200 && Xacc < 0) {
            //send data
        }
        //clear flag
        //end if
    }
}

static void timerTask(void *args)
{

    switch (state) {
    case 0:
        Xacc = 0;
        Zacc = 1;
        state = 1;
        break;
    case 1:
        Xacc = 1;
        Zacc = 2;
        state = 2;
        break;
    case 2:
        Xacc = 2;
        Zacc = 3;
        state = 3;
        break;
    case 3:
        Xacc = -1;
        Zacc = 0;
        state = 4;
        break;
    case 4:
        Xacc = -2;
        Zacc = -1;
        state = 0;
        break;
    }
}

int main(void)
{
    uart_init();
    uartBuf = calloc(1, 20 * sizeof(char));
    os_threadConfig_t conf = { .name = "main", .threadCallback = mainThread,
            .threadArgs = NULL, .stackSize = STACK_SIZE_DEFAULT, .priority =
                    THREAD_PRIO_LOW };

    os_timerConfig_t timerConf = { .name = "task1", .period = 10, .oneShot =
            false, .callback = timerTask };
    os_timerTaskNew(&timerConf, 0);
    threadHandle = os_threadNew(&conf);
    os_startScheduler();
    while (1)
        ;   // never reached
    free(uartBuf);
    return 0;
}

