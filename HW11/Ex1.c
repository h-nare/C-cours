#include <stdio.h>
#include <string.h>

int main() {
    char str1[101], str2[101];
    char copy[101];
    char concat[202];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    strcpy(concat, str1);
    strcat(concat, str2);
    printf("\nConcatenated: %s\n", concat);

    if (strcmp(str1, str2) == 0)
        printf("Strings are the SAME.\n");
    else
        printf("Strings are DIFFERENT.\n");

    printf("Length of first string: %lu\n", strlen(str1));
    printf("Length of second string: %lu\n", strlen(str2));

    strcpy(copy, str1);
    printf("Copy of first string: %s\n", copy);

    return 0;
}

