#include <stdio.h>
#include "rothelper.h"

int stringlength(char string[])
{
	if (string == NULL)
		return 0;

	int count = 0;
	while (string[count] != '\0')
		count++;
	return (count);
}
