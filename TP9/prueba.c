#include<stdio.h>
#include <stdint.h>



#define MASK 0x01
enum{PORTA,PORTB,PORTD};

void bitSet(int bit, int puerto);
void bitClr(int bit, int puerto);
int bitGet(int bit, int puerto);
void bitToggle(int bit, int puerto);
void maskOn(int puerto, int mask);
void maskOff(int puerto, int mask);
void maskToggle(int puerto, int mask);


//defino las uniones y estructuras necesarias
    
    typedef struct {        //una estructura de 8 bits
        uint8_t b0 :1;
        uint8_t b1 :1;
        uint8_t b2 :1;
        uint8_t b3 :1;
        uint8_t b4 :1;
        uint8_t b5 :1;
        uint8_t b6 :1;
        uint8_t b7 :1;
    } bitreg_t;

    typedef union {         //esta unión permite acceder a todo el byte "a" o a cada uno de sus bits
        uint8_t acca;
        bitreg_t bitrega;
    } porta_t;
    
    typedef union {         //este es el puerto b, se puede modificar todo el byte o cada uno de sus bits
        uint8_t accb;
        bitreg_t bitregb;
    } portb_t;
    
    typedef struct {        //estructura de 16 bits que contiene ambos puertos
        portb_t b;
        porta_t a;

    } ab_t;
    
    typedef struct {        //estructura con cada uno de los dieciseis bits del puerto d
        uint16_t bd0 :1;
        uint16_t bd1 :1;
        uint16_t bd2 :1;
        uint16_t bd3 :1;
        uint16_t bd4 :1;
        uint16_t bd5 :1;
        uint16_t bd6 :1;
        uint16_t bd7 :1;
        uint16_t bd8 :1;
        uint16_t bd9 :1;
        uint16_t bd10 :1;
        uint16_t bd11 :1;
        uint16_t bd12 :1;
        uint16_t bd13 :1;
        uint16_t bd14 :1;
        uint16_t bd15 :1;
    } bitd_reg_t;
    
    
    typedef union {         //el puerto d, se puede acceder en su totalidad (2 bytes) o trabajar sobre los puertos a y b que lo componenen o sobre cada bit.
        ab_t ab;
        uint16_t d;
        bitd_reg_t bitregd;
    } port_t;
    
    port_t registro;        //defino registro como una unión de este tipo


    int main (void){
	int num=0x33;
	printf("num=%x\n",num);
	printf("PORTD=%X\t\t",registro.d);
        printf("PORTA=%X\t\t",registro.ab.a.acca);
	printf("PORTB=%X\n",registro.ab.b.accb);
	int bit, puerto, mask;
	bit=1; puerto=PORTA;bitSet(bit, puerto); 
	printf("PORTD=%X\t",registro.d);
        printf("PORTA=%X\t\t",registro.ab.a.acca);
	printf("PORTB=%X\n",registro.ab.b.accb);
	bit=7; puerto=PORTB;bitSet(bit, puerto); 
	printf("PORTD=%X\t",registro.d);
        printf("PORTA=%X\t\t",registro.ab.a.acca);
	printf("PORTB=%X\n",registro.ab.b.accb);
	bit=15; puerto=PORTD;bitSet(bit, puerto); 
	printf("PORTD=%X\t",registro.d);
        printf("PORTA=%X\t",registro.ab.a.acca);
	printf("PORTB=%X\n",registro.ab.b.accb);
	bit=7; puerto=PORTB;
	printf("bitGet=%d\n",bitGet(bit, puerto));
	bit=15;puerto=PORTD;bitToggle(bit, puerto);
	printf("PORTD=%X\t",registro.d);
        printf("PORTA=%X\t\t",registro.ab.a.acca);
	printf("PORTB=%X\n",registro.ab.b.accb);
	puerto=PORTA; mask=0xff;maskOn(puerto, mask);
	printf("PORTD=%X\t",registro.d);
        printf("PORTA=%X\t",registro.ab.a.acca);
	printf("PORTB=%X\n",registro.ab.b.accb);
	puerto=PORTD; mask=0x0ff0;maskOff(puerto, mask);
	printf("PORTD=%X\t",registro.d);
        printf("PORTA=%X\t",registro.ab.a.acca);
	printf("PORTB=%X\n",registro.ab.b.accb);
	puerto=PORTD; mask=0xffff;maskToggle(puerto, mask);
	printf("PORTD=%X\t",registro.d);
        printf("PORTA=%X\t\t",registro.ab.a.acca);
	printf("PORTB=%X\n",registro.ab.b.accb);

    }





void bitSet(int bit, int puerto)
{
	uint16_t mask = (MASK<<bit);

	switch(puerto){
		case PORTD:
			registro.d=(registro.d | mask);
			break;
		case PORTA:
			registro.ab.a.acca=(registro.ab.a.acca | (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb=(registro.ab.b.accb | (uint8_t)mask);
			break;
	}
	
}

void bitClr(int bit, int puerto)
{
	uint16_t mask = (~(MASK<<bit));
	
	switch(puerto){
		case PORTD:
			registro.d=(registro.d & mask);
			break;
		case PORTA:
			registro.ab.a.acca=(registro.ab.a.acca & (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb=(registro.ab.b.accb & (uint8_t)mask);
			break;
	}
	
}

int bitGet(int bit, int puerto)
{
	uint16_t mask = (MASK<<bit);
	int result;
	
	switch(puerto){
		case PORTD:
			result=(registro.d & mask);
			break;
		case PORTA:
			result=(registro.ab.a.acca & (uint8_t)mask);
			break;
		case PORTB:
			result=(registro.ab.b.accb & (uint8_t)mask);
			break;
	}
	if(result)
		return 1;
	else
		return 0;
	
}

void bitToggle(int bit, int puerto)
{
	if(bitGet(bit, puerto))
		bitClr(bit, puerto);
	else
		bitSet(bit, puerto);
}
	

void maskOn(int puerto, int mask)
{
	switch(puerto){
		case PORTD:
			registro.d =(registro.d | (uint16_t)mask);
			break;
		case PORTA:
			registro.ab.a.acca =(registro.ab.a.acca | (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb =(registro.ab.b.accb | (uint8_t)mask);
			break;
	}

}


void maskOff(int puerto, int mask)
{
	mask=(~mask);

	switch(puerto){
		case PORTD:
			registro.d=(registro.d & (uint16_t)mask);
			break;
		case PORTA:
			registro.ab.a.acca =(registro.ab.a.acca & (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb=(registro.ab.b.accb & (uint8_t)mask);
			break;
	}

}


void maskToggle(int puerto, int mask)
{
	
	switch(puerto){
		case PORTD:
			registro.d =(registro.d ^ (uint16_t)mask);
			break;
		case PORTA:
			registro.ab.a.acca=(registro.ab.a.acca ^ (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb=(registro.ab.b.accb ^ (uint8_t)mask);
			break;
	}

}













