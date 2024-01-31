#include <stdio.h>

void ingreso(int *, float *);
float sueldo(int , float);

int main() {
	int hora,i;
	float precio, total;
	
	total=0;
	
	for (i=1;i<=3;i++){
		ingreso(&hora, &precio);
		printf("\nEL SUELDO A COBRAR SERA: %0.2f",sueldo(hora,precio));
		total= total + sueldo(hora,precio);
	}
	
	printf("\nEL IMPORTE TOTAL A DEPOSITAR ES: %0.2f",total);
	
	return 0;
}

void ingreso(int *h, float *s){
	printf("\nINGRESE LA CANTIDAD DE HORAS QUE TRABAJA AL DIA: ");
	scanf("%d",h);
	
	printf("\nINGRESE EL PRECIO DE LA HORA TRABAJADA: ");
	scanf("%f",s);
}
	
float sueldo(int h, float s){return (30*(h*s));}
