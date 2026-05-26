#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rothelper.h"
#include "bealehelper.h"
#include "beale.h"

int countletters(char msg[])
{
	int len = strlen(msg);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (msg[i] != ' ')
			count++;
	}
	return count;
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	char* text;

	if (argc == 2)
		text = argv[1];
	else
		text = "pride.txt";

	int b1 = count_words(text);
	printf("The file %s has %d words\n", text, b1);

	Beale bc1 = create_cipher(text);
	dump_cipher(bc1, text, 1000);

	char msg1[] = "The quick brown fox jumped over the lazy dog.";
	char msg2[] = "Amazingly, few discotheques provide Jukeboxes!";
	int* ec1 = encipher(msg1, bc1);
	int* ec2 = encipher(msg2, bc1);

	dump_ciphertext(ec1, 0, strlen(msg1));
	dump_ciphertext(ec2, 0, strlen(msg2));

	char* dc1 = decipher(ec1, bc1);
	char* dc2 = decipher(ec2, bc1);
	printf("The msg is %s\n", dc1);
	printf("The msg is %s\n", dc2);

	free(ec1);
	free(ec2);
	free(dc1);
	free(dc2);
	free(bc1.letters);

	return 0; 
}

