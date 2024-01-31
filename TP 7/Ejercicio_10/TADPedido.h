#ifndef TADPEDIDO_H
#define TADPEDIDO_H

#include "cadena.h"

typedef struct{
	long idPedido;
	long idAbonado;
	TCadena descripcion;
	TCadena fecha;
}TPedido;

TPedido crearPedido();
int comparaPoridPedido(TPedido, TPedido);
int comparaPoridAbonado(TPedido, TPedido);
int comparaPorFecha(TPedido, TPedido);
int comparaidAbonado(TPedido, long);
int comparaidPedido(TPedido, long);
int comparaFecha(TPedido, TCadena);
void modificaDescripcion(TPedido *);
void modificaFecha(TPedido *);
void modificaidAbonado(TPedido *);
void modificaidPedido(TPedido *);
long getidPedido(TPedido);
long getidAbonado(TPedido);
void getDescripcion(TPedido, TCadena);
void getFecha(TPedido, TCadena);
void muestraPedido(TPedido);

#endif
