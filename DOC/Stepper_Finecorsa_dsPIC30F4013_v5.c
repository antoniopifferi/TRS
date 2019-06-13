//#define __dsPIC30F4013__

// FIRMWARE STEPPER FINECORSA - version 5

//---------------------------------------------------------------------------
// Configuration bits

//   _FOSC(CSW_FSCM_OFF & XT_PLL16);  //XT with 16xPLL oscillator, Clock switching off, Failsafe clock off
//   _FWDT(WDT_OFF);                  //Watchdog timer disabled
//   _FBORPOR(PBOR_OFF & MCLR_EN);    //Brown-out reset disabled, MCLR reset enabled
//   _FGS(CODE_PROT_OFF);             //Code protect disabled

//---------------------------------------------------------------------------
// 'C' source line config statements

// FOSC
#pragma config FOSFPR = XT_PLL16        // Oscillator (XT w/PLL 4x)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_OFF         // PBOR Enable (Disabled)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = CODE_PROT_OFF      // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
//#include <i2c.h>
#include <p30F4013.h>
#include <stdlib.h>

#define FCY  32000000  // External oscillator 8 MHz

// UART
#define UARTCOMMLEN 4
char UARTretOK[UARTCOMMLEN];
char UARTin[UARTCOMMLEN];

// I2C
//#define	I2CBAUD 0x122; // Baud rate set for 100kHz I2CBRG = INT(FCY/Fscl - FCY/1,111,111)-1
//#define SLAVE_ADD 0x33

#define FALSE	0
#define TRUE	1

#define CLOSE	0
#define OPEN	1

// Hold modality
#define	OFF 0
#define	ON	1

// LCD write modality
//#define OFF	0
#define ALL	1
#define	END	2

#define	FORWARD -1
#define	BACKWARD 1

#define STEPMIN -8388608
#define STEPMAX 8388607
#define STEPHOME 0

//  #define MOTORHALF 0xAB9D576E
#define MOTORHALF 0xB9D576EA
#define HALF 8
#define FULL 4
#define PHASE 4

#define FREQ 100		// step/s	constant vel
#define FREQMAN 20		// step/s	manual velocity
#define FREQHOME 20     // step/s	home velocity
#define _2to16 65536
#define NOREBOUND 50e-3	// 50 ms

#define T1SCALER 256
#define T4SCALER 1
#define LCDTXTLEN 16
#define PRINT_TIME 0.5

/* Constants for LCD */
float LCDResetTime1 = 20e-3; 		// 20 ms; 
float LCDResetTime2 = 5e-3; 		// 5 ms; 
float LCDResetTime3 = 150e-6; 		// 150 us; 
float LCDClearDisplayTime = 2e-3;	// 2 ms executed clear display
float LCDInstTime = 40e-6;			// 40 us executed instructions
float LCDEnabTime = 125e-9;  		// 125 ns enabling time
unsigned char DDRAM_0 = 0x80;		// LCD line 1
unsigned char DDRAM_1 = 0xC0;		// LCD line 2
volatile char text[LCDTXTLEN];      // step
volatile char text_VER[LCDTXTLEN];  // Version
volatile char text_OFF[LCDTXTLEN];  // OFF
volatile char text_REL[LCDTXTLEN];  // Released
volatile char text_TEST[LCDTXTLEN];  // Test

/* Constants for Motor */
unsigned long int MotorCode = MOTORHALF;
unsigned int MotorMode = HALF;
char phase[PHASE][HALF];
int step_index = 0;

float freq = FREQ;

long int step_home = STEPHOME; 
volatile long int step_act; 
volatile long int step_goal; 
volatile int step_dir;
volatile int step_half = 0;

volatile char step_released = 0;
char step_hold = ON;
char step_write = ALL;
char step_end = 0;

/* FUNCTION DECLARATION */
void InitPort(void);
void InitInterrupt(void);
void InitTimer(void);
void InitStep(void);
//void InitI2CSlave(void);
void FreqStep(float);
void StartStep(void);
void StopStep(void);
void GotoStep(void);
void DoStep(void);
void HoldStep(void);
void ReleaseStep(void);
void Delay(float);

