#include <stdio.h>

void copy(int *arr,int *arr_cp,int size)
{

    for (int i = 0; i < size; i++)
    {
        *(arr_cp + i) = *(arr + i);
    }

    printf("\n");
}

int main()
{ 	
    int n;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], arr_cp[n];


    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
    copy(arr,arr_cp, n);

    printf("Copied array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr_cp+ i));
    }
    printf("\n");

    return 0;
}
