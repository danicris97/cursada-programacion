#include "TADPedido.h"
#include "cadena.h"
#include <stdio.h>

TPedido crearPedido(){
	TPedido nuevo;
	
	printf("\nIngrese id de pedido: ");
	scanf("%ld",&nuevo.idPedido);
	
	printf("\nIngrese id del abonado: ");
	scanf("%ld",&nuevo.idAbonado);
	
	vaciabuffer();
	printf("\nIngrese descripcion del problema: ");
	leeCad(&nuevo.descripcion);
	
	vaciabuffer();
	printf("\nIngrese fecha del pedido: ");
	leeCad(&nuevo.fecha);
	
	return nuevo;
}

int comparaidAbonado(TPedido pedido, long idAbonado){
	if(pedido.idAbonado==idAbonado){
		return 1;
	}else{
		return 0;
	}
}

int comparaidPedido(TPedido pedido, long idPedido){
	if(pedido.idPedido==idPedido){
		return 1;
	}else{
		return 0;
	}
}
	
/*int comparaFecha(TPedido pedido, TCadena fecha){
	return comparaFecha(pedido.fecha,fecha);
}
	
int comparaPoridPedido(TPedido pedido1, TPedido pedido2){
	return comparaidPedido(pedido1, pedido2.idPedido);
}
	
int comparaPoridAbonado(TPedido pedido1, TPedido pedido2){
	return comparaidAbonado(pedido1, pedido2.idAbonado);
}
	
int comparaPorFecha(TPedido pedido1, TPedido pedido2){
	return comparaFecha(pedido1, pedido2.fecha);
}*/
	
void modificaidPedido(TPedido *pedido){
	printf("\nreingrese el id del pedido: ");
	scanf("%ld",pedido->idPedido);
}
	
void modificaidAbonado(TPedido *pedido){
	printf("\nreingrese el id del abonado: ");
	scanf("%ld",pedido->idAbonado);
}
	
void modificaDescripcion(TPedido *pedido){
	vaciabuffer();
	printf("\nreingrese la descripcion del pedido: ");
	leeCad(pedido->descripcion);
}
	
void modificaFecha(TPedido *pedido){
	vaciabuffer();
	printf("\nreingrese la fecha del pedido: ");
	leeCad(pedido->fecha);
}
	
long getidPedido(TPedido pedido){
	return pedido.idPedido;
}
	
long getidAbonado(TPedido pedido){
	return pedido.idAbonado;
}
	
void getDescripcion(TPedido pedido, TCadena resultado){
	copiaCadena(pedido.descripcion, resultado);
}
	
void getFecha(TPedido pedido, TCadena resultado){
	copiaCadena(pedido.fecha, resultado);
}
	
void muestraPedido(TPedido pedido){
	printf("\nPEDIDO: ");
	printf("\nid pedido: %ld",pedido.idPedido);
	printf("\nid abonado: %ld",pedido.idAbonado);
	printf("\nid descripcion: %s",pedido.descripcion);
	printf("\nid fecha: %s",pedido.descripcion);
}
