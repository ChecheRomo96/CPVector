#ifndef CROSS_PLATFORM_VECTOR_BUILD_SETTINGS_H
#define CROSS_PLATFORM_VECTOR_BUILD_SETTINGS_H

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Arduino IDE

        #if defined(ARDUINO)
            #include <Arduino.h>
            #define PROGMEM_MACRO PROGMEM
            #define CPVECTOR_VERSION "0.0.1"
        #endif
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // PSoC Creator
    
        #if defined(PSOC_CREATOR)
            #define PROGMEM_MACRO
            #define CPVECTOR_VERSION "0.0.1"
        #endif
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Desktop C++
    
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__APPLE__) || defined(linux)
            #include <vector>
            #define PROGMEM_MACRO
        #endif
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Unknown System
    
        #if !defined(PROGMEM_MACRO)
            
            #error "Unknown System!!!"
            
        #endif
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif//CROSS_PLATFORM_VECTOR_BUILD_SETTINGS_H