#include <stdio.h>
#include <math.h>

void ingresaReal(float *, float *, float *);
void calculaRaiz(float, float, float);

int main(int argc, char *argv[]) {
	float a,b,c;
	
	ingresaReal(&a,&b,&c);
	calculaRaiz(a,b,c);
	
	return 0;
}

void ingresaReal(float *a, float *b, float *c){
	
	do{
		printf("\nINGRESE EL REAL DE 2DO GRADO: ");
		scanf("%f",a);
	}while(*a==0);
	
	printf("\nINGRESE EL REAL DE 1ER GRADO: ");
	scanf("%f",b);
	
	printf("\nINGRESE EL TERMINO INDEPENDIENTE: ");
	scanf("%f",c);
}
	
float calculaDeterminante(float a, float b, float c){return (pow(b,2)-(4*(a*c)));}
	
float calculaR(float a, float b, float d, short op){
	if(op==1)
		return (-b+sqrt(d))/(2*a);
	else
		return (-b-sqrt(d))/(2*a);
}
	
void calculaRaiz(float a, float b, float c){
	float d=calculaDeterminante(a,b,c);
	
	if(d<0)
		printf("\nLA ECUACION TIENE RAICES COMPLEJAS");
	else if(d==0)
		printf("\nLA RAIZ DE LA ECUACION ES UNICA Y ES: %f",calculaR(a,b,d,1));
	else
		printf("\nLAS RAICES DE LA ECUACION SON R1: %f , R2: %f",calculaR(a,b,d,1),calculaR(a,b,d,2));
	
}
