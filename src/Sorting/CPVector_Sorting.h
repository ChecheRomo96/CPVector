#ifndef CROSS_PLATFORM_VECTOR_SORTING_H
#define CROSS_PLATFORM_VECTOR_SORTING_H
	
	namespace CPVector::Sorting
	{
		////////////////////////////////////////////////////////////////////////
		// type used as return type for comparing functions

	    	typedef int8_t CompareResult;

	    	template<class T>
	    	using CompareCallback = CompareResult(*)(const T&, const T&);
	    //
		////////////////////////////////////////////////////////////////////////
		// Definitions

			static constexpr CompareResult Swap = 1;
			static constexpr CompareResult Equal = 0;
			static constexpr CompareResult Ignore = -1;
		//
        ////////////////////////////////////////////////////////////////////////
        // Comparing functions templates

	        template <class T>
	        CompareResult Ascending(const T& Element, const T& Pivot)
	        {
	            if(Element==Pivot){return Sorting::Equal;}
	            else if(Element<Pivot){return Sorting::Swap;}
	            else{return Sorting::Ignore;}
	        }
	        
	        template <class T>
	        CompareResult Descending(const T& Element, const T& Pivot)
	        {
	            if(Element==Pivot){return Sorting::Equal;}
	            else if(Element>Pivot){return Sorting::Swap;}
	            else{return Sorting::Ignore;}
	        }
        //
        ////////////////////////////////////////////////////////////////////////
	}

	#include "CPVector_SortingArray.h"

#endif//CROSS_PLATFORM_VECTOR_SORTING_H