/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18875
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

#define SWUART_TX_BUFFER_SIZE 8
#define SERIAL_TX_MASK 0x01

#define SW_TX_LAT LATBbits.LATB0

// Variable declarations for SWUART TX buffer
static uint8_t swuartTxHead = 0;
static uint8_t swuartTxTail = 0;
static uint8_t swuartTxBuffer[SWUART_TX_BUFFER_SIZE];
volatile uint8_t swuartTxBufferRemaining;
static uint8_t swuartTxBitCount, swuartTxData;

// Enumeration of serial states
typedef enum{
    SERIAL_SEND_START_BIT,
    SERIAL_SEND_BYTE,
    SERIAL_SEND_STOP_BIT,
    SERIAL_SEND_BREAK,
    SERIAL_RCV_START_BIT,
    SERIAL_RCV_STOP_BIT,
    SERIAL_RCV_BYTE,
    SERIAL_RCV_BREAK,
    SERIAL_IDLE
}serial_state_t;

static volatile serial_state_t serialState;
// Declaration of serial flags
typedef union{
    struct{
        unsigned SW_TRMT    : 1;
        unsigned SW_OERR    : 1;
        unsigned SW_FERR    : 1;
        unsigned SW_SENDB   : 1;
        unsigned SW_ABDEN   : 1;
        unsigned rsvd       : 3;
    }; 
    uint8_t SERIAL_FLAGS;    
}serial_flag_t;

serial_flag_t serialFlag;

void BB_TimerInterruptHandler(void){
    switch(serialState){
        case SERIAL_SEND_START_BIT:
            SW_TX_LAT = LOW;
            serialState = SERIAL_SEND_BYTE;
            swuartTxBitCount = 0;   
            break;
        case SERIAL_SEND_BYTE:
            if(swuartTxBitCount < 8){
                if(swuartTxData & SERIAL_TX_MASK){
                    SW_TX_LAT = HIGH;
                }
                else{
                    SW_TX_LAT = LOW;
                }
                swuartTxData >>= 1;
                swuartTxBitCount++;
            }
            else{
                SW_TX_LAT = HIGH;      
                serialState = SERIAL_SEND_STOP_BIT;
            }
            break;
        case SERIAL_SEND_STOP_BIT:     
            if(sizeof(swuartTxBuffer)> swuartTxBufferRemaining){
                swuartTxData = swuartTxBuffer[swuartTxTail++];
                if(sizeof(swuartTxBuffer)<= swuartTxTail){
                    swuartTxTail = 0;
                }
                swuartTxBufferRemaining++;
                serialState = SERIAL_SEND_START_BIT;
            }
            else{
                serialFlag.SW_TRMT = 1;
            }
            break;
        case SERIAL_SEND_BREAK:
            if(swuartTxBitCount < 10){
                swuartTxBitCount++;
            }
            else{
                SW_TX_LAT = HIGH;
                serialState = SERIAL_SEND_STOP_BIT;
            }
            break;
        case SERIAL_IDLE:
            break;
    }
}

// Initialize and wait for transmission of break character
void SWUART_SendBreak (void){
    serialState = SERIAL_SEND_BREAK;
    serialFlag.SW_SENDB = 0;
}

void BB_Initialize(void) {
    TMR0_SetInterruptHandler(BB_TimerInterruptHandler);
    
    serialState = SERIAL_IDLE;
    serialFlag.SERIAL_FLAGS = 0x00;
    serialFlag.SW_TRMT = 1;
    
    SW_TX_LAT = HIGH;
    
    swuartTxBufferRemaining = sizeof(swuartTxBuffer);
}

void BB_Write(char tx){
    while(0 == swuartTxBufferRemaining){   
    }
    
    if(serialFlag.SW_TRMT) {
        if (serialFlag.SW_SENDB) {
            SWUART_SendBreak();
        }
        else {
            swuartTxData = tx;
            serialState = SERIAL_SEND_BYTE;
        }
        serialFlag.SW_TRMT = 0;
        SW_TX_LAT = LOW;
        swuartTxBitCount = 0;
    }
    else {
        swuartTxBuffer[swuartTxHead++] = tx;
        if(sizeof(swuartTxBuffer) <= swuartTxHead){
            swuartTxHead = 0;
        }
    }
    swuartTxBufferRemaining--;
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    BB_Initialize();
    
    while (1)
    {
        BB_Write('M');
        __delay_ms(100);
        BB_Write('I');
        __delay_ms(100);
        BB_Write('N');
        __delay_ms(100);
        BB_Write('S');
        __delay_ms(100);
        BB_Write('A');
        __delay_ms(100);
        BB_Write('S');
        __delay_ms(100);
        BB_Write('I');
        __delay_ms(100);
        BB_Write('\r');
        __delay_ms(100);
        BB_Write('\n');
    }
}
/**
 End of File
*/