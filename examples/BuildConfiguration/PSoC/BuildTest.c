extern "C"{
    #include "project.h"
}

#include<CPVector.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_1_Start();
    UART_1_PutString("This project uses CPVector version: ");
    UART_1_PutString(CPVECTOR_VERSION);
    UART_1_PutChar('\n');
    UART_1_PutChar('\r');
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
