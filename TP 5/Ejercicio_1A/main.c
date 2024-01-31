#include <stdio.h>
#include "cadena_interfaz.h"

int main(){
	TCadena cadena1;
	char c;
	
	printf("\nINGRESA CADENA: ");
	leeCad(cadena1);
	mostrarCadena(cadena1);
	printf("\nINGRESA CHAR: ");
	scanf("%c",&c);
	insertaCaracter(cadena1,c);
	mostrarCadena(cadena1);
	
	return 0;
}
