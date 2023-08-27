#include <iostream>
#include <CPVector.h>

int main()
{
    std::cout<<"This project uses CPVector version: "<<CPVECTOR_VERSION<<std::endl;

    #if defined(CPVECTOR_SORTING_ENABLED)
    	std::cout<<"CPVector::Sorting Enabled."<<std::endl;
    #endif

    return 0;
}