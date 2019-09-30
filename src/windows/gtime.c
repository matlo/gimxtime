/*
 Copyright (c) 2019 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#include <gimxtime/include/gtime.h>
#include <windows.h>

static LARGE_INTEGER freq = { 0 };

gtime gtime_gettime() {

    if (freq.QuadPart == 0) {
        QueryPerformanceFrequency(&freq);
    }

    LARGE_INTEGER tnow;
    QueryPerformanceCounter(&tnow);

    return tnow.QuadPart * GTIME_RESOLUTION / freq.QuadPart;
}
