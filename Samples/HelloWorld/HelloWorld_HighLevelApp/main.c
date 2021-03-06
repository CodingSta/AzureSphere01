﻿#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>
//#include <applibs/log.h>
#include <applibs/gpio.h>
//#include <hw/sample_appliance.h>

typedef enum {
    ExitCode_Success = 0,
    ExitCode_Main_Led = 1
} ExitCode;

int main(void)
{
    //Log_Debug("Starting CMake Hello World application...\n");
    int fd0 = GPIO_OpenAsOutput(5, GPIO_OutputMode_PushPull, GPIO_Value_High);
    int fd1 = GPIO_OpenAsOutput(6, GPIO_OutputMode_PushPull, GPIO_Value_High);
    int fd2 = GPIO_OpenAsOutput(7, GPIO_OutputMode_PushPull, GPIO_Value_High);
    int fd3 = GPIO_OpenAsOutput(8, GPIO_OutputMode_PushPull, GPIO_Value_High);

    const struct timespec sleepTime = {.tv_sec = 1, .tv_nsec = 0};

    while (true) {
        GPIO_SetValue(fd0, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);

        GPIO_SetValue(fd1, GPIO_Value_Low);
        nanosleep(&sleepTime, NULL);

        GPIO_SetValue(fd2, GPIO_Value_Low);
        nanosleep(&sleepTime, NULL);

        GPIO_SetValue(fd3, GPIO_Value_Low);
        nanosleep(&sleepTime, NULL);



        GPIO_SetValue(fd0, GPIO_Value_Low);
        nanosleep(&sleepTime, NULL);

        GPIO_SetValue(fd1, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);

        GPIO_SetValue(fd2, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);

        GPIO_SetValue(fd3, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);        
    }
}

//
// To target different hardware, you'll need to update CMakeLists.txt. For example, to target the
// Avnet MT3620 Starter Kit, change the TARGET_HARDWARE variable to
// "avnet_mt3620_sk".
//
// See https://aka.ms/AzureSphereHardwareDefinitions for more details.
/// <summary>
/// Exit codes for this application. These are used for the
/// application exit code. They must all be between zero and 255,
/// where zero is reserved for successful termination.
/// </summary>