#include 'life.h'

//se procede a actualizar el tablero de juego
    //recibe la nueva matriz, la de juego y el número de filas y columnas
    generationleap(nextmatrix,matrix,fila,col);
}

//la funcón modifica la matriz del tablero de juego
void generationleap (char nextmatrix[MAXFIL][MAXCOL],char matrix[MAXFIL][MAXCOL], int fila, int col) {
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
