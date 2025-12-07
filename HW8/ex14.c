#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j, temp;
    	int *p;

    	printf("Input the number of elements to store in the array : ");
    	scanf("%d", &n);

    	p = (int *)malloc(n * sizeof(int));
    	if (p == NULL)
        	return 1;

   	printf("Input %d number of elements in the array :\n", n);
    	for (i = 0; i < n; i++)
    	{
        	printf("element - %d : ", i + 1);
        	scanf("%d", p + i);
    	}

    	for (i = 0; i < n - 1; i++)
    	{	
        	for (j = i + 1; j < n; j++)
        	{
            		if (*(p + j) < *(p + i))
            		{
                		temp = *(p + i);
                		*(p + i) = *(p + j);
                		*(p + j) = temp;
            		}
        	}
    	}

    	printf("\nThe elements in the array after sorting :\n");
    	for (i = 0; i < n; i++)
        	printf("element - %d : %d\n", i + 1, *(p + i));

    	free(p);
    	return 0;
}

