//declaraciones
#include <stdio.h>
#include <stdlib.h>

//el programa puede recibir fechas en formato dd/mm/aaaa o dd/mm/aaaa o d/m/a, todos los numeros que no se ingresen se asumen 0 con fin de realizar el ingreso de datos mas rapido
void loop(void);
int *getfecha(void);
int validacion(int, int);
int validyear(int);
int bisiesto(int);
int diferencia(int, int, int, int ,int ,int);

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
  int total, day0, month0, year0, day, month, year, err, fbisiesto, i;
  int *date;

  for (i=0;i<2;i++) { //se pedira el ingreso de datos 2 veces

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
            printf("Excepto en este caso (ano bisiesto).\n");
          }
        }
      }

    } while (err==1);

    printf("\n--------------------------------------------\n");
    printf("Termino validacion de mes y dia sin errores.\n");
    printf("--------------------------------------------\n");
    printf("Day: %d\n",day);
    printf("Month: %d\n",month);
    printf("Year: %d\n",year);

    if (i==0) { //si es el primer ingreso lo guardamos en variables distintas
      day0=day;
      month0=month;
      year0=year;
      printf("\n----------------------------\n");
      printf("Comienza el segundo ingreso.\n");
      printf("----------------------------\n");
    }
  }

  //pedimos que se calcule la cantidad de dias
  total=diferencia(day0, month0, year0, day, month, year);
  printf("\n--------------------------------\n");
  printf("La cantidad total de días es %d.\n",total);
  printf("--------------------------------\n");
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
    printf("------------------------\n");
    printf("Mes no valido\n");
    error=1;
  }

  if ((dia>31)||(dia<1)){ //el dia debe estar entre 1 y 31
      printf("------------------------\n");
      printf("Dia no valido.\n");
      error=1;
  }
  if ((mes==2)&&(dia==28)){ //si el mes es febrero puede tener 28 dias
    printf("------------------------\n");
    printf("No me vas a arruinar con 28 de febrero capo.\n");
  }
  else if ((mes==2)&&(dia>28)){ //si el mes es febrero la mayor cantidad posible es 29
    printf("------------------------\n");
    printf("El mes %d no tiene %d dias.\n",mes ,dia);
    error=1;
  }
  else if ((tabla[mes-1]==0)&&(dia==31)){ //si el mes tiene 30 dias y el dia es 31, esta mal
    printf("------------------------\n");
    printf("El mes %d tiene 30 dias.\n",mes);
    error=1;
  }

  return error;
}

//funcion para validar ano de 2 digitos
int validyear (int ano){

  int siglo=0, cha, ultimateano, mistake=0;

  if (ano<100){

    printf("\n*****************************************\n");
    printf("* El ano %d tiene dos o menos digitos.  *\n",ano);
    printf("* Ingrese el siglo, sino ingrese 0.     *\n");
    printf("*****************************************\n");

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

//funcion diferencia, calcula
int diferencia(int day1, int month1, int year1, int day2, int month2, int year2) {

  int i;  //variable para el FOR
  int dm1=0 ,dm2=0; //cantidad de días en los meses comprendidos entre el 1/1/y y el 1/m/y con m el mes que corresponda e y el año que corresponda
  int leap1 ,leap2;  //cantidad de años bisiestos desde el 1/1/0000 hasta la fecha 1 o 2
  int leaptotal;  //cantidad de años bisiestos entre las dos fechas
  int tdays1 ,tdays2 ,tdays;    //días totales desde 1/1/0000 hasta la fecha 1 o 2

    for (i=(month1-1);i>0;--i)  //calculo la cantidad de días desde el 1/1 hasta el 1/m con m el mes que corresponda
    {
        switch (i)          //según el mes la cantidad de días es distinta
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dm1=dm1+31;
            break;
            case 4: case 6: case 9: case 11:
            dm1=dm1+30;
            break;
            case 2:
            dm1=28+dm1;
            break;
        }
    }

    for (i=(month2-1);i>0;--i)  //hago lo mismo para el mes de la segunda fecha.
    {
        switch (i)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dm2=dm2+31;
            break;
            case 4: case 6: case 9: case 11:
            dm2=dm2+30;
            break;
            case 2:
            dm2=28+dm2;
            break;
        }
    }

    //calculo cantidad de años bisiestos desde el 1/1/0000 hasta la fechas
    if(month1<=2 && day1<=28)       //Si aún no se llego al 29 de Feb, no hay que considerar si el año es bisisesto o no.
    {
        leap1=((year1-1)/4)-((year1-1)/100)+((year1-1)/400);    //cantidad de años bisiestos entre 1/1/0000 y la fecha actual, se toma year-1 en caso de que
                                                                //el año sea bisiesto, ya que al no haber llegado al 29 de Feb no se debería considerar
    }
    else
    {
        leap1=(year1/4)-(year1/100)+(year1/400);
    }

    if(month2<=2 && day2<=28)       //análogo para el segundo año
    {
        leap2=((year2-1)/4)-((year2-1)/100)+((year2-1)/400);
    }
    else
    {
        leap2=(year2/4)-(year2/100)+(year2/400);
    }

    //calculo cantidad de días
    tdays1=day1+dm1+(year1*365); //calculo la cantidad de días desde el 1/1/0000 hasta la fecha
    tdays2=day2+dm2+(year2*365); //supongo que todos los años tienen 365 días y luego sumo los años bisiestos

    //imprimo el resultado
    if(year1>year2)     //efectúo la resta según cuál año sea mayor.
    {
        leaptotal=leap1-leap2;
        tdays=tdays1-tdays2+leaptotal;
    }
    else if(year2>year1)
    {
        leaptotal=leap2-leap1;
        tdays=tdays2-tdays1+leaptotal;
    }
    else                                //en este caso estamos en el mismo año de donde se procede a comparar los meses.
    {
        if(month1>month2)
        {
            if (((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 ==0) && month1>2 && month2<=2)  //si el año actual es bisiesto y se pasó 29 de feb en la fecha sumar uno
            {
                tdays=tdays1-tdays2+1;
            }
            else
            {
                tdays=tdays1-tdays2;
            }
        }
        else if (month2>month1)
        {
            if (((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 ==0) && month2>2 && month1<=2)
            {
                tdays=tdays2-tdays1+1;
            }
            else
            {
                tdays=tdays2-tdays1;
            }
        }
        else            //en este caso los meses son iguales
        {
            if(day1>day2)
            {
                tdays=day1-day2;
            }
            else
            {
                tdays=day2-day1;
            }
        }
    }

    return tdays;
}
