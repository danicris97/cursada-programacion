#include "Lista.h"
#include "TADPedido.h"
#include <stdio.h>
#include <stdlib.h>

Tptr crearListaVacia(){
	Tptr nuevo;
	
	nuevo=NULL;
	
	return nuevo;
}
	
Tptr crearNodo(){
	Tptr nodo;
	
	nodo=(TNodo*)malloc(sizeof(TNodo));
	nodo->elemento=crearPedido();
	nodo->sig=NULL;
	
	return nodo;
}
	
void agregaElementoInicio(Tptr lista){
	Tptr aux;
	
	aux=lista;
	
	lista->elemento=crearPedido();
	lista->sig=aux;
}

void agregaElemento(Tptr lista){
	Tptr aux, nuevo;
	nuevo=NULL;
	
	if(lista!=NULL){
		aux=lista;
		
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		
		nuevo=crearNodo();
		aux->sig=nuevo;
	}else{
		agregaElementoInicio(lista);
	}
}
	
void agregaOrdenado(Tptr lista){
	Tptr aux, ant, nuevo;
	
	if(lista!=NULL){
		aux=lista;
		ant=NULL;
		
		nuevo=crearNodo();
		while(aux->sig!=NULL && comparaPoridAbonado(aux->elemento, nuevo->elemento)){
			ant=aux;
			aux=aux->sig;
		}
		
		if(aux->sig!=NULL){
			ant->sig=nuevo;
			nuevo->sig=aux;
		}else{
			aux->sig=nuevo;
		}
	}else{
		agregaElementoInicio(lista);
	}
}

void ordenaLista(Tptr lista){
	Tptr aux, aux2, ant, pos;
	
	if(lista!=NULL){
		aux=lista;
		aux2=NULL;
		ant=NULL;
		pos=NULL;
		
		while(aux->sig!=NULL){
			aux2=aux;
			while(aux2->sig!=NULL && comparaPoridAbonado(aux->elemento,aux2->elemento)==0){
				ant=aux2;
				aux2=aux2->sig;
			}
			if(aux2->sig!=NULL){
				pos=aux->sig;
				aux->sig=ant;
				ant->sig=pos;
				aux=aux->sig;
			}
			aux=aux->sig;
		}
	}else{
		printf("\nlista vacia");
	}
}

//revisar los "elimina" si son pasados por valor o por referencia a pesar de ser punteros
void eliminaElemetoInicio(Tptr lista){
	if(lista!=NULL){
		Tptr aux;
	
		aux=lista->sig;
		free(lista);
		lista=aux;
	}else{
		printf("\nlista vacia");
	}
}

void eliminaUltimoElemento(Tptr lista){
	if(lista!=NULL){
		Tptr aux, ant;
		
		ant=NULL;
		aux=lista;
		while(aux->sig!=NULL){
			ant=aux;
			aux=aux->sig;
		}
		free(aux);
		if(ant==NULL){
			lista=NULL;
		}else{
			ant->sig=NULL;
		}
	}else{
		printf("\nlista vacia");
	}
}
	
void eliminaElementoPorIdPedido(Tptr lista, long idPedido){
	Tptr aux, ant;
	
	if(lista!=NULL){
		ant=NULL;
		aux=lista;
		
		while(aux->sig!=NULL && comparaidPedido(aux->elemento,idPedido)==0){
			ant=aux;
			aux=aux->sig;
		}
		
		if(aux->sig!=NULL){
			if(ant!=NULL){
				ant->sig=aux->sig;
				free(aux);
			}else{
				ant=aux->sig;
				free(aux);
			}
		}else{
			printf("\nno hay pedidos con el id ingresado");
		}
		
	}else{
		printf("\nlista vacia");
	}
}
	
void eliminaElementoPorIdAbonado(Tptr lista, long idAbonado){
	Tptr aux, ant;
		
	if(lista!=NULL){
		ant=NULL;
		aux=lista;
			
		while(aux->sig!=NULL && comparaidAbonado(aux->elemento,idAbonado)==0){
			ant=aux;
			aux=aux->sig;
		}
			
		if(aux->sig!=NULL){
			if(ant!=NULL){
				ant->sig=aux->sig;
				free(aux);
			}else{
				ant=aux->sig;
				free(aux);
			}
		}else{
			printf("\nno hay pedidos con el id abonado ingresado");
		}
		
	}else{
		printf("\nlista vacia");
	}
}	

void eliminaElementoPrimeroFecha(Tptr *lista, TCadena fecha){
	if(*lista!=NULL){
		Tptr aux;
		if(comparaFecha(aux->elemento,fecha)==1){
			aux=*lista;
			aux=aux->sig;
			free(aux);
		}else{
			eliminaElementoPrimeroFecha(&aux,fecha);
		}
	}else{
		printf("\nlista vacia");
	}
}
	
void muestraLista(Tptr lista){
	if(lista!=NULL){
		Tptr aux;
		
		aux=lista;
		while(aux!=NULL){
			muestraPedido(aux->elemento);
			aux=aux->sig;
		}
	}else{
		printf("\nlista vacia");
	}
}

void muestraListaPorFecha(Tptr lista, TCadena fecha){
	if(lista!=NULL){
		Tptr aux;
		int b;
		
		b=0;
		aux=lista;
		while(aux!=NULL){
			if(comparaFecha(aux->elemento,fecha)==1){
				b=1;
				muestraPedido(aux->elemento);
			}
			aux=aux->sig;
		}
		
		if(b==0){
			printf("\nno hay pedidos con esa fecha");
		}
	}
}

void muestraListaPoridAbonado(Tptr lista, long idAbonado){
	if(lista!=NULL){
		Tptr aux;
		int b;
			
		b=0;
		aux=lista;
		while(aux!=NULL){
			if(comparaidAbonado(aux->elemento,idAbonado)==1){
				b=1;
				muestraPedido(aux->elemento);
			}
			aux=aux->sig;
		}
			
		if(b==0){
			printf("\nno hay pedidos con ese id de abono");
		}
	}
}
