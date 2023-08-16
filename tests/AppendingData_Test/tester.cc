#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

// Demonstrate some basic assertions.
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