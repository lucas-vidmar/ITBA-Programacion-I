#include<stdio.h>
#define M 7 //cant filas
#define N 5 //cant columnas

int main(void) {
    char cantfil=M;
    char cantcol;
    char numfil=0;
    char numcol;

    printf("Cantidad de Filas:%d\n",M);
    printf("Cantidad de Columnas:%d\n",N);
    while(cantfil>0)    
    {
        for(cantcol=N,numcol=numfil;cantcol>0;--cantcol)
        /*Se inicializa el contador cantcol con la cantidad de columnas de la matriz e 
        incializa el numero a ingresar en la primera columna de la matriz dependiendo de la fila en la que esta ubicada. 
        Compara si cantcol es mayor que cero y al finalizar decrementa cantcol*/
        {
            printf("%d\t",numcol);
            ++numcol;
        }
        printf("\n");
        --cantfil;
        ++numfil;
    }

    return 0;

}




