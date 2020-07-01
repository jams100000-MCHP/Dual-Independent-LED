/******************************************************************************
*	Generated Main Source File
*
*	Company:
*	Microchip Technology Inc.
*
*	File Name:
*	main.c
*
*	Summary:
*	This is the main file for the Dual Independant LED driver demo
*
*	Description:
*	This header file provides implementations for driver APIs for all modules selected in the GUI.
*	Generation Information :
*		Product Revision  :  MPLAB(c) Code Configurator - 3.26.4
*		Device            :  PIC16F1769
*		Driver Version    :  2.00
*	The generated drivers wre built using the following:
*		Compiler          :  XC8 1.38
*		MPLAB             :  MPLAB X 3.60
*******************************************************************************
*	(c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
*	software and any derivatives exclusively with Microchip products.
*
*	THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
*	EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
*	WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
*	PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
*	WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
*
*	IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
*	INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
*	WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
*	BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
*	FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
*	ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
*	THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*
*	MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
*	TERMS.
******************************************************************************/

/******************************************************************************
*						Include Files
******************************************************************************/
#include "mcc_generated_files/mcc.h"

/******************************************************************************
*						Macro Definitions
******************************************************************************/

#define	M_COGASDE	(COG1ASD0 & 0b10000000) | (COG2ASD0 & 0b10000000)

/******************************************************************************
*						Constant Definitions
******************************************************************************/
// Button press defintions
#define	firstkey	0b00100000
#define	mode		1
#define chan1		2
#define chan2		3

// Manual / automatic control constants
#define ch1st		0
#define ch2st		0x1FF
#define intup		0
#define intdn		0xFF
#define maxint		0x3FF

/******************************************************************************
*						Variable Declarations
******************************************************************************/
// varible definitions for button debounce
union	U1
{
	struct S1
	{
		unsigned char	count:4;			// delay couter
		unsigned char	pkey:1;				// present key state
		unsigned char	oldk:1;				// previous debounced key state
		unsigned char	newk:1;				// new debounced key state
		unsigned char	nuse:1;				// unused
	} flags;
	unsigned char	whole;					// used to preset all variables at once
} keys[3];									// one collection of variables for each key

unsigned char	key_change;					// composite variable for key change
unsigned char	key_index;					// index variable
unsigned char	keymask;					// mask variables for accessing PORTA button inputs

// variable definitions for command decoding
enum {test,fade, man} Sys_state;			// system state variable; test mode, automatic fade, manual
unsigned int	Dim1, Dim2;					// dimming control variables
unsigned char	updn1, updn2;				// direction flags for fade; 0=inc, 1=dec

/******************************************************************************
*						Function Prototypes
******************************************************************************/
// High level prototypes
void	SYSTEM_Start(void);					// start previously configured peripherals
void	Variable_Start(void);				// preload system variables
void	Get_Inputs(void);					// get and debounce buttons
void	Decisions(void);					// decide on changes based on inputs
void	Do_Outputs(void);					// make changes to intensity
void	Timer(void);						// wait for next timer tick

// Support level prototypes
void	debounce(void);						// debound pushbutton state

/******************************************************************************
*						Main Applications
******************************************************************************/
void main(void)
{
    SYSTEM_Initialize();					// configure peripherals
    SYSTEM_Start();							// start peripherals
    Variable_Start();						// preload variables
    while (1)								// loop
    {
		Get_Inputs();						// get button press input and debounce
		Decisions();						// execute pending commands
		Do_Outputs();						// pass dimmer settings to outputs
		Timer();							// regulate loop timing
    }
}
/******************************************************************************
*						High Level Support Functions
******************************************************************************/

