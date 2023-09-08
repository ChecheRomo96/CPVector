/**
 * @defgroup   CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions
 * @author     Josem
 * @date       2023
 * @brief      This file implements CP Vector Exceptions.
 */
#ifndef CPVECTOR_EXCEPTIONS_H
#define CPVECTOR_EXCEPTIONS_H

	#include "CPVector_BuildSettings.h"

	#ifdef CPVECTOR_EXCEPTIONS_ENABLED
		namespace CPVector{


			/**
			 * @ingroup CPVECTOR_EXCEPTIONS
			 * @brief This class belongs to @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
			 */
			class exception : public std::exception {
			public:
			    exception() : std::exception(){}

			    const char* what() const throw() {
			        return "CPVector::exception";
			    }
			};

			/**
			 * @ingroup CPVECTOR_EXCEPTIONS
			 * @brief This class belongs to @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
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
			 * @ingroup CPVECTOR_EXCEPTIONS
			 * @brief This class belongs to @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
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
			 * @ingroup CPVECTOR_EXCEPTIONS
			 * @brief This class belongs to @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
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
			 * @ingroup CPVECTOR_EXCEPTIONS
			 * @brief This class belongs to @link CPVECTOR_EXCEPTIONS Cross Platform Vector Exceptions@endlink
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
	#endif
		
#endif//CPVECTOR_EXCEPTIONS_H