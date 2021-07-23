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

    ///////////////////////////////////////////////////////////////////////////////////
    // PSOC Creator

    #elif defined(PSOC_CREATOR)

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
   
    #elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

            #include <iostream>
            #include <stdint.h>
            #define ARDUINO

            #ifdef _WIN64
              //define something for Windows (64-bit only)
            #else
              //define something for Windows (32-bit only)
            #endif
            

    #elif defined(__APPLE__)

        #include <TargetConditionals.h>
        #include <iostream>

        #include <stdint.h>
        #define ARDUINO

        #if TARGET_IPHONE_SIMULATOR
            // iOS Simulator
        #elif TARGET_OS_IPHONE
            // iOS device
        #elif TARGET_OS_MAC
            // Other kinds of Mac OS
        #endif
    #endif

#endif//EMBEDDED_VECTOR_BUILD_SETTINGS_H
