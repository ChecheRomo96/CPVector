#ifndef EMBEDDED_VECTOR_TEMPLATE_H
#define EMBEDDED_VECTOR_TEMPLATE_H

    #include "EmbeddedVector_BuildSettings.h"

    namespace EVector
    {
        template <class T>
        class Vector;
        
        template <class T>
        bool _Compare_Ascending(const T& a, const T& b)
        {
            if(a<b){return 1;}
            else{return 0;}
        }
        
        template <class T>
        bool _Compare_Descending(const T& a, const T& b)
        {
            if(a>b){return 1;}
            else{return 0;}
        }
        
        template <class T>
        class CompareArray
        {
            EVector::Vector<int8_t(*)(const T& a, const T& b)> buffer;
            
            public:
            
                CompareArray()
                {
                }
            
                ~CompareArray()
                {
                }
            
                void Append(int8_t(*Fn)(const T& a, const T& b))
                {
                    buffer.push_back(Fn);
                }
            
                void Delete(uint n)
                {
                    if(n<buffer.size())
                    {
                        buffer.erase(n);
                    }
                }
            
            const EVector::Vector<int8_t(*)(const T& a, const T& b)> FunctionArray() const{return buffer;}
        };

        template <class T>
        class  Vector
        {
            uint _size;
            T* buffer;
            
            public:
                
                ///////////////////////////////////////////////////////////////////////
                // Constructors , Destructor and Clear functions
                
                Vector()
                {
                    buffer = NULL;
                    _size = 0;
                }
                
                Vector(uint _size)
                {
                    buffer = NULL;
                    _size = 0;
                    SetSize(_size);
                }
                
                Vector(const Vector<T>& source)
                {
                    buffer = NULL;
                    _size = 0;
                    SetSize(source.Size());
                    
                    for(uint i = 0; i < _size; i++)
                    {
                        buffer[i] = source[i];
                    }
                }
            
                Vector(const T* source, uint size)
                {
                    buffer = NULL;
                    _size = 0;
                    SetSize(size);
                    for(uint i = 0; i < _size; i++)
                    {
                        buffer[i] = source[i];
                    }
                }
                
                ~Vector()
                {
                    Clear();
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
                
                ///////////////////////////////////////////////////////////////////////
                // Const Return Functions
                
                const uint Size() const{return _size;}
                const uint size() const{return _size;}
                
                ///////////////////////////////////////////////////////////////////////
                // Operators
                
                operator T*() {return buffer;}
                operator T*() const{return buffer;}
                
                T& operator[](int x){return buffer[x];}
                T operator [](int x) const{return buffer[x];}
                
                
                Vector& operator=(const Vector& source)
                {
                    if(this == &source){return *this;}
                    
                    SetSize(source.size());
                    
                    for(uint i = 0; i < _size; i++)
                    {
                        buffer[i] = source[i];
                    }
                    return *this;
                }

                bool operator==(const Vector& source) const
                {
                    if(*this == source){return 1;}
                    
                    if(_size != source.Size()){return 0;}
                    
                    for(uint i = 0; i < _size; i++)
                    {
                        if(buffer[i] != source[i])
                        {return 0;}
                    }
                    return 1;
                }
                
                ///////////////////////////////////////////////////////////////////////
                // Setting Functions
                
                bool SetSize(uint new_size)
                {
                    if(_size == new_size){return 1;}
                    
                    T* tmp = NULL;
                    
                    tmp = new T[new_size];
                    if(tmp==NULL){return 0;}
                    else
                    {
                        uint min = new_size;
                        if(_size<new_size){min = _size;}
                        
                        for(uint i = 0; i < min; i++)
                        {
                            tmp[i] = buffer[i];
                        }

                        delete[] buffer;
                        buffer = tmp;
                        _size = new_size;
                        return 1;
                    }
                }

                bool resize(uint new_size)
                {
                    return SetSize(new_size);
                }

                ///////////////////////////////////////////////////////////////////////
                // Functionality
                
                void copy(const T* source, uint len, uint offset = 0, bool copyLength = 0)
                {
                    if(copyLength == 1){SetSize(len);}
                    
                    uint min = len;
                    if(_size<len){min = _size;}
                    
                    for(uint i = offset; i < min; i++)
                    {
                        buffer[i] = source[i];
                    }
                }
                
                void push_back(const T& data)
                {
                    SetSize(_size + 1);
                    buffer[_size - 1] = data;
                }
                
                T pop(uint postion = 0)
                {
                    T x = buffer[postion];
                    for(uint8_t i = postion; i < _size-1; i++)
                    {
                        buffer[i] = buffer[i+1];
                    }
                    SetSize(_size-1);
                    return x;
                }
                
                T pop_first()
                {
                    T x = buffer[0];
                    for(uint8_t i = 0; i < _size-1; i++)
                    {
                        buffer[i] = buffer[i+1];
                    }
                    SetSize(_size-1);
                    return x;
                }

                T pop_back()
                {
                    T x = buffer[_size-1];
                    SetSize(_size-1);
                    return x;
                }
                
                void emplace(T data, uint position)
                {
                    SetSize(_size+1);
                    for(uint i = 0; i < _size-position-1;i++)
                    {
                        buffer[position+i+1] = buffer[position+i];
                    }
                    buffer[position] = data;
                }

                uint get_pos(T* source)
                {
                    for(uint8_t i = 0; i < _size;i++)
                    {
                        if(&buffer[i] == source)
                        {
                            return i;
                        }
                    }
                    return -1;
                }

                void erase(uint position)
                {
                    if(position < _size)
                    {
                        for(uint8_t i = 0; i < _size - position - 1;i++)
                        {
                            buffer[position] = buffer[position+1];
                        }
                        SetSize(Size()-1);
                    }
                }

                void erase(T* source)
                {
                    for(uint8_t i = 0; i < _size;i++)
                    {
                        if(&buffer[i] == source)
                        {
                            for(uint8_t j = i; j < _size-1; j++)
                            {
                                buffer[j] = buffer[j+1];
                            }
                            SetSize(_size-1);
                            i=_size;
                        }
                    }
                }

                void swap(uint a, uint b)
                {
                    if(a == b){return;}
                    T c = buffer[a];
                    buffer[a] = buffer[b];
                    buffer[b] = c;
                }

                void SortAscending()
                {
                    _CustomSort_Helper(EVector::_Compare_Ascending, 0, size()-1);
                }
                
                void SortDescending()
                {
                    _CustomSort_Helper(EVector::_Compare_Descending, 0, size()-1);
                }
                
                void Sort(bool (*Compare)(const T& a, const T& b))
                {
                    _CustomSort_Helper(Compare, 0, size()-1);
                }
                
                void Sort(CompareArray<T> Compare)
                {
                    _CustomSort_Helper(Compare, 0, size()-1);
                }

                private:

                    void _CustomSort_Helper(bool (*Compare)(const T& a, const T& b), uint lower, uint upper)
                    {
                        if(lower<upper)
                        {
                            uint pivot = lower;
                            uint index = _CustomSort_Partition(Compare,lower,upper,pivot);
                            
                            if(index > 0){_CustomSort_Helper(Compare,lower,index-1);}
                            if(index < upper)_CustomSort_Helper(Compare,index+1,upper);
                        }
                    }
                    
                    uint _CustomSort_Partition(bool (*Compare)(const T& a, const T& b), uint lower, uint upper, uint pivot)
                    {
                        swap(pivot,upper);
                        
                        int index = lower;

                        for(int i = lower ; i < upper; i++)
                        {
                            if(Compare(buffer[i],buffer[upper]))
                            {
                                if(index != i)
                                {
                                    swap(index,i);
                                }
                                index++;
                            }
                        }
                        swap(index,upper);
                        return index;
                    }
                    
                    void _CustomSort_Helper(CompareArray<T> Compare, uint lower, uint upper)
                    {
                        if(lower<upper)
                        {
                            uint pivot = lower;
                            uint index = _CustomSort_Partition(Compare,lower,upper,pivot);
                            
                            if(index > 0){_CustomSort_Helper(Compare,lower,index-1);}
                            if(index < upper)_CustomSort_Helper(Compare,index+1,upper);
                        }
                    }
                    
                    uint _CustomSort_Partition(CompareArray<T> Compare, uint lower, uint upper, uint pivot)
                    {
                        swap(pivot,upper);
                        
                        int index = lower;
                        
                        uint count;
                        
                        for(int i = lower ; i < upper; i++)
                        {
                            count = 0;
                            
                            bool flag = 1;
                            int8_t compare;
                            while(flag)
                            {
                                compare = Compare.FunctionArray()[count](buffer[i],buffer[upper]);
                                
                                if(compare == 0)
                                {
                                    count++;
                                    if(count==Compare.FunctionArray().size()){flag = 0;}
                                }
                                else if(compare == 1)
                                {
                                    if(index != i)
                                    {
                                        swap(index,i);
                                    }
                                    index++;
                                    flag = 0;
                                }
                                else if(compare == -1)
                                {
                                    flag = 0;
                                }
                            }
                        }
                        swap(index,upper);
                        return index;
                    }
        };
    }


#endif//EMBEDDED_VECTOR_TEMPLATE_H
