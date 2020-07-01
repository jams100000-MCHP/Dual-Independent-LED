/**
  CMP3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    cmp3.c

  @Summary
    This is the generated driver implementation file for the CMP3 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for CMP3.
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
#include "cmp3.h"
/**
  Section: CMP3 APIs
*/

void CMP3_Initialize(void)
{

    // set the CMP to the options selected in MPLAB(c) Code Configurator
    // C3HYS disabled; C3ON enabled; C3POL not inverted; C3SYNC asynchronous; C3ZLF unfiltered;                          
    CM3CON0 = 0x84;

    // C3INTN no_intFlag; C3INTP no_intFlag;                          
    CM3CON1 = 0x00;

    // C3NCH CIN1-;                          
    CM3NSEL = 0x01;

    // C3PCH PRG2;                          
    CM3PSEL = 0x09;

}

bool CMP3_GetOutputStatus(void)
{
    return (CMOUTbits.MC3OUT);
}


/**
 End of File
*/
