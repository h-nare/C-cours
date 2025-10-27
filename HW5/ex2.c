#include <stdio.h>

int main() {
    int rows, cols;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter element at row %d, col %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nTranspose of the matrix:\n");
    for(int j = 0; j < cols; j++) {       
        for(int i = 0; i < rows; i++) { 
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

