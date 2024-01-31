#include "listaMP3.h"
#include <stdlib.h>
#include <stdio.h>

Tptr iniciaLista(){
	Tptr nuevo;
	
	nuevo=NULL;
	
	return nuevo;
}
	
Tptr crearCancion(){
	Tptr nuevo;
	
	printf("\nIngrese la duracion de la cancion (segundos): ");
	scanf("%d",nuevo->duracion);
	
	vaciabuffer();
	printf("\nIngrese nombre de la cancion: ");
	leeCad(nuevo->nombre);
	
	vaciabuffer();
	printf("\nIngrese nombre del interprete de la cancion: ");
	leeCad(nuevo->interprete);
	
	vaciabuffer();
	printf("\nIngrese nombre del album la cancion: ");
	leeCad(nuevo->album);
	
	vaciabuffer();
	printf("\nIngrese nombre del genero de la cancion: ");
	leeCad(nuevo->genero);
	
	nuevo->sig=NULL;
	
	return nuevo;
}
	
void mostrarCancion(TNodo cancion){
	printf("\nduracion: %d",cancion.duracion);
	printf("\ninterprete: %s",cancion.interprete);
	printf("\nalbum: %s",cancion.album);
	printf("\ngenero: %s",cancion.genero);
}
	
void agregaFin(Tptr lista, Tptr nuevo){
	Tptr aux;
	
	if(lista==NULL){
		lista=nuevo;
	}else{
		aux=lista;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		
		aux->sig=nuevo;
	}
}
	
void agregaPosicion(Tptr lista, Tptr nuevo, int pos){
	Tptr aux, ant;
	int contador;
	
	if(lista==NULL){
		printf("\nlista vacia");
	}else{
		aux=lista;
		contador=0;
		
		while(aux->sig!=NULL && contador<=pos){
			ant=aux;
			aux=aux->sig;
			contador++;
		}
		
		if(contador==pos){
			ant->sig=nuevo;
			nuevo->sig=aux;
		}else{
			printf("\nposicion incorrecta");
		}
	}
}
	
void agregaInicio(Tptr lista, Tptr nuevo){
	Tptr aux;
	
	aux=lista;
	lista=nuevo;
	lista->sig=aux;
}
	
void eliminaPrimero(Tptr lista){
	Tptr aux;
	
	aux=lista->sig;
	free(lista);
	lista=aux;
}

void eliminaUltimo(Tptr lista){
	Tptr aux, ant;
	
	if(lista!=NULL){
		aux=lista;
		ant=NULL;
		
		while(aux->sig!=NULL){
			ant=aux;
			aux=aux->sig;
		}
		
		ant->sig=NULL;
		free(aux);
	}else{
		printf("\nlista vacia");
	}
}
	
void eliminaPosicion(Tptr lista, int pos){
	Tptr aux, ant;
	int i;
	
	if(lista!=NULL){
		aux=lista;
		ant=NULL;
		
		while(aux->sig!=NULL && i<=pos){
			ant=aux;
			i++;
			aux=aux->sig;
		}
		
		if(i==pos){
			ant->sig=aux->sig;
			free(aux);
		}else{
			printf("\nposicion invalida");
		}
	}else{
		printf("\nlista vacia");
	}
}
	
void mostrarLista(Tptr lista){
	Tptr aux;
	
	aux=lista;
	
	printf("\nlista de reproduccion: ");
	while(aux!=NULL){
		printf("\n datos de la cancion ");
		mostrarCancion(*aux);
		aux=aux->sig;
	}
}
	
void mostrarPorAlbum(Tptr lista, TCadena album){
	Tptr aux;
	
	aux=lista;
	
	while(aux!=NULL){
		if(comparaCadena(aux->album,album)==1){
			mostrarCancion(*aux);
		}
		aux=aux->sig;
	}
}
	
void mostrarPorInterprete(Tptr lista, TCadena interprete){
	Tptr aux;
	
	aux=lista;
	
	while(aux!=NULL){
		if(comparaCadena(aux->interprete,interprete)==1){
			mostrarCancion(*aux);
		}
		aux=aux->sig;
	}
}
