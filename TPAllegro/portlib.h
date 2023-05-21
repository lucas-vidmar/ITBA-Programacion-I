
#ifndef PORTLIB_H
#define PORTLIB_H

enum{PORTA,PORTB,PORTD};
//Dado un puerto y un número de bit, cambia su estado a 1.
void bitSet(int bit, int puerto);

//Dado un puerto y un número de bit, cambia su estado a 0.
void bitClr(int bit, int puerto);

//Dado un puerto y un número de bit, devuelve su valor.
int bitGet(int bit, int puerto);

/*Dado un puerto y un número de bit, cambia al estado opuesto en el que está (si está en 0
pasa a 1, y si está en 1 pasa a 0).*/
void bitToggle(int bit, int puerto);

/*Dado un puerto y una máscara, prende todos aquellos bits que estén prendidos en la máscara,
sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que originalmente se encuentra
en el estado 0x01, al aplicarle la máscara 0x0A, el resultado será 0xB.*/
void maskOn(int puerto, int mask);

/*Dado un puerto y una máscara, apaga todos aquellos bits que estén prendidos en la máscara,
sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que originalmente se encuentra en el
estado 0x0A, al aplicarle la máscara 0x02, el resultado será 0x08.*/
void maskOff(int puerto, int mask);

/*Dado un puerto y una máscara, cambia el estado de todos aquellos bits que estén prendidos en la máscara al opuesto, 
sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que
originalmente se encuentra en el estado 0x02, al aplicarle la máscara 0x03, el resultado será 0x01*/
void maskToggle(int puerto, int mask);


#endif /* PORTLIB_H */

