#include <stdio.h>
#include "stringequal.h"

#define BOOLEAN int
#define OK 1
#define NOT_EQUAL 0

int stringequal (char *word1, char *word2)
{
    int i,wordlength1,wordlength2;       //i es una variable para el FOR, wordlength1 y 2 representan la cantidad de caracteres de las palabras
    BOOLEAN error=0;                     //1 y 2 respectivamente y error es un flag que vale uno si las palabras son distintas y cero si son iguales
    
    
    wordlength1=wordlength(word1);      //se calcula la cantidad de caracetres de cada palabra
    wordlength2=wordlength(word2);
    if(wordlength1!=wordlength2)        //si no tiene la misma cantidad de caracteres ya no pueden ser iguales
    {
        return NOT_EQUAL;
    }
    for (i=0;word1[i];++i)              //se compara carácter a carácter
    {
        if(word1[i]!=word2[i])          //en caso de que dos caracteres en la misma posición no coincidan los strings ya no serán iguales.
        {
            error=1;
        }
    }
    if(error!=1)                        //analiza el flag de error y devuelve 1 o cero según corresponda
    {
        return OK;
    }
    else return NOT_EQUAL;
}


int wordlength (char *word)
{
    int i,count=0;        //i es variable para el FOR y count guarda la cantidad de caracteres de la palabra
    i=0;
    while(word[i])      //evalúo hasta el terminador
    {
        ++count;        //si se trata de un carácter incremento en uno la cantidad
        ++i;
    }
    return count;
}
