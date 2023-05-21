#include "life.h"

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
