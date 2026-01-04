#ifdef __linux

#ifndef _POSIX_C_SOURCE
  #define _POSIX_C_SOURCE 200809L
#endif

#include <mcisid/mcisidv1.h>
#include <time.h>

#if _POSIX_C_SOURCE == 200809L
  mcisidv1tm mcisidv1GetSystemInstant() {
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    time_t milis = (spec.tv_sec * 1000L) + (time_t)(spec.tv_nsec / 1000000L);
    return (mcisidv1tm)(milis - MCISIDV1_BASE_EPOCH_UNIX_MS);
  }
#endif /** _POSIX_C_SOURCE  */
#endif // __linux