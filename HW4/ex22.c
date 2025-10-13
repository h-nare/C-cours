#include <stdio.h>

int main() {
    char str[100];
    char *start_ptr;
    char *end_ptr;

    printf("Input a string : ");
    scanf("%s", str);

    printf(" Pointer : Print a string in reverse order :                                                                  \n");
    printf("------------------------------------------------                                                              \n");
    printf(" Input a string : %s                                                                                  \n", str);
    printf(" Reverse of the string is : ");

    start_ptr = str;
    end_ptr = str;
    
    while (*end_ptr != '\0') {
        end_ptr++;
    }
    
    end_ptr--;

    while (end_ptr >= start_ptr) {
        printf("%c", *end_ptr);
        end_ptr--;
    }

    printf("\n");
    return 0;
}

