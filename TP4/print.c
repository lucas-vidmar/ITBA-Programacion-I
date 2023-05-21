#include<stdio.h>

int j=5, i=5;
//PROTOTIPO
void print (char mat [100][10],int, int);

//MAIN
int main (void)
{
	char matriz [100][10]={"X  XX"," XX X","XX  X","X X X"," XXX ","XXXXX"};
	print(matriz,i,j);
	return 0;
}


//FUNCION PRINT
void print (char mat [100][10],int i,int j)
//Esta funcion imprime en pantalla la martiz.
{
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
