#include <stdio.h>

int fibonacci(int);

int main() {
	int n;

	printf("\nIngrese el numero n para la sucesion de fibonacci: ");
	scanf("%d",&n);

	printf("\nFibonacci: %d",fibonacci(n));

	return 0;
}

int fibonacci(int n){
	if(n<=2)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}
