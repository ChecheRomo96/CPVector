#ifndef CROSS_PLATFORM_VECTOR_BUILD_SETTINGS_H
#define CROSS_PLATFORM_VECTOR_BUILD_SETTINGS_H

    ///////////////////////////////////////////////////////////////////////////////////
    // Arduino IDE

    #ifdef ARDUINO

        #define PROGMEM_MACRO PROGMEM

    ///////////////////////////////////////////////////////////////////////////////////
    // PSOC Creator

    #elif defined(PSOC_CREATOR)

        #define PROGMEM_MACRO
   
    #elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)


    #elif defined(__APPLE__)


    #endif

#endif//CROSS_PLATFORM_VECTOR_BUILD_SETTINGS_H
