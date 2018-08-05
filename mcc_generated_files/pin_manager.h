/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18875
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_RA4 aliases
#define LED_RA4_TRIS                 TRISAbits.TRISA4
#define LED_RA4_LAT                  LATAbits.LATA4
#define LED_RA4_PORT                 PORTAbits.RA4
#define LED_RA4_WPU                  WPUAbits.WPUA4
#define LED_RA4_OD                   ODCONAbits.ODCA4
#define LED_RA4_ANS                  ANSELAbits.ANSA4
#define LED_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_RA4_GetValue()           PORTAbits.RA4
#define LED_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED_RA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED_RA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED_RA4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define LED_RA4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set MyTX_RB0 aliases
#define MyTX_RB0_TRIS                 TRISBbits.TRISB0
#define MyTX_RB0_LAT                  LATBbits.LATB0
#define MyTX_RB0_PORT                 PORTBbits.RB0
#define MyTX_RB0_WPU                  WPUBbits.WPUB0
#define MyTX_RB0_OD                   ODCONBbits.ODCB0
#define MyTX_RB0_ANS                  ANSELBbits.ANSB0
#define MyTX_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define MyTX_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define MyTX_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define MyTX_RB0_GetValue()           PORTBbits.RB0
#define MyTX_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define MyTX_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define MyTX_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define MyTX_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define MyTX_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define MyTX_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define MyTX_RB0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define MyTX_RB0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/