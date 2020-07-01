/**
  DAC2 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    dac2.h

  @Summary
    This is the generated header file for the DAC2 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for DAC2.
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

#ifndef _DAC2_H
#define _DAC2_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: DAC2 APIs
*/

/**
  @Summary
    Initializes the DAC2

  @Description
    This routine initializes the DAC2.
    This routine must be called before any other DAC2 routine is called.
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
    DAC2_Initialize();
    </code>
*/

void DAC2_Initialize(void);
/**
  @Summary
    Load 16bit input data to DAC2.

  @Description
    This routine passes the 16bit input data into
    DAC2 voltage reference control register.This data will
    be left justified. 
 
  @Preconditions
    The DAC2_Initialize() routine should be called
    before using this routine.DAC input reference range should be 16bit.
 
  @Param
    input16BitData - 16bit input data to DAC2.

  @Returns
    None

  @Example
    <code>
    uint16_t count=0xFFFF;

    DAC2_Initialize();
    DAC2_Load16bitInputData(count);
    while(1)
    {
    }
    </code>
*/
void DAC2_Load16bitInputData(uint16_t input16BitData);

/**
  @Summary
    Load 10bit input data to DAC2.

  @Description
    This routine passes the 10bit input data into DAC2 
    voltage reference control register.This data will be right justified. 
 
  @Preconditions
   The DAC2_Initialize() routine should be called
   before using this routine.DAC input reference range should be 10bit.
 
  @Param
    input10BitData - 10bit input data to DAC2.

  @Returns
    None

  @Example
    <code>
    uint16_t count=0x3FF;

    DAC2_Initialize();
    DAC2_Load10bitInputData(count);
    while(1)
    {
    }
    </code>
*/
void DAC2_Load10bitInputData(uint16_t input10BitData);

/**
  @Summary
    Read 10bit data from DAC2.

  @Description
    This routine reads the 10bit data from DAC2 
    voltage reference control register.This data will be right justified. 
 
  @Preconditions
   The DAC2_Initialize() routine should be called
   before using this routine.DAC input reference range should be 10bit.

  @Returns
    uint16_t - 10bit data from DAC2.

  @Example
    <code>
    uint16_t count=0x3FF;

    DAC2_Initialize();
    DAC2_Load10bitInputData(count);
    
    // Make sure data was written to DAC correctly
    __conditional_software_breakpoint(count == DAC2_Read10BitInputData(count));
    </code>
*/
uint16_t DAC2_Read10BitInputData(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _DAC2_H
/**
 End of File
*/

