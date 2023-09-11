#include <gtest/gtest.h>
#include <CPVector.h>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the "reserve" functionality of the CPVector class.
//! The purpose of this test is to verify that the "reserve" method correctly
//! allocates memory to accommodate the specified capacity without affecting the
//! size of the vector.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "reserve" method correctly allocates memory as specified without changing
//! the size of the vector.

	TEST(BasicFunctionalityTesting, reserve) {

		CPVector::vector<uint8_t> myVector;
		ASSERT_EQ(myVector.size(),0);

		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			myVector.resize(i);
			ASSERT_EQ(myVector.size(),i);
			ASSERT_GE(myVector.capacity(),i);
		}

		myVector.clear();
		ASSERT_EQ(myVector.size(),0);
		ASSERT_EQ(myVector.capacity(),0);

		myVector.reserve(UINT8_MAX);
		ASSERT_EQ(myVector.size(),0);
		ASSERT_GE(myVector.capacity(),UINT8_MAX);

		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			myVector.resize(i);
			ASSERT_EQ(myVector.size(),i);
			ASSERT_GE(myVector.capacity(),UINT8_MAX);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the "resize" functionality of the CPVector class.
//! The purpose of this test is to verify that the "resize" method correctly
//! changes the size of the vector while maintaining its content integrity.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "resize" method effectively changes the size of the vector without
//! affecting the content's integrity.

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
//! @test
//! This test case assesses the "resize" functionality of the CPVector class with
//! initialization.
//! The purpose of this test is to verify that the "resize" method correctly
//! changes the size of the vector, initializes new elements, and maintains
//! existing content integrity.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "resize" method effectively changes the size of the vector, initializes
//! new elements to zero, and maintains the integrity of existing elements.

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
//! @test
//! This test case assesses the "clear" functionality of the CPVector class.
//! The purpose of this test is to verify that the "clear" method correctly
//! removes all elements from the vector, effectively resetting its size to zero.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "clear" method effectively removes all elements from the vector and resets
//! its size to zero.

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
//! @test
//! This test case assesses the "copy" functionality of the CPVector class.
//! The purpose of this test is to verify that the "copy" method correctly copies
//! a range of elements from an external data array into the vector.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "copy" method effectively copies the specified range of elements into the
//! vector, updating its size and content accordingly.

	TEST(BasicFunctionalityTesting, copy) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;

		myVector.copy(Data + 10, 10, 1);
		ASSERT_EQ(myVector.size(), 10);
		
		for(uint8_t i = 0; i < 10; i++ )
		{
			EXPECT_EQ(myVector[i],10+i);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the "push_back" functionality of the CPVector class.
//! The purpose of this test is to verify that the "push_back" method correctly
//! adds elements to the end of the vector, increments its size, and maintains
//! the integrity of the added elements.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "push_back" method effectively adds elements to the vector, increases its
//! size, and preserves the integrity of the added elements.

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
//! @test
//! This test case assesses the "pop" functionality of the CPVector class.
//! The purpose of this test is to verify that the "pop" method correctly removes
//! elements from the vector, decreases its size, and maintains the integrity of
//! the remaining elements.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "pop" method effectively removes elements from the vector, reduces its
//! size, and preserves the integrity of the remaining elements.

	TEST(BasicFunctionalityTesting, pop) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;
		myVector.copy(Data,UINT8_MAX,1);

		ASSERT_EQ(myVector.size(),UINT8_MAX);

		uint8_t counter = 0;
		while(myVector.size() > 0)
		{
			EXPECT_EQ(myVector[0],counter++);
			myVector.pop(0);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the "pop_first" functionality of the CPVector class.
//! The purpose of this test is to verify that the "pop_first" method correctly
//! removes the first element from the vector, decreases its size, and maintains
//! the integrity of the remaining elements.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "pop_first" method effectively removes the first element from the vector,
//! reduces its size, and preserves the integrity of the remaining elements.

	TEST(BasicFunctionalityTesting, pop_first) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;
		myVector.copy(Data,UINT8_MAX,1);

		ASSERT_EQ(myVector.size(),UINT8_MAX);

		uint8_t counter = 0;
		while(myVector.size() > 0)
		{
			EXPECT_EQ(myVector[0],counter++);
			myVector.pop_first();
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the "pop_back" functionality of the CPVector class.
//! The purpose of this test is to verify that the "pop_back" method correctly
//! removes the last element from the vector, decreases its size, and maintains
//! the integrity of the remaining elements.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "pop_back" method effectively removes the last element from the vector,
//! reduces its size, and preserves the integrity of the remaining elements.


	TEST(BasicFunctionalityTesting, pop_back) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ )
		{
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;
		myVector.copy(Data,UINT8_MAX,1);

		ASSERT_EQ(myVector.size(),UINT8_MAX);

		uint8_t counter = UINT8_MAX-1;
		while(myVector.size() > 0)
		{
			EXPECT_EQ(myVector[myVector.size()-1],counter--);
			myVector.pop_back();
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the "emplace" functionality of the CPVector class.
//! The purpose of this test is to verify that the "emplace" method correctly
//! inserts elements into the vector at the specified position, increments its
//! size, and maintains the integrity of the inserted elements.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "emplace" method effectively inserts elements into the vector, increases
//! its size, and preserves the integrity of the inserted elements.


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
//! @test
//! This test case assesses the "swap" functionality of the CPVector class.
//! The purpose of this test is to verify that the "swap" method correctly swaps
//! elements within the vector, maintaining their integrity.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "swap" method effectively swaps elements within the vector while
//! preserving the integrity of the swapped elements.

	TEST(BasicFunctionalityTesting, swap) {

		CPVector::vector<uint8_t> myVector;
		EXPECT_EQ(myVector.size(),0);

		uint8_t counter = 0;
		for(uint8_t i = 0; i < 10; i++){
			myVector.push_back(i);
		}

		for(uint8_t i = 0; i < 5; i++){
			myVector.swap(i,9-i);
		}

		for(uint8_t i = 0; i < 10; i ++){
			EXPECT_EQ(myVector[i],9-i);
		}
	}
//
//////////////////////////////////////////////////////////////////////////////////
//! @test
//! This test case assesses the "erase" functionality of the CPVector class.
//! The purpose of this test is to verify that the "erase" method correctly removes
//! elements from the vector at the specified position, decreases its size, and
//! maintains the integrity of the remaining elements.\n\n
//! The test is expected to pass if all assertions hold true, demonstrating that
//! the "erase" method effectively removes elements from the vector, reduces its
//! size, and preserves the integrity of the remaining elements.

	TEST(BasicFunctionalityTesting, erase) {

		uint8_t Data[UINT8_MAX] = {};
		for(uint8_t i = 0; i < UINT8_MAX; i++ ){
			Data[i] = i;
		}

		CPVector::vector<uint8_t> myVector;
		myVector.copy(Data,UINT8_MAX,1);

		uint8_t counter = 0;
		
		while(myVector.size() > 0){
			EXPECT_EQ(myVector[0],counter++);
			myVector.erase(0);
		}
	}
//
/////////////////////////////////////////////////////////////////////////////////