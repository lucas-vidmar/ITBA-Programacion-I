#include <stdio.h>
#define NUM 1
int main(void) {

// declaro variables
  int num=NUM, i, flag=0;
  printf("Numero elegido: %d\n",num);
  if (num>=2)
  {
    for (i=2;i<num;i++)
    {
      if (!(num%i)) //si es el resto es 0, no es primo
      {
        flag=1;
        printf("Es divisible por: %d\n",i);
      }
    }
    if (flag==1)
    {
      printf("Por lo tanto no es primo\n");
    }
    else
      printf("Es primo\n");
  }
  else if (num==1)
  {
    printf("Existe toda una discusion matematica acerca de este caso.\nPodriamos considerar al 1 como no primo porque solo\ncumple con una de las dos condiciones. \n");
  }
  else
  {
    printf("Elija un numero mayor a 1\n");
  }
  return 0;
}
