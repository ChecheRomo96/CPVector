/**
 * @defgroup   CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions
 * @brief      This file implements the exceptions used on CPVector.
 * 
 * When the library employs the standard library (std), CPVector::exception is inherited from std::exception. This design ensures that exceptions can be caught without the need to explicitly catch any of the exceptions declared for this module.
 * In cases where the library does not utilize the standard library, a custom exception class is introduced. This class is designed to emulate and adhere to the behavior of C++11's std::exception class. \n\n
 * 
 * All exceptions generated by the CPVector library inherit from std::exception.\n
 */

#ifndef CPVECTOR_EXCEPTIONS_H
#define CPVECTOR_EXCEPTIONS_H

	#include "CPVector_BuildSettings.h"

	namespace CPVector{

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CPVector::exception

		#ifdef CPVECTOR_USING_STD_VECTOR_ALLOCATION
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//! @ingroup CPVECTOR_EXCEPTIONS
		//! @class CPVector::exception CPVector_Exceptions.h "src/CPVector_Exceptions.h"
		//! @brief  Standard CPVector exception class.
		//! 
		//! Provides consistent interface to handle errors through the throw expression.\n
		//! All exceptions generated by the CPVector library inherit from CPVector::exception.\n
		//! This class belongs to the group: @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
		
			class exception : public std::exception {
			public:
			    exception() noexcept: std::exception(){}
				exception (const exception&) noexcept{}
				exception& operator= (const exception&) noexcept{ return (*this); }

			    const char* what() const throw() {
			        return "CPVector::exception";
			    }
			};
		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		#else
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//! @ingroup CPVECTOR_EXCEPTIONS
		//! @class CPVector::exception CPVector_Exceptions.h "src/CPVector_Exceptions.h"
		//! @brief  Standard CPVector exception class.
		//! 
		//! Provides consistent interface to handle errors through the throw expression.\n
		//! All exceptions generated by the CPVector library inherit from CPVector::exception.\n
		//! This class belongs to the group: @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink

			class exception {
			public:
				exception () noexcept{}
				exception (const exception&) noexcept{}
				exception& operator= (const exception&) noexcept{}
				virtual ~exception(){};
				
				virtual const char* what() const noexcept{
			        return "CPVector::exception";
				}
			}
		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		#endif
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CPVector::logic_error
	// 
		namespace {
			const char logic_error_str[] = "CPVector::logic_error";
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//! @ingroup CPVECTOR_EXCEPTIONS
		//! @class CPVector::logic_error CPVector_Exceptions.h "src/CPVector_Exceptions.h"
		//! @brief  Logic error exception.
		//! 
		//! This class defines the type of objects thrown as exceptions to report errors in the internal logical of the program, such as violation of logical preconditions or class invariants.\n
		//! These errors are presumably detectable before the program executes.\n
		//! This class exceptions inherits from from CPVector::exception.\n
		//! This class belongs to the group: @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
		//
			class logic_error : public CPVector::exception {
			private:
				std::string _M_msg;
			public:
			    explicit logic_error() : exception(), _M_msg(logic_error_str){}
			    explicit logic_error(const std::string& __arg) : exception(), _M_msg(logic_error_str){ _M_msg += " ->" + __arg; }
			    explicit logic_error(const char* message) : exception(), _M_msg(logic_error_str){ _M_msg += " ->" + std::string(message); }

				~logic_error() throw() { }

			    explicit logic_error(const logic_error& other) noexcept{
			    	if(this != &other){
			    		_M_msg = other.what();
			    	}
			    }

			    const char* what() const throw(){ 
			    	return _M_msg.c_str(); 
			    }
			};
		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CPVector::bad_alloc

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//! @ingroup CPVECTOR_EXCEPTIONS
		//! @class CPVector::bad_alloc CPVector_Exceptions.h "src/CPVector_Exceptions.h"
		//! @brief  Exception thrown on failure allocating memory.
		//! 
		//! All exceptions generated by the CPVector library inherit from std::exception.\n
		//! This class belongs to @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
		//
			class bad_alloc : public CPVector::exception {
			public:
			    bad_alloc(): CPVector::exception(){}
			    bad_alloc(const bad_alloc& other) noexcept: CPVector::exception(){}

			    const char* what() const throw() {
			        return "CPVector::bad_alloc";
			    }
			};
		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CPVector::out_of_range

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//! @ingroup CPVECTOR_EXCEPTIONS
		//! @class CPVector::out_of_range CPVector_Exceptions.h "src/CPVector_Exceptions.h"
		//! @brief  Out-of-range exception.
		//! 
		//! All exceptions generated by the CPVector library inherit from std::exception.\n
		//! This class belongs to @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
		//

			class out_of_range : public CPVector::logic_error {
			public:
			    out_of_range() : CPVector::logic_error(what()){}
			    out_of_range(const std::string& what_arg) : CPVector::logic_error(what_arg){}
			    out_of_range(const char* what_arg) : CPVector::logic_error(what_arg){}
			    out_of_range(const out_of_range& other) noexcept: CPVector::logic_error(other){}

			    const char* what() const throw() {
			        return "CPVector::out_of_range";
			    }
			};
		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

		/**
		 * @ingroup CPVECTOR_EXCEPTIONS
		 * @brief This class belongs to @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
		 */
		class length_error : public CPVector::logic_error {
		public:
		    length_error() : CPVector::logic_error(what()){}
		    length_error(const std::string& what_arg) : CPVector::logic_error(what_arg){}
		    length_error(const char* what_arg) : CPVector::logic_error(what_arg){}
		    length_error(const logic_error& other) noexcept: CPVector::logic_error(other){}

		    const char* what() const throw() {
		        return "CPVector::length_error";
		    }
		};

	}
		
#endif//CPVECTOR_EXCEPTIONS_H