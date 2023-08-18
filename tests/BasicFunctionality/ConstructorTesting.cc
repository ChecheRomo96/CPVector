#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
// DefaultConstructor

	TEST(ConstructorTesting, DefaultConstructor) {

		CPVector::vector<uint8_t> myVector;
		ASSERT_EQ(myVector.size(),0);
	}
//
//////////////////////////////////////////////////////////////////////////////////
// ResizeConstructor

	TEST(ConstructorTesting, ResizeConstructor) {

		CPVector::vector<uint8_t> myVector(20);
		ASSERT_EQ(myVector.size(),20);
	}
//
//////////////////////////////////////////////////////////////////////////////////
// CopyConstructor

	TEST(ConstructorTesting, CopyConstructor) {

		CPVector::vector<uint8_t> myVector(20);
		ASSERT_EQ(myVector.size(),20);

		for(uint8_t i = 0; i < myVector.size(); i++)
		{
			myVector[i] = i;
		}

		CPVector::vector<uint8_t> myVector2(myVector);

		for(uint8_t i = 0; i < myVector.size(); i++)
		{
			EXPECT_EQ(myVector[i], myVector2[i]);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// CopyConstructor2

	TEST(ConstructorTesting, CopyConstructor2) {

		uint8_t Data[UINT8_MAX] = {};

		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;

		}

		CPVector::vector<uint8_t> myVector(Data, UINT8_MAX);
		ASSERT_EQ(myVector.size(),UINT8_MAX);

		for(uint8_t i = 0; i < myVector.size(); i++)
		{
			EXPECT_EQ(myVector[i], i);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////