/**
  COG1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    cog1.c

  @Summary
    This is the generated driver implementation file for the COG1 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides implementations for driver APIs for COG1.
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
#include "cog1.h"

/**
  Section: COG1 APIs
*/

void COG1_Initialize(void)
{
    // Reset double buffered register COG1CON0
    COG1CON0 = 0x00;

    // Set the COG to the options selected in MPLAB(c) Code Configurator

    // G1POLD Active high; G1POLB Active high; G1POLC Active high; G1RDBS Delay chain and COGxDBR; G1POLA Active high; G1FDBS Delay chain and COGxDF; 
    COG1CON1 = 0xC0;

    // G1RIS3 disabled; G1RIS4 disabled; G1RIS1 disabled; G1RIS2 disabled; G1RIS0 disabled; G1RIS7 disabled; G1RIS5 disabled; G1RIS6 disabled; 
    COG1RIS0 = 0x00;

    // G1RIS14 enabled; G1RIS15 disabled; G1RIS12 disabled; G1RIS13 disabled; G1RIS9 disabled; G1RIS10 disabled; G1RIS11 disabled; G1RIS8 disabled; 
    COG1RIS1 = 0x40;

    // G1RSIM2 Level Trigger; G1RSIM3 Level Trigger; G1RSIM0 Level Trigger; G1RSIM1 Level Trigger; G1RSIM6 Level Trigger; G1RSIM7 Level Trigger; G1RSIM4 Level Trigger; G1RSIM5 Level Trigger; 
    COG1RSIM0 = 0x00;

    // G1RSIM10 Level Trigger; G1RSIM14 Edge Trigger; G1RSIM13 Level Trigger; G1RSIM12 Level Trigger; G1RSIM11 Level Trigger; G1RSIM15 Level Trigger; G1RSIM8 Level Trigger; G1RSIM9 Level Trigger; 
    COG1RSIM1 = 0x40;

    // G1FIS2 disabled; G1FIS1 enabled; G1FIS4 disabled; G1FIS3 disabled; G1FIS6 enabled; G1FIS5 disabled; G1FIS7 disabled; G1FIS0 disabled; 
    COG1FIS0 = 0x42;

    // G1FIS8 disabled; G1FIS14 disabled; G1FIS9 disabled; G1FIS15 disabled; G1FIS10 disabled; G1FIS11 disabled; G1FIS12 disabled; G1FIS13 disabled; 
    COG1FIS1 = 0x00;

    // G1FSIM1 Level Trigger; G1FSIM0 Level Trigger; G1FSIM3 Level Trigger; G1FSIM2 Level Trigger; G1FSIM5 Level Trigger; G1FSIM4 Level Trigger; G1FSIM7 Level Trigger; G1FSIM6 Edge Trigger; 
    COG1FSIM0 = 0x40;

    // G1FSIM10 Level Trigger; G1FSIM9 Level Trigger; G1FSIM12 Level Trigger; G1FSIM8 Level Trigger; G1FSIM11 Level Trigger; G1FSIM14 Level Trigger; G1FSIM13 Level Trigger; G1FSIM15 Level Trigger; 
    COG1FSIM1 = 0x00;

    // G1ARSEN disabled; G1ASE not shutdown; G1ASDAC inactive state; G1ASDBD inactive state; 
    COG1ASD0 = 0x00;

    // G1AS7E disabled; G1AS0E disabled; G1AS1E disabled; G1AS2E enabled; G1AS3E disabled; G1AS4E disabled; G1AS5E disabled; G1AS6E disabled; 
    COG1ASD1 = 0x04;

    // G1SDATD static data low; G1SDATC static data low; G1STRD static level; G1STRC static level; G1STRB static level; G1STRA waveform; G1SDATB static data low; G1SDATA static data low; 
    COG1STR = 0x01;

    // DBR 0; 
    COG1DBR = 0x00;

    // G1DBF 0; 
    COG1DBF = 0x00;

    // BLKR 0; 
    COG1BLKR = 0x00;

    // BLKF 0; 
    COG1BLKF = 0x00;

    // PHR 0; 
    COG1PHR = 0x00;

    // PHF 0; 
    COG1PHF = 0x00;

    // G1EN enabled; G1CS FOSC/4; G1LD transfer complete; G1MD synchronous steered PWM mode; 
    COG1CON0 = 0x81;

}

void COG1_AutoShutdownEventSet()
{
    // Setting the GxASE bit of COGxASD0 register
    COG1ASD0bits.G1ASE = 1;
}

void COG1_AutoShutdownEventClear()
{
    // Clearing the GxASE bit of COGxASD0 register
    COG1ASD0bits.G1ASE = 0;
}
/**
 End of File
*/

