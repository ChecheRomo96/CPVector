/**
 * @brief      This file implements CP Vector Exceptions.
 *
 * @author     Josem
 * @date       2023
 */
#ifndef CPVECTOR_EXCEPTIONS_H
#define CPVECTOR_EXCEPTIONS_H

	#include "CPVector_BuildSettings.h"

	#ifdef CPVECTOR_EXCEPTIONS_ENABLED
		namespace CPVector{

		/**
		 * @defgroup   CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions
		 * @{
		 */

			/**
			 * @brief      Exception for signaling  errors.
			 */
			class exception : public std::exception {
			public:
			    exception() : std::exception(){}

			    const char* what() const throw() {
			        return "CPVector::exception";
			    }
			};

			/**
			 * @brief      This class describes a logic error.
			 */
			class logic_error : public std::logic_error {
			public:
			    logic_error() : std::logic_error(what()){}
			    logic_error(const std::string& what_arg) : std::logic_error(what_arg){}
			    logic_error(const char* what_arg) : std::logic_error(what_arg){}
			    logic_error(const logic_error& other) noexcept: std::logic_error(other){}

			    const char* what() const throw() {
			        return "CPVector::logic_error";
			    }
			};




			/**
			 * @brief      This class describes a bad allocation.
			 */
			class bad_alloc : public CPVector::exception {
			public:
			    bad_alloc(): CPVector::exception(){}
			    bad_alloc(const bad_alloc& other) noexcept: CPVector::exception(){}

			    const char* what() const throw() {
			        return "CPVector::bad_alloc";
			    }
			};

			/**
			 * @brief      This class describes an allocation error.
			 */
			class allocation_error : public CPVector::exception {
			public:
			    allocation_error(){}
			    allocation_error(const allocation_error& other) noexcept: CPVector::exception(){}

			    const char* what() const throw() {
			        return "CPVector::allocation_error";
			    }
			};




			/**
			 * @brief      This class describes an index out of range.
			 */
			class index_out_of_range : public CPVector::logic_error {
			public:
			    index_out_of_range() : CPVector::logic_error(what()){}
			    index_out_of_range(const std::string& what_arg) : CPVector::logic_error(what_arg){}
			    index_out_of_range(const char* what_arg) : CPVector::logic_error(what_arg){}
			    index_out_of_range(const index_out_of_range& other) noexcept: CPVector::logic_error(other){}

			    const char* what() const throw() {
			        return "CPVector::index_out_of_range";
			    }
			};

			/**
			 * @brief      This class describes a length error.
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

		/**
		 * @}
		 */
		}
	#endif
		
#endif//CPVECTOR_EXCEPTIONS_H