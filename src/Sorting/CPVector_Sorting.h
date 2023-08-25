#ifndef CROSS_PLATFORM_VECTOR_SORTING_H
#define CROSS_PLATFORM_VECTOR_SORTING_H
	
	namespace CPVector::Sorting
	{
		////////////////////////////////////////////////////////////////////////
		// type used as return type for comparing functions

            /**
             * @brief return type for comparing functions
             *
             * Any Result that is not Swap, Equal, or Ignore, will have no efect on the sorting functionality of the vector. 
             */
	    	typedef int8_t Result;

            /**
             * @brief Template callback type
             *
             * Used in CPVector::vector<T> in order to reference a Sorting::Callback. A Sorting::Callback stores a pointer to a function that follows the required convention.
             * The sorting function definition must recive two contstant references to a template type object, and must return a CPVector::Sorting::Result containing CPVector::Sorting::Equal, CPVector::Sorting::Swap, or CPVector::Sorting::Ignore.\n 
             * Check CPVector::Sorting::Ascending and CPVector::Sorting::Descending as a reference.
             */
	    	template<class T>
	    	using Callback = Result(*)(const T&, const T&);
	    //
		////////////////////////////////////////////////////////////////////////
		// Definitions

            /**
             * @brief Template callback type
             *
             * Used in CPVector::vector<T> in order to reference a Sorting::Callback. A Sorting::Callback stores a pointer to a function that follows the required convention.
             * The sorting function definition must recive two contstant references to a template type object, and must return a CPVector::Sorting::Result containing CPVector::Sorting::Equal, CPVector::Sorting::Swap, or CPVector::Sorting::Ignore.\n 
             * Check CPVector::Sorting::Ascending and CPVector::Sorting::Descending as a reference.
             */
			static constexpr Result Swap = 1;
			static constexpr Result Equal = 0;
			static constexpr Result Ignore = -1;
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