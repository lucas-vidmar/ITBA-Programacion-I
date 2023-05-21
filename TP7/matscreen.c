#include "life.h"

//esta funcion imprime en pantalla la martiz.
void print (char mat [MAXFIL][MAXCOL],int i,int j) {
	int contcol;
	int contfil=0;

	while(contfil<i)
	//Imprime las filas de la matriz hasta llegar a la ultima.==
	{
		printf("|");
		for(contcol=0;contcol<j;++contcol)
		//Imprime todos los caracteres de la misma fila hasta llegar al ultimo.
		{
			printf("%c|",mat[contfil][contcol]);
		}
		++contfil;
		printf("\n");
	}
}
