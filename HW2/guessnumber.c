#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int target_number;
	int guess = 0;
	int attempts = 0;
	int input_status;

	srand(time(NULL));
	target_number = (rand() % 100) + 1;

	printf("Let's play a guess the number game, numbers being between 1 to 100.\n");

	do {
		printf("\nEnter your guess: ");

		input_status = scanf("%d", &guess);
		
		if(input_status == 0)
		{
			printf("Invalid input! Please enter a whole number.\n");
			scanf("%*[^\n]%*c");
			continue;

		}
		else if(input_status == EOF)
		{
			printf("\nGame terminated by user.\n");
			break;
		}
		scanf("%*[^\n]%*c");

		attempts++;
	
		if (guess < target_number)
		{
			printf("Too low!\n");
		}
		else if(guess > target_number)
		{
			printf("Too high!\n");
		}
		else
		{
			printf("Congratulations!You guessed it right the number was: %d\n", target_number);
		}
	} while(guess != target_number);
	
	return 0;
}	
