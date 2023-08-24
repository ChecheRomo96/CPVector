#ifndef CROSS_PLATFORM_VECTOR_SORTING_H
#define CROSS_PLATFORM_VECTOR_SORTING_H

	#include "CPVector_SortingDefinitions.h"
	#include "CPVector_SortingArray.h"
	#include "CPVector_SortingTemplates.h"


	namespace CPVector::Sorting
	{
		////////////////////////////////////////////////////////////////////////
		// Definitions

			static constexpr int8_t Swap = 1;
			static constexpr int8_t Equal = 0;
			static constexpr int8_t Ignore = -1;
		//
		////////////////////////////////////////////////////////////////////////
		// SortingArray Class

			template <class T>
	        class SortingArray
	        {

	            ////////////////////////////////////////////////////////////////
	            // Compare Function Buffer

	            	CPVector::vector<int8_t(*)(const T& a, const T& b)> buffer;
	            //
	            ////////////////////////////////////////////////////////////////

	            public:

	        	////////////////////////////////////////////////////////////////
	        	// Constructor and Destructor

	                SortingArray()
	                {
	                }
	            
	                ~SortingArray()
	                {
	                }
	        	//
	        	////////////////////////////////////////////////////////////////
	        	// API

	                void Append(int8_t(*Fn)(const T& a, const T& b))
	                {
	                    if(Fn != NULL)
	                    {
	                        buffer.push_back(Fn);
	                    }
	                }
	            
	                void Delete(unsigned int n)
	                {
	                    if(n<buffer.size())
	                    {
	                        buffer.erase(n);
	                    }
	                }

	                int8_t Evaluate(const T& a, const T& b) const
	                {
	             		if(buffer.size() == 0){return Sorting::Equal;}
	                    
	                    uint8_t index = 0;
	                    int8_t result = Sorting::Equal;
	                    
	                    while(result == Sorting::Equal)
	                    {
	                        result = buffer[index](a,b);
	                        index++;
	                        if(index == buffer.size()){return result;}
	                    }

	                    return result;
	                }
	        	//
	        	////////////////////////////////////////////////////////////////
	        };
	    //
        ////////////////////////////////////////////////////////////////////////
        // Comparing functions templates

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
        //
        ////////////////////////////////////////////////////////////////////////
	}




#endif//CROSS_PLATFORM_VECTOR_SORTING_H