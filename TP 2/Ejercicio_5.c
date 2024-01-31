#include <stdio.h>

void ingresoDatos(int *, float *);
float calculoImporte(int, float);

int main() {
	int metroc;
	float precio;
	
	ingresoDatos(&metroc,&precio);
	
	printf("\nEL IMPORTE A PAGAR ES: $%0.2f",calculoImporte(metroc,precio));
	
	return 0;
}

void ingresoDatos (int *mc, float *p){
	printf("\nINGRESE LA CANTIDAD DE METRO CUBICO UTILIZADA POR EL USUARIO: ");
	scanf("%d",mc);
	
	printf("\nINGRESE EL PRECIO POR 1000 METROS CUBICOS: ");
	scanf("%f",p);
}

float calculoImporte(int mc, float p){
	if(mc<1000)
		return p;
	else if((mc>=1000)&&(mc<2000))
		return (p+(mc/4));
	else
		return (p+(mc/2)); 
}
