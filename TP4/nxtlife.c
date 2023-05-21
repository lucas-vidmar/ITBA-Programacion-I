#include<stdio.h>

void nxtgeneration(int matrix[][10],int fila, int col); //la función actualiza el tablero de juego
void generationleap(int nextmatrix[][10],int matrix [][10],int fila, int col); //la funcón modifica la matriz del tablero de juego

void nxtgeneration(int matrix[][10], int fila, int col)    //recibe la matriz de juego y la cantidad de columnas y filas
{
    int state,cellcount;    //state indica si la célula está viva o muerta; cellcount indica cuántas células vivas la rodean
    int i,j;    //variables para usar en el FOR
    int nextmatrix[][10]; //matriz del nuevo tablero de juego, se utilizará para actualizar el tablero principal una vez completa
    for(i=0;i<fila;i++)    //el proceso se repite para cada posición del tablero de juego
    {
        for(j=0;j<col;j++)
        {
            cellcount=lucas(matrix[][10],i,j);  //se determina cuántas células vivas rodean a la célula analizada
            if(matrix[i][j]=='X');        //si la célula en la posición i,j está viva, se analiza su futuro
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
            else                            //si la célula está muerta, se procede a hallar su destino
            {
                if(cellcount==3)        //si la rodean tres células vivas, la célula vuelve a la vida como lázaro
                {
                    state='X';
                    nextmatrix[i][j]=state;
                }
                else                    //si no la rodean tres células vivas, la célula permanece muerta
                {
                    state=' ';
                    nextmatrix[i][J]=state;
                }
            }
        }
    }
    //se procede a actualizar el tablero de juego
    generationleap(nextmatrix,matrix,fila,col);
}

void generationleap (int nextmatrix[][10],int matrix[][10], int fila, int col) //recibe la nueva matriz, la de juego y el número de filas y columnas
{
    int i,j; //variables para el FOR
    for (i=0;i<fila;i++)       //para cada elemento de la matriz
    {
        for(j=0;j<col;j++)
        {
            matrix[i][j]=nextmatrix[i][j];  //actualiza el tablero de juego con los nuevos estados de las células.
        }
    }
}
