#ifndef LISTA_H
#define LISTA_H

#include "TADPedido.h"
#include "cadena.h"

typedef struct nodo{
	TPedido elemento;
	struct nodo *sig;
}TNodo;

typedef TNodo* Tptr;

Tptr crearListaVacia();
void agregaElementoInicio(Tptr);
void agregaElemento(Tptr);
void agregaOrdenado(Tptr);
void ordenaLista(Tptr);
void eliminaElemetoInicio(Tptr);
void eliminaUltimoElemento(Tptr);
void eliminaElementoPorIdPedido(Tptr, long);
void eliminaElementoPorIdAbonado(Tptr, long);
void eliminaElementoPrimeroFecha(Tptr *, TCadena);
void muestraLista(Tptr);
void muestraListaPorFecha(Tptr, TCadena);
void muestraListaPoridAbonado(Tptr, long);

#endif
