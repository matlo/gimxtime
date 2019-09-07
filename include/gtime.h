/*
 Copyright (c) 2019 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef GTIME_H_
#define GTIME_H_

typedef unsigned long long int gtime;
typedef unsigned long int gtimepart;
typedef long long int gtimediff;

/*
 * Get current time. Value is monotonic and not bound to system time.
 */
gtime gtime_gettime();

#define GTIME_SECPART(T) ((gtimepart)(T / 1000000UL))
#define GTIME_USECPART(T) ((gtimepart)(T % 1000000UL))

#endif /* GTIME_H_ */
