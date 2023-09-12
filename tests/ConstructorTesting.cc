#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the default constructor of the CPVector class.
//! The purpose of this test is to verify that the default constructor correctly
//! initializes an empty vector with a size of zero.\n\n
//! The test is expected to pass if the assertion holds true, demonstrating that
//! the default constructor effectively creates an empty vector with a size of zero.

	TEST(ConstructorTesting, DefaultConstructor) {
		CPVector::vector<uint8_t> myVector;
		ASSERT_EQ(myVector.size(),0);
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the resize constructor of the CPVector class.
//! The purpose of this test is to verify that the resize constructor correctly
//! initializes a vector with the specified size.\n\n
//! The test is expected to pass if the assertion holds true, demonstrating that
//! the resize constructor effectively creates a vector with the specified size.


	TEST(ConstructorTesting, ResizeConstructor) {
		CPVector::vector<uint8_t> myVector(20);
		ASSERT_EQ(myVector.size(),20);
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the copy constructor of the CPVector class.
//! The purpose of this test is to verify that the copy constructor correctly
//! initializes a new vector by copying the content of an existing vector.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the copy constructor effectively creates a new vector with content identical
//! to the original vector.

	TEST(ConstructorTesting, CopyConstructor) {
		CPVector::vector<uint8_t> myVector(20);
		ASSERT_EQ(myVector.size(),20);

		for(uint8_t i = 0; i < myVector.size(); i++){
			myVector[i] = i;
		}

		CPVector::vector<uint8_t> myVector2(myVector);

		for(uint8_t i = 0; i < myVector.size(); i++){
			EXPECT_EQ(myVector[i], myVector2[i]);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// CopyConstructor2

	TEST(ConstructorTesting, CopyConstructor2) {

		uint8_t Data[UINT8_MAX] = {};

		for(uint8_t i = 0; i < UINT8_MAX; i++ ){
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector(Data, UINT8_MAX);
		ASSERT_EQ(myVector.size(),UINT8_MAX);

		for(uint8_t i = 0; i < myVector.size(); i++){
			EXPECT_EQ(myVector[i], i);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the copy constructor of the CPVector class with a
//! range of data.
//! The purpose of this test is to verify that the copy constructor correctly
//! initializes a new vector by copying a range of data from an external array.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the copy constructor effectively creates a new vector with content identical
//! to the specified data range.

	TEST(ConstructorTesting, MoveConstructor) {

		static const uint8_t values[] = {0, 1, 2};
		CPVector::vector<uint8_t> myVector(values, 3);
		ASSERT_EQ(myVector.size(),3);

		for(uint8_t i = 0; i < myVector.size(); i++){
			EXPECT_EQ(myVector[i], i);
		}

		CPVector::vector<uint8_t> myVec2 = CPVector::move(myVector);

		EXPECT_EQ(myVector.size(), 0);
		EXPECT_EQ(myVector.capacity(), 0);

		for (uint8_t i = 0; i < myVec2.size(); i++){
			EXPECT_EQ(myVec2[i], i);
		}

	}
//
//////////////////////////////////////////////////////////////////////////////////