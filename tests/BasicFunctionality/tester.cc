#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

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
		std::cout<<(uint16_t)i<<" - "<<(uint16_t)myVector[i]<<std::endl;
		EXPECT_EQ(myVector[i],i);
	}

}

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

// resize
TEST(CPVectorTests, resize) {

	CPVector::vector<uint8_t> myVector;
	ASSERT_EQ(myVector.size(),0);

	for(uint8_t i = 0; i < UINT8_MAX; i++ )
	{
		myVector.resize(i);
		ASSERT_EQ(myVector.size(),i);
		myVector.clear();
		ASSERT_EQ(myVector.size(),0);
	}
}