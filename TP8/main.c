
#include <stdio.h>

//definimos algunas constantes
#define MAXLETTERS 10 //maximos caracteres de la palabra
#define MAXWORDS 10 //maxima cantidad de palabras

//prototipos
static void arrcreate(int, char* [], char [MAXWORDS][MAXLETTERS]);
static int separate(char arreglo[MAXWORDS][MAXLETTERS], char clave[MAXWORDS][MAXLETTERS], char valores[MAXWORDS][MAXLETTERS], int);

int main (int argc, char *argv[]) {
  int i, cantDeOp, cantDeVal;
  char m[MAXWORDS][MAXLETTERS]={{0}}, optKey[MAXWORDS][MAXLETTERS]={{0}}, optValue[MAXWORDS][MAXLETTERS]={{0}};
  arrcreate(argc,argv,m); //pasamos las palabras en un arreglo

  for (i=0;i<argc-1;i++) { //imprimimos el arreglo de palabras hasta la cantidad (menos uno por que no imprimimos el nombre del programa)
    printf("Arreglo pos. %d: %s\n",i ,m[i]);
  }

	printf("\n"); //separador
	
  cantDeOp=separate(m, optKey, optValue, argc); //separamos en arreglos distintos y contamos cuantas opciones hay
	cantDeVal=argc-1; //cantidad de valores (argc-1 porque no tomamos el nombre del programa)

	for (i=0;i<cantDeOp;i++) {
    printf("Clave pos. %d: %s\n",i ,optKey[i]); //imprimimos arreglo de claves con los valores obtenidos
  }

	printf("\n"); //separador

	for (i=0;i<cantDeVal;i++) {
    printf("Valores pos. %d: %s\n",i ,optValue[i]); //imprimimos arreglo de valores o argumentos con los valores calculados
  }

}

//funcion creadora de arreglo
static void arrcreate(int cant, char *palabras[], char m[MAXWORDS][MAXLETTERS]) {
  int i, j; //simples contadores

  for (i=1;i<cant;i++) {
    j=0;
    while (*(*(palabras+i)+j)!=0) {  //mientras no sea el terminador copiamos caracter a caracter al arreglo
      m[i-1][j]=*(*(palabras+i)+j);  //no copiamos la primera palabra pero el arreglo arranca desde cero, por eso es i-1
      j++;
    }
    m[i-1][j]=0;  //cuando terminamos de copiar la palabra forzamos el terminador
  }

}

//funcion separadora
static int separate(char arreglo[MAXWORDS][MAXLETTERS], char clave[MAXWORDS][MAXLETTERS], char valores[MAXWORDS][MAXLETTERS], int cant){
	int i, j; //simples contadores
	int cclave=0; //contador de claves

	for (i=0;i<cant;i++) {

    if (arreglo[i][0]=='-') { //nos fijamos si es una opcion por el guion
    	j=0;
    	while (arreglo[i][j]!=0) {  //mientras no sea el terminador copiamos caracter a caracter al arreglo de claves
      	clave[cclave][j]=arreglo[i][j];
      	j++;
    	}
			clave[cclave][j]=0; //forzamos terminador
			valores[i][0]='O'; valores[i][1]='P'; valores[i][2]='T'; valores[i][3]='.'; //dejamos un ¨OPT.¨ de separacion en el arreglo de valores
			cclave++; //nos movemos en el arreglo de claves
  	}
		else { //si no es una opcion, es un valor o argumento
			j=0;
    	while (arreglo[i][j]!=0) {  //mientras no sea el terminador copiamos caracter a caracter al arreglo de valores
      	valores[i][j]=arreglo[i][j];
      	j++;
    	}
			valores[i][j]=0; //forzamos terminador
		}

  }
	return cclave;

}

