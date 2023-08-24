#ifndef CROSS_PLATFORM_VECTOR_SORTING_ARRAY_H
#define CROSS_PLATFORM_VECTOR_SORTING_ARRAY_H
	
	#include "CPVector_Sorting.h"

	namespace CPVector
	{
        template <class T>
        class vector;
	}

	namespace CPVector::Sorting
	{
		////////////////////////////////////////////////////////////////////////
		// SortingArray Class

			template <class T>
	        class SortingArray
	        {
	            ////////////////////////////////////////////////////////////////
	            // Compare Function Vector

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

	                void append(int8_t(*Fn)(const T& a, const T& b))
	                {
	                    if(Fn != NULL)
	                    {
	                        buffer.push_back(Fn);
	                    }
	                }

	                void swap(unsigned int a, unsigned int b)
	                {
	                	buffer.swap(a,b);
	                }
	            
	                void erase(unsigned int n)
	                {
	                    if(n<buffer.size())
	                    {
	                        buffer.erase(n);
	                    }
	                }
	            
	                void erase(int8_t(*Fn)(const T& a, const T& b))
	                {
	                	for(uint8_t i = 0; i < buffer.size(); i++)
	                	{
	                		if(buffer[i] == Fn)
	                		{
	                			buffer.erase(i--);
	                		}
	                	}
	                }

	                CompareResult compare(const T& a, const T& b) const
	                {
	             		if(buffer.size() == 0){return Sorting::Equal;}
	                    
	                    uint8_t index = 0;
	                    CompareResult result = Sorting::Equal;
	                    
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
	}

#endif//CROSS_PLATFORM_VECTOR_SORTING_ARRAY_H