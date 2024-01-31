#include <stdio.h>
#define PI 3.1415926

float ingreso(void);
float calculoP(float);
float calculoS(float);

int main() {
	float r;
	
	r=ingreso();
	printf("\nEL PERIMETRO DE LA CIRCUNFERENCIA ES: %0.3f",calculoP(r));
	printf("\nLA SUPERFICIE DE LA CIRCUNFERENCIA ES: %0.3f",calculoS(r));
	
	return 0;
}

float ingreso(){
	float radio;

	do{
		printf("INGRESE EL RADIO DE LA CIRCUNFERENCIA: ");
		scanf("%f",&radio);
	}while(radio<0);
	
	return radio;
}

float calculoP(float radio){return (2*PI*radio);}
float calculoS(float radio){return (PI*radio*radio);}
