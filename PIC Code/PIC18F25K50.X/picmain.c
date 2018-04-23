/******************************************************************************/
/* Configuration bits                                                         */
/******************************************************************************/

// CONFIG1L
#pragma config PLLSEL = PLL3X    // PLL Selection->3x clock multiplier
#pragma config CFGPLLEN = ON    // PLL Enable Configuration bit->PLL Enabled
#pragma config CPUDIV = NOCLKDIV    // CPU System Clock Postscaler->CPU uses system clock (no divide)
#pragma config LS48MHZ = SYS48X8    // Low Speed USB mode with 48 MHz system clock->System clock at 48 MHz, USB clock divider is set to 8

// CONFIG1H
#pragma config FOSC = INTOSCIO    // Oscillator Selection->Internal oscillator
#pragma config PCLKEN = ON    // Primary Oscillator Shutdown->Primary oscillator enabled
#pragma config FCMEN = OFF    // Fail-Safe Clock Monitor->Fail-Safe Clock Monitor disabled
#pragma config IESO = OFF    // Internal/External Oscillator Switchover->Oscillator Switchover mode disabled

// CONFIG2L
#pragma config nPWRTEN = OFF    // Power-up Timer Enable->Power up timer disabled
#pragma config BOREN = SBORDIS    // Brown-out Reset Enable->BOR enabled in hardware (SBOREN is ignored)
#pragma config BORV = 190    // Brown-out Reset Voltage->BOR set to 1.9V nominal
#pragma config nLPBOR = OFF    // Low-Power Brown-out Reset->Low-Power Brown-out Reset disabled

// CONFIG2H
#pragma config WDTEN = OFF    // Watchdog Timer Enable bits->WDT disabled in hardware (SWDTEN ignored)
#pragma config WDTPS = 32768    // Watchdog Timer Postscaler->1:32768

// CONFIG3H
#pragma config CCP2MX = RC1    // CCP2 MUX bit->CCP2 input/output is multiplexed with RC1
#pragma config PBADEN = ON    // PORTB A/D Enable bit->PORTB<5:0> pins are configured as analog input channels on Reset
#pragma config T3CMX = RC0    // Timer3 Clock Input MUX bit->T3CKI function is on RC0
#pragma config SDOMX = RC7    // SDO Output MUX bit->SDO function is on RC7
#pragma config MCLRE = ON    // Master Clear Reset Pin Enable->MCLR pin enabled; RE3 input disabled

// CONFIG4L
#pragma config STVREN = ON    // Stack Full/Underflow Reset->Stack full/underflow will cause Reset
#pragma config LVP = ON    // Single-Supply ICSP Enable bit->Single-Supply ICSP enabled if MCLRE is also 1
#pragma config ICPRT = OFF    // Dedicated In-Circuit Debug/Programming Port Enable->ICPORT disabled
#pragma config XINST = OFF    // Extended Instruction Set Enable bit->Instruction set extension and Indexed Addressing mode disabled
#pragma config DEBUG = OFF    // Background Debugger Enable bit->Background debugger disabled

// CONFIG5L
#pragma config CP0 = OFF    // Block 0 Code Protect->Block 0 is not code-protected
#pragma config CP1 = OFF    // Block 1 Code Protect->Block 1 is not code-protected
#pragma config CP2 = OFF    // Block 2 Code Protect->Block 2 is not code-protected
#pragma config CP3 = OFF    // Block 3 Code Protect->Block 3 is not code-protected

// CONFIG5H
#pragma config CPB = OFF    // Boot Block Code Protect->Boot block is not code-protected
#pragma config CPD = OFF    // Data EEPROM Code Protect->Data EEPROM is not code-protected

// CONFIG6L
#pragma config WRT0 = OFF    // Block 0 Write Protect->Block 0 (0800-1FFFh) is not write-protected
#pragma config WRT1 = OFF    // Block 1 Write Protect->Block 1 (2000-3FFFh) is not write-protected
#pragma config WRT2 = OFF    // Block 2 Write Protect->Block 2 (04000-5FFFh) is not write-protected
#pragma config WRT3 = OFF    // Block 3 Write Protect->Block 3 (06000-7FFFh) is not write-protected

// CONFIG6H
#pragma config WRTC = OFF    // Configuration Registers Write Protect->Configuration registers (300000-3000FFh) are not write-protected
#pragma config WRTB = OFF    // Boot Block Write Protect->Boot block (0000-7FFh) is not write-protected
#pragma config WRTD = OFF    // Data EEPROM Write Protect->Data EEPROM is not write-protected

// CONFIG7L
#pragma config EBTR0 = OFF    // Block 0 Table Read Protect->Block 0 is not protected from table reads executed in other blocks
#pragma config EBTR1 = OFF    // Block 1 Table Read Protect->Block 1 is not protected from table reads executed in other blocks
#pragma config EBTR2 = OFF    // Block 2 Table Read Protect->Block 2 is not protected from table reads executed in other blocks
#pragma config EBTR3 = OFF    // Block 3 Table Read Protect->Block 3 is not protected from table reads executed in other blocks

// CONFIG7H
#pragma config EBTRB = OFF    // Boot Block Table Read Protect->Boot block is not protected from table reads executed in other blocks


/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif


/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main(void)
{
    /* Configure the oscillator for the device */
    // SCS FOSC; IDLEN disabled; IRCF 16MHz; 
    OSCCON = 0x70;
    // INTSRC INTRC_31_25KHz; PLLEN disabled; PRISD disabled; SOSCGO disabled; 
    OSCCON2 = 0x00;
    // SPLLMULT 3xPLL; TUN 0; 
    OSCTUNE = 0x80;
    // ACTSRC SOSC; ACTUD enabled; ACTEN disabled; 
    ACTCON = 0x00;
    // Wait for PLL to stabilize
    while(PLLRDY == 0)
    {
    }

    /* Initialize I/O and Peripherals for application */
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;

    /**
    ANSELx registers
    */
    ANSELC = 0x00;
    ANSELB = 0x00;
    ANSELA = 0x00;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    INTCON2bits.nRBPU = 1;

    //PORTC
    
    //Level Shifter VCC Always on
    PORTC = 0b00000111;
    
    while(1)
    {
        
        PORTB = 0b00001110;
        _delay(22);
        PORTA = 0b00001110;
         _delay(22);
        PORTA = 0b00001111;
        _delay(34);     
    
        PORTB = 0b00001101;
        _delay(22);
        PORTA = 0b00001101;
         _delay(22);
        PORTA = 0b00001111;
        _delay(34);

        PORTB = 0b00001011;
        _delay(22);
        PORTA = 0b00001011;
         _delay(22);
        PORTA = 0b00001111;
        _delay(34);
  
        PORTB = 0b00000111;
        _delay(22); 
        PORTA = 0b00000111;
         _delay(22);
        PORTA = 0b00001111;
        _delay(34);

    }
}