#include <stdio.h>
#include <math.h>

int main() {
    float num;

    printf("Enter a floating-point number: ");
    scanf("%f", &num);

    printf("Square root: %.4f\n", sqrt(num));

    printf("Rounded: %d\n", (int)round(num));

    printf("Sine: %.4f\n", sin(num));

    return 0;
}

