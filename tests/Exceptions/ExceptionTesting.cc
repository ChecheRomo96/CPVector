#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
// bad_alloc 1

    TEST(Exceptions, exception )
    {
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
// logic_error 1

    TEST(Exceptions, logic_error )
    {
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
// bad_alloc

    TEST(Exceptions, bad_alloc )
    {
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
// allocation_error

    TEST(Exceptions, allocation_error )
    {
        EXPECT_THROW({
            try
            {
                throw CPVector::allocation_error();
            }
            catch( const CPVector::allocation_error& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::allocation_error", e.what() );
                throw;
            }
        }, CPVector::allocation_error );
    }
//
//////////////////////////////////////////////////////////////////////////////////
// index_out_of_range

    TEST(Exceptions, index_out_of_range )
    {
        EXPECT_THROW({
            try
            {
                throw CPVector::index_out_of_range();
            }
            catch( const CPVector::index_out_of_range& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::index_out_of_range", e.what() );
                throw;
            }
        }, CPVector::index_out_of_range );
    }
//
//////////////////////////////////////////////////////////////////////////////////
// index_out_of_range

    TEST(Exceptions, index_out_of_range2 )
    {
        EXPECT_THROW({
            try
            {
                CPVector::vector<uint8_t> vec(5);

                vec[5];
            }
            catch( const CPVector::index_out_of_range& e )
            {
                // and this tests that it has the correct message
                EXPECT_STREQ( "CPVector::index_out_of_range", e.what() );
                throw;
            }
        }, CPVector::index_out_of_range );
    }
//
//////////////////////////////////////////////////////////////////////////////////
// length_error

    TEST(Exceptions, length_error )
    {
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