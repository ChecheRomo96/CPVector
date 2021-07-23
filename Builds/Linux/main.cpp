#include <iostream>
#include <EmbeddedVector.h>

int main()
{
    EVector::Vector<uint8_t> a;
    
    a.resize(10);

    for(uint8_t i = 0; i < a.size(); i++)
    {
    	a[i] = rand();
    	std::cout<<(uint)(a[i]);
    	if(i<a.size()-1){std::cout<<", ";}
    	else{std::cout<<".\n";}
    }

    a.SortAscending();

    for(uint8_t i = 0; i < a.size(); i++)
    {
    	std::cout<<(uint)(a[i]);
    	if(i<a.size()-1){std::cout<<", ";}
    	else{std::cout<<".\n";}
    }

	return 0;
}
