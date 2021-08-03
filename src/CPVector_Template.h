#ifndef CROSS_PLATFFORM_VECTOR_TEMPLATE_H
#define CROSS_PLATFFORM_VECTOR_TEMPLATE_H

    #include "CPVector_BuildSettings.h"
    #include "Sorting/CPVector_Sorting.h"

    namespace CPVector
    {
        template <class T>
        class  vector
        {
            unsigned int _size;
            T* buffer;
            
            public:
                
                ///////////////////////////////////////////////////////////////////////
                // Constructors and Destructor
                
                    vector()
                    {
                        buffer = NULL;
                        _size = 0;
                    }
                    
                    vector(unsigned int _size)
                    {
                        buffer = NULL;
                        _size = 0;
                        resize(_size);
                    }
                    
                    vector(const vector<T>& source)
                    {
                        buffer = NULL;
                        _size = 0;
                        resize(source.size());
                        
                        for(unsigned int i = 0; i < _size; i++)
                        {
                            buffer[i] = source[i];
                        }
                    }
                
                    vector(const T* source, unsigned int size)
                    {
                        buffer = NULL;
                        _size = 0;
                        resize(size);
                        for(unsigned int i = 0; i < _size; i++)
                        {
                            buffer[i] = source[i];
                        }
                    }
                    
                    ~vector()
                    {
                        Clear();
                    }
                //
                ///////////////////////////////////////////////////////////////////////
                // Const Return Functions
                //
                ///////////////////////////////////////////////////////////////////////
                // Operators
                
                    operator T*() {return buffer;}
                    operator T*() const{return buffer;}
                    
                    T& operator[](int x){return buffer[x];}
                    T operator [](int x) const{return buffer[x];}
                    
                    
                    vector& operator=(const vector& source)
                    {
                        if(this == &source){return *this;}
                        
                        resize(source.size());
                        
                        for(unsigned int i = 0; i < _size; i++)
                        {
                            buffer[i] = source[i];
                        }
                        return *this;
                    }

                    bool operator==(const vector& source) const
                    {
                        if(*this == source){return 1;}
                        
                        if(_size != source.size()){return 0;}
                        
                        for(unsigned int i = 0; i < _size; i++)
                        {
                            if(buffer[i] != source[i])
                            {return 0;}
                        }
                        return 1;
                    }
                //
                ///////////////////////////////////////////////////////////////////////
                // Setting Functions
                
                    const unsigned int size() const
                    {
                        return _size;
                    }

                    bool resize(unsigned int new_size)
                    {
                        if(_size == new_size){return 1;}
                        
                        T* tmp = NULL;
                        
                        tmp = new T[new_size];
                        if(tmp==NULL){return 0;}
                        else
                        {
                            unsigned int min = new_size;
                            if(_size<new_size){min = _size;}
                            
                            for(unsigned int i = 0; i < min; i++)
                            {
                                tmp[i] = buffer[i];
                            }

                            delete[] buffer;
                            buffer = tmp;
                            _size = new_size;
                            return 1;
                        }
                    }

                    void Clear()
                    {
                        delete[] buffer;
                        buffer = NULL;
                        _size = 0;
                    }

                    void clear()
                    {
                        Clear();
                    }
                //
                ///////////////////////////////////////////////////////////////////////
                // Functionality
                
                    void copy(const T* source, unsigned int len, unsigned int offset = 0, bool copyLength = 0)
                    {
                        if(copyLength == 1){resize(len);}
                        
                        unsigned int min = len;
                        if(_size<len){min = _size;}
                        
                        for(unsigned int i = offset; i < min; i++)
                        {
                            buffer[i] = source[i];
                        }
                    }
                    
                    void push_back(const T& data)
                    {
                        resize(_size + 1);
                        buffer[_size - 1] = data;
                    }
                    
                    T pop(unsigned int postion = 0)
                    {
                        T x = buffer[postion];
                        for(unsigned int i = postion; i < _size-1; i++)
                        {
                            buffer[i] = buffer[i+1];
                        }
                        resize(_size-1);
                        return x;
                    }
                    
                    T pop_first()
                    {
                        T x = buffer[0];
                        for(unsigned int i = 0; i < _size-1; i++)
                        {
                            buffer[i] = buffer[i+1];
                        }
                        resize(_size-1);
                        return x;
                    }

                    T pop_back()
                    {
                        T x = buffer[_size-1];
                        resize(_size-1);
                        return x;
                    }
                    
                    void emplace(T data, unsigned int position)
                    {
                        resize(_size+1);
                        for(unsigned int i = 0 ; i < (_size - position - 1) ; i++)
                        {
                            buffer[position+i+1] = buffer[position+i];
                        }
                        buffer[position] = data;
                    }

                    void swap(unsigned int a, unsigned int b)
                    {
                        if(a == b){return;}
                        T c = buffer[a];
                        buffer[a] = buffer[b];
                        buffer[b] = c;
                    }

                    unsigned int get_pos(T* source)
                    {
                        for(unsigned int i = 0; i < _size;i++)
                        {
                            if(&buffer[i] == source)
                            {
                                return i;
                            }
                        }
                        return -1;
                    }

                    void erase(unsigned int position)
                    {
                        if(position < _size)
                        {
                            for(unsigned int i = 0; i < _size - position - 1;i++)
                            {
                                buffer[position] = buffer[position+1];
                            }
                            resize(size()-1);
                        }
                    }

                    void erase(T* source)
                    {
                        for(unsigned int i = 0; i < _size;i++)
                        {
                            if(&buffer[i] == source)
                            {
                                for(unsigned int j = i; j < _size-1; j++)
                                {
                                    buffer[j] = buffer[j+1];
                                }
                                resize(_size-1);
                                i=_size;
                            }
                        }
                    }
                //
                ///////////////////////////////////////////////////////////////////////
                // Sorting

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    // In order for these to work the element T must have declared the <, >, and the == operators.
                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    void SortAscending()
                    {
                        Sort(Sorting::Ascending);
                    }
                    
                    void SortDescending()
                    {
                        Sort(Sorting::Descending);
                    }
                    
                    void Sort(int (*CompareFunction)(const T& a, const T& b))
                    {
                        _CustomSort_Helper(CompareFunction, 0, size()-1);
                    }
                    
                    void Sort(Sorting::SortingArray<T> SortingArray)
                    {
                        _CustomSort_Helper(SortingArray, 0, size()-1);
                    }
                //
                ///////////////////////////////////////////////////////////////////////

            private:

                ///////////////////////////////////////////////////////////////////////
                // Sorting Helpers

                    void _CustomSort_Helper(int (*CompareFunction)(const T& a, const T& b), unsigned int lower, unsigned int upper)
                    {
                        // Limits check
                        if(lower > upper)
                        {
                            unsigned int tmp = lower;
                            lower = upper;
                            upper = lower;
                        }

                        // Calculate new Pivot
                        unsigned int pivot = lower;
                        pivot = _CustomSort_Partition(CompareFunction,lower,upper,pivot);
                        
                        // Recursive calls
                        if(pivot > 0){_CustomSort_Helper(CompareFunction,lower,pivot-1);}
                        if(pivot < upper)_CustomSort_Helper(CompareFunction,pivot+1,upper);
                    }
                    
                    unsigned int _CustomSort_Partition(int (*CompareFunction)(const T& a, const T& b), unsigned int lower, unsigned int upper, unsigned int pivot)
                    {
                        // Store Pivot value at the Highest index (upper limit)
                        swap(pivot,upper);
                        
                        // Initialize the exchange index at the lower limit
                        int index = lower;

                        // Cycle through each element
                        for(int i = lower ; i < upper; i++)
                        {
                            // Comparing the n'th element against the pivot 
                            if(CompareFunction(buffer[i],buffer[upper]) == 1)
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
                    
                    void _CustomSort_Helper(Sorting::SortingArray<T> SortingArray, unsigned int lower, unsigned int upper)
                    {
                        // Limits check
                        if(lower > upper)
                        {
                            unsigned int tmp = lower;
                            lower = upper;
                            upper = lower;
                        }

                        // Calculate new Pivot
                        unsigned int pivot = lower;
                        pivot = _CustomSort_Partition(SortingArray,lower,upper,lower);
                        
                        // Recursive calls
                        if(pivot > 0){_CustomSort_Helper(SortingArray,lower,pivot-1);}
                        if(pivot < upper)_CustomSort_Helper(SortingArray,pivot+1,upper);
                        
                    }
                    
                    unsigned int _CustomSort_Partition(Sorting::SortingArray<T> CompareVector, unsigned int lower, unsigned int upper, unsigned int pivot)
                    {
                        // Store Pivot value at the Highest index (upper limit)
                        swap(pivot,upper);
                        
                        // Initialize the exchange index at the lower limit
                        int index = lower;

                        // Cycle through each element
                        for(int i = lower ; i < upper; i++)
                        {
                            // Comparing the n'th element against the pivot 
                            if(CompareVector.Evaluate(buffer[i],buffer[upper]) == 1)
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
                ///////////////////////////////////////////////////////////////////////
        };
    }


#endif//CROSS_PLATFFORM_VECTOR_TEMPLATE_H