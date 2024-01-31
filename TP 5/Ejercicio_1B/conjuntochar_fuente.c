#include "conjuntochar_interfaz.h"
#include <stdio.h>

void iniciarVacio(conjuntochar conjuntoC){
	conjuntoC[0]='\0';
}
	
void eliminaRepetidos(conjuntochar conjuntoC){
	int i,j;
	
	i=0;
	j=0;
	while(conjuntoC[i]!='\0'){
		j=i;
		while(conjuntoC[j]!='\0'){
			if(conjuntoC[i]==conjuntoC[j]){
				eliminarCaracter(conjuntoC,conjuntoC[i]);
			}
			j++;
		}
		i++;
	}
}
	
void agregarCaracter(conjuntochar conjuntoC, char caracter){
	int tam;
	tam=cantidadCaracteres(conjuntoC);
	
	conjuntoC[tam]=caracter;
	conjuntoC[tam+1]='\0';
	
	eliminaRepetidos(conjuntoC);
}
	
void eliminarCaracter(conjuntochar conjuntoC, char caracter){
	int i,p,tam;
	
	p=existeCaracter(conjuntoC,caracter);
	tam=cantidadCaracteres(conjuntoC);
	if(p!=-1){
		for(i=p;p<tam;i++){
			conjuntoC[i]=conjuntoC[i+1];
		}
		conjuntoC[i]='\0';
	}else{
		printf("\nEL CARACTER QUE QUIERE ELIMINAR NO ESTA");
	}
}
	
void mostrarConjuntochar(conjuntochar conjuntoC){
	printf("%s",conjuntoC);
}
	
void unionConjuntochar(conjuntochar conjuntoA, conjuntochar conjuntoB, conjuntochar conjuntoC){
	int i,j;
	
	i=0;
	j=0;
	while(conjuntoA[i]!='\0'){
		conjuntoC[j]=conjuntoA[i];
		i++;
		j++;
	}
	i=0;
	while(conjuntoB[i]!='\0'){
		conjuntoC[j]=conjuntoB[i];
		i++;
		j++;
	}
	conjuntoC[j]='\0';
	
	eliminaRepetidos(conjuntoC);
}
	
void interseccionConjuntochar(conjuntochar conjuntoA, conjuntochar conjuntoB, conjuntochar conjuntoC){
	int i,j;
	
	i=0;
	j=0;
	while(conjuntoA[i]!='\0'){
		if(existeCaracter(conjuntoB,conjuntoA[i])!=-1){
			conjuntoC[j]=conjuntoA[i];
			j++;
		}
		i++;
	}
	conjuntoC[j]='\0';

	eliminaRepetidos(conjuntoC);
}

void restaConjuntochar(conjuntochar conjuntoA, conjuntochar conjuntoB, conjuntochar conjuntoC){
	int i,j;
	
	i=0;
	j=0;
	while(conjuntoA[i]!='\0'){
		if(existeCaracter(conjuntoB,conjuntoA[i])==-1){
			conjuntoC[j]=conjuntoA[i];
			j++;
		}
		i++;
	}
	conjuntoC[j]='\0';
	
	eliminaRepetidos(conjuntoC);
}
	
int existeCaracter(conjuntochar conjuntoC, char caracter){
	int i;

	i=0;
	while(conjuntoC[i]!=caracter && conjuntoC[i]!='\0'){
		i++;
	}
	
	if(conjuntoC[i]!='\0'){
		return i;
	}else{
		return -1;
    }
}
	
int cantidadCaracteres(conjuntochar conjuntoC){
	int i;
		
	i=0;
	while(conjuntoC[i]!='\0'){
		i++;
	}

	return i;
}	
