
#include <stdio.h>


#define TER '\n' //terminador establecido de palabra

int main(void) {
  FILE *fp;
  char array[200], ch;
  int i;

  fp=fopen("bancoPruebas.txt", "r");
  do {
    ch=fgetc(fp);
    array[i]=ch;
    i++;
  } while (ch!=EOF);
  fclose(fp);

  for (i=0; array[i]!=EOF ;i++)
    printf("%c\n",array[i]);

}
