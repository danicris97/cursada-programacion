#include <stdio.h>
#include "cadena.h"

int main(){
	TCadena cadena;
	
	printf("\nIngrese una cadena: ");
	leeCad(cadena);
	
	printf("\nCadena ingresada: %s",cadena);
	
	return 0;
}
