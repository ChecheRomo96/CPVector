#include <CPVector.h>

int8_t Sorting_EvenFirst(const uint8_t& Element, const uint8_t& Pivot)
{
    if( (Element%2) == (Pivot%2) ){return CPVector::Sorting::Equal;}
    else if((Element%2) == 0){return CPVector::Sorting::Swap;}
    return CPVector::Sorting::Ignore;
}

void setup()
{
    Serial.begin(115200);
    
    CPVector::vector<uint8_t> myVector1;
    myVector1.resize(25);
    
    for(uint16_t i = 0; i < myVector1.size(); i++)
    {
        myVector1[i] = rand();
        Serial.print(myVector1[i]);
        if(i < myVector1.size()-1){Serial.print(", ");}
        else{Serial.println();}
    }


    CPVector::Sorting::SortingArray<uint8_t> SortConfig;
    SortConfig.Append(Sorting_EvenFirst);
    SortConfig.Append(CPVector::Sorting::Ascending);
    myVector1.Sort(SortConfig);

    for(uint16_t i = 0; i < myVector1.size(); i++)
    {
        Serial.print(myVector1[i]);
        if(i < myVector1.size()-1){Serial.print(", ");}
        else{Serial.println();}
    }
    myVector1.clear();
}

void loop()
{
    
}