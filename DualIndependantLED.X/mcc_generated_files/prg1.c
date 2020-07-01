/**
  PRG1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    prg1.c

  @Summary
    This is the generated driver implementation file for the PRG1 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for PRG1.
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
#include "prg1.h"

/**
  Section: PRG1 APIs
*/

void PRG1_Initialize(void)
{
    // RG1GO not operating; RG1EN enabled; RG1MODE slope compensation; RG1OS disabled; RG1REDG edge_sensitive; RG1FEDG edge_sensitive; 
    PRG1CON0 = 0xB0;
    // RG1FPOL active_low; RG1RPOL active_low; 
    PRG1CON1 = 0x03;
    // INS PRG1IN0/OPA1OUT; 
    PRG1INS = 0x00;
    // RG1ISET 0.4  V/us; 
    PRG1CON2 = 0x04;
    // RTSS CCP1_out; 
    PRG1RTSS = 0x09;
    // FTSS CCP2_out; 
    PRG1FTSS = 0x0A;

}

bool PRG1_IsReady(void)
{
    return (PRG1CON1bits.RG1RDY);
}

void PRG1_StartRampGeneration(void)
{
    // Start the PRG module by set GO bit
    PRG1CON0bits.RG1GO = 1;
}

void PRG1_StopRampGeneration(void)
{
    // Stop the PRG module by clearing GO bit
    PRG1CON0bits.RG1GO = 0;
}

void PRG1_EnableOneShot(void)
{
    // Enable One-Shot mode by setting OS bit
    PRG1CON0bits.RG1OS = 1;
}

void PRG1_DisableOneShot(void)
{
    // Disable One-Shot mode by clearing OS bit
    PRG1CON0bits.RG1OS = 0;
}

void PRG1_UpdateSlope(uint8_t slopeValue )
{
    PRG1CON2bits.RG1ISET = (slopeValue&0x1F);
}


/**
 End of File
*/
