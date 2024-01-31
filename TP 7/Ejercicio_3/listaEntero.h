#ifndef LISTAENTERO_H
#define LISTAENTERO_H

typedef struct nodo{
	int entero;
	struct nodo *sig;
}TNodo;

typedef TNodo* TPtr;

TPtr cargarLista(int);
void muestraLista(TPtr);
void agregaElementoFin(TPtr, int);
void calculaPar(TPtr);

#endif
