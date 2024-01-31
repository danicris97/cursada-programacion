#include <stdio.h>

void ingreso(int *, float *);
float sueldo(int , float);

int main() {
	int hora;
	float precio;
	
	ingreso(&hora, &precio);
	printf("\nEL SUELDO A COBRAR SERA: %0.2f",sueldo(hora,precio));
	
	return 0;
}

void ingreso(int *h, float *s){
	printf("INGRESE LA CANTIDAD DE HORAS QUE TRABAJA AL DIA: ");
	scanf("%d",h);
	
	printf("\nINGRESE EL PRECIO DE LA HORA TRABAJADA: ");
	scanf("%f",s);
}
	
float sueldo(int h, float s){return (30*(h*s));}