void LCDInit(void);
void LCDWriteChar(char);
void LCDWriteInstr(unsigned char);
void LCDWriteBit(unsigned char);
void LCDWrite(volatile char*, unsigned char);
void PrintStep(void);
void Step2Text(long int);

void InitUART(void);
void ClearUARTin(void);
void SendUART(char*);
void CommStep(void);
void TellStep(void);

int main(void) {
	InitPort();
	InitInterrupt();
	InitTimer();
	LCDInit();
	InitUART();	
//	InitI2CSlave();
	InitStep();
	while(1); 			// repeat forever
	
	}

void InitPort(void) {

	// Motor phases
	TRISFbits.TRISF0=0;		// Initialize as output RF0
	TRISFbits.TRISF1=0;		// Initialize as output RF1
	TRISFbits.TRISF4=0;		// Initialize as output RF4
	TRISFbits.TRISF5=0;	    // Initialize as output RF5
	//Fine corsa
	TRISFbits.TRISF6=1;	    // Initialize as input RF6

	//Release stepper
	LATFbits.LATF0 = 1;
	LATFbits.LATF1 = 1;
	LATFbits.LATF4 = 1;
	LATFbits.LATF5 = 1;

	//Display
	TRISBbits.TRISB0=0;		// Initialize as output RB0 -> RS
//	TRISBbits.TRISB1=0;		// Initialize as output RB1 -> R/W
	TRISBbits.TRISB2=0;	    // Initialize as output RB2 -> E

	TRISBbits.TRISB3=0;		// Initialize as output RB2 -> DB4
	TRISBbits.TRISB4=0;	    // Initialize as output RB3 -> DB5
	TRISBbits.TRISB5=0;	    // Initialize as output RB4 -> DB6
	TRISBbits.TRISB8=0;	    // Initialize as output RB5 -> DB7

	//interrupt
	TRISAbits.TRISA11=1;	    // Initialize as input RA11 (INT0) (UP/DW)
	TRISDbits.TRISD2 =1;		// Initialize as input RD2  (UP)
	TRISDbits.TRISD3 =1;		// Initialize as input RD3  (DW)
	TRISDbits.TRISD8 =1;		// Initialize as input RD8  (INT1) (ZERO)

	}

void InitInterrupt(void) {
	
	IFS0bits.U1RXIF = 0;	// clear UART RX interrupt flag
	IFS0bits.U1TXIF = 0;	// clear UART TX interrupt flag
	IFS0bits.INT0IF = 0;	// clear INT0 interrupt flag
	IFS1bits.INT1IF = 0;	// clear INT1 interrupt flag
	IFS0bits.T1IF = 0;		// clear TIMER1 interrupt flag
	IFS0bits.T3IF = 0;		// clear TIMER3 interrupt flag
	IFS1bits.T5IF = 0;		// clear TIMER5 interrupt flag
//	IFS0bits.SI2CIF=0;	    // clear I2C slave interrupt flag
	
	IPC1bits.T3IP = 7;		// priority of TIMER3 higher than other interrupt
	IPC0bits.T1IP = 5;		// priority of TIMER1 third interrupt in priority
	IPC2bits.U1TXIP = 6;	// priority of U1TX second interrupt in priority 
	IPC2bits.U1RXIP = 6;	// priority of U1RX second interrupt in priority
//	IPC3bits.SI2CIP = 6;	// priority of I2C second interrupt in priority 

	IEC0bits.U1RXIE = 1;	// UART RX Interrupt enabled
	IEC0bits.U1TXIE = 1;	// UART TX Interrupt enabled
	IEC0bits.INT0IE = 1;	// INT0 Interrupt enabled (solo se c'è la routine!)
	IEC1bits.INT1IE = 1;	// INT1 Interrupt enabled (solo se c'è la routine!)
	IEC0bits.T1IE = 1;		// TIMER1 Interrupt enabled (solo se c'è la routine!)
	IEC0bits.T3IE = 1;		// TIMER3 Interrupt enabled (solo se c'è la routine!)
//	IEC1bits.T5IE = 1;		// TIMER5 Interrupt enabled (solo se c'è la routine!)
//	IEC0bits.SI2CIE = 1;    // I2C slave interrupt enabled (solo se c'è la routine!)

	INTCON2bits.INT0EP = 1;	// Set INT0 interrupt on negative edge
	INTCON2bits.INT1EP = 1;	// Set INT1 interrupt on negative edge

	return;
	}

