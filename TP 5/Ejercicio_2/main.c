#include <stdio.h>
#include "angulo.h"

int main(){
	TAngulo a,b;
	
	cargarAngulo(&a);
	cargarAngulo(&b);
	
	mostrarAngulo(a);
	mostrarAngulo(b);
	
	return 0;
}
