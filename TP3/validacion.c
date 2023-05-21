//declaraciones
#include <stdio.h>
#include <stdlib.h>

void loop(void);
int *getfecha(void);
int validacion(int, int);
int validyear(int);
int bisiesto(int);

//funcion main
int main(void) {
  while (1)
  {
    loop();
  }
  return 0;
}

//funcion loop, donde se realizan todas las tareas
void loop(void){
  int day, month, year, err, fbisiesto;
  int *date;

  do{

    //la funcion devuelve un array con multiples datos
    do {
      date=getfecha();
    } while (!((int)date)); //si trae codigo de error 0, debe hacerlo de nuevo

    //asignamos variables fijas para cada uno de los parametros
    day=(*(date + 0));
    month=(*(date + 1));
    year=(*(date + 2));

    //mandamos los datos a ser validados
    err=validacion(day, month); //si err=1, dia o mes no valido

    //nos fijamos, si hay un error, que no se deba al 29 de febrero
    if (err==1) {
      fbisiesto=bisiesto(year); //si fbisiesto=1, año bisiesto
      if (fbisiesto==1) { //si dio error y el año es bisiesto, evaluar que el error no sea por 29 de febrero
        if ((day==29)&&(month==2)) {
          err=0;  //el error era por el 29 de feb, corregimos el flag
          printf("Excepto en este caso (año bisiesto).\n");
        }
      }
    }

  } while (err==1);
  printf("Termino validacion de mes y dia sin errores.\n");

  printf("Day: %d\n",day);
  printf("Month: %d\n",month);
  printf("Year: %d\n",year);
}

//funcion para tomar la fecha del input
int *getfecha(){

  int mm=0, dd=0, yy=0, ch, caso=0, mistake=0;
  static int fecha[3];
  printf("\n\n********************\n"); printf("* Ingrese la fecha *\n"); printf("********************\n");

  while ((ch = getchar()) != '\n') {  //mientras que no se presione enter, leer
    if (ch == '/'){
      caso++; //cuando se presione la barra se aumenta el caso
    }
    else if ( ((ch - '0')>9) || ((ch - '0')<0) ) { //si el caracter no es un numero esta mal
      printf("----------Input Error----------\n");
      mistake=1;
    }
    else {
      switch (caso) { //dependiendo del caso se guardara en mes dia o año
        case 0: dd= dd*10 + (ch - '0'); break;
        case 1: mm= mm*10 + (ch - '0'); break;
        case 2: yy= yy*10 + (ch - '0'); break;
        case 3: printf("No se tomaran los datos luego de la ultima barra.\n"); caso++; break;
        default: break;
      } //se multiplica por 10 para correr el numero hacia la izquierda
    }
  }

  if (mistake!=1) {
    //seteamos un array para devolver todos los datos
    fecha[0]=dd;
    fecha[1]=mm;
    fecha[2]=validyear(yy);

    if (fecha[2]==(-1)) { //si hubo error de input en la validacion de ano, avisar
      return 0;
    }

    return fecha;
  }

  return 0; //devolvemos codigo de error 0 si hubo error de input

}

//funcion para validar dia y mes
int validacion(int dia, int mes){

  int error=0;
  int tabla[12]={0}; //array tabla que contiene 1 en los meses con 31 y 0 en los de 30
  tabla[0]=1;
  tabla[2]=1;
  tabla[4]=1;
  tabla[6]=1;
  tabla[7]=1;
  tabla[9]=1;
  tabla[11]=1;


  //comienza validacion de datos
  if ((mes>12)||(mes<1)){ //el mes debe estar entre 1 y 12
    printf("Mes no valido\n");
    error=1;
  }

  if ((dia>31)||(dia<1)){ //el dia debe estar entre 1 y 31
      printf("Dia no valido.\n");
      error=1;
  }
  if ((mes==2)&&(dia==28)) //si el mes es febrero puede tener 28 dias
    printf("No me vas a arruinar con 28 de febrero capo.\n");
  else if ((mes==2)&&(dia>28)){ //si el mes es febrero la mayor cantidad posible es 29
    printf("El mes %d tiene 28 dias.\n",mes);
    error=1;
  }
  else if ((tabla[mes-1]==0)&&(dia==31)){ //si el mes tiene 30 dias y el dia es 31, esta mal
    printf("El mes %d tiene 30 dias.\n",mes);
    error=1;
  }

  return error;
}

//funcion para validar ano de 2 digitos
int validyear (int ano){

  int siglo=0, cha, ultimateano, mistake=0;

  if (ano<100){
    printf("El año %d tiene dos o menos digitos. Ingrese el siglo, sino ingrese 0.\n",ano);
    while ((cha = getchar()) != '\n') {
      if ( ((cha - '0')>9) || ((cha - '0')<0) ) { //si el caracter no es un numero esta mal
        printf("----------Input Error----------\n");
        mistake=1;
      }
      else
        siglo= siglo*10 + (cha - '0'); //vamos sumando los numeros ingresados, corriendo el anterior hacia la izquierda
    }

    if (mistake!=1) { //si no hubo error de input, se pasan los datos

      if (siglo!=0) //se corrige el ano
        ultimateano=(siglo-1)*100+ano;  //self explanatory
      else  //si se ingreso el 0, no se hace ninguna modificacion al ano
        ultimateano=ano;

      return ultimateano;

    }

    return (-1); //se devuelve flag de error -1

  }
  else {
    return ano;
  }
}

//funcion para ver si el ano es bisiesto
int bisiesto (int n) {

  if ( !(n%4) ) {  //podria ser bisiesto
    if ( !(n%100) ){  //si es divisible por 100, podria ser bisiesto
      if ( !(n%400) ) { //si es divisible por 400 es bisiesto
        return 1;
      }
      else  //no es divisible por 400 y si por 100, no es bisiesto
        return 0;
    }
    else  //no es divisible por 100 y si por 4, es bisiesto
      return 1;
  }
  else  //no es divisible por 4, no es bisiesto
    return 0;
}
