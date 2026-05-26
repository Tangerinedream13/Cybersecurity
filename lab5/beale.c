#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "beale.h"
#include "rothelper.h"

#define SENTINEL (0)
#define BUF_SIZE 255

//Opens a file and counts how many words are contained, then returns this number for later use
int count_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { perror("Failed to open file"); exit(1); }

    char buf[BUF_SIZE];
    int count = 0;
    while (fscanf(fp, "%254s", buf) == 1) {
        count++;
    }

    fclose(fp);
    return count;
}
// Opens file, then builds array containing the first letter of each word in the file
char *first_letters(char *filename) {
    char buf[BUF_SIZE];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file!");
        exit(1);
    }

    int len = count_words(filename) + 1;
    char *letters = (char *)malloc(sizeof(char) * len);
    if (letters == NULL) {
        perror("Failed to allocate memory!");
        exit(1);
    }

    char *format_string = malloc(sizeof(char) * 6);
    if (format_string == NULL) {
        perror(
            "Failed to allocate memory!");
        free(letters);
        exit(1);
    }
    
    sprintf(format_string, "%%%ds", BUF_SIZE - 1);

    int c = fscanf(fp, format_string, buf);
    int index = 1;
    while (c != EOF) {
        letters[index] = buf[0];
        c = fscanf(fp, format_string, buf);
        index++;
    }
    letters[index] = '\0';

    free(format_string);
    fclose(fp);
    return letters;
}

//converst a string into an array of ints
// uses cipher array to store index of characters 
int *encipher(char *str, Beale b) {
    int len = stringlength(str);

    int *cipher = malloc(sizeof(int) * (len + 1));
    if (cipher == NULL) {
        perror("Failed to allocate memory!");
        exit(1);
    }

    for (int i = 0; i < len + 1; i++) {
        cipher[i] = -1;
    }

    int j;
    int i;
    for (i = 0; i < len; i++) {
        for (j = 1; j < b.length; j++) {
        if (b.letters[j] == str[i]) {
            cipher[i] = j;
            break;
        }
        }
    }
    cipher[i] = SENTINEL;

    return cipher;
}
//reads ints until the sentinel value is located., then returns a string containing decrypted text. 
char *decipher(int *msg, Beale b) {
    int len = 0;
    for (int k = 0; msg[k] != SENTINEL; k++) {
        len++;
    }

    char *deciphered_text = malloc(len + 1);
    if (deciphered_text == NULL) {
        perror("Failed to allocate memory!");
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        int index = msg[i];
        if (index != -1) {
        deciphered_text[i] = b.letters[index];
        } else {
        deciphered_text[i] = '*';
        }
    }
    deciphered_text[len] = '\0';

    return deciphered_text;
}
//used to create and return the Beale cipher structure. 
Beale create_cipher(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
    perror("Unable to open file");
    exit(1);
    }
    fclose(fp);

    char *letters = first_letters(filename);
    int count = count_words(filename);

    Beale b;
    b.length = count;
    b.letters = letters;
    b.letters[0] = -1;

    return b;
}