/******************************************************************************/
/**
@file
@author		Dana Klamut
@brief		A simple time API used to determine the length of time required
			to run PlanckUnit tests, regardless of the operating
			system being used.
@license	Licensed under the Apache License, Version 2.0 (the "License");
			you may not use this file except in compliance with the License.
			You may obtain a copy of the License at
			http://www.apache.org/licenses/LICENSE-2.0

@par
			Unless required by applicable law or agreed to in writing,
			software distributed under the License is distributed on an
			"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
			either express or implied. See the License for the specific
			language governing permissions and limitations under the
			License.
*/
/******************************************************************************/

#if !defined(PLANCKUNIT_ION_TIME_H)
#define PLANCKUNIT_ION_TIME_H

#if defined(ARDUINO)
#include <Arduino.h>
#endif

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include <Windows.h>
#include <time.h>

#elif defined (__unix__) || defined(__APPLE__) && defined (__MACH__)
#include <time.h>

#elif defined (__MACH__) && defined(__APPLE__)
#include <mach/mach.h>
#include <mach/mach_time.h>

#elif defined(__CYGWIN)
#include <sys/time.h>
#endif

/**
@brief		A general time function that can be used by any operating system.
@returns	Current time in milliseconds.
*/
unsigned long
ion_time(
);

#endif /* PLANCKUNIT_ION_TIME_H */
