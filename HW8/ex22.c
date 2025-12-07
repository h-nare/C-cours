#include <stdio.h>

int main()
{
    	char str[100], *p;
    	int len = 0, i;

    	printf("Input a string : ");
    	scanf("%s", str);

    	p = str;

    	while (*(p + len) != '\0')
        	len++;

    	printf("\nPointer : Print a string in reverse order :\n");
    	printf("------------------------------------------------\n");
    	printf("Input a string : %s\n", str);

    	printf("Reverse of the string is : ");
    	for (i = len - 1; i >= 0; i--)
        	printf("%c", *(p + i));

    	printf("\n");
    	return 0;
}
