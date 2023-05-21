#include <stdio.h>
#include "palindrome.h"

int palindrome (char *word, char *reves)
{
    if (word[0]=='\0')      //caso base, si el string no tiene letras, se considera un palíndromo
    {
        return OK;
    }
    else if (word[0]!=reves[0])        //caso base, si la primea y última letra no coinciden, no puede ser un palíndromo
    {
        return 0;
    }
    else return OK*(palindrome(word+1,reves+1));       //de lo contrario, se evalúa la nueva palabra sin la primera y última letra 
}

