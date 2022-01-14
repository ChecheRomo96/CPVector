#include <CPVector.h>

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

  myVector1.SortAscending();
  
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