#include <stdio.h>
#include "stoi.h"

int stoi (char *num)
{
	int i=0;
	int result=0;
	while(num[i])
	{
		result=result*10+(num[i]-'0');
		i++;
	}
	return result;
}

