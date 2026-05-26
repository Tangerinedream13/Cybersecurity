#include <stdio.h>
#include "bealehelper.h"
#include "beale.h"

void dump_cipher(Beale b, char* name, int displayHowMany)
{
	int index = 0;
	char c;
	printf("Dumping %d characters of cipher %s (%d words):\n", displayHowMany, name, b.length);
	for (int i = 1; i < b.length; i++)
	{
		c = b.letters[i];
		printf("%c ", c);
		if ((i % 25 == 0) && (i != 0))
			printf("\n");
	}
	printf("\n");
}

void dump_ciphertext(int* enc, int ingrader, int len)
{
	char* padding;
	printf("Length of ciphertext is %d\n", len);
	if (ingrader)
	{
		padding = "         ";
	}
	else
	{
		padding = "";
		printf("Dumping beale-encrypted text:\n");
	}
	printf("%s", padding);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", enc[i]);
		if ((i % 25 == 0) && (i != 0))
			printf("\n%s", padding);
	}
	printf("\n");
}
