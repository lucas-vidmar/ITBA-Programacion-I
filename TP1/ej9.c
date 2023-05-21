#include <stdio.h>

int main(void) {

// declaro variables
  double num=54.636;
  int entero;
  int numf;
  int pdec;
  int dosdec;
  int tresdec;
  double numf2;
  int entinf;
  double partedecimal;

// mostramos el nro
  printf("El numero:%f\n",num);

//redondeo a entero
  entero=(int)num;
  pdec=(num-entero)*10;
  numf=entero;
  pdec>=5?++numf:(numf=numf);
  printf("El entero redondeado:%d\n",numf);

//entero superior
  printf("El entero superior:%d\n",entero+1);

//entero inferior
  num>entero?(entinf=entero):(entinf=entero-1);
  printf("El entero inferior:%d\n",entinf);

//parte decimal
  partedecimal=num-entero;
  printf("La parte decimal:%f\n",partedecimal);

//redondeo a dos decimales
  dosdec=num*100;
  tresdec=num*1000;

  (tresdec-dosdec*10)>=5?(numf2=(++dosdec)/100.0):(numf2=(dosdec/100.0));
  printf("El numero redondeado con 2 decimales:%f\n",numf2);

  return 0;
}