void InitTimer(void) {
	
	T1CON = 0x0030;	// timer 1 with prescaler 256
	T2CON = 0x0008;	// timer 2 and 3 combined to form a 32-bit timer
	T4CON = 0x0008;	// timer 4 and 5 combined to form a 32-bit timer
	TMR1 = 0;
	TMR2 = 0;
	TMR3 = 0;
	TMR4 = 0;
	TMR5 = 0;

	PR1 = ((unsigned long int) ((FCY / T1SCALER) * PRINT_TIME)) & 0xFFFF;

	return;
	}

void LCDInit (void) {

	unsigned char ResetWord = 0x3;
	unsigned char FunctSet = 0x28;  // 4-bit interface, 2 line, big font
	unsigned char DisplayOFF = 0x8;
	unsigned char DisplayON = 0xC;
	unsigned char ClearDisplay = 0x1;
	unsigned char EntryModeSet = 0x6;
	int ic;
	
//	start LCD initialization
	Delay(LCDResetTime1);

	LATBbits.LATB0=0;
	LATBbits.LATB1=0;
	LATBbits.LATB2=0;

	LCDWriteBit(ResetWord);
	Delay(LCDResetTime2);
	LCDWriteBit(ResetWord);
	Delay(LCDResetTime3);
	LCDWriteBit(ResetWord);
	Delay(LCDInstTime);	
	LCDWriteBit((FunctSet>>4) & 0xF);
	Delay(LCDInstTime);	
	LCDWriteInstr(FunctSet);
	LCDWriteInstr(DisplayOFF);
	LCDWriteInstr(ClearDisplay);
	Delay(LCDClearDisplayTime);	
	LCDWriteInstr(EntryModeSet);
//	end LCD initialization
	
	LCDWriteInstr(DisplayON);

//	Init text_VER
	ic = 0;
    text_VER[ic++] = 'F';
	text_VER[ic++] = 'I';
	text_VER[ic++] = 'N';
    text_VER[ic++] = 'E';
	text_VER[ic++] = 'C';
	text_VER[ic++] = 'O';
    text_VER[ic++] = 'R';
	text_VER[ic++] = 'S';
	text_VER[ic++] = 'A';
    text_VER[ic++] = ' ';
	text_VER[ic++] = 'v';
	text_VER[ic++] = '5';
	for(ic; ic<LCDTXTLEN; ic++) text_VER[ic]=' ';

//	Init text_OFF	
	ic = 0;
    text_OFF[ic++] = 'O';
	text_OFF[ic++] = 'F';
	text_OFF[ic++] = 'F';
	for(ic; ic<LCDTXTLEN; ic++) text_OFF[ic]=' ';

//	Init text_Released	
	ic = 0;
    text_REL[ic++] = 'R';
	text_REL[ic++] = 'e';
	text_REL[ic++] = 'l';
    text_REL[ic++] = 'e';
	text_REL[ic++] = 'a';
	text_REL[ic++] = 's';
    text_REL[ic++] = 'e';
	text_REL[ic++] = 'd';
	for(ic; ic<LCDTXTLEN; ic++) text_REL[ic]=' ';

//	Init text_TEST
	ic = 0;
    text_TEST[ic++] = 'T';
	text_TEST[ic++] = 'E';
	text_TEST[ic++] = 'S';
    text_TEST[ic++] = 'T';
	for(ic; ic<LCDTXTLEN; ic++) text_TEST[ic]=' ';

	return;
    
	return;
	}

void LCDWriteBit(unsigned char Bit) {

	//Output 4-bits
	LATBbits.LATB3=Bit & 1;
	LATBbits.LATB4=(Bit >> 1) & 1;
	LATBbits.LATB5=(Bit >> 2) & 1;
	LATBbits.LATB8=(Bit >> 3) & 1;
	
	//Enable/Disable
	LATBbits.LATB2=1;
	Delay(LCDEnabTime);
	LATBbits.LATB2=0;

	return;
	}

void LCDWriteChar(char Byte) {

	LATBbits.LATB0=1;
	LATBbits.LATB1=0;
	LCDWriteBit((Byte>>4) & 0xF);
	LATBbits.LATB0=1;
	LATBbits.LATB1=0;
	LCDWriteBit(Byte & 0xF);
	Delay(LCDInstTime);	

	return;
	}

