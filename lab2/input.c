#include <stdio.h>

void get_input_unsafe(char stuff[], int len)
{
	int c = getchar();
	int count = 0;
	// While loop only checks for \n
	while (c != '\n')
	{
		stuff[count] = c;
		c = getchar();
		count++;
	}
	// Where are the null terminators?
}

void get_input_safe(char stuff[], int len)
{
	int c = getchar();
	int count = 0;
	// While loop checks for length and \n
	while (count < len)
	{
		stuff[count] = c;
		c = getchar();
		count++;
		if (c == '\n')
			break;
	}
	// Handle when the input is less than the length
	stuff[count] = 0;
	// Handle in case the input was >= the length
	stuff[len-1] = 0;

	// Flush the stdin buffer
	while (c != '\n' && c != EOF)
		c = getchar();
}

void get_input(char stuff[], int len)
{
	// get_input_safe(stuff, len);
	get_input_unsafe(stuff, len);
}
