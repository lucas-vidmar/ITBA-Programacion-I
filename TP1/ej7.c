#include<stdio.h>
#define mascara1 0x21       //0010 0001b
#define mascara2 0xE7       //1110 0111b
#define verdadero 1
#define falso 0

int main(void) {
  char porta=0x21;
  char result;
/*se eligio usar variables de tipo char porque el puerto A consiste en 1 byte
y el resultado es binario*/

  result=((porta&mascara1)==mascara1)||((porta|mascara2)==mascara2)?verdadero:falso;
/*compara el puerto A con las mascaras para determinar si los bits 5 y 0 estan en 1
o si los bits 3 y 4 estan en 0*/

  printf("%d\n",result);
  return 0;
}
