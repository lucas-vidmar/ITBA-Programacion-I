#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//mayuscula a minuscula
void convert (char arr[]);

int main (void)
{
char arr[]= "HOlAcoMOesTAN";
convert(arr);
}



void convert (char *arr)
{
	char mayu[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char minu[]= "abcdefghijklmnopqrstuvwxyz";
	int i;
	int j;
	for(i=0;arr[i];++i)
	{
		for(j=0;mayu[j];++j)
		{
			if(arr[i]==mayu[j])
			{
				arr[i]=minu[j];
			}
		}
	}
	printf("%s\n",arr);
}