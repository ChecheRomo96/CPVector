#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
// resize

	TEST(SortingTesting, Ascending) {

		
		CPVector::vector<uint8_t> myVector(UINT8_MAX);
		ASSERT_EQ(myVector.size(), UINT8_MAX);

		for(uint8_t i = 0; i < myVector.size(); i++ )
		{
			myVector[i] = rand();
		}

		myVector.SortAscending();

		for(uint8_t i = 0; i < myVector.size()-1; i++ )
		{
			EXPECT_LE(myVector[i], myVector[i+1]);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////