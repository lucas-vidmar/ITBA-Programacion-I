#include "life.h"

//funcion evalua la cantidad de celulas vivas al rededor de la celda ij
int evaluate (char matrx[MAXFIL][MAXCOL], int i, int j, int fila, int col) {

  int n, h ,total=0; //n y h son contadores, total es el numero total

  for (n=-1;n<=1;n++) { //evaluamos las posiciones de las filas anterior, misma y sig
    for (h=-1;h<=1;h++) { //evaluamos las posiciones de las columnas anterior, misma y sig
      if ( ((i+n)>=0) && ((i+n)<fila) && ((j+h)>=0) && ((j+h)<col) ) {  //la particula a evaluar debe estar dentro del rango
	if (matrx[i+n][j+h]=='X') {
          total++;  //sumamos uno al total
        }
      }
    }
  }

  if (matrx[i][j]=='X')
    total=total-1;  //corregimos el total porque se conto la posicion ij en si misma

  return total;
}
