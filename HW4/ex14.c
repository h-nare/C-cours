#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swap((arr + j), (arr + j + 1));
            }
        }
    }
}

int main() {
    int n;

    printf("Input the number of elements to store in the array : ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of elements.\n");
        return 1;
    }

    int arr[n];

    printf("Input %d number of elements in the array :\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for element.\n");
            return 1;
        }
    }

    sort_array(arr, n);

    printf("\n The elements in the array after sorting :\n");
    for (int i = 0; i < n; i++) {
        // Accessing array element using pointer arithmetic: *(arr + i)
        printf(" element - %d : %d\n", i + 1, *(arr + i));
    }

    return 0;
}

