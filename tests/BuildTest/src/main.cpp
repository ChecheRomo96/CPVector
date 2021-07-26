#include <iostream>
#include <EmbeddedVector.h>

int main()
{
	EVector::Vector<uint8_t> a;
	uint8_t elements = 10;

	a.resize(elements);



	for(uint8_t i = 0; i < elements; i++)
	{
		a[i] = rand();
		std::cout<<(uint)(a[i]);
		if(i < elements-1){std::cout<<", ";}
		else{std::cout<<".\n";}
	}
	
	a.SortAscending();

	for(uint8_t i = 0; i < elements; i++)
	{
		std::cout<<(uint)(a[i]);
		if(i < elements-1){std::cout<<", ";}
		else{std::cout<<".\n";}
	}

	
	a.SortDescending();

	for(uint8_t i = 0; i < elements; i++)
	{
		std::cout<<(uint)(a[i]);
		if(i < elements-1){std::cout<<", ";}
		else{std::cout<<".\n";}
	}




	return 0;
}