#include <stdio.h>
#include "stringfun.h"


void reverse (char *string, char *reves)		//genera el inverso de la palabra
{
    int i=0;		//variables para el for
    int j=0;
    while(string[j])		//se ubica la variable j apuntando al último carácter antes de la palabra 
    {
        j++;
    }
    --j;
    while(string[i])		//se genera la palabra inversa
    {
        reves[i]=string[j];
        i++;
        j--;
    }
}


void resize (char *word)		//transforma mayúsculas en minúsculas
{
    int i;
    
    for (i=0;word[i];++i)		//evalúa si el carácter es una mayúscula, si lo es lo transforma en minúscula
    {
        if((word[i])<='Z' && 'A'<=(word[i]))
        {
            word[i]-=('A'-'a');
        }
    }
}

void reshape(char *string, char *destino) //elimina carcateres que no sean letras o números
{
    int i,j;
    i=0,j=0;
    while(string[i])  //evalúa cada carácter y si no es una letra o número no lo copia en el destino
    {
        if (('a'<=(string[i]) && (string[i])<='z') || ('A'<=(string[i]) && (string[i])<='Z') || ((string[i])>='0' && (string[i])<='9'))
        {
            destino[j]=string[i];
            j++;
        }
        i++;
    }
}

int wordlength (char *word)  //calcula la longitud de una palabra
{
    int length=0;
    int i=0;
    while(word[i])	
    {
        ++length;
        ++i;
    }
    return length;		//se cuenta cada carácter y se devuelve el total
}
