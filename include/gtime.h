/*
 Copyright (c) 2020 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef GTIME_H_
#define GTIME_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Use this type to store the result of gtime_gettime(),
 * or to store difference of two following results of gtime_gettime(),
 * which is guaranteed to be a positive value.
 */
typedef unsigned long long int gtime;

/*
 * Use this type to store the seconds or nanoseconds part of gtime.
 */
typedef unsigned long int gtimepart;

/*
 * Use this type to store the difference between the result of gtime_gettime() and an expected time.
 * In such case the result can be negative.
 */
typedef long long int gtimediff;

/*
 * gtime resolution is  1 nanosecond.
 */
#define GTIME_RESOLUTION 1000000000UL

/*
 * gtime format specifier.
 */
#ifdef WIN32
#define GTIME_FS "%I64u"
#else
#define GTIME_FS "%llu"
#endif

/*
 * gtimepart format specifier.
 */
#define GTIMEPART_FS "%lu"

/*
 * gtimediff format specifier.
 */
#ifdef WIN32
#define GTIMEDIFF_FS "%I64d"
#else
#define GTIMEDIFF_FS "%lld"
#endif

/*
 * Get current time as nanoseconds. Value is monotonic and not bound to system time.
 */
gtime gtime_gettime();

/*
 * Convert gtime to seconds.
 */
#define GTIME_SEC(T) ((T) / GTIME_RESOLUTION)

/*
 * Convert gtime to microseconds.
 */
#define GTIME_USEC(T) ((T) / 1000UL)

/*
 * Get the seconds part from gtime.
 */
#define GTIME_SECPART(T) ((gtimepart)((T) / GTIME_RESOLUTION))

/*
 * Get the nanoseconds part from gtime.
 */
#define GTIME_NSECPART(T) ((gtimepart)((T) % GTIME_RESOLUTION))

/*
 * Get the microseconds part from gtime.
 */
#define GTIME_USECPART(T) (GTIME_NSECPART(T) / 1000UL)

#ifdef __cplusplus
}
#endif

#endif /* GTIME_H_ */
