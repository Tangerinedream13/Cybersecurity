#ifndef __BEALE
#define __BEALE

typedef struct beale {
	int length;
	char* letters;
} Beale;

int* encipher(char* str, Beale b);
char* decipher(int* msg, Beale b);
int count_words(char filename[]);

Beale create_cipher(char filename[]);
#endif
