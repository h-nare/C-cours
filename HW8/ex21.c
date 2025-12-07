#include <stdio.h>

int main()
{
	char ch = 'A';
    	char *p = &ch;

    	printf("The Alphabets are :\n");

    	for (; *p <= 'Z'; (*p)++)
        	printf("%c  ", *p);

    	return 0;
}

