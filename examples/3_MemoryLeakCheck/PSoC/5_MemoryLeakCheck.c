extern "C"{
    #include "project.h"
}

#include <stdio.h>
#include<CPVector.h>
#include "matrix.h"
#include "NeuralNetwork.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_1_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    char Buffer[50];
    
    
    CPVector::vector<uint8_t> NetworkDimensions;
    NetworkDimensions.resize(3);
    NetworkDimensions[0] = 3;
    NetworkDimensions[1] = 2;
    NetworkDimensions[2] = 1;

    AI::NeuralNetwork<float> myNeuralNetwork;
    
    for(;;)
    {
        
        myNeuralNetwork.SetDimensions(NetworkDimensions);
        
        UART_1_PutString("Weight Matrices:\n\r");   
        for(uint8_t i = 0; i < myNeuralNetwork.WeightMatrixVector().size(); i++)
        {
            UART_1_PutString("Rows: ");   
            sprintf(Buffer,"%u",myNeuralNetwork.WeightMatrix(i).Rows());
            UART_1_PutString(Buffer);
            UART_1_PutString(", Cols: ");
            sprintf(Buffer,"%u",myNeuralNetwork.WeightMatrix(i).Cols());
            UART_1_PutString(Buffer);
            UART_1_PutString("\n\r");
        }
        
        UART_1_PutString("Bias Matrices:\n\r");  
        for(uint8_t i = 0; i < myNeuralNetwork.BiasMatrixVector().size(); i++)
        {
            UART_1_PutString("Rows: ");   
            sprintf(Buffer,"%u",myNeuralNetwork.BiasMatrix(i).Rows());
            UART_1_PutString(Buffer);
            UART_1_PutString(", Cols: ");
            sprintf(Buffer,"%u",myNeuralNetwork.BiasMatrix(i).Cols());
            UART_1_PutString(Buffer);
            UART_1_PutString("\n\r");
        }
        
        UART_1_PutString("Output Matrices:\n\r");  
        for(uint8_t i = 0; i < myNeuralNetwork.OutputMatrixVector().size(); i++)
        {
            UART_1_PutString("Rows: ");   
            sprintf(Buffer,"%u",myNeuralNetwork.OutputMatrix(i).Rows());
            UART_1_PutString(Buffer);
            UART_1_PutString(", Cols: ");
            sprintf(Buffer,"%u",myNeuralNetwork.OutputMatrix(i).Cols());
            UART_1_PutString(Buffer);
            UART_1_PutString("\n\r");
        }
        
        myNeuralNetwork.clear();

        /*for(uint8_t i = 0; i < Network.BiasMatrixVector().size(); i++)
        {
          Serial.print("Rows: ");
          Serial.print(Network.BiasMatrix(i).Rows());
          Serial.print(", Cols: ");
          Serial.println(Network.BiasMatrix(i).Cols());
        }

        for(uint8_t i = 0; i < Network.OutputMatrixVector().size(); i++)
        {
          Serial.print("Rows: ");
          Serial.print(Network.OutputMatrix(i).Rows());
          Serial.print(", Cols: ");
          Serial.println(Network.OutputMatrix(i).Cols());
        }*/

        CyDelay(2000);
    }
    
    
    
    
    /*
    uint32_t x = 0;
    
    for(;;)
    {
        CPVector::vector<uint8_t> myVector;
        myVector.resize(24);
        
        for(uint8_t i = 0; i < myVector.size()/4; i++)
        {
            myVector[ (i*4) ] = 0xFE;
            myVector[(i*4)+1] = 0xED;
            myVector[(i*4)+2] = 0xBE;
            myVector[(i*4)+3] = 0xEF;
        }
        
        CPMath::Matrix<uint32_t> myMatrix;
        myMatrix.SetDimensions(2,2,1,x++);
        
        char Buffer[50];
        sprintf(Buffer,"%lu\n\r",x);
        UART_1_PutString(Buffer); 
    } */
    
}

/* [] END OF FILE */
