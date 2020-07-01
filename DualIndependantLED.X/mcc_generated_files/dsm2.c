/**
  DSM2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dsm2.c

  @Summary
    This is the generated driver implementation file for the DSM2 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides implementations for driver APIs for DSM2.
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
#include "dsm2.h"

/**
  Section: DSM2 APIs
*/

void DSM2_Initialize(void)
{
    // set the DSM2 to the options selected in the User Interface
    
    // Modulator Output Pin Polarity is not inverted
    MD2CON0bits.MD2OPOL = 0;

    // Modulation Low Carrier Synchronization is disabled
    MD2CON1bits.MD2CLSYNC = 0;

    // Modulation Low Carrier Polarity is not inverted
    MD2CON1bits.MD2CLPOL = 0;

    // Modulation High Carrier Synchronization is disabled
    MD2CON1bits.MD2CHSYNC = 0;

    // Modulation High Carrier Polarity is not inverted
    MD2CON1bits.MD2CHPOL = 0;

    // MD2MS PWM4_out; 
    MD2SRC = 0x0A;
    
    // MD2CH CCP2_out; 
    MD2CARH = 0x08;
    
    // MD2CL MD2CLPPS pin; 
    MD2CARL = 0x00;
    
 
    // Enable the Modulator
    MD2CON0bits.MD2EN = 1;
}

void DSM2_ManualModulationSet (void)
{
    // Set MDBIT to High, Modulator uses high carrier source
    MD2CON0bits.MD2BIT = 1;
}

void DSM2_ManualModulationClear (void)
{
    // Set MDBIT to Low, Modulator uses low carrier source
    MD2CON0bits.MD2BIT = 0;
}

void DSM2_ManualModulationToggle (void)
{
    // Toggle the MDBIT
    MD2CON0bits.MD2BIT ^= 1;
}

void DSM2_ModulationStart (void)
{
    // Enables module and begins modulation
    MD2CON0bits.MD2EN = 1;
}

void DSM2_ModulationStop (void)
{
    // Disables module and stops modulation
    MD2CON0bits.MD2EN = 0;
}
/**
 End of File
*/