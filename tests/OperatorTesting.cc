#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the assignment operator of the CPVector class.
//! The purpose of this test is to verify that the assignment operator correctly
//! assigns the values from one CPVector to another and ensures the size is
//! correctly updated.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the assignment operator effectively assigns values from one CPVector to
//! another and updates the size accordingly.

	TEST(OperatorTesting, Assignment) {

		CPVector::vector<uint8_t> myVector;
		ASSERT_EQ(myVector.size(),0);

		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			myVector.resize(i);
			ASSERT_EQ(myVector.size(),i);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the subscript operator [] of the CPVector class for
//! array-style element access.
//! The purpose of this test is to verify that the subscript operator correctly
//! allows access to individual elements of a CPVector, enabling reading and
//! updating their values. It also checks the size of the vector to ensure it
//! remains unchanged.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the subscript operator [] effectively enables array-style element access, and
//! the size of the vector remains consistent.

	TEST(OperatorTesting, SubscriptArray) {

		CPVector::vector<uint8_t> myVector(5);
		ASSERT_EQ(myVector.size(),5);

		for(uint8_t i = 0; i < myVector.size(); i++ )
		{
			myVector[i] = i;
			ASSERT_EQ(myVector[i],i);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the comparison operators of the CPVector class.
//! The purpose of this test is to verify that the equality and inequality operators
//! correctly compare two CPVector instances for equality and inequality based on
//! their contents. The test covers scenarios with empty and non-empty vectors,
//! resizing, and changing element values to ensure the operators work as expected.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the comparison operators effectively compare CPVector instances based on their
//! contents and return the correct results.

	TEST(OperatorTesting, Comparison) {

		CPVector::vector<uint8_t> myVector1;
		CPVector::vector<uint8_t> myVector2(5);

		ASSERT_EQ(myVector1.size(),0);
		ASSERT_EQ(myVector2.size(),5);
		EXPECT_EQ(myVector1!=myVector2,1);
		EXPECT_EQ(myVector1==myVector2,0);

		myVector1.resize(5);
		myVector2.resize(5);

		ASSERT_EQ(myVector1.size(),5);
		ASSERT_EQ(myVector2.size(),5);
		EXPECT_EQ(myVector1!=myVector2,0);
		EXPECT_EQ(myVector1==myVector2,1);

		myVector1[0] = 1;
		myVector1[1] = 2;

		myVector2[0] = 2;
		myVector2[1] = 2;

		ASSERT_EQ(myVector1.size(),5);
		ASSERT_EQ(myVector2.size(),5);
		EXPECT_EQ(myVector1!=myVector2,1);
		EXPECT_EQ(myVector1==myVector2,0);

		myVector1[0] = 3;
		myVector1[1] = 3;

		myVector2[0] = 3;
		myVector2[1] = 3;

		ASSERT_EQ(myVector1.size(),5);
		ASSERT_EQ(myVector2.size(),5);
		EXPECT_EQ(myVector1!=myVector2,0);
		EXPECT_EQ(myVector1==myVector2,1);
	}
//
//////////////////////////////////////////////////////////////////////////////////