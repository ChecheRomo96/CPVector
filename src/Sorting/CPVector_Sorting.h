#ifndef CROSS_PLATFORM_VECTOR_SORTING_H
#define CROSS_PLATFORM_VECTOR_SORTING_H
	
	namespace CPVector::Sorting
	{
		////////////////////////////////////////////////////////////////////////
		// type used as return type for comparing functions

	    	typedef int8_t Result;


	    	template<class T>
	    	using Callback = Result(*)(const T&, const T&);
	    //
		////////////////////////////////////////////////////////////////////////
		// Definitions

			static constexpr Result Swap = 1;
			static constexpr Result Equal = 0;
			static constexpr Result Ignore = -1;
		//
        ////////////////////////////////////////////////////////////////////////
        // Comparing functions templates
			
			#define CPVector::Sorting::CompareFunction(Name) 	\
	        template <class T>									\
	        Result Name(const T& Element, const T& Pivot)		\

		// 
        ////////////////////////////////////////////////////////////////////////
        // Comparing functions templates

	        template <class T>
	        Result Ascending(const T& Element, const T& Pivot)
	        {
	            if(Element==Pivot){return Sorting::Equal;}
	            else if(Element<Pivot){return Sorting::Swap;}
	            else{return Sorting::Ignore;}
	        }
	        
	        template <class T>
	        Result Descending(const T& Element, const T& Pivot)
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