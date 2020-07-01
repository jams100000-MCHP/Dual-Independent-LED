

/**
  DAC2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dac2.c

  @Summary
    This is the generated driver implementation file for the DAC2 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for DAC2.
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "dac2.h"

/**
  Section: Macros
*/

/**
 *  Loads data from DAC buffer onto the DAC output
 */
#define DAC2_DoubleBufferLatch() \
    (DACLDbits.DAC2LD = 1)

/**
  Section: DAC2 APIs
*/

void DAC2_Initialize(void)
{
    // 
    DAC2REFL = 0x5E;
    // 
    DAC2REFH = 0x01;
    // DACOE disabled; DAC2FM right justified; DACEN enabled; DACNSS VSS; DACPSS VDD; 
    DAC2CON0 = 0x80;
    //Loading DAC2 double buffer data to latch.
    DAC2_DoubleBufferLatch();
}


void DAC2_Load16bitInputData(uint16_t input16BitData)
{
    //DAC input reference range should be 16bit.
    //Input data left justified.
    DAC2CON0bits.DAC2FM = 1;
    
    //Loading 16bit data to DAC2
    DAC2REFL  = (uint8_t) input16BitData;  
    DAC2REFH  = (uint8_t)(input16BitData >> 8);
    //Loading DAC2 double buffer data to latch.
    DAC2_DoubleBufferLatch();
}

void DAC2_Load10bitInputData(uint16_t input10BitData)
{
    //DAC input reference range should be 10bit.
    //Input data right justified.
    DAC2CON0bits.DAC2FM = 0;
    
    //Loading 10bit data to DAC2
    DAC2REFL  = (uint8_t) input10BitData;  
    DAC2REFH  = (uint8_t)(input10BitData >> 8);
    //Loading DAC2 double buffer data to latch.
    DAC2_DoubleBufferLatch();
}

uint16_t DAC2_Read10BitInputData(void) {
    // Right justified, to match ?load? function
    DAC2CON0bits.DAC2FM = 0;

    // Read data
    uint16_t data = ((uint16_t) DAC2REFH) << 8;
    data |= ((uint16_t) DAC2REFL);

    return data;
}
/**
 End of File
*/ 



