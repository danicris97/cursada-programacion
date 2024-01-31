#include "listaEntero.h"

#include <stdio.h>
#include <stdlib.h>

TPtr crearNodo(int numero){
	TPtr nuevo=NULL;
	
	nuevo=(TPtr)malloc(sizeof(TNodo));
	nuevo->entero=numero;
	nuevo->sig=NULL;
	
	return nuevo;
}

TPtr cargarLista(int n){
	TNodo *elemento;
	TPtr lista;
	int i;
	
	lista=NULL;
	
	for(i=1;i<=n;i++){
		//reserva de memoria
		elemento=(TNodo*)malloc(sizeof(TNodo));
		//carga de elemento
		printf("\nIngrese un numero entero: ");
		scanf("%d",&elemento->entero);
		//enlazado dinamico de lista
		elemento->sig=lista;
		//se toma al ultimo elemento como primero
		lista=elemento;
	}
		
	return lista;
}

void muestraLista(TPtr lista){
	TPtr aux;
	
	aux=lista;
	while(aux!=NULL){
		printf("%d - ",aux->entero);
		aux=aux->sig;
	}
	
	lista=aux;
}
	
void agregaElementoFin(TPtr lista, int entero){
	TPtr nuevo, cabezera;
	
	nuevo=crearNodo(entero);
	
	cabezera=lista;
	while(cabezera!=NULL){
		cabezera=cabezera->sig;
	}
	
	cabezera->sig=nuevo;
}
	
void calculaPar(TPtr lista){
	TPtr aux, nuevo;
	int contador;
	
	contador=0;
	//recorre lista hasta el final
	aux=lista;
	while(aux!=NULL){
		if(aux->entero%2==0){
			contador++;
		}
		aux=aux->sig;
	}
	//nuevo nodo
	nuevo=(TPtr)malloc(sizeof(TNodo));
	nuevo->entero=contador;
	nuevo->sig=NULL;
	//enlaza al final
	aux->sig=nuevo;
}