void LCDWriteInstr(unsigned char Byte) {

	LATBbits.LATB0=0;
	LATBbits.LATB1=0;
	LCDWriteBit((Byte>>4) & 0xF);
	LATBbits.LATB0=0;
	LATBbits.LATB1=0;
	LCDWriteBit(Byte & 0xF);
	Delay(LCDInstTime);	

	return;
	}

void LCDWrite(volatile char *string, unsigned char addr) {

	int ic;

	//Set address line 1
	LCDWriteInstr(addr);
	for(ic=0; ic<LCDTXTLEN; ic++) LCDWriteChar(string[ic]);

	return;
	}

void InitStep() {

	int ic,icc;
	
    LCDWrite(text_VER, DDRAM_0);

	for(ic=0; ic<MotorMode; ic++)
		for(icc=0; icc<PHASE; icc++) 
			phase[icc][ic] = ( MotorCode >> ((PHASE*ic)+icc) ) & 0x1;

//	Ricerca Home
	FreqStep(FREQHOME);
	HoldStep();
	Delay(1./FREQHOME);
	step_act = 0;
	step_goal = STEPMAX;
	step_dir = FORWARD;
	GotoStep();
	while(PORTFbits.RF6);
	StopStep();
	Delay(1./FREQHOME);
	
	step_act = 0;
	step_goal = STEPMIN;
	step_dir = BACKWARD;
	GotoStep();
	while(!PORTFbits.RF6);
	StopStep();
	Delay(1./FREQHOME);

//	Fine Ricerca Home

    FreqStep(freq);
	step_act = step_home;

	if((step_hold == OFF)&&(!step_released)) ReleaseStep(); 

	if(step_write != OFF) PrintStep();

	return;
	}
	
//Create a delay of "time" seconds
void Delay(float time) {

	unsigned long int clock_time;
	
	clock_time = (FCY / T4SCALER) * time;

	PR5 = clock_time >> 16;
	PR4 = clock_time & 0xFFFF;

	T4CONbits.TON = 1;
	while(!IFS1bits.T5IF);
	T4CONbits.TON = 0;
	IFS1bits.T5IF = 0;
	TMR4 = 0;
	TMR5 = 0;
	
	return;
	}

void FreqStep(float freq) {
	
	unsigned long int clock_freq;

	clock_freq = (unsigned long int) (FCY / (2.*freq));
	PR3 = clock_freq >> 16;
	PR2 = clock_freq & 0xFFFF;

	return;
	}

void StartStep() {

    step_half = 0;
	if (step_released) HoldStep();

	T2CONbits.TON = 1;
	T1CONbits.TON = 1;	//start counter for LCD
//    step_going = ON;

	return;
	}
	
void StopStep() {

	while(step_half);
	T2CONbits.TON = 0;
	TMR2 = 0;
	TMR3 = 0;

	T1CONbits.TON = 0;	//reset counter for LCD
	TMR1 = 0;

	if(step_end) {
		TellStep();
		step_end = 0;
		}

    //    step_going = OFF;
	if(step_hold == OFF) ReleaseStep(); 
	if(step_write != OFF) PrintStep();

	return;
	}

void GotoStep(void) {

	if(step_act == step_goal) return;
	else if(step_goal > step_act) step_dir = FORWARD;
	else step_dir = BACKWARD;

	StartStep();

	return;
	}

void DoStep(void) {

	step_index = (step_index+step_dir) & 0x7;
	LATFbits.LATF0 = phase[0][step_index];
	LATFbits.LATF1 = phase[1][step_index];
	LATFbits.LATF4 = phase[2][step_index];
	LATFbits.LATF5 = phase[3][step_index];
	step_half = !step_half;
    if(!step_half) {
    	if(step_dir == FORWARD) step_act++;
        else step_act--;
        }
	return;
	}

void HoldStep(void) {
	
	LATFbits.LATF0 = phase[0][step_index];
	LATFbits.LATF1 = phase[1][step_index];
	LATFbits.LATF4 = phase[2][step_index];
	LATFbits.LATF5 = phase[3][step_index];
	step_released = 0;
	if(step_write != OFF) PrintStep();
    else LCDWrite(text_OFF, DDRAM_1);

	return;
	}

