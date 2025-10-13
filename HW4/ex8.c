#include <stdio.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int start, int end) {
    if (start == end) {
        printf("%s  ", str);
    } else {
        for (int i = start; i <= end; i++) {
            swap((str + start), (str + i));
            permute(str, start + 1, end);
            swap((str + start), (str + i));
        }
    }
}

int main() {
    char str[] = "abcd";
    
    int n = 0;
    char *p = str;
    while (*p != '\0') {
        n++;
        p++;
    }
    int end = n - 1;

    printf("The original string is: %s\n", str);
    printf("The permutations of the string are:\n");

    permute(str, 0, end);

    printf("\n");

    return 0;
}

