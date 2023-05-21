#include<stdio.h>
#include <stdlib.h>
#include "palindrome.h"
#include "stringfun.h"




int main (void)
{
    do{
    	int length,result;
    	char *word= (char *) malloc(50*sizeof(char));			//se reserva memoria dinámica para guardar el string con la palabra
    	printf("Please, write something\n");
    	fgets(word,50*sizeof(char),stdin);		        	//se lee lo escrito por el usuario utilizando el puntero anterior
    	length=wordlength(word);					//se calcula la longitud de la palabra
    	word=realloc (word,length+15);					//para mejor manejo de memoria se modifica la cantidad ya que sólo se guardará un string
    	printf("Your input was: %s\n",word);
    	char *reves= (char *) malloc (length+15);			//se reserva más memoria, una para la palabra sin símbolos que no sean letras o números y otra para la palabra sin los símbolos pero al revés.
    	char *destino=(char *) malloc (length+15);
    	reshape(word,destino);						//se eliminan los símbolos que no sean letras o números de la palabra
	printf("The word that will be considered is : %s\n",destino);
    	resize(destino);						//se cambian todas las mayúsculas (si hay) por minúsculas
    	reverse(destino,reves);						//se genera la palabra al revés
    	result=palindrome(destino,reves);				//se usa la función recursiva para ver si la palabra es un palíndromo
    	if(result==OK)
    	printf("Your Word is a Palindrome\n");				//se imprime el resultado
    	else printf("Your Word isn't a Palindrome\n");
	printf("--------------------------\n");
      }
    while(1);
}


