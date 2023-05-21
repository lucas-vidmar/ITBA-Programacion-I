#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"
#include "print_screen.h"
#include "modify_mat.h"


static int evaluate(char[MAXFIL][MAXCOL], int, int, int, int);
static void generationleap(char[MAXFIL][MAXCOL],char[MAXFIL][MAXCOL] ,int ,int);


//la función actualiza el tablero de juego
void nxtgeneration(char matrix[MAXFIL][MAXCOL], int fila, int col) {
    int cellcount;    //cellcount indica cuántas células vivas la rodean
    int i,j;    //variables para usar en el FOR
    char state, nextmatrix[MAXFIL][MAXCOL]; //state indica si la célula está viva o muerta; matriz del nuevo tablero de juego, se utilizará para actualizar el tablero principal una vez completa

    for(i=0;i<fila;i++)    //el proceso se repite para cada posición del tablero de juego
    {
        for(j=0;j<col;j++)
        {
            cellcount=evaluate(matrix,i,j,fila,col);  //se determina cuántas células vivas rodean a la célula analizada
            if((matrix[i][j])=='X')        //si la célula en la posición i,j está viva, se analiza su futuro
            {
                if(cellcount<2 || cellcount>3)      //si la célula tiene menos de dos vecinos vivos o más de tres, la célula muere
                {
                    state=' ';
                    nextmatrix[i][j]=state;
                }
                else     //si la célula tiene dos o tres vecinos vivos continúa viviendo
                {
                    state='X';
                    nextmatrix[i][j]=state;
                }
            }
            else  //si la célula está muerta, se procede a hallar su destino
            {
                if(cellcount==3)  //si la rodean tres células vivas, la célula vuelve a la vida como lázaro
                {
                    state='X';
                    nextmatrix[i][j]=state;
                }
                else  //si no la rodean tres células vivas, la célula permanece muerta
                {
                    state=' ';
                    nextmatrix[i][j]=state;
                }
            }
        }
    }

    //se procede a actualizar el tablero de juego
    //recibe la nueva matriz, la de juego y el número de filas y columnas
    generationleap(nextmatrix,matrix,fila,col);
}



//funcion evalua la cantidad de celulas vivas al rededor de la celda ij
static int evaluate (char matrx[MAXFIL][MAXCOL], int i, int j, int fila, int col) {

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



//la funcón modifica la matriz del tablero de juego
static void generationleap (char nextmatrix[MAXFIL][MAXCOL],char matrix[MAXFIL][MAXCOL], int fila, int col) {
    int i,j; //variables para el FOR
    for (i=0;i<fila;i++)       //para cada elemento de la matriz
    {
        for(j=0;j<col;j++)
        {
            matrix[i][j]=nextmatrix[i][j];  //actualiza el tablero de juego con los nuevos estados de las células.
        }
    }
    print(matrix,fila,col);
}
