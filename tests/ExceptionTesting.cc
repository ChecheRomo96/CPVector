#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the exception handling in the CPVector class.
//! The purpose of this test is to verify that the CPVector::exception is correctly
//! thrown and that it contains the expected error message when an exception occurs.

    TEST(Exceptions, exception ){
        EXPECT_THROW({
            try
            {
                throw CPVector::exception();
            }
            catch( const CPVector::exception& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::exception", e.what() );
                throw;
            }
        }, CPVector::exception );
    }
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the exception handling in the CPVector class for
//! logic_error.
//! The purpose of this test is to verify that a CPVector::logic_error exception
//! is correctly thrown and that it contains the expected error message when such
//! an exception occurs. The test also checks that the thrown exception matches the
//! expected exception type.\n\n
//! The test is expected to pass if a CPVector::logic_error exception is thrown,
//! and its error message matches the expected message, while also verifying the
//! correctness of the thrown exception type.

    TEST(Exceptions, logic_error ){
        EXPECT_THROW({
            try
            {
                throw CPVector::logic_error();
            }
            catch( const CPVector::logic_error& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::logic_error", e.what() );
                throw;
            }
        }, CPVector::logic_error );
    }
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the exception handling in the CPVector class for
//! bad_alloc.
//! The purpose of this test is to verify that a CPVector::bad_alloc exception is
//! correctly thrown and that it contains the expected error message when such an
//! exception occurs. The test also checks that the thrown exception matches the
//! expected exception type.\n\n
//! The test is expected to pass if a CPVector::bad_alloc exception is thrown,
//! and its error message matches the expected message, while also verifying the
//! correctness of the thrown exception type.

    TEST(Exceptions, bad_alloc ){
        EXPECT_THROW({
            try
            {
                throw CPVector::bad_alloc();
            }
            catch( const CPVector::bad_alloc& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::bad_alloc", e.what() );
                throw;
            }
        }, CPVector::bad_alloc );
    }
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the exception handling in the CPVector class for
//! out_of_range.
//! The purpose of this test is to verify that a CPVector::out_of_range exception
//! is correctly thrown and that it contains the expected error message when such
//! an exception occurs. The test also checks that the thrown exception matches the
//! expected exception type.\n\n
//! The test is expected to pass if a CPVector::out_of_range exception is thrown,
//! and its error message matches the expected message, while also verifying the
//! correctness of the thrown exception type.

    TEST(Exceptions, out_of_range ){
        EXPECT_THROW({
            try
            {
                throw CPVector::out_of_range();
            }
            catch( const CPVector::out_of_range& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::out_of_range", e.what() );
                throw;
            }
        }, CPVector::out_of_range );
    }
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the exception handling in the CPVector class for
//! out_of_range when accessing an element out of range.
//! The purpose of this test is to verify that a CPVector::out_of_range exception
//! is correctly thrown and that it contains the expected error message when trying
//! to access an element beyond the valid range. The test also checks that the thrown
//! exception matches the expected exception type.\n\n
//! The test is expected to pass if a CPVector::out_of_range exception is thrown
//! while attempting to access an out-of-range element, and its error message
//! matches the expected message, while also verifying the correctness of the
//! thrown exception type.

    TEST(Exceptions, out_of_range2 ){
        EXPECT_THROW({
            try
            {
                CPVector::vector<uint8_t> vec(5);

                vec[5];
            }
            catch( const CPVector::out_of_range& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::out_of_range", e.what() );
                throw;
            }
        }, CPVector::out_of_range );
    }
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the exception handling in the CPVector class for
//! length_error.
//! The purpose of this test is to verify that a CPVector::length_error exception
//! is correctly thrown and that it contains the expected error message when such
//! an exception occurs. The test also checks that the thrown exception matches the
//! expected exception type.\n\n
//! The test is expected to pass if a CPVector::length_error exception is thrown,
//! and its error message matches the expected message, while also verifying the
//! correctness of the thrown exception type.

    TEST(Exceptions, length_error ){
        EXPECT_THROW({
            try
            {
                throw CPVector::length_error();
            }
            catch( const CPVector::length_error& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::length_error", e.what() );
                throw;
            }
        }, CPVector::length_error );
    }
//
//////////////////////////////////////////////////////////////////////////////////