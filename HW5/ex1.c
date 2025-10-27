#include <stdio.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

int str_cmp(char *s1, char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main() {
    int n;  
    char names[MAX_NAMES][MAX_LENGTH];
    int i, j;
    int duplicateFound;

    printf("Enter number of names: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("\nDuplicate names are:\n");

    for (i = 0; i < n; i++) {
        duplicateFound = 0;

        for (j = 0; j < i; j++) {
            if (str_cmp(names[i], names[j]) == 0) {
                duplicateFound = 1;
                break;
            }
        }

        if (!duplicateFound) {
            // Check if this name appears later
            for (j = i + 1; j < n; j++) {
                if (str_cmp(names[i], names[j]) == 0) {
                    printf("%s\n", names[i]);
                    break;
                }
            }
        }
    }

    return 0;
}

