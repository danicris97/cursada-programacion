#ifndef FRACCION_H
#define FRACCION_H

typedef struct{
	int p;//entero
	int q;//razon
}Fraccion;

Fraccion inicia();
Fraccion cargar();
Fraccion suma(Fraccion,Fraccion);
Fraccion resta(Fraccion,Fraccion);
Fraccion mult(Fraccion,Fraccion);
Fraccion dividir(Fraccion,Fraccion);
short equivalencia(Fraccion,Fraccion);
void modificar(Fraccion *);
void mostrar(Fraccion);

#endif
