#ifndef CROSS_PLATFFORM_VECTOR_SORTING_ARRAY_TEMPLATE_H
#define CROSS_PLATFFORM_VECTOR_SORTING_ARRAY_TEMPLATE_H

	#include <CPVector_BuildSettings.h>
    #include "CPVector_SortingDefinitions.h"

	namespace CPVector
    {   
        template <class T>
        class vector;

        namespace Sorting
        {
            template <class T>
            class SortingArray
            {
                CPVector::vector<int8_t(*)(const T& a, const T& b)> buffer;
                
                public:
                
                    SortingArray()
                    {
                    }
                
                    ~SortingArray()
                    {
                    }
                
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

                    int8_t Evaluate(const T& a, const T& b)
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
            };
        }
    }


#endif//CROSS_PLATFFORM_VECTOR_SORTING_ARRAY_TEMPLATE_H