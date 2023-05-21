#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "leds.h"
#include "definitions.h"


bool init(void) {  //funcion inicializa las leds
    FILE *handle_export; //pointer a archivo
    int nWritten, i;
    bool init_success=true;
    const char *pins[PINQUANT]={PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8};

    if((handle_export=fopen("/sys/class/gpio/export","w")) == NULL){ //si el pointer es nulo es un error de apertura
        printf("Could not open /sys/class/gpio/export \n");
        init_success=false;
    }

    for(i=0;i<PINQUANT;i++){
        nWritten=fputs(pins[i],handle_export);
        fflush(handle_export);
        if(nWritten==-1){
            printf("Cant export pin %s\n",pins[i]);
            init_success=false;
        }
    }

    fclose(handle_export); //cerramos el archivo

    return init_success;
}

bool output(void){ //setea las leds como outputs
    FILE *handle;
    int nWritten, i;
    bool init_success=true;
    char direccion[PINQUANT][100]={{0}};
    const char *pins[PINQUANT]={PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8};

    for(i=0;i<PINQUANT;i++) { //concatena los strings
        strcat(direccion[i],"/sys/class/gpio/gpio");
        strcat(direccion[i],pins[i]);
        strcat(direccion[i],"/direction");
    }

    for(i=0;i<PINQUANT;i++) {

        if((handle=fopen(direccion[i],"w")) == NULL){ //abrimos los archivos
            printf("Could not open  %s\n",direccion[i]);
            init_success=false; //hay error
        }

        if((nWritten=fputs("out",handle))==-1){
            fflush(handle);
            printf("Could not set pin %s as out.\n",pins[i]);
            init_success=false;
        }
        fflush(handle);

    }
        fclose(handle);
        return init_success;
}

bool setpin (int p, bool state){ //setea la led dependiendo del estado

    FILE *handle;
    int nWritten, i;
    bool set_success=true;
    char direccion[PINQUANT][100]={{0}};
    const char *pins[PINQUANT]={PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8};

    for(i=0;i<PINQUANT;i++) { //concatenar direcciones
        strcat(direccion[i],"/sys/class/gpio/gpio");
        strcat(direccion[i],pins[i]);
        strcat(direccion[i],"/value");
    }

    if( (handle=fopen(direccion[p],"w") ) == NULL){ //abrimos el archivo del pin pedido
        printf("Could not open %s\n",direccion[p]);
        set_success=false;
    }
    fflush(handle);
    if (state==false) { //set pin low
        if ( (nWritten=fputc('0',handle))==-1 ) {
            fflush(handle);
            printf("Cant write in file %s \n",direccion[p]);
            set_success=false;
        }
    fflush(handle);
    }

    else { //set pin up
        if ( (nWritten=fputc('1',handle))==-1 ) {
            fflush(handle);
            printf("Cant write in file %s \n",direccion[p]);
            set_success=false;
        }
    fflush(handle);
    }

    return set_success;
}
