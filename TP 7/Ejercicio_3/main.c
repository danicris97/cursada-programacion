#include <stdio.h>
#include "listaEntero.h"

int main(){
	TPtr lista;
	int n;
	
	printf("\nIngrese la cantidad de elementos de la lista: ");
	scanf("%d",&n);
	
	lista=cargarLista(n);
	
	muestraLista(lista);

	calculaPar(lista);
	
	printf("\nLista modificada: ");
	muestraLista(lista);
	
	return 0;
}
