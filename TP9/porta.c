#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "portlib.h"

int main (void){

	int counter, bit, mask,ch, puerto=PORTA;
	printf("*****************************************************************\n");
	printf("*\t\tSIMULACION DEL PUERTO A\t\t\t\t*\n");
	printf("*Ingrese el número (del 0 al 7) del LED que se desea prender\t*\n");
	printf("*Ingrese 't' para cambiar todos los LEDs al estado opuesto\t*\n");
	printf("*Ingrese 'c' para apagar todos los LEDs\t\t\t\t*\n");
	printf("*Ingrese 's' para prender todos los LEDs\t\t\t*\n");
	printf("*Ingrese 'q' para salir del programa\t\t\t\t*\n");
	printf("*****************************************************************\n");
	printf("Puerto A:");
	for(counter=0;counter<8;counter++){
		printf("%d",bitGet(counter,puerto));
	}	
	printf("\n");

	while((ch=getchar())!='q'){
	
		if((ch>='0')&&(ch<='7')){		//si se ingreso un numero entre 0 y 7, setea el bit en 1.
			bit=(ch-48);
			bitSet(bit, puerto);
		}
		else{	
			switch(ch){
				case 't':		//se invierten todos los bits con la mascara 0xff.
					mask=0xFF;
					maskToggle(puerto,mask);
					break;
				case 'c':		//se borran todos los bits.
					mask=0xFF;
					maskOff(puerto,mask);
					break;
				case 's':
					mask=0xFF;	//se prenden todos los bits. 
					maskOn(puerto,mask);
					break;
			}

		}
		printf("Puerto A:");
		for(counter=0;counter<8;counter++){		//imprime el estado del puerto
			printf("%d",bitGet(counter,puerto));
		}	
		printf("\n");
		while(ch!='\n'){		//se libera el stdin.
		ch=getchar();
		}
	}


}
