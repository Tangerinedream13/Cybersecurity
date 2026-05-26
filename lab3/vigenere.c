#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rothelper.h"
#include "vigenere.h"

char rotate(char c, int howmuch)
{
    if (howmuch < 0) {
        howmuch = 26 - ((-howmuch) % 26); 
    }
    
    int shift = howmuch % 26; 
    
    if (c >= 'A' && c <= 'Z') {
        int pos = c - 'A';
        pos = (pos + shift) % 26; 
        return (char)('A'+ pos); 
    }

    if (c >= 'a' && c <= 'z') {
        int pos = c - 'a'; 
        pos = (pos + shift) % 26; 
        return (char)('a' + pos);
    }

    return c; 
}

int keyshift(char k){
    if (k >= 'A' && k <= 'Z') return k - 'A';
    if (k >= 'a' && k <= 'z') return k - 'a';
    return 0;
}

char* flatten_key(char key[]){
    int str_len = stringlength(key);
    char* flat = malloc(str_len +1);

    int j =0;
    for ( int i =0; i < str_len; i++ ){
        char c = key[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            flat[j] = c;
            j++;
        }
    }
    flat[j] = '\0';
    return flat;
}

char* encipher(char somewords[], char key[]){
    int str_len = stringlength(somewords);
    char* flat = flatten_key(key);
    int key_len = stringlength(flat);
    

    char* out = malloc((str_len + 1) * sizeof(char));
    int j = 0; 

    for (int i = 0; i<str_len; i++){
        char c = somewords[i];
        int shift = keyshift(flat[j % key_len]);

        if ((c >= 'A' && c <='Z') || (c >= 'a' && c <= 'z')){
            
            out[i] = rotate(c,shift);
            
        } else {out[i] = c;
        }
        j++;
    }
    out[str_len] = '\0';
    free(flat);
    return out;

}

char* decipher(char somewords[], char key[]){
    int str_len = stringlength(somewords);
    char * flat = flatten_key(key);
    int key_len = stringlength(flat);

    char* out = malloc((str_len + 1) * sizeof(char));
    int j = 0; 

    for ( int i=0; i<str_len; i++){
        char c = somewords[i];
        int shift = keyshift(flat[j % key_len]);

        if ((c >= 'A' && c <='Z') || (c >= 'a' && c <= 'z')){
            
            out[i] = rotate(c, -shift);
            
        } else { out [i] =c;
        }
        j++;
    }
    out [str_len] = '\0';
    free(flat);
    return out;
}