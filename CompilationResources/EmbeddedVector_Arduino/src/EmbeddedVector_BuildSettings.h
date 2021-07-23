#ifndef EMBEDDED_VECTOR_BUILD_SETTINGS_H
#define EMBEDDED_VECTOR_BUILD_SETTINGS_H

    #include <stdint.h>
    #include <math.h>

    ///////////////////////////////////////////////////////////////////////////////////
    // Arduino IDE

    #ifdef ARDUINO
        #include <Arduino.h>
        #include <stdint.h>

        typedef unsigned int uint;

        #define PROGMEM_MACRO PROGMEM
    #endif

    ///////////////////////////////////////////////////////////////////////////////////
    // PSOC Creator

    #ifdef PSOC_CREATOR

        //#ifdef __cplusplus
        //    extern "C" {
        //        #include "project.h"   
        //    }
        //#else
        //    #include "project.h"
        //#endif

        #include <stdio.h>

        typedef unsigned int uint;

        #define PROGMEM_MACRO
    #endif

#endif//EMBEDDED_VECTOR_BUILD_SETTINGS_H
