/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
extern "C"{
    #include "project.h"
}
#include "stdlib.h"
#include <stdio.h>
#include<CPVector.h>

int8_t Sorting_EvenFirst(const uint8_t& Element, const uint8_t& Pivot)
{
  if( (Element%2) == (Pivot%2) ){return CPVector::Sorting::Equal;}
  else if((Element%2) == 0){return CPVector::Sorting::Swap;}
  return CPVector::Sorting::Ignore;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_1_Start();
    
    CPVector::vector<uint8_t> myVector1;
    myVector1.resize(25);

    for(uint16_t i = 0; i < myVector1.size(); i++)
    {
        myVector1[i] = rand();
        
        char str[10];
        sprintf(str, "%d", myVector1[i]);
        UART_1_PutString(str);
        
        if(i < myVector1.size()-1){UART_1_PutString(", ");}
        else{UART_1_PutString("\n\r");}
    }
    myVector1.clear();
    
    CPVector::vector<uint16_t> myVector2;
    myVector2.resize(17);

    for(uint8_t i = 0; i < myVector2.size(); i++)
    {
        myVector2[i] = rand();
        
        char str[10];
        sprintf(str, "%d", myVector2[i]);
        UART_1_PutString(str);
        
        if(i < myVector2.size()-1){UART_1_PutString(", ");}
        else{UART_1_PutString("\n\r");}
    }
    myVector2.clear();

    UART_1_PutString("\n\r");

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
