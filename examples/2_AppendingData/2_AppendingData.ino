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

  myVector1.clear();
  
  CPVector::vector<uint16_t> myVector2;
  myVector2.resize(15);

  for(uint8_t i = 0; i < myVector2.size(); i++)
  {
    myVector2[i] = rand();
    Serial.print(myVector2[i]);
    if(i < myVector2.size()-1){Serial.print(", ");}
    else{Serial.println();}
  }

  myVector2.clear();
}

void loop()
{
  
}