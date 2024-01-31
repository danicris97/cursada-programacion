#include "fraccion.h"
#include <stdio.h>
#include <stdlib.h>

Fraccion inicia(){
	Fraccion inicia;
	
	inicia.p=0;
	inicia.q=1;
	
	return inicia;
}
	
Fraccion cargar(){
	Fraccion nuevo;
	
	printf("\nINGRESE PARTE ENTERA DE LA FRACCION: ");
	scanf("%d",&nuevo.p);
	
	do{
		printf("\nINGRESE PARTE RACIONAL DE LA FRACCION (distinto de 0): ");
		scanf("%d",&nuevo.q);
	}while(nuevo.q==0);
	
	return nuevo;
}

Fraccion suma(Fraccion a, Fraccion b){
	Fraccion resultado;
	
	if(abs(a.q) == abs(b.q)){
		if(a.q!=b.q){
			resultado.q = abs(a.q)*-1;
		}else{
			resultado.q = a.q;
		}
		resultado.p = a.p + b.p;
	}else{
		resultado.q = a.q * b.q;
		resultado.p = (a.p * b.q) + (b.p * a.q);
	}
	
	return resultado;
}
	
Fraccion resta(Fraccion a, Fraccion b){
	Fraccion resultado;
		
	if(abs(a.q) == abs(b.q)){
		if(a.q!=b.q){
			resultado.q = abs(a.q)*-1;
		}else{
			resultado.q = a.q;
		}
		resultado.p = a.p - b.p;
	}else{
		resultado.q = a.q * b.q;
		resultado.p = (a.p * b.q) - (b.p * a.q);
	}
		
	return resultado;
}

Fraccion mult(Fraccion a, Fraccion b){
	Fraccion resultado;
	
	resultado.p = a.p * b.p;
	resultado.q = a.q * b.q;
	
	return resultado;
}
	
Fraccion dividir(Fraccion a, Fraccion b){
	Fraccion resultado;
	
	resultado.p = a.p * b.q;
	resultado.q = a.q * b.p;
	
	return resultado;
}
	
short equivalencia(Fraccion a, Fraccion b){
	if((a.p/a.q)==(b.p/b.q))
		return 1;
	else
		return 0;
}
	
void modificar(Fraccion *a){
	printf("\nINGRESE UN NUEVO VALOR ENTERO: ");
	scanf("%d",a->p);
	
	do{
		printf("\nINGRESE UN NUEVO VALOR RACIONAL: ");
		scanf("%d",a->q);
	} while(a->q==0);
}
	
void mostrar(Fraccion a){
	printf("%d/%d",a.p,a.q);
}