/************************************************
* SYSTEM_Start(void)
* 		this function presses the go/done button
*		for any peripheral that requires it to
*		function.  It also contains any patches
*		needed for bugs found in MCC
************************************************/
void	SYSTEM_Start(void)					// peripheral function startup
{
	// Start functions
	PRG1_StartRampGeneration();				// start PRG1
	PRG2_StartRampGeneration();				// start PRG2

	MD1CARL = 0x04;							// set low carrier frequency to fixed low
	MD2CARL = 0x04;							// (missing option in MCC)

	// TMR0 drives timing for user interface
	TMR0IE	= 0;							// disable TMR0 interrupts
	TMR0 	= 0;							// clear timer
	TMR0IF	= 0;							// clear timer flag
}

/************************************************
* Variable_Start(void)
* 		this function presets any variables that
*		requie a preload
************************************************/
void	Variable_Start(void)
{
	// clear flags and counter for debounce array
	for(key_index = 0; key_index < 3; key_index++)	keys[key_index].whole = 0;

	if ((PORTB & 0x20) == 0)			// check for mode switch held at reset
	{
		Sys_state = test;				// if held, then goto test mode
		Dim1  = maxint;					// set both channels to full bright
		Dim2  = maxint;
	}
	else
	{
		key_change	= 0;				// clear any new key indicators

		Sys_state = fade;				// if mode not held, goto normal startup
		Dim1  = ch1st;					// set channel 1 to full dark
		updn1 = intup;					// set for channel 1 increment
		Dim2  = ch2st;					// set channel 2 to 1/2 on
		updn2 = intup;					// set for channel 2 increment
	}
	COG1_AutoShutdownEventClear();		// clear any spurious startup shutdown events
	COG2_AutoShutdownEventClear();
}

/************************************************
* Get_Inputs(void)
* 		this function reads any external inputs
*		and formats the data for internal variables
*	Port	Function	Key
*	RB5		Mode		 1
*	RB6		Channel 1	 2
*	RB7		Channel 2	 3
************************************************/
void	Get_Inputs(void)
{
	keymask = firstkey;												// reset mask to first input
	for(key_index = 0; key_index < 3; key_index++)					// cycle through all 3 switches
	{
		keys[key_index].flags.pkey = 0;								// preset 0 = open
		if((PORTB & keymask) == 0)	keys[key_index].flags.pkey = 1;	// if input is low, 1 = key pressed
		keymask = keymask << 1;										// next input
	}
}

/************************************************
* Decisions(void)
* 		this function make decisions based on
*		external inputs and system timing
*		It contains the command decode statemachine
*		The statemachine has 3 states
*			Test:	No commands decoded or recognized
*					This state holds the boost active
*					for testing
*			Fade:	This mode runs both channels up and
*					down with a 90 degree phase shift
*			Man:	This mode recognizes increment commands
*					for each channel
************************************************/
void	Decisions(void)
{
	debounce();
	switch(Sys_state)
	{
		case test:	break;							// test mode for loop testing
													// no exit, power cycle to clear

					// automatic fade in and out
		case fade:	if(key_change == mode)			// if mode change command
					{
						Sys_state = man;
						Dim1	= 0;				// set channel 1 to full dark
						updn1 	= intup;			// set channel 1 to increment (not required)
						Dim2	= 0;				// set channel 2 to full dark
						updn2	= intup;			// set channel 2 to increment (not required)
					}
					if(updn1 == 0)							// if channel 1 increment
					{
						Dim1 += 1;							// increment intensity
						if(Dim1 == maxint) updn1 = intdn;	// check for top end and switch direction if needed
					}
					else									// if channel 1 not increment
					{
						Dim1 -= 1;							// decrement intensity
						if(Dim1 == 0) updn1 = intup;		// check for bottom and switch direction if needed
					}
					if(updn2 == 0)							// if channel 2 increment
					{
						Dim2 += 1;							// increment intensity
						if(Dim2 == maxint) updn2 = intdn;	// check for top end and switch direction if needed
					}
					else									// if channel 2 not increment
					{
						Dim2 -= 1;							// decrement intensity
						if(Dim2 == 0) updn2 = intup;		// check for bottom and switch direction if needed
					}
					break;

					// manual control mode
		case man:	if(key_change == chan1) Dim1 +=0x10;	// if increment channel 1 command
					if(key_change == chan2) Dim2 +=0x10;	// if increment channel 2 command
					if(key_change == mode)					// if mode change command
					{
						Sys_state = fade;				// return to auto fade in/out mode
						Dim1  = ch1st;					// set channel 1 to full dark
						updn1 = intup;					// set for channel 1 increment
						Dim2  = ch2st;					// set channel 2 to 1/2 on
						updn2 = intup;					// set for channel 2 increment
					}
					break;

					// state variable is corrupted
		default:	Sys_state = fade;					// reset to the default state
					Dim1  = ch1st;					// set channel 1 to full dark
					updn1 = intup;					// set for channel 1 increment
					Dim2  = ch2st;					// set channel 2 to 1/2 on
					updn2 = intup;					// set for channel 2 increment
					break;
	}
	key_change = 0;										// clear variable to show command handled

	if (M_COGASDE)										// if an undervoltage shutdown occurs, turn off
	{													// dimming PWM
		Dim1 = 0;
		Dim2 = 0;
	}
}

