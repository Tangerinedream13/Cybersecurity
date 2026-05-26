#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rothelper.h"
#include "vigenere.h"

void test_decipher(char somewords[], char key[])
{
	char* result = encipher(somewords, key);
	char* result2 = decipher(result, key);

	printf("Original: '%s' with length %d\n", somewords, (int)strlen(somewords));
	printf("Encoded : '%s' with length %d\n", result, (int)strlen(result));
	printf("Deciphered: '%s' with length %d\n", result2, (int)strlen(result2));
	if (strcmp(somewords, result2))
		printf("   *** Your answer did not match the expected answer (strcmp(result, answer) == %d) ***\n", strcmp(somewords, result2));
	printf("\n");
	free(result);
	free(result2);
}

void test_words(char somewords[], char key[], char answer[])
{
	char* result = encipher(somewords, key);

	printf("Original: '%s' with length %d\n", somewords, (int)strlen(somewords));
	printf("Encoded : '%s' with length %d\n", result, (int)strlen(result));
	printf("Answer  : '%s' with length %d\n", answer, (int)strlen(answer));
	if (strcmp(result, answer))
		printf("   *** Your answer did not match the expected answer (strcmp(result, answer) == %d) ***\n", strcmp(result, answer));
	printf("\n");
	free(result);
}

int main()
{
	char testcase1[] = "abcde";
	char testcase2[] = "abcdefghijklmno";
	char testcase3[] = "word1 word2 words";
	char testcase4[] = "the five boxing wizards jump quickly";
	char testcase5[] = "QUIZZICAL TWINS PROVED MY HIJACK BUG FIX";
	char testcase6[] = "Amazingly, few discotheques provide Jukeboxes!";

	test_words("secret", "cipher", "umryik");
	test_words(testcase1, "aaaaa", "abcde");    			// no change
	test_words(testcase1, "abcde", "acegi");    			// each letter is shifted by one more than the previous
	test_words(testcase1, "abc", "acedf");					// key repeats sooner than the test above
	test_words(testcase1, "abcdefghijklmno", "acegi");		// key is longer than the word; shouldn't be different or blow up

	test_words(testcase2, "aaaaa", "abcdefghijklmno");		// no change
	test_words(testcase2, "abcde", "acegifhjlnkmoqs");
	test_words(testcase2, "abc", "acedfhgikjlnmoq");

	test_words(testcase3, "qwerty", "mkvu1 mkvu2 mkvul");	// numbers/spaces should be unchanged
	test_words(testcase3, "QWERTY", "mkvu1 mkvu2 mkvul");	// capitalization of key should not matter
	test_words(testcase3, "QwErTy", "mkvu1 mkvu2 mkvul");

	test_words(testcase4, testcase5, "jbm eqxe ukfvfv kddddbz suoz kankhbs");
	test_words(testcase5, testcase4, "JBMEHDGBZ BJOJA PIRNNX BO PKTLAD FZO JJL");
	test_words(testcase6, testcase5, "Qgiyhvilj, nro uwngrfflydeu qluaqau Rtjmdoixo!");
	test_words(testcase6, testcase4, "Tteeqikmm, sks cijfgcbqfkya zcmophj Eylsywkko!");

	printf("Testing decipher by deciphering your enciphered words...\n");
	test_decipher(testcase4, testcase5);
	test_decipher(testcase5, testcase4);
	test_decipher(testcase6, testcase5);
	test_decipher(testcase6, testcase4);
}
