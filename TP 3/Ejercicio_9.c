#include <stdio.h>

void cargaFraccion(int *, int *);
void suma(int, int, int, int);
void resta(int, int, int, int);
void multiplicacion(int, int, int, int);
void division(int, int, int, int);
void comparacion(int, int, int, int);
void menu();

int main() {
	
	printf("\nBIENVENIDO A CALCULADORA DE FRACCIONES");
	menu();
	
	return 0;
}

int ingresaOpcion(){
	int i;
	
	do{
		printf("\nINGRESA OPCION: ");
		scanf("%d",&i);
	}while((i<0)&&(i>5));
	
	return i;
	
}

void menu(){
	int o,a,b,c,d;
	
	printf("\n1. SUMAR");
	printf("\n2. RESTAR");
	printf("\n3. MULTIPLICAR");
	printf("\n4. DIVIDIR");
	printf("\n5. COMPARAR");
	printf("\n0. SALIR");
	o=ingresaOpcion();
	
	while(o!=0){
		
		cargaFraccion(&a,&b);
		cargaFraccion(&c,&d);
		
		switch(o){
			case 1: suma(a,b,c,d);
					break;
			case 2: resta(a,b,c,d);
					break;
			case 3: multiplicacion(a,b,c,d);
					break;
			case 4: division(a,b,c,d);
					break;
			case 5: comparacion(a,b,c,d);
					break;
			default: break;
		}
		o=ingresaOpcion();
		fflush(stdin);
	}
	
}
	
void cargaFraccion(int *numerador, int *denominador){
	printf("\nINGRESA EL NUMERADOR: ");
	scanf("%d",numerador);
	
	do{
		printf("\nINGRESA EL DENOMINADOR: ");
		scanf("%d",denominador);
	}while(*denominador==0);
}
	
void suma(int a, int b, int c, int d){
	if(b==d)
		printf("\nLA SUMA DE FRACCIONES ES: %d/%d",(a+c),b);
	else
		printf("\nLA SUMA DE FRACCIONES ES: %d/%d",((a*d)+(c*b)),(b*d));
}
	
void resta(int a, int b, int c, int d){
	if(b==d)
		printf("\nLA SUMA DE FRACCIONES ES: %d/%d",(a-c),b);
	else
		printf("\nLA SUMA DE FRACCIONES ES: %d/%d",((a*d)-(c*b)),(b*d));
}
	
void multiplicacion(int a, int b, int c, int d){
	if((a==0)||(c==0))
		printf("\nLA MULTIPLICACION ES IGUAL A 0");
	else
		printf("\nLA MULTIPLICACION ES IGUAL A %d/%d",(a*d),(b*c));
}
	
void division(int a, int b, int c, int d){
	if((a==0)||(c==0))
		printf("\nLA DIVISION ES IGUAL A 0");
	else
		printf("\nLA DIVISION ES IGUAL A %d/%d",(a*c),(b*d));
}
	
void comparacion(int a, int b, int c, int d){
	float r,s;
	
	r=(float)a/(float)b;
	s=(float)c/(float)d;
	
	if(r==s)
		printf("\nLAS FRACCIONES SON IGUALES: %d/%d = %d/%d",a,b,c,d);
	else if(r>s)
		printf("\n%d/%d > %d/%d",a,b,c,d);
	else
		printf("\n%d/%d < %d/%d",a,b,c,d);
}
