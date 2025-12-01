
/*
int sum_avg(char *arr)
{
	int sum = 0;
	int avg = 0;
	int c = 0;
	while(*arr)
	{
		sum += *arr;
		c++;
		(*arr)++;
	}
	avg = sum/c;
	return avg;
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		printf("%s\n", *av);
	}
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

void sum_and_avg(int *arr, int size, int *sum, float *avg)
{
    *sum = 0;
    int *ptr = arr;
    for(int i = 0; i < size; i++)
    {
        *sum += *ptr;
        ptr++;
    }
    *avg = (float)(*sum) / size;
}

int main(int ac, char **av)
{
    if(ac < 2)
    {
        return 1;
    }

    int size = ac - 1;
    int arr[size];
    int *ptr = arr;

    for(int i = 1; i < ac; i++)
    {
        *ptr = atoi(av[i]);
        ptr++;
    }

    int sum;
    float avg;
    sum_and_avg(arr, size, &sum, &avg);

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);

    return 0;
}
		
