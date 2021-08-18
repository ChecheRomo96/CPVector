#ifndef CROSS_PLATFFORM_VECTOR_SORTING_TEMPLATES_H
#define CROSS_PLATFFORM_VECTOR_SORTING_TEMPLATES_H

	#include <CPVector_BuildSettings.h>
    #include "CPVector_SortingDefinitions.h"

	namespace CPVector
    {
        namespace Sorting
        {
            template <class T>
            int8_t Ascending(const T& Element, const T& Pivot)
            {
                if(Element==Pivot){return Sorting::Equal;}
                else if(Element<Pivot){return Sorting::Swap;}
                else{return Sorting::Ignore;}
            }
            
            template <class T>
            int8_t Descending(const T& Element, const T& Pivot)
            {
                if(Element==Pivot){return Sorting::Equal;}
                else if(Element>Pivot){return Sorting::Swap;}
                else{return Sorting::Ignore;}
            }
        }
    }

#endif//CROSS_PLATFFORM_VECTOR_SORTING_TEMPLATES_H