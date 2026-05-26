#include <stdio.h>
#include "rothelper.h"
#include "rot13.h"

void test_words(char somewords[], int rotation)
{
	char* result = rotate_words(somewords, rotation);

	printf("Original: %s\n", somewords);
	printf("Rotation: %d\n", rotation);
	printf("Encoded : %s\n\n", result);
}

void test_rotate(char c, int rotation)
{
	printf("The character %c rotated by %d is %c\n", c, rotation, rotate(c, rotation));
}

int main()
{
	char testcase1[] = "the five boxing wizards jump quickly";
	char testcase2[] = "QUIZZICAL TWINS PROVED MY HIJACK_BUG FIX";
	char testcase3[] = "Amazingly, few discotheques provide Jukeboxes!";

	test_rotate('a', 5);
	test_rotate('z', 5);
	test_rotate('E', 10);
	test_rotate('Q', 12);

	test_words(testcase1, 1);		// every letter gets the next letter
	test_words(testcase1, 4);		// same as the example in the spec
	test_words(testcase2, 5);
	test_words(testcase3, 13);
	test_words(testcase1, 0);		// no change
	test_words(testcase1, 25);		// every letter gets the previous letter
	test_words(testcase1, 26);		// 0 and 26 should be the same - no change
	test_words(testcase1, 22);		// 22 and 100 should be the same
	test_words(testcase1, 100);
}
