/**
  DSM2 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    dsm2.h

  @Summary
    This is the generated header file for the DSM2 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for DSM2.
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


#ifndef _DSM2_H
#define _DSM2_H

/**
  Section: Included Files
*/

#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: DSM2 APIs
*/

/**
  @Summary
    Initializes the DSM2

  @Description
    This routine configures the DSM2 specific control registers

  @Preconditions
    None

  @Returns
    None

  @Param
    None

  @Comment
    

  @Example
    <code>
    DSM2_Initialize();
    </code>

*/
void DSM2_Initialize(void);

/**
  @Summary
    Sets the MDxCON0<BIT> high

  @Description
    This API sets the MDxCON0<BIT> high, so modulator uses carrier high signal

  @Preconditions
    DSM2_Initialize() function should have been called before calling this function

  @Returns
    None

  @Param
    None

  @Example
    <code>
    DSM2_Initialize();
    DSM2_ManualModulationSet();
    </code>

*/
void DSM2_ManualModulationSet (void);

/**
  @Summary
    Sets the MDxCON0<BIT> low

  @Description
    This API sets the MDxCON0<BIT> low, so modulator uses carrier low signal

  @Preconditions
    DSM2_Initialize() function should have been called before calling this function

  @Returns
    None

  @Param
    None

  @Example
    <code>
    DSM2_Initialize();
    DSM2_ManualModulationClear();
    </code>

*/
void DSM2_ManualModulationClear (void);
/**
  @Summary
    Toggles the MDxCON0<BIT>

  @Description
    This API toggles the MDxCON0<BIT>

  @Preconditions
    DSM2_Initialize() function should have been called 
	before calling this function

  @Returns
    None

  @Param
    None

  @Example
    <code>
    DSM2_Initialize();
    DSM2_ManualModulationToggle();
    </code>
*/
void DSM2_ManualModulationToggle (void);

/**
  @Summary
    Enables modulation

  @Description
    This API enables the modulator.

  @Preconditions
    DSM2_Initialize() function should have been called 
	before calling this function

  @Returns
    None

  @Param
    None

  @Example
    <code>
    DSM2_Initialize();
    DSM2_ModulationStart();
    </code>
*/
void DSM2_ModulationStart (void);

/**
  @Summary
    Disables modulation

  @Description
    This API disables the modulator.

  @Preconditions
    DSM2_Initialize() and DSM2_ModulationStart()
	functions should have been called before calling this function

  @Returns
    None

  @Param
    None

  @Example
    <code>
    DSM2_Initialize();
    DSM2_ModulationStart();
    ...
    DSM2_ModulationStop();
    </code>
*/
void DSM2_ModulationStop (void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // _DSM2_H
/**
 End of File
*/
