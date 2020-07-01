/**
  DSM1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dsm1.c

  @Summary
    This is the generated driver implementation file for the DSM1 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides implementations for driver APIs for DSM1.
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
#include "dsm1.h"

/**
  Section: DSM1 APIs
*/

void DSM1_Initialize(void)
{
    // set the DSM1 to the options selected in the User Interface
    
    // Modulator Output Pin Polarity is not inverted
    MD1CON0bits.MD1OPOL = 0;

    // Modulation Low Carrier Synchronization is disabled
    MD1CON1bits.MD1CLSYNC = 0;

    // Modulation Low Carrier Polarity is not inverted
    MD1CON1bits.MD1CLPOL = 0;

    // Modulation High Carrier Synchronization is disabled
    MD1CON1bits.MD1CHSYNC = 0;

    // Modulation High Carrier Polarity is not inverted
    MD1CON1bits.MD1CHPOL = 0;

    // MD1MS PWM3_out; 
    MD1SRC = 0x09;
    
    // MD1CH CCP2_out; 
    MD1CARH = 0x08;
    
    // MD1CL MD1CLPPS pin; 
    MD1CARL = 0x00;
    
 
    // Enable the Modulator
    MD1CON0bits.MD1EN = 1;
}

void DSM1_ManualModulationSet (void)
{
    // Set MDBIT to High, Modulator uses high carrier source
    MD1CON0bits.MD1BIT = 1;
}

void DSM1_ManualModulationClear (void)
{
    // Set MDBIT to Low, Modulator uses low carrier source
    MD1CON0bits.MD1BIT = 0;
}

void DSM1_ManualModulationToggle (void)
{
    // Toggle the MDBIT
    MD1CON0bits.MD1BIT ^= 1;
}

void DSM1_ModulationStart (void)
{
    // Enables module and begins modulation
    MD1CON0bits.MD1EN = 1;
}

void DSM1_ModulationStop (void)
{
    // Disables module and stops modulation
    MD1CON0bits.MD1EN = 0;
}
/**
 End of File
*/