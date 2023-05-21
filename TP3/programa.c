#include<stdio.h>
#include<stdlib.h>

int day1=12,month1=4,year1=1874,day2=27,month2=10,year2=2013; //variables donde van a estar guardadas el día, mes y año de ambas fechas.
int i;  //variable para el FOR
int dm1=0,dm2=0; //cantidad de días en los meses comprendidos entre el 1/1/y y el 1/m/y con m el mes que corresponda e y el año que corresponda
int leap1,leap2;  //cantidad de años bisiestos desde el 1/1/0000 hasta la fecha 1 o 2
int leaptotal;  //cantidad de años bisiestos entre las dos fechas
int tdays1,tdays2,tdays;    //días totales desde 1/1/0000 hasta la fecha 1 o 2

int main(void)
{
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
    printf("La cantidad total de días es %d.\n",tdays);
    return 0;
}
