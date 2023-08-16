#include <gtest/gtest.h>
#include <CPVector.h>

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
		EXPECT_THAT(myVector[i],i);
	}

}