/************************************************
* Do_Outputs(void)
* 		this function takes the outputs of the
*		decisions function and generates a
*		synchronized output from the software to the
*		dimming PWMs (PWM3[CH1], PWM3[CH2])
************************************************/
void	Do_Outputs(void)					// make changes to intensity
{
	PWM3_LoadDutyValue(Dim1);				// PWM3 drives channel 1
	PWM4_LoadDutyValue(Dim2);				// PWM4 drives channel 2
}

/************************************************
* Timer(void)
* 		this function regulates the loops timing
*		by delaying until the start of the next
*		system tick (TMR0 roll over)
************************************************/
void	Timer(void)							// delay until TMR0 overflow
{
	while(TMR0IF == 0);
	TMR0IF	= 0;
}

/******************************************************************************
*						Support Level Support Functions
******************************************************************************/

/************************************************
* debounce(void)
* 		this function takes data collected in the
*		.pkey variable and determines when a new
*		button press is generated, when it is, the
*		key_change will hold the key number [1..3]
*
*		System increments counter when button is closed
*		and decrements counter when button is open
*		Closed condition occurs when counter = 0x0C
*		Open condition occurs when coutner = 0x04
* 		if old != new key then open to closed transition
*		new is copied into old for next pass
************************************************/
void	debounce(void)
{
	for(key_index = 0; key_index < 3; key_index++)
	{
		// process key pressed (button pressed and counter < max)
		if((keys[key_index].flags.pkey > 0) && (keys[key_index].flags.count < 0x0F))
		{
			keys[key_index].flags.count++;		// count keypress

			// if count = hi-hyst keypressed
			if (keys[key_index].flags.count == 0x0C) keys[key_index].flags.newk = 1;

			// of new = 1 and old = 0, then keypress event
			if ((keys[key_index].flags.newk == 1) && (keys[key_index].flags.oldk == 0))
			{

			// log keypress event into key_change
				key_change = key_index + 1;

				// copy new key into old key
				keys[key_index].flags.oldk = 1;
			}
		}
		// presess key open (button open and counter > 0)
		if((keys[key_index].flags.pkey == 0) && (keys[key_index].flags.count > 0))
		{
			keys[key_index].flags.count--;		// count keyopen

			// if count = lo-hyst keyopen
			if (keys[key_index].flags.count == 0x04) keys[key_index].flags.newk = 0;

			// of new = 0 and old = 1, then keyrelease event
			if ((keys[key_index].flags.newk == 0) && (keys[key_index].flags.oldk == 1))
			{

				// copy new key into old key
				keys[key_index].flags.oldk = 0;
			}
		}
	}

}

/******************************************************************************
*						End of File
******************************************************************************/
