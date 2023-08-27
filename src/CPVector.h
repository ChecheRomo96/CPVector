/** Cross Platform Vector main header
 *  In this file the needed files are included depending on the build configuration.
 */
#ifndef CROSS_PLATFORM_VECTOR_H
#define CROSS_PLATFORM_VECTOR_H

	#include "CPVector_BuildSettings.h"
	
	#if defined (CPVECTOR_SORTING_ENABLED)
		#include "Sorting/CPVector_Sorting.h"
	#endif

	#include "CPVector_Template.h"

#endif//CROSS_PLATFORM_STRING_H

/** \example ./examples/1_BuildTest/Desktop/main.cpp
 * This is an example of how to use the Example_Test class.
 * More details about this example.
 */