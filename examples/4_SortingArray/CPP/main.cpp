#include <iostream>
#include <CPVector.h>

int8_t Sorting_EvenFirst(const uint8_t& Element, const uint8_t& Pivot)
{
  if( (Element%2) == (Pivot%2) ){return CPVector::Sorting::Equal;}
  else if((Element%2) == 0){return CPVector::Sorting::Swap;}
  return CPVector::Sorting::Ignore;
}

int main()
{
	CPVector::Sorting::SortingArray<uint8_t> SortConfig;
	SortConfig.Append(Sorting_EvenFirst);
	SortConfig.Append(CPVector::Sorting::Ascending);

    CPVector::vector<uint8_t> myVector1;
	myVector1.resize(20);

	for (uint16_t i = 0; i < myVector1.size(); i++)
	{
		myVector1[i] = rand();
		std::cout << (unsigned int)myVector1[i];
		if (i < myVector1.size() - 1) { std::cout << ", "; }
		else { std::cout << std::endl; }
	}
	
	myVector1.Sort(SortConfig);

	for (uint16_t i = 0; i < myVector1.size(); i++)
	{
		std::cout << (unsigned int)myVector1[i];
		if (i < myVector1.size() - 1) { std::cout << ", "; }
		else { std::cout << std::endl; }
	}

	myVector1.clear();

    return 0;
}