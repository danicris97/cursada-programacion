#include <stdio.h>

void ingresoAngulosInt(int *, int *, int *);
void controlTriangulo(int, int, int);

int main() {
	int A,B,C;
	
	ingresoAngulosInt(&A,&B,&C);
	controlTriangulo(A,B,C);
	
	return 0;
}

void ingresoAngulosInt(int *a, int *b, int *c){
	printf("LOS ANGULOS INTERNOS DEBEN SUMAR UN TOTAL DE 180°");
	int cont=0;
	
	do{
		do{
			printf("\nINGRESE EL PRIMER ANGULO: ");
			scanf("%d",a);
			cont = *a;
		}while(*a<0);
		
		do{
			printf("\nINGRESE EL SEGUNDO ANGULO: ");
			scanf("%d",b);
			cont += *b;
		}while(*b<0);
		
		do{
			printf("\nINGRESE EL TERCER ANGULO: ");
			scanf("%d",c);
			cont += *c;
		}while(*c<0);
		
	} while(cont!=180);
}

void controlTriangulo(int a, int b, int c){
	if (a==90)
		printf("\nEL TRIANGULO INGRESADO ES RECTANGULO");
	else if (b==90)
		printf("\nEL TRIANGULO INGRESADO ES RECTANGULO");
	else if (c==90)
		printf("\nEL TRIANGULO INGRESADO ES RECTANGULO");
	else if (a>90)
		printf("\nEL TRIANGULO INGRESADO ES OBTUSANGULO");
	else if (b>90)
		printf("\nEL TRIANGULO INGRESADO ES OBTUSANGULO");
	else if (c>90)
		printf("\nEL TRIANGULO INGRESADO ES OBTUSANGULO");
	else
		printf("\nEL TRIANGULO ES ACUTANGULO");
}
