#include<stdio.h>
int findname(int argc, char *argv[]);        //la función busca el índice tal que en argv[0][i] comience el nombre del programa

int main (int argc,char *argv[]) {
    int start;
    start=findname(argc,argv);
    printf("Nombre del programa:\n%s\n",*argv+start);	//imprime el nombre del programa
    
}

int  findname(int argc, char *argv[]) {      
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
