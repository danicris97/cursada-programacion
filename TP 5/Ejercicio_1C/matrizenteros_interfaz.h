#ifndef MATRIZENTEROS_INTERFAZ_H
#define MATRIZENTEROS_INTERFAZ_H
#define TMAX 100

typedef int elementosMatriz[TMAX][TMAX];

typedef struct{
	int fila;
	int columna;
	elementosMatriz MatrizEnteros;
}Matriz;

void iniciaMatriz(Matriz *,int,int);
void iniciaMatrizNula(Matriz *);
void cargaMatriz(Matriz *);
void muestraMatriz(Matriz);
void sumarMatrices(Matriz,Matriz,Matriz *);
void productoEscalar(Matriz,int,Matriz *);
void productoMatrices(Matriz,Matriz,Matriz *);
void restaMatrices(Matriz,Matriz,Matriz *);
void copiaMatriz(Matriz,Matriz *);
int igualdadMatrices(Matriz,Matriz);
int cantidadFilas(Matriz);
int cantidadColumnas(Matriz);
int esCuadrada(Matriz);

#endif
