#include <stdio.h>
#include <math.h>

float calculaSucesion(float, int);
float calculaError(float, int);
int factorial(int);

int main() {
	int n;
	float r;
	
	printf("\nINGRESE UN NUMERO REAL: ");
	scanf("%f",&r);
	
	printf("\nINGRESE LA CANTIDAD DE SUCESIONES A REALIZAR: ");
	scanf("%d",&n);
	
	printf("\nEL RESULTADO DE LA SUCESION ES: %f",calculaSucesion(r,n));
	
	return 0;
}

int factorial(int f){
	if(f==0)
		return 1;
	else
		return (f*factorial(f-1));
}
	
float calculaSucesion(float x, int i){
	if(x!=0){
		if(i==0)
			return x + 1;
		else if(i>0){
			return x + calculaSucesion(pow(x,i)/factorial(i),i-1);
		}else{
			return 0;
		}
	}else
	   return 1;
}
	
float calculaError(float x, int i){
	return calculaSucesion(x,i+1);
}
