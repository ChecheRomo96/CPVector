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
// CopyConstructor

	TEST(ConstructorTesting, CopyConstructor) {

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
// resize

	TEST(BasicFunctionalityTesting, resize) {

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

	TEST(BasicFunctionalityTesting, resize_initialization) {

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

	TEST(BasicFunctionalityTesting, clear) {

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
// dynamicAllocation1

	TEST(DynamicAllocationTesting, VectorPointerToObject) {

		CPVector::vector<uint8_t>* myVectorptr = nullptr;

		EXPECT_EQ((void*)myVectorptr,nullptr);
		
		myVectorptr = new CPVector::vector<uint8_t>(12);

		ASSERT_NE(myVectorptr,nullptr);

		EXPECT_EQ(myVectorptr->size(),12);

		delete(myVectorptr);
	}
//
//////////////////////////////////////////////////////////////////////////////////
// dynamicAllocation2

	TEST(DynamicAllocationTesting, VectorPointerToArray) {

		CPVector::vector<uint8_t>* myVectorptr = nullptr;

		EXPECT_EQ((void*)myVectorptr,nullptr);
		
		myVectorptr = new CPVector::vector<uint8_t>[8];

		ASSERT_NE(myVectorptr,nullptr);

		for(uint8_t i = 0; i < 8; i++)
		{
			myVectorptr[i] = CPVector::vector<uint8_t>(8);
			ASSERT_EQ(myVectorptr[i].size(), 8);

		    for(uint8_t j = 0; j < 8; j++) 
		    {    
				myVectorptr[i][j] = (8*i) + j;
		    }
		}
		
		for(uint8_t i = 0; i < 8; i++)
		{
		    for(uint8_t j = 0; j < 8; j++) 
		    {
		        EXPECT_EQ(myVectorptr[i][j], (8*i) + j);
		    }
		}

		delete[] myVectorptr;
	}
//
//////////////////////////////////////////////////////////////////////////////////
// dynamicAllocation3

	TEST(DynamicAllocationTesting, VectorOfVectors) {
		CPVector::vector<CPVector::vector<uint8_t>> myVector(8);

		ASSERT_EQ(myVector.size(),8);

		for(uint8_t i = 0; i < myVector.size(); i++)
		{
			ASSERT_EQ(myVector[i].size(),0);

			myVector[i].resize(8);
			ASSERT_EQ(myVector[i].size(),8);

			for(uint8_t j = 0; j < myVector[i].size(); j++)
			{
				myVector[i][j] = (8*i) + j;
				EXPECT_EQ(myVector[i][j], (8*i) + j);
			}
		}

		for(uint8_t i = 0; i < myVector.size(); i++)
		{
			for(uint8_t j = 0; j < myVector[i].size(); j++)
			{
				myVector[i][j] = (8*i) + j;
				EXPECT_EQ(myVector[i][j], (8*i) + j);
			}
			myVector[i].clear();
		}

		myVector.clear();
	}
//
//////////////////////////////////////////////////////////////////////////////////
// copy

	TEST(BasicFunctionalityTesting, copy) {

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

	TEST(BasicFunctionalityTesting, push_back) {

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
// pop

	TEST(BasicFunctionalityTesting, pop) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;
		myVector.copy(Data,UINT8_MAX,0,1);

		ASSERT_EQ(myVector.size(),UINT8_MAX);

		uint8_t counter = 0;
		while(myVector.size() > 0)
		{
			EXPECT_EQ(myVector.pop(),counter++);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// pop_first

	TEST(BasicFunctionalityTesting, pop_first) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;
		myVector.copy(Data,UINT8_MAX,0,1);

		ASSERT_EQ(myVector.size(),UINT8_MAX);

		uint8_t counter = 0;
		while(myVector.size() > 0)
		{
			EXPECT_EQ(myVector.pop_first(),counter++);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// pop_back

	TEST(BasicFunctionalityTesting, pop_back) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;
		myVector.copy(Data,UINT8_MAX,0,1);

		ASSERT_EQ(myVector.size(),UINT8_MAX);

		uint8_t counter = UINT8_MAX-1;
		while(myVector.size() > 0)
		{
			EXPECT_EQ(myVector.pop_back(),counter--);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// emplace

	TEST(BasicFunctionalityTesting, emplace) {

		CPVector::vector<uint8_t> myVector;

		EXPECT_EQ(myVector.size(),0);

		uint8_t counter = 0;
		while(myVector.size() > 0)
		{
			myVector.emplace(counter,0);
			EXPECT_EQ(myVector[0],counter++);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// swap

	TEST(BasicFunctionalityTesting, swap) {

		CPVector::vector<uint8_t> myVector;
		EXPECT_EQ(myVector.size(),0);

		uint8_t counter = 0;
		for(uint8_t i = 0; i < 10; i++)
		{
			myVector.push_back(i);
		}

		for(uint8_t i = 0; i < 5; i++)
		{
			myVector.swap(i,9-i);
		}

		for(uint8_t i = 0; i < 10; i ++)
		{
			EXPECT_EQ(myVector[i],9-i);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
// erase

	TEST(BasicFunctionalityTesting, erase) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;
		myVector.copy(Data,UINT8_MAX,0,1);

		uint8_t counter = 0;
		
		while(myVector.size() > 0)
		{
			EXPECT_EQ(myVector[0],counter++);
			myVector.erase(0);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////