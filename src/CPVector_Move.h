/**
 * @file CPVector_Template.h
 * @brief CPVector::vector<> class template
 */
#ifndef CROSS_PLATFFORM_VECTOR_MOVE_H
#define CROSS_PLATFFORM_VECTOR_MOVE_H

    #include "CPVector_BuildSettings.h"
    #include "Sorting/CPVector_Sorting.h"

    namespace CPVector
    {

        #ifndef(CPVECTOR_USING_STD) 
            template <class T>
            struct remove_reference{ typedef T type; };

            template <class T>
            struct remove_reference<T&> { typedef T type; };

            template <class T>
            struct remove_reference<T&&> { typedef T type; };
        #endif

        template <typename T>
        typename remove_reference<T>::type&& move(T&& arg)
        {

            #if defined(CPVECTOR_USING_STD) 
              return static_cast<typename std::remove_reference<T>::type&&>(arg);
            #else
              return static_cast<typename CPVector::remove_reference<T>::type&&>(arg);
            #endif

        }

    }

#endif//CROSS_PLATFFORM_VECTOR_MOVE_H