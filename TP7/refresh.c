#include "life.h"

//la función actualiza el tablero de juego
void nxtgeneration(char matrix[MAXFIL][MAXCOL], int fila, int col) 
{
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