void ReleaseStep(void) {

	LATFbits.LATF0 = 1;
	LATFbits.LATF1 = 1;
	LATFbits.LATF4 = 1;
	LATFbits.LATF5 = 1;
	step_released = 1;
    LCDWrite(text_REL, DDRAM_1);

	return;
	}

void _ISR _T1Interrupt(void) {
	
	IFS0bits.T1IF = 0;		// clear TIMER1 interrupt flag

	if (step_write) PrintStep();
	
	}	

void _ISR _T3Interrupt(void) {
	
	IFS0bits.T3IF = 0;		// clear TIMER3 interrupt flag

	if(step_act == step_goal) {
		StopStep();
        return;
		}

    DoStep();

	return;
	}

// UP/DW step interrupt
void _ISR _INT0Interrupt(void) {

	int go;

	Delay(NOREBOUND);
	IFS0bits.INT0IF = 0;	// clear interrupt flag
	if(PORTAbits.RA11) return;

	go = FALSE;
	do {
		if (!PORTDbits.RD2 && PORTDbits.RD3) {
			step_goal = STEPMAX;
			go = TRUE;
			}	
		else if (PORTDbits.RD2 && !PORTDbits.RD3) {
			step_goal = STEPMIN;
			go = TRUE;
			}
		}	
	while (!go);

	FreqStep(FREQMAN);

	GotoStep();

	while((!PORTAbits.RA11)&&(T2CONbits.TON));
    
	StopStep();
	Delay(1./FREQMAN);
    
	FreqStep(freq);
    
	if((step_hold == OFF)&&(!step_released)) ReleaseStep();	
    return;
	}

// Zero interrupt (INT1)
void _ISR _INT1Interrupt(void) {

	Delay(NOREBOUND);

	IFS1bits.INT1IF = 0;	// clear interrupt flag
	if(PORTDbits.RD8) return;

	StopStep();
	step_goal = step_home;
	GotoStep();
    
    return;
	}

/*
void InitI2CSlave(void) {

	unsigned int Conf7Bit;
	Conf7Bit = (I2C_ON & I2C_IDLE_CON & I2C_CLK_HLD & I2C_IPMI_DIS & 
			I2C_7BIT_ADD & I2C_SLW_DIS & I2C_SM_DIS & I2C_GCALL_EN & I2C_STR_DIS & 
			I2C_NACK & I2C_ACK_DIS & I2C_RCV_EN & I2C_STOP_EN & 
			I2C_RESTART_EN & I2C_START_EN);
	I2CADD = SLAVE_ADD; //set Slave address slave number 6
//	EnableIntSI2C;  //enable I2C slave interrupts
//	OpenI2C(Conf7Bit, I2CBAUD);  //in the slave the I2C module is always active since an I2C interrupt may come in avery moment
	I2CCON = Conf7Bit;
	I2CBRG = I2CBAUD;		
	}

//slave receive interrupt
void _ISR _SI2CInterrupt(void) {
	
	unsigned char buffer;

	IFS0bits.SI2CIF=0; //clear Interrupt flag
	
	//buffer=I2CRCV; //data are stored in I2CRCV register 
	if(I2CSTATbits.R_W == 0) {	// check if master is in write mode
		while(!I2CSTATbits.RBF);
		IFS0bits.SI2CIF=0; //clear Interrupt flag
		buffer = I2CRCV;
		LATDbits.LATD1 = (buffer >> 3) & 0x1;
//		Shutter();
		step_goal = (buffer & 0x07)*STEPFACT;
		GotoStep();		
		}
	else if (I2CSTATbits.R_W == 1) { //if master is set for read mode the slave puts data un the I2CTRN buffer
//		buffer = (step_act%STEPROUND)/STEPFACT + 8*shut_act;
		I2CTRN = buffer;
		while(I2CSTATbits.TBF); //wait intill the buffer is full
		}
	}
*/

void PrintStep(void) {

	Step2Text(step_act);
	LCDWrite(text, DDRAM_1);

	return;
	}

