/******************************************************************************/
/**
@file		ramutil.c
@author		Kris Wallperington
@brief		Source file for ram check utility function.
*/
/******************************************************************************/

#include "ramutil.h"

#if defined(ARDUINO)

/**
@brief    Arduino-compatible utility function to check available RAM.
*/
int free_ram () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

#else
#include <limits.h>

/**
@brief  System-nonspecific workaround that assumes memory limitations are
        not an issue. (For safety, @c malloc calls should
        be checked for success regardless.)
*/
int free_ram() {
    return INT_MAX;
}
#endif