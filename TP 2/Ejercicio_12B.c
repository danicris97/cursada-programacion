#include <stdio.h>
#include <math.h>

void determinaSubLista(int *);
void muestraCantdeLista(int);

int main() {
	int cont;
	
	cont=0;
	determinaSubLista(&cont);
	muestraCantdeLista(cont);
	
	return 0;
}

float ingresaNumero(){
	float num;
	
	printf("\nINGRESA UN NUMERO ENTERO: ");
	scanf("%f",&num);
	
	return num;
}
	
void determinaMenorAnte(int ant, int n, int *cont, int *b){
	if((ant==(n-1))&&(*b==0)){
		*cont=*cont+1;
		*b=1;
	}
	else if(ant==(n-1))
		*b=0;

}

void determinaSubLista(int *cont){
	float n,ant;
	int b;
	
	printf("\nINGRESE UN NUMERO REAL PARA TERMINAR EL INGRESO");
	n=ingresaNumero();
	ant=n;
	b=0;
	
	while(n==(int)n){
		determinaMenorAnte(ant,n,cont,&b);
		ant=n;
		n=ingresaNumero();
	}
}

void muestraCantdeLista(int c){
	printf("\nLA CANTIDAD DE SUBLISTAS ES: %d",c);
}
