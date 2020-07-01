/**
  CMP2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    cmp2.c

  @Summary
    This is the generated driver implementation file for the CMP2 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for CMP2.
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
#include "cmp2.h"
/**
  Section: CMP2 APIs
*/

void CMP2_Initialize(void)
{

    // set the CMP to the options selected in MPLAB(c) Code Configurator
    // C2HYS disabled; C2ON enabled; C2POL not inverted; C2SYNC asynchronous; C2ZLF unfiltered;                          
    CM2CON0 = 0x84;

    // C2INTN no_intFlag; C2INTP no_intFlag;                          
    CM2CON1 = 0x00;

    // C2NCH FVR;                          
    CM2NSEL = 0x06;

    // C2PCH DAC2;                          
    CM2PSEL = 0x0B;

}

bool CMP2_GetOutputStatus(void)
{
    return (CMOUTbits.MC2OUT);
}


/**
 End of File
*/
