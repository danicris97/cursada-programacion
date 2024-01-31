#include <stdio.h>

void ingreso(float *, float *);
void MostrarCalculoP(float, float);
void MostrarCalculoS(float, float);

int main() {
	float a,b;
	
	ingreso(&a,&b);
	MostrarCalculoP(a,b);
	MostrarCalculoS(a,b);
	
	return 0;
}

void ingreso(float *ladoMayor, float *ladoMenor){
	do{
		printf("INGRESE EL LADO MAYOR DEL RECTANGULO: ");
		scanf("%f",ladoMayor);
	}while(*ladoMayor<0);
	
	do{
		printf("\nINGRESE EL LADO MENOR DEL RECTANGULO: ");
		scanf("%f",ladoMenor);
	}while(*ladoMenor<0);
}

void MostrarCalculoP(float a, float b){
	printf("\nEL PERIMETRO DEL RECTANGULO ES: %0.2f",(2*(a+b)));
}

void MostrarCalculoS(float a, float b){
	printf("\nLA SUPERFICIE DEL RECTANGULO ES: %0.2f",(a*b));
}
