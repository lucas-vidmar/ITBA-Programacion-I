#include<stdio.h>
int validate (char *w1, char *w2); //la función evalúa si es posible formar la primer palabra con las letras de la segunda, recibe punteros al inicio de ambas palabras.
int wordlength (char *word); //calcula la cantidad de caracteres en una palabra


int main (void)
{
    int result;
    char word1[]="triss";
    char word2[]="mississipirt";
    result=validate(word1,word2);
    printf("%d",result);
}

int validate (char *w1, char *w2)
{
    //Declaro variables
    int i,j; //variables para indicar posición en arreglo
    int wordlength1,wordlength2; //variables que indican la cantidad de caracteres en la palabra 1 y 2
    int found=0; //la variable vale 1 si ya se ha encontrado la letra evaluada de la palabra 1 en la palabra 2
    int count=0,ok=1,toughluck=0; //count se utiliza para comparar si la palabra se puede devolver o no, ok y toughluck son los valores que devolverá la función
    
    //comienza la ejecución del programa
    wordlength1=wordlength (w1);   //devuelve la cantidad de caracteres en la palabra 1
    wordlength2=wordlength (w2);   //idéntico para la segunda palabra
    if(wordlength2<wordlength1) //si la palabra 2 tiene menos letras que la palabra 1, luego no se podrá formar con las letras de la palabra 2 la palabra 1
    {
        return toughluck;
    }
    for (i=0;w1[i];i++)   //evalúa si se llegó al terminador de la primera palabra
    {
        for (j=0;w2[j];j++)	//evalúa si se llegó al final de la segunda palabra.
        {
            if (w1[i]==w2[j])	//si ambas letras coinciden
            {
                if(found==0)	//si la letra a buscar no ha sido encontrada aún, se prosigue a marcar como encontrada, sino no se hace nada
                {
                    w2[j]=' '; //para que no se continúe considerando esta letra, se le da el valor ' ', que nunca coincidirá con una letra de la palabra 1
                    count++;  //se incrementa la cantidad de letras en común
                    found=1; //se ubica un 1 en found para evitar que se sigan considerando si coinciden
                }
            }
        }
        found=0;  //regreso el valor de found al original
    }
    if (count==wordlength1) //si la cantidad de letras coincidentes coincide con la cantidad de letras de la palabra 1
    {
        return ok;
    }
    else
    {
        return toughluck;
    }
}


int wordlength (char *word)
{
    int count=0, i=0; //count indica cuántas letras hay en la palabra, i se utiliza para moverse en el arreglo
    while (word[i])     //evalúa si el carácter indicado es el terminador de la palabra
    {
        count++;
        i++;
    }
    return count;
}
