/**
  COG2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    cog2.c

  @Summary
    This is the generated driver implementation file for the COG2 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides implementations for driver APIs for COG2.
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
#include "cog2.h"

/**
  Section: COG2 APIs
*/

void COG2_Initialize(void)
{
    // Reset double buffered register COG2CON0
    COG2CON0 = 0x00;

    // Set the COG to the options selected in MPLAB(c) Code Configurator

    // G2POLD Active high; G2POLB Active high; G2POLC Active high; G2RDBS Delay chain and COGxDBR; G2POLA Active high; G2FDBS Delay chain and COGxDF; 
    COG2CON1 = 0xC0;

    // G2RIS3 disabled; G2RIS4 disabled; G2RIS1 disabled; G2RIS2 disabled; G2RIS0 disabled; G2RIS7 disabled; G2RIS5 disabled; G2RIS6 disabled; 
    COG2RIS0 = 0x00;

    // G2RIS14 disabled; G2RIS15 enabled; G2RIS12 disabled; G2RIS13 disabled; G2RIS9 disabled; G2RIS10 disabled; G2RIS11 disabled; G2RIS8 disabled; 
    COG2RIS1 = 0x80;

    // G2RSIM2 Level Trigger; G2RSIM3 Level Trigger; G2RSIM0 Level Trigger; G2RSIM1 Level Trigger; G2RSIM6 Edge Trigger; G2RSIM7 Level Trigger; G2RSIM4 Level Trigger; G2RSIM5 Edge Trigger; 
    COG2RSIM0 = 0x60;

    // G2RSIM10 Level Trigger; G2RSIM14 Level Trigger; G2RSIM13 Level Trigger; G2RSIM12 Level Trigger; G2RSIM11 Level Trigger; G2RSIM15 Edge Trigger; G2RSIM8 Level Trigger; G2RSIM9 Level Trigger; 
    COG2RSIM1 = 0x80;

    // G2FIS2 disabled; G2FIS1 disabled; G2FIS4 disabled; G2FIS3 enabled; G2FIS6 enabled; G2FIS5 disabled; G2FIS7 disabled; G2FIS0 disabled; 
    COG2FIS0 = 0x48;

    // G2FIS8 disabled; G2FIS14 disabled; G2FIS9 disabled; G2FIS15 disabled; G2FIS10 disabled; G2FIS11 disabled; G2FIS12 disabled; G2FIS13 disabled; 
    COG2FIS1 = 0x00;

    // G2FSIM1 Level Trigger; G2FSIM0 Level Trigger; G2FSIM3 Level Trigger; G2FSIM2 Level Trigger; G2FSIM5 Level Trigger; G2FSIM4 Level Trigger; G2FSIM7 Level Trigger; G2FSIM6 Edge Trigger; 
    COG2FSIM0 = 0x40;

    // G2FSIM10 Level Trigger; G2FSIM9 Level Trigger; G2FSIM12 Level Trigger; G2FSIM8 Level Trigger; G2FSIM11 Level Trigger; G2FSIM14 Level Trigger; G2FSIM13 Level Trigger; G2FSIM15 Level Trigger; 
    COG2FSIM1 = 0x00;

    // G2ARSEN disabled; G2ASE not shutdown; G2ASDAC inactive state; G2ASDBD inactive state; 
    COG2ASD0 = 0x00;

    // G2AS7E disabled; G2AS0E disabled; G2AS1E disabled; G2AS2E enabled; G2AS3E disabled; G2AS4E disabled; G2AS5E disabled; G2AS6E disabled; 
    COG2ASD1 = 0x04;

    // G2SDATD static data low; G2SDATC static data low; G2STRD static level; G2STRC static level; G2STRB static level; G2STRA waveform; G2SDATB static data low; G2SDATA static data low; 
    COG2STR = 0x01;

    // DBR 0; 
    COG2DBR = 0x00;

    // G2DBF 0; 
    COG2DBF = 0x00;

    // BLKR 0; 
    COG2BLKR = 0x00;

    // BLKF 0; 
    COG2BLKF = 0x00;

    // PHR 0; 
    COG2PHR = 0x00;

    // PHF 0; 
    COG2PHF = 0x00;

    // G2EN enabled; G2CS FOSC/4; G2LD transfer complete; G2MD synchronous steered PWM mode; 
    COG2CON0 = 0x81;

}

void COG2_AutoShutdownEventSet()
{
    // Setting the GxASE bit of COGxASD0 register
    COG2ASD0bits.G2ASE = 1;
}

void COG2_AutoShutdownEventClear()
{
    // Clearing the GxASE bit of COGxASD0 register
    COG2ASD0bits.G2ASE = 0;
}
/**
 End of File
*/

