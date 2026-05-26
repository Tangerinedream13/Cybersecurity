#include <stdio.h>
#include <stdlib.h>
#include "rothelper.h"
#include "rot13.h"

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

char* rotate_words(char input[], int howmuch)
{
    int len = stringlength(input); 

    char* out = (char*)malloc((len + 1) * sizeof(char));
    if (out == NULL) return NULL; 
    
    for (int i = 0; i < len; i++) {
        out[i] = rotate(input[i], howmuch);
    }
    out[len] = '\0';

    return out; 
}

char* rot13(char input[])
{
    return rotate_words(input, 13);
}
