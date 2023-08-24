#include <iostream>
#include <CPVector.h>

int main()
{
    CPVector::vector<uint8_t> myVector1;
	myVector1.resize(20);

	for (uint16_t i = 0; i < myVector1.size(); i++)
	{
		myVector1[i] = rand();
		std::cout << (unsigned int)myVector1[i];
		if (i < myVector1.size() - 1) { std::cout << ", "; }
		else { std::cout << std::endl; }
	}
	
	myVector1.sortAscending();

	for (uint16_t i = 0; i < myVector1.size(); i++)
	{
		std::cout << (unsigned int)myVector1[i];
		if (i < myVector1.size() - 1) { std::cout << ", "; }
		else { std::cout << std::endl; }
	}

	myVector1.clear();

    return 0;
}