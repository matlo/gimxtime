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
 * Get current time as nanoseconds. Value is monotonic and not bound to system time.
 */
gtime gtime_gettime();

#define GTIME_SEC(T) ((T) / 1000000000UL)
#define GTIME_USEC(T) ((T) / 1000UL)

#define GTIME_SECPART(T) ((gtimepart)((T) / 1000000000UL))
#define GTIME_NSECPART(T) ((gtimepart)((T) % 1000000000UL))
#define GTIME_USECPART(T) (GTIME_NSECPART(T) / 1000UL)

#endif /* GTIME_H_ */
