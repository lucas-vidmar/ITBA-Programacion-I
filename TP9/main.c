#include<stdio.h>
#include <stdint.h>
#include "bitToggle.h"
#include "bitClr.h"
#include "bitSet.h"
#include "bitGet.h"


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
        porta_t a;
        portb_t b;
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
        
    }
