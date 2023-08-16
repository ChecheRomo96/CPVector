#include <gtest/gtest.h>
#include <crtdbg.h>
#include <CPVector.h>
#include <iostream>

class MemoryLeakDetector
{
	public:
	    MemoryLeakDetector() {
	        _CrtMemCheckpoint(&memState_);
	    }

	    ~MemoryLeakDetector() {
	        _CrtMemState stateNow, stateDiff;
	        _CrtMemCheckpoint(&stateNow);
	        int diffResult = _CrtMemDifference(&stateDiff, &memState_, &stateNow);
	        if (diffResult)
	            reportFailure(stateDiff.lSizes[1]);
	    }
	private:
	    void reportFailure(unsigned int unfreedBytes) {
	        FAIL() << "Memory leak of " << unfreedBytes << " byte(s) detected.";
	    }
	    _CrtMemState memState_;
};

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
// dynamicAllocation1

	TEST(CPVectorTests, dynamicAllocation1) {

		MemoryLeakDetector leakDetector;

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

	TEST(CPVectorTests, dynamicAllocation2) {

		MemoryLeakDetector leakDetector;

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

	TEST(CPVectorTests, dynamicAllocation3) {

		MemoryLeakDetector leakDetector;
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
			//myVector[i].clear();
		}

		myVector.clear();
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