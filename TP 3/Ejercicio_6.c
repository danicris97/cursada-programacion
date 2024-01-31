#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>

float obtieneNumero();
void obtieneMantisaExponente(int*,int*);
void menu();

int main() {
	
	printf("BIENVENIDO A NUMEROS PUNTO FLOTANTE");
	menu();
	
	return 0;
}

short ingresaOpcion(){
	int i;
	
	fflush(stdin);
	printf("\nINGRESA OPCION: ");
	scanf("%d",&i);
	
	return i;
}

void menu(){
	short op;
	int mantisa,exponete;
	
	op=3;
	do{
		printf("\n1.OBTENER UN FLOTANTE DE UNA MANTISA Y UN EXPONENTE");
		printf("\n2.OBTENER UNA MANTISA Y UN EXPONENTE DE UN FLOTANTE");
		printf("\n0.SALIR");
		op=ingresaOpcion();
		
		switch(op){
			case 1: printf("\nEL FLOTANTE DE LOS EXPONENTES INGRESADOS ES: %f",obtieneNumero());
					break;
			case 2: obtieneMantisaExponente(&mantisa,&exponete);
					printf("\nMANTISA: %d",mantisa);
					printf("\nEXPONENTE: %d",exponete);
					break;
			default: break;
		}
		op=ingresaOpcion();
		__fpurge(stdin);
		//fflush(stdin);
		
	} while(op!=0);
}

int ingresaNumero(){
	int n;
	
	printf("\nINGRESE UN NUMERO ENTERO: ");
	scanf("%d",&n);
	
	return n;
}
	
float obtieneNumero(){
	int mantisa,exponete;
	float real;
	
	mantisa=ingresaNumero();
	exponete=ingresaNumero();
	
	real=mantisa*pow(10,exponete);
	
	return real;
}
	
int ingresaReal(){
	int r;
		
	printf("\nINGRESE UN NUMERO REAL: ");
	scanf("%f",&r);
		
	return r;
}
	

void obtieneMantisaExponente(int *mantisa, int *exponente){
	float real=ingresaReal();
	
	unsigned int *representacion = (unsigned int*)&numero;
	
	// Se extraen la mantisa y el exponente
	*mantisa = (*representacion) & 0x007FFFFF;  // Máscara para obtener la mantisa
	*exponente = ((*representacion) >> 23) & 0xFF;  // Máscara para obtener el exponente >> significa desplazar a derecha
	*exponente -= 127;  // Se resta el sesgo del exponente
}
