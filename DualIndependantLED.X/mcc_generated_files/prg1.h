/**
  PRG1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    prg1.h

  @Summary
    This is the generated header file for the PRG1 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for PRG1.
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

#ifndef _PRG1_H
#define _PRG1_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: PRG1 APIs
*/

/**
  @Summary
    Initializes the PRG1 module

  @Description
    This routine initializes the PRG1.
    This routine must be called before any other PRG1 routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    PRG1_Initialize();
    </code>
*/
void PRG1_Initialize(void);

/**
  @Summary
    Provides the readiness status of the {moduleNameUpperCase} moduel

  @Description
    This Funtion provides the readiness status of the {moduleNameUpperCase} moduel

  @Preconditions
    PRG1_Initialize() function should have been called before calling this function.

  @Returns
    true  - PRG module is ready for use.
    false - PRG module is not ready for use


  @Param
    None

  @Example
    <code>
      PRG1_Initialize();
      if(PRG1_IsReady())
      {
        PRG1_GenarateRamp();
      }

    </code>
*/
bool PRG1_IsReady(void);

/**
  @Summary
    Starts the Ramp generation.

  @Description
    This Funtion starts the Ramp generation.

  @Preconditions

    PRG1_Initialize() function should have been called before calling this function  and
    PRG1_IsReady() function should return true.

  @Returns
    None

  @Param
    None

  @Example
    <code>
      PRG1_Initialize();
      if(PRG1_IsReady())
      {
        PRG1_StartRampGeneration();
      }
    </code>
*/
void PRG1_StartRampGeneration(void);

/**
  @Summary
    Stops the Ramp generation.

  @Description
    This Funtion stops the Ramp generation.

  @Preconditions
    None

  @Returns
    None

  @Param
    None

  @Example
    <code>
        PRG1_StopRampGeneration();
    </code>
*/
void PRG1_StopRampGeneration(void);


/**
  @Summary
    Enables the One shot operation.

  @Description
    This Funtion enables the One shot operation.

  @Preconditions

    PRG1_Initialize() function should have been called before calling this function  and
    PRG1_IsReady() function should return true.

  @Returns
    None

  @Param
    None

  @Example
    <code>
      PRG1_Initialize();
      if(PRG1_IsReady())
      {
        PRG1_EnableOneShot();
        PRG1_StartRampGeneration();
      }
    </code>
*/
void PRG1_EnableOneShot(void);

/**
  @Summary
    Disables the One shot operation.

  @Description
    This Funtion disables the One shot operation.

  @Preconditions
    None

  @Returns
    None

  @Param
    None

  @Example
    <code>
        PRG1_DisableOneShot();
    </code>
*/
void PRG1_DisableOneShot(void);
/**
  @Summary
    Used to update the slope rate of the Ramp.

  @Description
    This function is used to update the slope rate of the Ramp.

  @Preconditions
    None

  @Returns
    None

  @Param
    slopeValue: unsigned 8-bit value, valid value range is 0x00 <= slopeValue <= 0x1F

  @Example
    <code>
      PRG1_UpdateSlope(0x10);
    </code>
*/
void PRG1_UpdateSlope(uint8_t slopeValue);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _PRG1_H
/**
 End of File
*/


