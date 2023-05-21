//funciones para crear la matriz

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"
#include "generate_mat.h"

//pide la fila, columna o densidad de part
int request (void) {
  int ch ,cant=0, mistake=0;
  while ( (ch = getchar()) != '\n') {

    if ( ((ch - '0')>9) || ((ch - '0')<0) ) { //si el caracter no es un numero esta mal
      mistake=1;  //flag error
    }
    else
      cant = cant*10 + (ch - '0');

  }

  if ( (cant==0)&&(mistake==0) ) //ninguna de las cantidades pedidas puede ser 0
    printf("No puede ser cero.\n");

  if (mistake==1) {
    printf("----------Input Error----------\n");
    return 0; //si hubo error devolvemos un 0 como flag
  }
  else {
    return cant; //sino devolvemos el valor
  }
}

//funcion que genera una matriz random
void generate (char matrx[MAXFIL][MAXCOL], int j) {

  int i, h, random;
  srand(time(NULL));  //seteo una semilla para que la generacion sea completamente random

  for (i=0;i<MAXFIL;i++) {
    for (h=0;h<MAXCOL;h++) {
      random = 1 + (rand()%j);  //la probabilidad de generar unos aumenta con la densidad elegida
      if (random == 1)  //si se genera un uno, hay una celula viva
        matrx[i][h]='X';
      else
        matrx[i][h]=' ';
    }
  }

}

