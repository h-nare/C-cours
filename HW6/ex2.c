#include <stdio.h>

typedef struct{
	double real;
	double imag;
}Complex;

Complex addComplex(Complex c1, Complex c2){
	Complex result;

	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;
	return result;
}

Complex multiplyComplex(Complex c1, Complex c2) {
    	Complex result;

    	result.real = c1.real * c2.real - c1.imag * c2.imag;
    	result.imag = c1.real * c2.imag + c1.imag * c2.real;
    	return result;
}

int main() {
    	Complex c1, c2, sum, product;

    	printf("Enter first complex number (real imag): ");
    	scanf("%lf %lf", &c1.real, &c1.imag);

    	printf("Enter second complex number (real imag): ");
    	scanf("%lf %lf", &c2.real, &c2.imag);

    	sum = addComplex(c1, c2);
    	product = multiplyComplex(c1, c2);

    	printf("Sum: %.2lf + %.2lfi\n", sum.real, sum.imag);
    	printf("Product: %.2lf + %.2lfi\n", product.real, product.imag);

    	return 0;
}	
