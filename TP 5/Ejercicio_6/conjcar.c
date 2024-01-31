#include "conjcar.h"
#include <stdio.h>

void iniciarVacio(conjcar conjunto){
	conjunto[0]='\n';
}
	
void agregarCaracter(conjcar conjunto,  char c){
	int i;
	
	i=0;
	while(conjunto[i]!='\n'){
		i++;
	}
	
	conjunto[i]=c;
	conjunto[i+1]='\n';
}
	
void quitarCaracter(conjcar conjunto, char c){
	int i;
	
	i=0;
	while(conjunto[i]!='\n' && conjunto[i]!=c){
		i++;
	}
	
	if(conjunto[i]!='\n'){
		int j;
		
		j=i;
		while(conjunto[j]!='\n'){
			conjunto[j]=conjunto[j+1];
			j++;
		}
		//conjunto[j]=nullptr;
	}else{
		printf("\nEL CARACTER NO ESTA EN EL CONJUNTO");
	}
}
	
void mostrarConjunto(conjcar conjunto){
	int i=0;
	
	printf("\nCONJUNTO: ");

	while(conjunto[i]!='\n'){
		printf("%c - ",conjunto[i]);
		i++;
	}
}

void unionConjunto(conjcar resultado, conjcar a, conjcar b){
	int i;
	
	i=0;
	while(a[i]!='\n'){
		resultado[i]=a[i];
		i++;
	}
	
	while(b[i]!='\n'){
		resultado[i]=b[i];
		i++;
	}
	
	resultado[i]='\n';
}
	
void interConjunto(conjcar resultado, conjcar a, conjcar b){
	int i;
	
	i=0;
	while(a[i]!='\n' && b[i]!='\n'){
		if(a[i]==b[i]){
			resultado[i]=a[i];
		}
		i++;
	}
	
	resultado[i]='\n';
}

void restaConjunto(conjcar resultado, conjcar a, conjcar b){
	int i,j;
	
	i=0;
	while(b[i]!='\n'){
		j=0;
		while(a[j]!='\n'){
			if(a[j]!=b[i]){
				resultado[j]=a[j];
			}
			j++;
		}
		i++;
	}
	
	resultado[i]='\n';
}
