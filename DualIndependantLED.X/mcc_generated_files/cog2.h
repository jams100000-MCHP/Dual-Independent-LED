/**
  COG2 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    cog2.h

  @Summary
    This is the generated header file for the COG2 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for COG2.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.1
        Device            :  PIC16F1769
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _COG2_H
#define _COG2_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: COG2 APIs
*/

/**
  @Summary
    Initializes the COG2

  @Description
    This routine configures the COG2 specific control registers and input clock

  @Preconditions
    None

  @Returns
    None

  @Param
    None

  @Comment
    

  @Example
    <code>
    COG2_Initialize();
    </code>
*/
void COG2_Initialize(void);

/**
  @Summary
    Software generated Shutdown

  @Description
    This function forces the COG into Shutdown state.

  @Preconditions
    COG2_Initialize() function should have been called before calling this function

  @Returns
    None

  @Param
    None

  @Example
    <code>
    COG2_initialize();

    // Do something

    COG2_AutoShutdownEventSet();
    </code>
*/
void COG2_AutoShutdownEventSet();

/**
  @Summary
    This function makes the COG to resume its operations from the software
    generated shutdown state.

  @Description
    When auto-restart is disabled, the shutdown state will persist as long as the
    GxASE bit is set and hence to resume operations, this function should be used.

    However when auto-restart is enabled, the GxASE bit will clear automatically
    and resume operation on the next rising edge event. In that case, there is no
    need to call this function.

  @Preconditions
    COG2_Initialize() and COG2_AutoShutdownEventSet() functions should have been called before calling this function

  @Returns
    None

  @Param
    None

  @Example
    <code>
    COG2_initialize();

    // Do something

    COG2_AutoShutdownEventSet();

    // Do something

    COG2_AutoShutdownEventClear();
    </code>
*/
void COG2_AutoShutdownEventClear();

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  //_COG2_H
/**
 End of File
*/
