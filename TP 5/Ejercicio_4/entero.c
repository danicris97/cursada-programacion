#include "entero.h"
#include <stdio.h>

entero iniciar(){
	entero nuevo;
	
	nuevo = 0;
	
	return nuevo;
}

entero cargar(){
	entero nuevo;
	
	printf("\nINGRESE UN NUMERO ENTERO: ");
	scanf("%ld",&nuevo);
	
	return nuevo;
}
	
/*modo dinamico*/
	
long getEntero(entero a){
	return a;
}
	
void setEntero(entero *a, long b){
	*a=b;
}
	
void modificar(entero *a){
	printf("\INGRESE UN NUEVO VALOR: ");
	scanf("%ld",a);
}
	
entero suma(entero a, entero b){
	entero resultado;
	
	setEntero(&resultado, (getEntero(a) + getEntero(b)));
	
	return resultado;
}
	
/*fin  de dinamico xd*/
	
entero resta(entero a, entero b){
	entero resultado;
	
	resultado = a - b;
	
	return resultado;
}
	
entero mult(entero a, entero b){
	entero resultado;
	
	resultado = a * b;
	
	return resultado;
}
	
entero div(entero a, entero b){
	entero resultado;
	
	if(b!=0){
		resultado = (long)a/b;
	}else{
		printf("\nerror: dividendo=0");
		resultado = 0;
	}
	
	return resultado;
}
	
void mostrar(entero a){
	printf("\nValor: %ld",a);
}
