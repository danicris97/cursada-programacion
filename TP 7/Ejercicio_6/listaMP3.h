#ifndef LISTAMP3_H
#define LISTAMP3_H

#include "cadena.h"

typedef struct nodo{
	int duracion;
	TCadena nombre;
	TCadena interprete;
	TCadena album;
	TCadena genero;
	struct nodo *sig;
}TNodo;

//seria tad puntero
typedef TNodo* Tptr;

//seria otro tad
Tptr crearCancion();

Tptr iniciaLista();
void agregaFin(Tptr, Tptr);
void agregaPosicion(Tptr, Tptr, int);
void agregaInicio(Tptr, Tptr);
void eliminaPrimero(Tptr);
void eliminaUltimo(Tptr);
void eliminaPosicion(Tptr, int);
void mostrarLista(Tptr);
void mostrarPorInterprete(Tptr, TCadena);
void mostrarPorAlbum(Tptr, TCadena);

#endif
