#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"

void dice (int cantidad, int tiradas, int caras, char *nombre_archivo)
{
    FILE *fpointer;
    srand(time(NULL));		//se genera un seed con la función time para lograr luego números pseudoaleatorios
    int i,j;        //variables para el for
    int store=0,store1=0;    //variable para realizar la suma de cada tiro

    if(nombre_archivo==NULL)		//si recibe el puntero null imprime en la pantalla.
    {	printf("Se están utilizando dados de %d caras\n",caras);
    	for(i=1;i<=tiradas;i++)     //se realiza la cantidad de tiradas necesarias
    	{
        	printf("tirada %d: ",i);
        	for(j=1;j<=cantidad;j++)        
        	{
            	printf("%d, ",store1=(rand()%caras+1));     //se genera un número aleatorio entre 1 y el número de caras del dado
            	store+=store1;      //se guarda la suma de cada lanzamiento
        	}
        	printf(" -Suma:%d \n",store);
        	store=0;
    	}
    }
    else 
    {
	fpointer=fopen(nombre_archivo,"w");		//se abre el archivo en el que se trabajará en modo escritura
    	fprintf(fpointer,"Se están utilizando dados de %d caras\n",caras);
    	for(i=1;i<=tiradas;i++)     //se realiza la cantidad de tiradas necesarias
    	{
        	fprintf(fpointer,"tirada %d: ",i);
        	for(j=1;j<=cantidad;j++)        
        	{
            	fprintf(fpointer,"%d, ",store1=(rand()%caras+1));     //se genera un número aleatorio entre 1 y el número de caras del dado

            	store+=store1;      //se guarda la suma de cada lanzamiento
        	}
        	fprintf(fpointer," -Suma:%d \n",store);
        	store=0;
    	}
	fclose(fpointer);		//se cierra el archivo
    }
}
