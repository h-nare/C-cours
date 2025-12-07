#include <stdio.h>
#include <stdlib.h>

int main() {
    	int n, i;
    	int *ptr;

    	printf("Input the number of elements to store in the array : ");
    	scanf("%d", &n);

   	ptr = (int*)malloc(n * sizeof(int));

    	if (ptr == NULL) {
        	printf("Memory allocation failed.\n");
        	return 1;
    	}

    	printf("Input %d number of elements in the array :\n", n);
    	for (i = 0; i < n; i++) {
        	printf("element - %d : ", i);
        	scanf("%d", ptr + i); 
    	}

    	printf("\nThe elements you entered are :\n");
    	for (i = 0; i < n; i++) {
        	printf("element - %d : %d\n", i, *(ptr + i));
    	}

    	free(ptr);
    	return 0;
}
