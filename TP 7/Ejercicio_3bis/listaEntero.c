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
	while(cabezera->sig!=NULL){
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
	
	agregaElementoFin(lista,contador);
	/*
	//nuevo nodo
	nuevo=(TNodo*)malloc(sizeof(TNodo));
	nuevo->entero=contador;
	nuevo->sig=NULL;
	//enlaza al final
	aux=lista;
	
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	
	aux->sig=nuevo;
	*/
}

void calculaImpar(TPtr lista){
	TPtr aux, nuevo;
	int contador;
	
	contador=0;

	aux=lista;
	while(aux!=NULL){
		if(aux->entero%2!=0){
			contador++;
		}
		aux=aux->sig;
	}
	
	agregaElementoFin(lista,contador);
	
}

int determinaPrimo(int entero){
	int p;
	
	while(p<=entero/2 && entero%p==0){
		p++;
	}
	
	if(p<=entero/2){
		return 1;
	}else{
		return 0;
	}
}
	
void insertaEnteroPrimo(TPtr lista){
	TPtr aux, nuevo, anterior;
	
	srand(time(NULL));
	
	aux=lista;
	while(aux!=NULL && determinaPrimo(aux->entero)==0){
		anterior=aux;
		aux=aux->sig;
	}
	
	if(aux!=NULL){
		nuevo=crearNodo(rand()%11+101);
		anterior->sig=nuevo;
		nuevo->sig=aux;
	}else{
		printf("\nNo hay numeros primos en la lista");
	}
}
