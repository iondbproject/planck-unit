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

#include "ion_time.h"

double
ion_time(){
#if defined(ARDUINO)
	return (double)(millis());

#elif defined(WIN32)||defined(_WIN32)||defined(__WIN32)
	return ((double) clock()/CLOCKS_PER_SEC)*1000;

#elif defined (__unix__)||defined(__APPLE__)&&defined (__MACH__)
	return ((double) clock()/CLOCKS_PER_SEC)*1000;

#elif defined (__MACH__)&& defined(__APPLE__)
	return ((double) AbsoluteToNanoseconds((mach_absolute_time())))*1000000;

#elif defined(__CYGWIN)
	struct timeval time;
	gettimeofday(&time, NULL);
	return (double) (time.tv_sec*1000);

#endif
}