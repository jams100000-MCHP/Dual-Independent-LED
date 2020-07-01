/**
  PRG2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    prg2.c

  @Summary
    This is the generated driver implementation file for the PRG2 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for PRG2.
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
#include "prg2.h"

/**
  Section: PRG2 APIs
*/

void PRG2_Initialize(void)
{
    // RG2GO not operating; RG2EN enabled; RG2MODE slope compensation; RG2OS disabled; RG2REDG edge_sensitive; RG2FEDG edge_sensitive; 
    PRG2CON0 = 0xB0;
    // RG2FPOL active_low; RG2RPOL active_low; 
    PRG2CON1 = 0x03;
    // INS PRG2IN0/OPA2OUT; 
    PRG2INS = 0x00;
    // RG2ISET 0.4  V/us; 
    PRG2CON2 = 0x04;
    // RTSS CCP1_out; 
    PRG2RTSS = 0x09;
    // FTSS CCP2_out; 
    PRG2FTSS = 0x0A;

}

bool PRG2_IsReady(void)
{
    return (PRG2CON1bits.RG2RDY);
}

void PRG2_StartRampGeneration(void)
{
    // Start the PRG module by set GO bit
    PRG2CON0bits.RG2GO = 1;
}

void PRG2_StopRampGeneration(void)
{
    // Stop the PRG module by clearing GO bit
    PRG2CON0bits.RG2GO = 0;
}

void PRG2_EnableOneShot(void)
{
    // Enable One-Shot mode by setting OS bit
    PRG2CON0bits.RG2OS = 1;
}

void PRG2_DisableOneShot(void)
{
    // Disable One-Shot mode by clearing OS bit
    PRG2CON0bits.RG2OS = 0;
}

void PRG2_UpdateSlope(uint8_t slopeValue )
{
    PRG2CON2bits.RG2ISET = (slopeValue&0x1F);
}


/**
 End of File
*/
