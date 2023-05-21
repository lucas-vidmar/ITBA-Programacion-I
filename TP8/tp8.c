#include<stdio.h>
#include<stdlib.h>


#define MAXOPC 10
#define MAXPARAM 10
#define VALID 1
#define INVALID 0



static int evaluate (int argc, char *argv[],char *opciones[],char *valores[], char *parametros[], int *cantopc, int *cantparam);
//la funcion clasifica los argumentos en opciones valores y parametros.
static int evalopc (int argc, char *argv[], int num);
//la funcion evalua si se ha ingresado correctamente la opcion (clave+valor)
static int findname(int argc, char *argv[]);        
//la función busca el índice tal que en argv[0][i] comience el nombre del programa
static void print (char *nombre, char *opciones[],char *valores[], char *parametros[], int *cantopc, int *cantparam);
//la funcion imprime en pantalla los argumentos ingresados ordenados

int main (int argc,char *argv[]) {
	char *nombre;
	char *opciones[MAXOPC];
	char *valores[MAXOPC];
	char *parametros[MAXPARAM];
	//se definen arreglos de punteros a char para ordenar los argumentos ingresados
	int cantopc=0, cantparam=0;
	nombre=*argv+findname(argc,argv);
	if(evaluate(argc,argv,opciones,valores,parametros,&cantopc,&cantparam)==VALID){
		print(nombre,opciones,valores,parametros,&cantopc,&cantparam);
		//para este tp se decide imprimir en pantalla
	}
	else{
		printf("Error argumento: %d\nFalta el valor de la opcion\n",cantparam+cantopc*2+1);
	}
	
}

static void print (char *nombre, char *opciones[],char *valores[], char *parametros[], int *cantopc, int *cantparam){
//Imprime en pantalla
	int countopc=0, countparam=0;
	printf("Nombre del programa:%s\n",nombre);	//imprime el nombre del programa
	while(countopc<*cantopc){
		printf("Opcion%d:\tClave:%s\tValor:%s\n",countopc+1,opciones[countopc]+1,valores[countopc]);
		countopc++;
	}
	while(countparam<*cantparam){
		printf("Parametro%d:%s\n",countparam+1,parametros[countparam]);
		countparam++;
	}
}
	


static int  findname(int argc, char *argv[]) {      
    //declaro variables
    int i=0,name=0;  //i es variable para el for, name es el índice donde se encuentra el puntero al primer carácter del nombre dentro de argv[0]
    char c;       //c es un carácter para usar dentro del while
    
    
    //comienza el programa
    while((c=argv[0][i]))     //evalúa cada carácter hasta llegar al terminador
    {
        if(c=='/')      //si el carácter corresponda a una '/', hay una posibilidad de que en ese i comience el nombre del programa
        {
            name=i;
        }
        ++i;
    }
    if(name==0)
    {
	return name;
    }
    else return ++name;        //regresa el valor de i tal que en argv[0][i] comienza el nombre del programa 
}



static int evaluate (int argc, char *argv[],char *opciones[],char *valores[], char *parametros[], int *cantopc, int *cantparam){
/*Esta funcion evalua los argumentos clasificando segun sea opcion o parametros.
Devuelve un 1 si se pudo evaluar correctamente, al contrario un 0 */
	int counter=1;
	while(counter<argc){
		if(*argv[counter]=='-'){
			if(evalopc(argc,argv,counter)==VALID){		//evalua si se ingreso correctamente
				opciones[*cantopc]=argv[counter];	
				counter++;
				valores[*cantopc]=argv[counter];
				(*cantopc)++;
				counter++;
			}
			else{
				return INVALID;				//devuelve INVALIDO si no se ingreso correctamente
			}
		}
		else{
			parametros[*cantparam]=argv[counter];
			(*cantparam)++;
			counter++;
		}

	}
	return VALID;							//devuelve VALIDO si se pudo evaluar correctamente

}





static int evalopc (int argc, char *argv[], int num){		
//Esta funcion evalua si se ha ingresado el valor para la opcion.
	num++;
	if((num==argc)||((*argv[num])=='-')){
	//compara si es el ultimo argumento ingresado o si le sigue otra opcion.
		return INVALID;
	}
	else{
		return VALID;
	}

}

