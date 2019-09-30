/*
 Copyright (c) 2019 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#include <gimxtime/include/gtime.h>
#include <time.h>

gtime gtime_gettime() {
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);
    return tv.tv_sec * GTIME_RESOLUTION + tv.tv_nsec;
}
