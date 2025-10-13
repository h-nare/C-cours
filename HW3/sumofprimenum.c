#include <stdio.h>

int primes(int n)
{
	int i = 2;
	if (n <= 1)
		return 0;
	
	if(n == 2)
		return n;

	while(i*i <= n)
	{
		if(n % i == 0)
			return 0;
		i++;
	}
	return n;
}

void check(int n) {
    int found = 0;
    for (int a = 2; a <= n; a++) {
        int b = n - a;
        if (primes(a) && primes(b)) {
            printf("%d + %d = %d\n", a, b, n);
            found = 1;
        }
    }
    if (!found) {
        printf("No prime pairs found for %d\n", n);
    }
}
/*
int check(int n)
{
	int a, b;
	for(a = 2; a < n; a++)
	{
		for(b = 2; b < n; b++)
		{
			if(a + b == n && primes(a) && primes(b))
			{
				printf("%d + %d = %d\n", a, b, n);  // show combination
			}
		}
	}
	return 0;
}*/
/*
int check(int n)
{
	int a = 0;
	int b = 0; 
	
	while(a < n)
	{
		while(b < n)
		{
	
			if(n == a + b)
			{
				if((primes(a) == a) && (primes(b) == b))
					return 1;
			}
			b++;
		}
		a++;
	}
	return 0;
} */

int main()
{

	int num;

	printf("Enter a number: ");
	scanf("%d", &num);
	
	check(num);
	return 0;
}

