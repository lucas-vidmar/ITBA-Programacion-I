
#include <stdio.h>

//definimos algunas constantes
#define MAX 10 //maximos caracteres de la palabra
#define MAXTXT 200  //maximo de caracteres dentro del txt
#define MAXWORDS 10  //maximo de palabras dentro del txt
#define TER '\n' //terminador establecido de palabra

int validate (char *w1, char *w2);  //la función evalúa si es posible formar la primer palabra con las letras de la segunda, recibe punteros al inicio de ambas palabras.
int wordlength (char *word);  //calcula la cantidad de caracteres en una palabra
int askuser (char *point);  //toma las palabras de la consola
void convert (char *arr);  //cambia las mayusculas por sus equivalentes en minusculas
void copy (char *arr1, char *arr2);  //crea una copia del arreglo
int request(void);  //pide numeros y valida
void program (void);  //programa de comparacion de palabras
void banco (char *array);  //toma el banco de pruebas y lo copia a un arreglo
void pruebas (void);  //separa las palabras y las compara
void askbank (char *point, char *arr, int *times); //va sacando palabras del banco

int main (void) {
  int opcion;

  while (1) { //mantener ciclo

    printf("\n\n*******************MENU*******************\n");
    printf("* 1. Programa de prueba de palabras.     *\n");
    printf("* 2. Banco de pruebas.                   *\n");
    printf("******************************************\n");

    do {  //pedir el numero hasta que no haya errores
      printf("Ingrese el numero de opcion:\n");
      opcion=request();
    } while (!opcion);

    switch (opcion) { //menu
      case 1: program(); break; //se eligio la primera opcion
      case 2: pruebas(); break; //se eligio la segunda opcion
    }
  }

}

void program (void) {
    int result, error, i;
    char word1[MAX], word2[MAX], word1c[MAX], word2c[MAX];

    //ingreso de palabras
    do {
      printf("\n-----------------------\n");
      printf("Ingrese primera palabra\n");
      error=askuser(word1);
    } while (error==1);

    do {
      printf("\n-----------------------\n");
      printf("Ingrese segunda palabra\n");
      error=askuser(word2);
    } while (error==1);

    //mostramos palabras elegidas
    printf("\n****************************************\n");
    printf("Primera palabra: ");
    for (i=0; word1[i] != TER ;i++) {
      printf("%c",word1[i]);
    }
    printf("\n");

    printf("Segunda palabra: ");
    for (i=0; word2[i] != TER ;i++) {
      printf("%c",word2[i]);
    }
    printf("\n");
    printf("****************************************\n");

    //pasamos todas las mayusculas a minisculas
    convert(word1);
    convert(word2);

    //hacemos una copia de las palabras
    copy(word1, word1c);
    copy(word2, word2c);

    //imprimimos las palabras convertidas
    printf("\nEn minisculas:\n");
    printf("****************************************\n");

    printf("Primera palabra: ");
    for (i=0; word1[i] != TER ;i++) {
      printf("%c",word1[i]);
    }
    printf("\n");

    printf("Segunda palabra: ");
    for (i=0; word2[i] != TER ;i++) {
      printf("%c",word2[i]);
    }
    printf("\n");
    printf("****************************************\n");

    //validamos las palabras en un orden
    result=validate(word1,word2);

    if (result==1) {  //se puede armar, lo comunicamos
      printf("\nSe puede armar la primera palabra con la segunda.\n");
    }
    else {  //no se puede armar, decimos que no se puede
      printf("\nNo se puede armar la primera palabra con la segunda.\n");
    }

    //validamos las palabras en otro orden
    result=validate(word2c,word1c);

    if (result==1) {  //se puede armar, lo comunicamos
      printf("\nSe puede armar la segunda palabra con la primera.\n\n");
    }
    else {  //no se puede armar, decimos que no se puede
      printf("\nNo se puede armar la segunda palabra con la primera.\n\n");
    }
}

