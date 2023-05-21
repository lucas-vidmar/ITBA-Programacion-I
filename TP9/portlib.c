#include <stdio.h>
#include <stdint.h>
#include "portlib.h"
#define MASK 0x01

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


//Dado un puerto y un número de bit, cambia su estado a 1.
void bitSet(int bit, int puerto)		
{
	uint16_t mask = (MASK<<bit);			//se ajusta la mascara para modificar el bit deseado.

	switch(puerto){
		case PORTD:
			registro.d=(registro.d | mask);		//se utiliza un or bitwise para setear el bit.
			break;
		case PORTA:
			registro.ab.a.acca=(registro.ab.a.acca | (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb=(registro.ab.b.accb | (uint8_t)mask);
			break;
	}
	
}

//Dado un puerto y un número de bit, cambia su estado a 0.
void bitClr(int bit, int puerto)
{
	uint16_t mask = (~(MASK<<bit));			//se ajusta la mascara para modificar el bit deseado y luego se invierte.
	
	switch(puerto){
		case PORTD:
			registro.d=(registro.d & mask);		//se utiliza un and bitwise para borrar el bit.
			break;
		case PORTA:
			registro.ab.a.acca=(registro.ab.a.acca & (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb=(registro.ab.b.accb & (uint8_t)mask);
			break;
	}
	
}


//Dado un puerto y un número de bit, devuelve su valor.
int bitGet(int bit, int puerto)
{
	uint16_t mask = (MASK<<bit);		//se ajusta la mascara hasta llegar al bit deseado.
	int result;
	
	switch(puerto){
		case PORTD:
			result=(registro.d & mask);	//se utiliza un and bitwise para borrar los otros bits
			break;
		case PORTA:
			result=(registro.ab.a.acca & (uint8_t)mask);
			break;
		case PORTB:
			result=(registro.ab.b.accb & (uint8_t)mask);
			break;
	}
	if(result)		//si el resultado no es 0, quiere decir que habia un 1.
		return 1;	
	else
		return 0;
	
}

/*Dado un puerto y un número de bit, cambia al estado opuesto en el que está (si está en 0
pasa a 1, y si está en 1 pasa a 0).*/
void bitToggle(int bit, int puerto)
{
	if(bitGet(bit, puerto))			//evalua si el bit esta en 0 o en 1.
		bitClr(bit, puerto);		//si esta en 1, se borra.
	else
		bitSet(bit, puerto);		//si esta en 0, se setea en 1.
}
	

/*Dado un puerto y una máscara, prende todos aquellos bits que estén prendidos en la máscara,
sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que originalmente se encuentra
en el estado 0x01, al aplicarle la máscara 0x0A, el resultado será 0xB.*/
void maskOn(int puerto, int mask)
{
	switch(puerto){
		case PORTD:
			registro.d =(registro.d | (uint16_t)mask);	//se utiliza un or bitwise para setear todos los bits deseados.
			break;
		case PORTA:
			registro.ab.a.acca =(registro.ab.a.acca | (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb =(registro.ab.b.accb | (uint8_t)mask);
			break;
	}

}



/*Dado un puerto y una máscara, apaga todos aquellos bits que estén prendidos en la máscara,
sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que originalmente se encuentra en el
estado 0x0A, al aplicarle la máscara 0x02, el resultado será 0x08.*/
void maskOff(int puerto, int mask)
{
	mask=(~mask);	//se invierte la mascara

	switch(puerto){
		case PORTD:
			registro.d=(registro.d & (uint16_t)mask);	//se utiliza un and bitwise para borrar todos los bits deseados.
			break;
		case PORTA:
			registro.ab.a.acca =(registro.ab.a.acca & (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb=(registro.ab.b.accb & (uint8_t)mask);
			break;
	}

}

/*Dado un puerto y una máscara, cambia el estado de todos aquellos bits que estén prendidos en la máscara al opuesto, 
sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que
originalmente se encuentra en el estado 0x02, al aplicarle la máscara 0x03, el resultado será 0x01*/
void maskToggle(int puerto, int mask)
{
	
	switch(puerto){
		case PORTD:
			registro.d =(registro.d ^ (uint16_t)mask);	//se ulitiza un xor bitwise para invertir todos los bits deseados.
			break;
		case PORTA:
			registro.ab.a.acca=(registro.ab.a.acca ^ (uint8_t)mask);
			break;
		case PORTB:
			registro.ab.b.accb=(registro.ab.b.accb ^ (uint8_t)mask);
			break;
	}

}












