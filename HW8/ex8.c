#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
    	*b = temp;
}

void permute(char *str, int left, int right)
{
    	int i;
    	if (left == right)
    	{
        	printf("%s  ", str);
        	return;
    	}
    	for (i = left; i <= right; i++)
    	{
        	swap(str + left, str + i);
        	permute(str, left + 1, right);
        	swap(str + left, str + i);
    	}
}

int main()
{
    	char input[100];
    	char *str;
    	int length = 0;

    	printf("Enter a string: ");
    	scanf("%s", input);

    	while (*(input + length) != '\0')
        	length++;

    	str = (char *)malloc((length + 1) * sizeof(char));
    	if (str == NULL)
        	return 1;

    	for (int i = 0; i <= length; i++)
        	*(str + i) = *(input + i);

    	printf("\nThe permutations of the string are:\n");
    	permute(str, 0, length - 1);

    	free(str);
    	return 0;
}

