#include <stdio.h>

struct Time{
	int hours;
	int minutes;
	int seconds;
};

struct Time addTimes(struct Time t1, struct Time t2){
	struct Time result;

	result.seconds = t1.seconds + t2.seconds;
    	result.minutes = t1.minutes + t2.minutes + result.seconds / 60;
    	result.seconds = result.seconds % 60;
    	result.hours = t1.hours + t2.hours + result.minutes / 60;
    	result.minutes = result.minutes % 60;

	return result;
}

int main(){
	struct Time t1,t2,sum;
	
	printf("Enter first time (hours minutes seconds): ");
    	scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

   
	printf("Enter second time (hours minutes seconds): ");
    	scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

	sum = addTimes(t1, t2);

    	printf("Sum of times: %02d:%02d:%02d\n", sum.hours, sum.minutes, sum.seconds);

    	return 0;
}

