#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h" //funcion del dado
#include "validation.h" //valida el input, devuelve 0 si error
#include "stoi.h" //pasa un char a un num, devuelve 0 si no es un numero
#include "verify.h" //verifica si es un numero

int main (int argc, char *argv[]) {

	int cantidad, tiradas, caras;

	if ( validation(argc,argv) ) //si hay un error se termina el programa
		return 0;

	cantidad = stoi (argv[2]); //convertimos el argumento cantidad en numero
	if ( verify(argv[2]) == 0 ) {
		printf("\nInput error: Cantidad not a number\n"); printf("-------------------------\n");
		return 0; //si hay error termina el programa
		}

	tiradas = stoi (argv[4]); //convertimos el argumento tiradas en numero
	if ( verify(argv[4]) == 0 ) {
		printf("\nInput error: Tiradas not a number\n"); printf("-------------------------\n");
		return 0; //si hay error termina el programa
		}

	caras = stoi (argv[6]); //convertimos el argumento caras en numero
	if ( verify(argv[6]) == 0 ) {
		printf("\nInput error: Caras not a number\n"); printf("-------------------------\n");
		return 0; //si hay error termina el programa
		}

	//si no hay errores tiramos el dado
	if (argc==CANTDEARG)
  	dice(cantidad,tiradas,caras,argv[7]); //con salida de datos
	else
		dice(cantidad,tiradas,caras,NULL); //sin salida de datos

	return 0;
}
