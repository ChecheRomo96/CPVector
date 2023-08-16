#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

// Demonstrate some basic assertions.
TEST(CPVectorTests, AppendingData) {


	uint8_t Data[100] = {};
	for(uint8_t i = 0; i < 100; i++ )
	{
		Data[i] = i;
	}

	CPVector::vector<uint8_t> myVector;


	for(uint8_t i = 0; i < 100; i++ )
	{
		myVector.push_back(Data[i]);
		std::cout<<(uint16_t)i<<" - "<<myVector[i]<<std::endl;
		EXPECT_GT(myVector[i],i);
	}

}