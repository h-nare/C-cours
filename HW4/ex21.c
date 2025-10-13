#include <stdio.h>

int main() {
    char alphabets[27];
    int i;
    
    for (i = 0; i < 26; i++) {
        alphabets[i] = 'A' + i;
    }
    alphabets[26] = '\0';

    char *ptr = alphabets;

    printf("The Alphabets are :                                                                         \n");
    
    while (*ptr != '\0') {
        printf(" %c ", *ptr);
        
        ptr++;
    }

    printf("\n");

    return 0;
}

