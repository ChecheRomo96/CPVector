
extern "C"{
    #include "project.h"
}

#include<stdio.h>
#include<CPVector.h>

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

    myVector1.SortAscending();

    for(uint16_t i = 0; i < myVector1.size(); i++)
    {
        char str[10];
        sprintf(str, "%d", myVector1[i]);
        UART_1_PutString(str);
        
        if(i < myVector1.size()-1){UART_1_PutString(", ");}
        else{UART_1_PutString("\n\r");}
    }

    myVector1.clear();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
