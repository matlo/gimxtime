/*
 Copyright (c) 2019 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef GTIME_H_
#define GTIME_H_

/*
 * Use this type to store the result of gtime_gettime(),
 * or to store difference of two following results of gtime_gettime(),
 * which is guaranteed to be a positive value.
 */
typedef unsigned long long int gtime;

/*
 * Use this type to store the seconds or nanosecond part of gtime.
 */
typedef unsigned long int gtimepart;

/*
 * Use this type to store the difference between the result of gtime_gettime() and an expected time.
 * In such case the result can be negative.
 */
typedef long long int gtimediff;

#define GTIME_RESOLUTION 1000000000UL

/*
 * Get current time as nanoseconds. Value is monotonic and not bound to system time.
 */
gtime gtime_gettime();

#define GTIME_SEC(T) ((T) / GTIME_RESOLUTION)
#define GTIME_USEC(T) ((T) / 1000UL)

#define GTIME_SECPART(T) ((gtimepart)((T) / GTIME_RESOLUTION))
#define GTIME_NSECPART(T) ((gtimepart)((T) % GTIME_RESOLUTION))
#define GTIME_USECPART(T) (GTIME_NSECPART(T) / 1000UL)

#endif /* GTIME_H_ */
