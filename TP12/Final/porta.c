#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "portlib.h"
#include "leds.h"
#include "nonblock.h"
#include "definitions.h"

#define MASK 0x01
void printscreen(void);
void final(void);

int main (void){

	int counter, bit, mask,ch, puerto=PORTA;
	int blink=false, blinkstatus=false,flagblink=false;
	bool init_success, led_success=true;

	//funciones leds.h
	do {
		init_success=init();
		if (!init_success)
			printf("Init Error\n");
	} while (!init_success);

	do {
		init_success=output();
		if (!init_success)
			printf("Set as output Error\n");
	} while (!init_success);


	system("clear");
	printscreen();
	printf("Puerto A:");
	for(counter=0;counter<PINQUANT;counter++){
		printf("%d",bitGet(counter,puerto));
	}
	printf("\n");

	while((ch=getchar())!='q'){
		flagblink=true;

		if((ch>='0')&&(ch<='7')){		//si se ingreso un numero entre 0 y 7, setea el bit en 1.
			bit=(ch-48);
			bitToggle(bit, puerto);
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
				case 'b':
					if(blink){
						blink=false;
					}
					else{
						blink=true;
					}
					break;
			}

		}

		while(blink&&flagblink){
			if(blinkstatus){

				system("clear");
				printscreen();
				printf("Puerto A:");
				for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime el estado del puerto
					printf("%d",0);
				}
				printf("\n");


				for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime leds
					led_success=setpin(counter,0);
					if (!led_success) { //when false there is an error
						printf("Error setting led %d\n",counter);
						return 0; //error setting led
					}
				}


				blinkstatus=false;
			}
			else{
				system("clear");
				printscreen();
				printf("Puerto A:");
				for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime 0s
					printf("%d",bitGet(counter,puerto));
				}
				printf("\n");


				for(counter=(PINQUANT-1);counter>=0;counter--){		//borra los leds
					led_success=setpin(counter,(bool)bitGet(counter,puerto));
					if (!led_success) { //when false there is an error
						printf("Error setting led %d\n",counter);
						return 0; //error setting led
					}
				}


				blinkstatus=true;
			}
			usleep(500000);
			if(kbhit()){

				flagblink=false;
			}




		}


		system("clear");

		printscreen();
		printf("Puerto A:");
		for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime el estado del puerto
			printf("%d",bitGet(counter,puerto));
		}
		printf("\n");


		for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime leds
			led_success=setpin(counter,(bool)bitGet(counter,puerto));
			if (!led_success) { //when false there is an error
				printf("Error setting led %d\n",counter);
				return 0; //error setting led
			}

		}



		while(ch!='\n'){		//se libera el stdin.
		ch=getchar();
		}
	}
	final();
	return 0;

}

void final(void){
	int mask, i,puerto=PORTA,counter;
	bool led_success=true;
	mask=0xFF;	//se prenden todos los bits.
	maskOn(puerto,mask);
	system("clear");

	printscreen();
	printf("Puerto A:");
	for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime el estado del puerto
		printf("%d",bitGet(counter,puerto));
	}
	printf("\n");


	for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime leds
		led_success=setpin(counter,(bool)bitGet(counter,puerto));
		if (!led_success) { //when false there is an error
			printf("Error setting led %d\n",counter);
			return; //error setting led
		}
	}



	usleep(500000);

	for(i=0;i<=(PINQUANT-1);i++){
		mask=(MASK<<i);
		maskOff(puerto,mask);
		system("clear");
		printscreen();
		printf("Puerto A:");
		for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime el estado del puerto
			printf("%d",bitGet(counter,puerto));
		}
		printf("\n");

		for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime leds
			led_success=setpin(counter,(bool)bitGet(counter,puerto));
			if (!led_success) { //when false there is an error
				printf("Error setting led %d\n",counter);
				return; //error setting led
			}
		}




		usleep(500000);
	}
	for(i=(PINQUANT-1);i>4;i--){
		bitSet((PINQUANT-1), puerto);
		system("clear");
		printscreen();
		printf("Puerto A:");
		for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime el estado del puerto
			printf("%d",bitGet(counter,puerto));
		}
		printf("\n");


		for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime leds
			led_success=setpin(counter,(bool)bitGet(counter,puerto));
			if (!led_success) { //when false there is an error
				printf("Error setting led %d\n",counter);
				return; //error setting led
			}
		}


		usleep(500000);



		bitClr((PINQUANT-1), puerto);
		system("clear");
		printscreen();
		printf("Puerto A:");
		for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime el estado del puerto
			printf("%d",bitGet(counter,puerto));
		}
		printf("\n");


		for(counter=(PINQUANT-1);counter>=0;counter--){		//imprime leds
			led_success=setpin(counter,(bool)bitGet(counter,puerto));
			if (!led_success) { //when false there is an error
				printf("Error setting led %d\n",counter);
				return; //error setting led
			}
		}


		usleep(500000);
	}



}
void printscreen(void){
	printf("*****************************************************************\n");
	printf("*\t\tSIMULACION DEL PUERTO A\t\t\t\t*\n");
	printf("*Ingrese el número (del 0 al 7) del LED que se desea prender\t*\n");
	printf("*Ingrese 't' para cambiar todos los LEDs al estado opuesto\t*\n");
	printf("*Ingrese 'c' para apagar todos los LEDs\t\t\t\t*\n");
	printf("*Ingrese 's' para prender todos los LEDs\t\t\t*\n");
	printf("*Ingrese 'b' para que parpadeen los LEDs\t\t\t*\n");
	printf("*Ingrese 'q' para salir del programa\t\t\t\t*\n");
	printf("*****************************************************************\n");


}
