#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascending(const char *a, const char *b) {
    return strcmp(a, b);
}

int descending(const char *a, const char *b) {
    return strcmp(b, a);
}

void sort_strings(char *arr[], int size, int (*cmp)(const char *, const char *)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (cmp(arr[i], arr[j]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    char *arr[] = {"banana", "apple", "cherry", "mango"};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);

    sort_strings(arr, size, ascending);
    printf("\nSorted ascending:\n");
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);

    sort_strings(arr, size, descending);
    printf("\nSorted descending:\n");
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);

    return 0;
}
