#include "conjentero.h"
#include <stdio.h>

int getcardinal(conjentero a){
	return a.cardinal;
}

conjentero iniciavacio(){
	conjentero resultado;
	
	resultado.cardinal = 0;
	
	return resultado;
}
	
void agregaentero(conjentero *a, int entero){
	if(a->cardinal!=0){
		a->cardinal=a->cardinal+1;
		a->conjunto[a->cardinal]=entero;
	}else{
		a->conjunto[1]=entero;
		a->cardinal=1;
	}
}

void quitaentero(conjentero *a, int entero){
	int i;
	
	i=1;
	while(a->conjunto[i]!=entero && i<=a->cardinal){
		i++;
	}
	
	if(i<=a->cardinal){
		int j;
		
		for(j=i;j<=a->cardinal-1;j++){
			a->conjunto[j]=a->conjunto[j+1];
		}
		a->cardinal=a->cardinal-1;
		
	}else{
		printf("\nel elemnto a eliminar no pertenece al conjunto dado");
	}
}
	
void mostrarconj(conjentero a){
	int i;
	
	printf("\nCONJUNTO: ");
	for(i=1;i<=a.cardinal;i++){
		printf("%d - ",a.conjunto[i]);
	}
}
	
conjentero unionconj(conjentero a, conjentero b){
	conjentero resultado;
	int i;
	
	resultado=iniciavacio();
	resultado.cardinal = a.cardinal + b.cardinal;
	
	for(i=1;i<=a.cardinal;i++){
		resultado.conjunto[i]=a.conjunto[i];
	}
	
	for(i=i;i<=b.cardinal;i++){
		resultado.conjunto[i]=b.conjunto[i];
	}
	
	return resultado;
}
	
conjentero interconj(conjentero a, conjentero b){
	conjentero resultado;
	int i;
	
	resultado=iniciavacio();
	i=1;
	while(i<=a.cardinal && i<=b.cardinal){
		if(a.conjunto[i]==b.conjunto[i]){
			resultado.cardinal=resultado.cardinal+1;
			resultado.conjunto[resultado.cardinal]=a.conjunto[i];
		}
		i++;
	}
	
	return resultado;
}

conjentero restaconj(conjentero a, conjentero b){
	conjentero resultado;
	int i;
	
	resultado = a;
	
	for(i=1;i<=b.cardinal;i++){
		if(resultado.conjunto[i]==b.conjunto[i]){
			quitaentero(&resultado,b.conjunto[i]);
		}
	}
	
	return resultado;
}