void Step2Text(long int value) {
	
	unsigned char digit;
	char sign = ' ';
	int ic;

	if (value<0) {value = -value; sign='-';}

	ic = 0;
	do {
		digit = value - value/10 * 10;
		text[LCDTXTLEN-1-ic] = '0'+digit;
		value = (value-digit)/10;
		ic++;
		}
	while(value>0);

	text[LCDTXTLEN-1-ic] = sign;
	while(++ic<LCDTXTLEN) text[LCDTXTLEN-1-ic]=' ';
	
	return;
	}

// UART ROUTINES
void InitUART(void) {
	
	int ic;

	U1BRG = 0; // BAUDRATE = FCY/16/(U1BGR + 1) = 2000000
	U1MODE = 0x8400;	// Alternate I/O enabled: used U1ATX and U1ARX
	U1STA = 0x84C0;
	
	for(ic=0; ic<UARTCOMMLEN; ic++) UARTretOK[ic]= 0;
	ClearUARTin();

	}

void ClearUARTin(void) {

	int ic;
	for(ic=0; ic<UARTCOMMLEN; ic++) UARTin[ic]= 0;

	}

// interrupt vector for UART TX interrupt
void _ISR _U1TXInterrupt(void) {
	
	IFS0bits.U1TXIF = 0;	// clear interrupt flag
	}

// interrupt vector for UART RX interrupt
void _ISR _U1RXInterrupt(void) {
    
	int ic;

//  clear interrupt flag
	IFS0bits.U1RXIF = 0;

	for (ic=0; ic<UARTCOMMLEN; ic++) {
		UARTin[ic] = U1RXREG;
		}
	CommStep();
	return;
	}

void SendUART(char *ret) {

	int ic;

	for(ic=0; ic<UARTCOMMLEN; ic++) {
		while(U1STAbits.UTXBF);
		U1TXREG = *(ret+ic);		
		}
	}

void CommStep(void) {
	char command;
	long int value;
	long int dir;
	
	//read command
	command = UARTin[UARTCOMMLEN-1];
	if(UARTin[UARTCOMMLEN-2]<0) UARTin[UARTCOMMLEN-1]= 0xFF;
	else UARTin[UARTCOMMLEN-1]= 0x00;
	value = *((long int*) UARTin);
	switch(command) {
		case 'I':
		case 'i':
			step_home = value;
			InitTimer();
			InitStep();
			SendUART(UARTretOK);
			break;

		case 'V':
		case 'v':
			freq = value;
            FreqStep(value);
			SendUART(UARTretOK);
			break;

		case 'M':
		case 'm':
			SendUART(UARTretOK);
			break;

		case 'A':
		case 'a':
			SendUART(UARTretOK);
			break;

		case 'W':
		case 'w':
			step_write = value;
			if(step_write == OFF) LCDWrite(text_OFF, DDRAM_1);
            else PrintStep();
			SendUART(UARTretOK);
			break;

		case 'S':
		case 's':
			dir = value;
			if(dir>0) {step_dir = FORWARD; step_goal = STEPMAX;}
			else {step_dir = BACKWARD; step_goal = STEPMIN;}
			GotoStep();
			SendUART(UARTretOK);
			break;

		case 'F':
		case 'f':
			step_end = 1;
        	if(step_dir == FORWARD) step_goal = step_act+1;
            else step_goal = step_act-1;
        //	StopStep();
			break;

		case 'H':
		case 'h':
			step_hold = value;
			if(step_hold != OFF) {
                HoldStep();
               	Delay(1./FREQHOME);
                }
			else ReleaseStep();
			SendUART(UARTretOK);
			break;

		case 'E':
		case 'e':
//			if(step_hold == MEAS) ReleaseStep();
			SendUART(UARTretOK);
			break;

		case 'G':
		case 'g':
			step_goal = value;
			GotoStep();
			SendUART(UARTretOK);
			break;

		case 'C':
		case 'c':
			step_goal = step_home;
			GotoStep();
			SendUART(UARTretOK);
			break;

		case 'T':
		case 't':
			TellStep();
			break;

		case 'R':
		case 'r':
			ReleaseStep();
			SendUART(UARTretOK);
			break;

		case ';':
			break;
		}
	
	ClearUARTin();
	
	}

void TellStep(void) {

	SendUART( (char*) &step_act );
	}
