#include <stdio.h>

void determinaSubLista();

int main() {
	
	determinaSubLista();
	
	return 0;
}

float ingresaNumero(){
	float num;
	
	printf("\nINGRESA UN NUMERO ENTERO: ");
	scanf("%f",&num);
	
	return num;
}
	
void detyMuestraMenorAnte(int ant, int n, int antt){
	if(ant==(n-1))
		printf("%d ",ant);
	else if(antt==(ant-1))
		printf("%d ",ant);

}

void determinaSubLista(){
	float n,ant,antt;
	
	printf("\nINGRESE UN NUMERO REAL PARA TERMINAR EL INGRESO");
	n=ingresaNumero();
	ant=n;
	antt=n;
	
	while(n==(int)n){
		detyMuestraMenorAnte(ant,n,antt);
		antt=ant;
		ant=n;
		n=ingresaNumero();
	}
}
