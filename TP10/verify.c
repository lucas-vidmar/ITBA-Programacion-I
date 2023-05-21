#include <stdio.h>
#include "verify.h"

int verify (char *number)
{
	int i=0;
	while( (int)number[i] )
	{
		if('0'>number[i] || '9'<number[i])
		{
			return 0; //hay error
		}
		i++;
	}
	return 1; //no hay error
}
