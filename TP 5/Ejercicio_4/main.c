#include "entero.h"
#include <stdio.h>

int main(){
	entero ent1, ent2;
	
	printf("INGRESE UN NUMERO ENTERO: ");
	scanf("%ld",&ent1);
	
	ent2=cargar();
	
	mostrar(ent1);
	mostrar(ent2);
	
	return 0;
}
