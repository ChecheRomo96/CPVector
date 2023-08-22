/**
 * @file CPVector_Template.h
 * @brief CPVector::vector<> class template
 */
#ifndef CROSS_PLATFFORM_VECTOR_TEMPLATE_H
#define CROSS_PLATFFORM_VECTOR_TEMPLATE_H

    #include "CPVector_BuildSettings.h"
    #include "Sorting/CPVector_Sorting.h"

    namespace CPVector
    {
        /**
         * @brief Cross Platform Vector class. \n\n
         * CPVector::Vector<T> is a sequence container that encapsulates dynamic size arrays.\n\n
         * The elements are stored contiguously, which means that elements can be accessed not only through iterators, but also using offsets to regular pointers to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer to an element of an array.\n\n
         * The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to reallocate each time an element is inserted, but only when the additional memory is exhausted. The total amount of allocated memory can be queried using capacity() function. Extra memory can be returned to the system via a call to shrink_to_fit()[1].\n\n
         * Reallocations are usually costly operations in terms of performance. The reserve() function can be used to eliminate reallocations if the number of elements is known beforehand.
         * @tparam T Data type to be used for the Dynamic Array
         */
        template <class T>
        class  vector
        {
            ////////////////////////////////////////////////////////////////////////////////////////////
            // Arduino and PSoC

                #if defined(ARDUINO) || defined(PSOC_CREATOR)
                    unsigned int _Size;
                    unsigned int _Capacity;
                    T* _Buffer;
                #endif
            //
            ////////////////////////////////////////////////////////////////////////////////////////////
            // Desktop C++
            
                #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                    std::vector<T> _Vector;
                #endif
            //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            public:
                
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Constructors, Destructor
                
                    /**
                     * @brief Default Constructor
                     * 
                     * Initializes the vector to have size() = 0, the Capacity value is undefined, it's value is only bigger than size at all times. In order to reduce the capacity of the vector see shrink_to_fit() or clear()
                     */
                    vector()
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Initialization 
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                _Buffer = NULL;
                                _Size = 0;
                                _Capacity = 0;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////

                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Resizing
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Cross Compatible Code

                            clear();
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }
                    
                    /**
                     * @brief Resize Constructor
                     * Resizes the container to contain count elements, does nothing if count == size().\n\n
                     * If the current size is greater than count, the container is reduced to its first count elements.\n\n
                     * If the current size is less than count, then:\n
                     * 1) additional default-inserted elements are appended\n
                     * 2) additional copies of value are appended.\n                     
                     * @tparam count New size of the conatainer
                     * @tparam value The value to initialize the elements with
                     */
                    vector(unsigned int count, const T& value = T())
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Initialization 
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                _Buffer = NULL;
                                _Size = 0;
                                _Capacity = 0;
                            #endif
                        //
                        ///////////////// ///////////////////////////////////////////////////////////////////////////

                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Resizing
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Cross Compatible Code
                            
                            resize(count, value);

                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }
                    
                    /**
                     * @brief Resize Constructor
                     * 
                     * Initializes the vector to have size() = new_size, the Capacity value is undefined, it's value is only bigger than size at all times. In order to reduce the capacity of the vector see shrink_to_fit() or clear()
                     * @tparam new_size Number of elements in the vector
                     */
                    vector(const vector<T>& Source)
                    {            
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Initialization 
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                _Buffer = NULL;
                                _Size = 0;
                                _Capacity = 0;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////

                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Resizing and copying data
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Cross Compatible Code
                                
                            resize(Source.size());
                            
                            for(unsigned int i = 0; i < size(); i++)
                            {
                                (*this)[i] = Source[i];
                            }
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }
                
                    vector(const T* Source, unsigned int Size)
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Initialization 
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                _Buffer = NULL;
                                _Size = 0;
                                _Capacity = 0;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////

                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Resizing and copying data
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Cross Compatible Code
                                
                            resize(Size);
                            
                            for(unsigned int i = 0; i < size(); i++)
                            {
                                (*this)[i] = Source[i];
                            }
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }
                    
                    ~vector()
                    {
                        clear();
                    }
                //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Operators
                    
                    ///////////////////////////////////////////////////////////////////
                    // Assignment Operators

                        vector& operator=(const vector& source)
                        {
                            if(this == &source){return *this;}
                            
                            if(resize(source.size()))
                            {
                                for(unsigned int i = 0; i < size(); i++)
                                {
                                    (*this)[i] = source[i];
                                }
                            }
                                
                            return *this;
                        }
                    //
                    ///////////////////////////////////////////////////////////////////
                    // Subscript Array Operators
                    
                        T& operator[](unsigned int x)
                        {
                            ////////////////////////////////////////////////////////////////////////////////////////////
                            // Cast Operator 
                            ////////////////////////////////////////////////////////////////////////////////////////////
                            // Arduino and PSoC

                                #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                     return _Buffer[x];
                                #endif
                            //
                            ////////////////////////////////////////////////////////////////////////////////////////////
                            //  std::vector

                                #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                    return _Vector[x];
                                #endif
                            //
                            ////////////////////////////////////////////////////////////////////////////////////////////
                        }

                        const T& operator[](unsigned int x) const
                        {
                            ////////////////////////////////////////////////////////////////////////////////////////////
                            // Cast Operator 
                            ////////////////////////////////////////////////////////////////////////////////////////////
                            // Arduino and PSoC

                                #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                     return _Buffer[x];
                                #endif
                            //
                            ////////////////////////////////////////////////////////////////////////////////////////////
                            //  std::vector

                                #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                    return _Vector[x];
                                #endif
                            //
                            ////////////////////////////////////////////////////////////////////////////////////////////
                        }
                    //
                    ///////////////////////////////////////////////////////////////////
                    // Comparison Operators

                        bool operator==(const vector& source) const
                        {
                            if(this == &source){return 1;}
                            
                            if(size() != source.size()){return 0;}
                            
                            for(unsigned int i = 0; i < size(); i++)
                            {
                                if((*this)[i] != source[i])
                                {return 0;}
                            }
                            return 1;
                        }

                        bool operator!=(const vector& source) const
                        {
                            if(this == &source){return 1;}
                            
                            if(size() != source.size()){return 1;}
                            
                            for(unsigned int i = 0; i < size(); i++)
                            {
                                if((*this)[i] != source[i])
                                {return 1;}
                            }
                            return 0;
                        }
                    //
                    ///////////////////////////////////////////////////////////////////
                //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Size And Resize API
                
                    uint32_t capacity() const
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                return _Capacity;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        //  std::vector

                            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                return (uint32_t)_Vector.capacity();
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }

                    uint32_t size() const
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                return _Size;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        //  std::vector

                            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                return (uint32_t)_Vector.size();
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }

                    void reserve(uint32_t new_cap)
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)

                                if(new_cap < _Size){ return;}
                                if(new_cap == 0){ clear(); return;}

                                if(_Buffer == NULL)
                                {
                                    if((_Buffer = (T*)malloc(new_cap * sizeof(T)) ) == NULL)
                                    {
                                        _Size = 0;
                                        _Capacity = 0;
                                    }

                                    _Capacity = new_cap;
                                }
                                else
                                {
                                    T* ptr = NULL;
                                    
                                    if((ptr = (T*)malloc(new_cap * sizeof(T)) ) != NULL)
                                    {


                                        for(uint32_t i = 0; i < _Size; i++)
                                        {
                                            ptr[i] = _Buffer[i];
                                        }

                                        free(_Buffer );
                                        _Buffer = ptr;
                                    }
                                }
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        //  std::vector

                            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                _Vector.reserve(new_cap);
                            #endif
                        //
                    }

                    bool resize(uint32_t new_size, const T& Value = T())
                    {
                        if(size() == new_size){return 1;}
                        
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                
                                if(new_size == 0){ clear(); return 1;}

                                if(new_size > _Capacity)
                                { 
                                    reserve(new_size); 
                                    if(new_size < _Capacity)
                                    {
                                        return 0;
                                    }
                                }

                                auto min = (_Size<new_size) ? _Size : new_size;

                                for(uint32_t i = min; i < new_size; i++)
                                {
                                    _Buffer[i] = Value;
                                }

                                _Size = new_size;
                                
                                return 1;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        //  std::vector

                            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                
                                auto OldSize = _Vector.size();

                                _Vector.resize(new_size, Value);

                                if(OldSize > new_size)
                                {
                                    _Vector.shrink_to_fit();
                                }

                                if(_Vector.size() == new_size)
                                {
                                    return 1;
                                }
                                else
                                {
                                    return 0;
                                }
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }

                    void clear()
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Arduino and PSoC

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)

                                for(uint8_t i = 0; i < _Size; i++)
                                {
                                    _Buffer[i].~T();
                                }

                                free(_Buffer);
                                _Buffer = NULL;
                                _Size = 0;
                                _Capacity = 0;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        //  std::vector

                            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                if(_Vector.size() != 0)
                                {
                                    _Vector.resize(0);
                                }
                                
                                _Vector.shrink_to_fit();
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    } 
                //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // API
                
                    void copy(const T* source, unsigned int len, unsigned int offset = 0, bool Resize = 0)
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Cross Compatible Code

                            if(Resize == 1){resize(len);}
                            
                            unsigned int min = ((size()<len)?size():len) + offset;

                            
                            for(unsigned int i = offset; i < min; i++)
                            {
                                (*this)[i-offset] = source[i];
                            }
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }
                    
                    void push_back(const T& data)
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // std::vector

                            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                _Vector.push_back(data);
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        //  PSoC Creator and Arduino IDE

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                resize(size() + 1);
                                _Buffer[size() - 1] = data;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }
                    
                    T pop(unsigned int postion = 0)
                    {
                        T x = (*this)[postion];
                        for(unsigned int i = postion; i < size()-1; i++)
                        {
                            (*this)[i] = (*this)[i+1];
                        }
                        resize(size()-1);
                        return x;
                    }
                    
                    T pop_first()
                    {
                        return pop(0);
                    }

                    T pop_back()
                    {
                        return pop(size()-1);
                    }
                    
                    void emplace(T data, unsigned int position)
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // std::vector

                            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                _Vector.emplace(_Vector.begin()+position,data);
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        //  PSoC Creator and Arduino IDE

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                resize(_Size+1);
                                for(unsigned int i = 0 ; i < (_Size - position - 1) ; i++)
                                {
                                    (*this)[position+i+1] = (*this)[position+i];
                                }
                                (*this)[position] = data;
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }

                    void swap(unsigned int a, unsigned int b)
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // Cross Compatible Code

                            if(a == b){return;}
                            T c = (*this)[a];
                            (*this)[a] = (*this)[b];
                            (*this)[b] = c;
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }

                    void erase(unsigned int Position)
                    {
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        // std::vector

                            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
                                _Vector.erase(_Vector.begin()+Position);
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                        //  PSoC Creator and Arduino IDE

                            #if defined(ARDUINO) || defined(PSOC_CREATOR)
                                if(Position < _Size)
                                {
                                    for(unsigned int i = Position; i < _Size ;i++)
                                    {
                                        (*this)[i] = (*this)[i+1];
                                    }
                                    resize(size()-1);
                                }
                            #endif
                        //
                        ////////////////////////////////////////////////////////////////////////////////////////////
                    }
                //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Sorting

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    // In order for these to work the class T must have declared the <, >, and the == operators.
                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    //
                        void SortAscending()
                        {
                            Sort(Sorting::Ascending);
                        }
                        
                        void SortDescending()
                        {
                            Sort(Sorting::Descending);
                        }
                    //
                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    void Sort(int8_t (*CompareFunction)(const T& a, const T& b))
                    {
                        _CustomSort_Helper(CompareFunction, 0, size()-1);
                    }
                    
                    void Sort(const Sorting::SortingArray<T>& SortingArray)
                    {
                        _CustomSort_Helper(SortingArray, 0, size()-1);
                    }
                //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            private:

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Sorting Helpers

                    void _CustomSort_Helper(int8_t (*CompareFunction)(const T& a, const T& b), unsigned int lower, unsigned int upper)
                    {
                        // Limits check
                        if(lower > upper)
                        {
                            unsigned int tmp = lower;
                            lower = upper;
                            upper = tmp;
                        }

                        // Calculate new Pivot
                        unsigned int pivot = lower;
                        pivot = _CustomSort_Partition(CompareFunction,lower,upper,pivot);
                        
                        // Recursive calls
                        if(pivot > lower+1){_CustomSort_Helper(CompareFunction,lower,pivot-1);}
                        if(pivot < upper-1)_CustomSort_Helper(CompareFunction,pivot+1,upper);
                    }
                    
                    unsigned int _CustomSort_Partition(int8_t (*CompareFunction)(const T& a, const T& b), unsigned int lower, unsigned int upper, unsigned int pivot)
                    {
                        // Store Pivot value at the Highest index (upper limit)
                        swap(pivot,upper);
                        
                        // Initialize the exchange index at the lower limit
                        int index = lower;

                        // Cycle through each element
                        for(unsigned int i = lower ; i < upper; i++)
                        {
                            // Comparing the n'th element against the pivot 
                            if(CompareFunction((*this)[i],(*this)[upper]) == CPVector::Sorting::Swap)
                            {
                                // If the element at the n'th position is lower compared to the Pivot,
                                // then it is swapped to its new place and the the index counter increases.
                                swap(index,i);
                                index++;
                            }
                        }

                        // Move the pivot element back to it's place
                        swap(index,upper);
                        return index;
                    }
                    
                    void _CustomSort_Helper(const Sorting::SortingArray<T>& SortingArray, unsigned int lower, unsigned int upper)
                    {
                        // Limits check
                        if(lower > upper)
                        {
                            unsigned int tmp = lower;
                            lower = upper;
                            upper = tmp;
                        }

                        // Sort and get new pivot index
                        unsigned int pivot = lower;
                        pivot = _CustomSort_Partition(SortingArray,lower,upper,lower);

                        // Recursive calls
                        if(pivot > lower+1){_CustomSort_Helper(SortingArray,lower,pivot-1);}
                        if(pivot < upper-1)_CustomSort_Helper(SortingArray,pivot+1,upper);
                        
                    }
                    
                    unsigned int _CustomSort_Partition(const Sorting::SortingArray<T>& CompareVector, unsigned int lower, unsigned int upper, unsigned int pivot)
                    {
                        // Store Pivot value at the Highest index (upper limit)
                        swap(pivot, upper);
                        
                        // Initialize the exchange index at the lower limit
                        int index = lower;

                        // Cycle through each element
                        for(unsigned int i = lower ; i < upper; i++)
                        {
                            // Comparing the n'th element against the pivot 
                            if(CompareVector.Evaluate((*this)[i],(*this)[upper]) == CPVector::Sorting::Swap)
                            {
                                // If the element at the n'th position is lower compared to the Pivot,
                                // then it is swapped to its new place and the the index counter increases.
                                swap(index,i);
                                index++;
                            }
                        }

                        // Move the pivot element back to it's place
                        swap(index,upper);
                        return index;
                    }
                //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        };
    }


#endif//CROSS_PLATFFORM_VECTOR_TEMPLATE_H