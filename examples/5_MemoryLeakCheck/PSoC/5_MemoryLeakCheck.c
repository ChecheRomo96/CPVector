extern "C"{
    #include "project.h"
}

#include <stdio.h>
#include<CPVector.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_1_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        CPVector::vector<uint8_t> myVector;
        myVector.resize(22);
        CyDelay(50);
    }
}

/* [] END OF FILE */
