#include <stdio.h>

int main()
{
	int choice;

	double num1;
	double num2;
	double result;

	while(1)
	{
		printf("Simple Calculator\n");
		printf("1.Addition\n");
		printf("2.Substraction\n");
		printf("3.Multiplication\n");
		printf("4.Division\n");
		printf("5.Quit\n");
		printf("Enter number = \n");
		scanf("%d", &choice);
		
		if(choice == 5)
		{
			printf("Exiting Program byeeeee!\n");
			break;
		}
		if(choice >= 1 && choice <= 4)
		{
			printf("Enter first number: ");
			scanf("%lf", &num1);
			printf("Enter 2nd number: ");
			scanf("%lf", &num2);
		
			switch(choice)
			{
				case 1:
					result = num1 + num2;
					printf("%lf", result);
					break;
				case 2:
					result = num1 - num2;
					printf("%lf", result);
                                        break;
				case 3:
					result = num1 * num2;
					printf("%lf", result);
                                        break;
				case 4:
					if (num2 != 0)
					{
						result = num1/num2;
						printf("%lf", result);
                                                break;
					}
					else
					{
						printf("Error can't be divided\n");
					}
					break;
			}
		}else{
			printf("Enter valid numbers\n");
		     } 
		
		}
		return 0;
}