int validate (char *w1, char *w2) {
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
    for (i=0;w1[i]!=TER;i++)   //evalúa si se llegó al terminador de la primera palabra
    {
        for (j=0;w2[j]!=TER;j++)	//evalúa si se llegó al final de la segunda palabra.
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

int wordlength (char *word) {
    int count=0, i=0; //count indica cuántas letras hay en la palabra, i se utiliza para moverse en el arreglo
    while (word[i]!=TER)  //evalúa si el carácter indicado es el terminador de la palabra
    {
        count++;
        i++;
    }
    return count;
}

int askuser (char *point) {
  int mistake=0, j=0, i, mistakes=0;
  char ch;
  char valid[52]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  while ( (ch = getchar()) != '\n') {

    if (mistakes==0) { //si estamos dentro del segmento

      for (i=0;i<52;i++) {  //evaluamos con todas las letras posibles

        if ( j>=MAX) {  //si llegamos al final de la palabra
          mistakes=1; //seteamos error de violacion de segmento
          break;
        }
        else if ( ch==valid[i] ) { //si el caracter es valido esta bien
          *(point + j)=ch;
          mistake=0;  //el caracter era valido asi que seteamos el flag en 0
          break;  //salimos del ciclo para que el flag quede en 0
        }
        else  { //si el caracter no es valido seteamos el flag en 1
          mistake=1;
        }

      } //termina for
      j++;  //nos movemos a la siguiente posicion del arreglo

    }

  } //termina ingreso de datos
  *(point+j)=TER;  //dejamos un terminador en la ultima posicion

  if (mistake==1) //se ingreso caracter no valido
    printf("\n----------Input Error----------\n");

  if (mistakes==1) { //se violo segmento
    printf("\nLa cantidad de maxima de letras es %d.\n",MAX);
    mistake=1;
  }

  return mistake; //devolvemos el flag de error
}

void convert (char *arr) {
	char mayu[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char minu[]= "abcdefghijklmnopqrstuvwxyz";
	int i, j;

	for(i=0;arr[i]!=TER;++i)
	{
		for(j=0;mayu[j];++j)
		{
			if(arr[i]==mayu[j])
			{
				arr[i]=minu[j];
			}
		}
	}
}

void copy (char *arr1, char *arr2) {
  int i;

  for(i=0;arr1[i]!=TER;i++) {  //copiamos todos los caracteres
    arr2[i]=arr1[i];
  }
  arr2[i]=TER;  //y copiamos el terminador

}

int request (void) {
  int ch ,cant=0, mistake=0;
  while ( (ch = getchar()) != '\n') {

    if ( ((ch - '0')>2) || ((ch - '0')<0) ) { //si el caracter no es un numero esta mal
      mistake=1;  //flag error
    }
    else
      cant = cant*10 + (ch - '0');

  }

  if ( (cant==0)&&(mistake==0) ) //ninguna de las cantidades pedidas puede ser 0
    printf("No puede ser cero.\n\n");

  if (mistake==1) {
    printf("----------Input Error----------\n\n");
    return 0; //si hubo error devolvemos un 0 como flag
  }
  else {
    return cant; //sino devolvemos el valor
  }
}

void banco (char *array) {

  FILE *fp; //seteamos puntero dentro del archivo
  char ch;
  int i=0;

  fp=fopen("bancoPruebas.txt", "r");  //abrimos el archivo con modalidad read
  while (ch!=EOF) { //hasta final del archivo
    ch=fgetc(fp); //tomamos caracter por caracter
    if (ch==EOF) {  //si llegamos al final del archivo corregimos errores de copiado
      array[i]=TER;
      array[i+1]=TER;
      break;
    }
    array[i]=ch;  //si no llegamos al final seguimos copiando
    i++;
  }
  fclose(fp); //cerramos el archivo

  return;
}

void pruebas (void) {
  char bank[MAXTXT]; //definimos arreglo de banco de ejemplos
  char word1[MAX], word2[MAX], word1c[MAX], word2c[MAX];
  int i, result, times=0;

  //lenamos el arreglo con el txt
  banco(bank);
  while (bank[times]!='/') {

    askbank(word1,bank,&times);
    times++;
    askbank(word2,bank,&times);
    times++;

    //mostramos palabras elegidas
    printf("\n****************************************\n");
    printf("Primera palabra: ");
    for (i=0; word1[i] != TER ;i++) {
      printf("%c",word1[i]);
    }
    printf("\n");

    printf("Segunda palabra: ");
    for (i=0; word2[i] != TER ;i++) {
      printf("%c",word2[i]);
    }
    printf("\n");
    printf("****************************************\n");

    //pasamos todas las mayusculas a minisculas
    convert(word1);
    convert(word2);

    //hacemos una copia de las palabras
    copy(word1, word1c);
    copy(word2, word2c);

    //imprimimos las palabras convertidas
    printf("\nEn minisculas:\n");
    printf("****************************************\n");

    printf("Primera palabra: ");
    for (i=0; word1[i] != TER ;i++) {
      printf("%c",word1[i]);
    }
    printf("\n");

    printf("Segunda palabra: ");
    for (i=0; word2[i] != TER ;i++) {
      printf("%c",word2[i]);
    }
    printf("\n");
    printf("****************************************\n");

    //validamos las palabras en un orden
    result=validate(word1,word2);

    if (result==1) {  //se puede armar, lo comunicamos
      printf("\nSe puede armar la primera palabra con la segunda.\n");
    }
    else {  //no se puede armar, decimos que no se puede
      printf("\nNo se puede armar la primera palabra con la segunda.\n");
    }

    //validamos las palabras en otro orden
    result=validate(word2c,word1c);

    if (result==1) {  //se puede armar, lo comunicamos
      printf("\nSe puede armar la segunda palabra con la primera.\n\n");
    }
    else {  //no se puede armar, decimos que no se puede
      printf("\nNo se puede armar la segunda palabra con la primera.\n\n");
    }
  }

  return;
}

void askbank (char *point, char *arr, int *times) {
  int mistake=0, j=0, i, mistakes=0;
  char ch;
  char valid[52]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  while ( (ch = arr[*(times)]) != '\n') {

    if (mistakes==0) { //si estamos dentro del segmento

      for (i=0;i<52;i++) {  //evaluamos con todas las letras posibles

        if ( j>=MAX) {  //si llegamos al final de la palabra
          mistakes=1; //seteamos error de violacion de segmento
          break;
        }
        else if ( ch==valid[i] ) { //si el caracter es valido esta bien
          *(point + j)=ch;
          (*times)++;
          mistake=0;  //el caracter era valido asi que seteamos el flag en 0
          break;  //salimos del ciclo para que el flag quede en 0
        }
        else  { //si el caracter no es valido seteamos el flag en 1
          mistake=1;
        }

      } //termina for
      j++;  //nos movemos a la siguiente posicion del arreglo

    }

  } //termina ingreso de datos
  *(point+j)=TER;  //dejamos un terminador en la ultima posicion

  if (mistake==1) //se ingreso caracter no valido
    printf("\n----------Input Error----------\n");

  if (mistakes==1) { //se violo segmento
    printf("\nLa cantidad de maxima de letras es %d.\n",MAX);
    mistake=1;
  }
  return;
}
