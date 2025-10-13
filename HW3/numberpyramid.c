#include <stdio.h>

void  pyramid(int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
			printf(" ");
		for(int j = 0; j < i + 1; j++)
			printf("*");
		printf("\n");
	}
}

int main()
{
	int num;
	printf("Enter size: ");
	scanf("%d", &num);
	pyramid(num);
	return 0;
}
