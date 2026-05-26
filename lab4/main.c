#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_words(char* filename)
{
	// opens the file in read mode
	FILE* fp = fopen(filename, "r");

	// this tests if the file will open
	if (fp == NULL)
	{
		printf("Error when opening %s\n", filename);
		return -1;
	}

	char buf[255];

	int count = 0;  // counts the words to be found

	// fscanf returns 1 when it successfully reads a word
	// it returns EOF when it reaches the end of the file
	while (fscanf(fp, "%254s", buf) == 1)
	{
		count++;
	}

	// always close the file when done
	fclose(fp);

	return count;
}

char* first_letters(char* filename)
{
	// This function should read each word from the filename
	// and return a char array that contains the first letter
	// of each word in the file.
	// For example, if "everything.txt" contained "So long and thanks for all the fish!"
	// this function would return the char array [S, l, a, t, f, a, t, f]

	// Step 1: Figure out how many words are in the file
	int count = count_words(filename);

	if (count <= 0)
	{
		return NULL;
	}

	// Step 2: Open the file again so it can be read a second time
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Error: could not open file %s\n", filename);
		return NULL;
	}

	// Allocate enough space to hold all the first letters
	// +1 so we can add a '\0' at the end (like a string)
	char* letters = (char*) malloc((count + 1) * sizeof(char));

	if (letters == NULL)
	{
		printf("Error: memory allocation failed\n");
		fclose(fp);
		return NULL;
	}

	char buf[255];   // temporary buffer to store each word
	int index = 0;   // keeps track of where we are in letters array

	// Read each word again
	while (fscanf(fp, "%254s", buf) == 1)
	{
		// Take the first character of the word
		letters[index] = buf[0];

		index++;
	}

	// Add null terminator at the end
	letters[count] = '\0';

	fclose(fp);

	return letters;
}


char* arrtostr(char* charry, int len)
{
	char* ret = (char*) malloc((2*len+3) * sizeof(char));

	int retindex = 0;
	ret[retindex++] = '[';
	for (int i = 0; i < len; i++)
	{
		ret[retindex++] = charry[i];
		ret[retindex++] = ' ';
	}
	ret[retindex++] = ']';
	ret[retindex++] = '\0';
	return ret;
}

int main(int argc, char** argv)
{
	// Use the command line arguments to take in a file
	// First, call count_words on the file to determine how many words are in the file
	// Then, call first_letters to create and return the char array
	// of the first letters of every word in the file.

	// int count = count_words(file here);
	// char* firsts = first_letters(file here);
	// printf("Your array is %s\n", arrtostr(firsts, count));

	// Defensive check: make sure exactly one filename was given
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	char* filename = argv[1];

	// Counts how many words are in the file
	int count = count_words(filename);

	if (count < 0)
	{
		return 1;
	}

	// Creates an array of the first letters
	char* firsts = first_letters(filename);

	if (firsts == NULL)
	{
		return 1;
	}

	// Converts the array into a printable form 
	char* printable = arrtostr(firsts, count);

	printf("word count: %d\n", count);
	printf("your array: %s\n", printable);

	free(printable);
	free(firsts);

	return 0;
}