#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
// resize

	TEST(CPVectorTests, resize) {

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
// resize_initialization

	TEST(CPVectorTests, resize_initialization) {

		CPVector::vector<uint8_t> myVector;

		for(uint8_t i = 1; i < UINT8_MAX; i++ )
		{
			bool MemoryAllocationStatus = myVector.resize(i);
			ASSERT_EQ(MemoryAllocationStatus,1);
			EXPECT_EQ(myVector.size(),i);
			EXPECT_EQ(myVector[i-1],(uint8_t)0u);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// clear

	TEST(CPVectorTests, clear) {

		CPVector::vector<uint8_t> myVector;
		ASSERT_EQ(myVector.size(),0);

		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			myVector.resize(i);
			ASSERT_EQ(myVector.size(),i);
			myVector.clear();
			EXPECT_EQ(myVector.size(),0);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// new_delete

	TEST(CPVectorTests, new_delete) {

		CPVector::vector<uint8_t>* myVectorptr = nullptr;

		EXPECT_EQ((void*)myVectorptr,nullptr);
		
		myVectorptr = new CPVector::vector<uint8_t>(12);

		ASSERT_NE(myVectorptr,nullptr);

		EXPECT_EQ(myVectorptr->size(),12);

		delete(myVectorptr);
	}
//
//////////////////////////////////////////////////////////////////////////////////
// new_delete

	TEST(CPVectorTests, new_delete2) {

		CPVector::vector<uint8_t>* myVectorptr = nullptr;

		EXPECT_EQ((void*)myVectorptr,nullptr);
		
		myVectorptr = new CPVector::vector<uint8_t>[2];

		ASSERT_NE(myVectorptr,nullptr);

		for(uint8_t i = 0; i < 2; i++)
		{
			myVectorptr[i] = nullptr;
			myVectorptr[i] = new CPVector::vector<uint8_t>(2);

			ASSERT_NE(myVectorptr[i],nullptr);
			ASSERT_EQ(myVectorptr[i].size(),2);

			myVectorptr[i][0] = (2*i);
			myVectorptr[i][1] = (2*i) + 1;
		}

		for(uint8_t i = 0; i < 4; i++)
		{
			EXPECT_EQ(myVectorptr[i/2][i%2], i);
		}
		
		for(uint8_t i = 0; i < 2; i++)
		{
			delete(myVectorptr[i]);
		}

		delete(myVectorptr);
	}
//
//////////////////////////////////////////////////////////////////////////////////
// copy

	TEST(CPVectorTests, copy) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;

		myVector.copy(Data, 10, 10, 1);
		ASSERT_EQ(myVector.size(), 10);
		
		for(uint8_t i = 0; i < 10; i++ )
		{
			EXPECT_EQ(myVector[i],10+i);
		}

	}
//
//////////////////////////////////////////////////////////////////////////////////
// push_back

	TEST(CPVectorTests, push_back) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;

		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			myVector.push_back(Data[i]);
			ASSERT_EQ(myVector.size(),i+1);
			EXPECT_EQ(myVector[i],i);
		}

	}
//
//////////////////////////////////////////////////////////////////////////////////