#include "matrizenteros_interfaz.h"
#include <stdio.h>

void iniciaMatrizNula(Matriz *m){
	m->fila=1;
	m->columna=1;
	m->MatrizEnteros[1][1]=0;
}
	
void iniciaMatriz(Matriz *m, int fila, int columna){
	m->fila=fila;
	m->columna=fila;
	int i,j;
	
	for(i=1;i<=m->fila;i++){
		for(j=1;j<=m->columna;j++){
			m->MatrizEnteros[i][j]=0;
		}
	}
}

void cargaMatriz(Matriz *m){
	int i,j,n;
	printf("\nCARGAR MATRIZ...");
	
	for(i=1;i<=m->fila;i++){
		for(j=1;j<=m->columna;j++){
			printf("\nINGRESE NUMERO: ");
			scanf("%d",&n);
			m->MatrizEnteros[i][j]=n;
		}
	}
}
	
void muestraMatriz(Matriz m){
	int i,j;
	
	printf("\nMATRIZ...\n");
	for(i=1;i<=m.fila;i++){
		for(j=1;j<=m.columna;j++){
			printf("%d ",m.MatrizEnteros[i][j]);
		}
		printf("\n");
	}
}
	
void sumarMatrices(Matriz m, Matriz n, Matriz *resultado){
	if(m.fila==n.fila && m.columna==n.columna){
		int i,j;
		resultado->fila=m.fila;
		resultado->columna=m.columna;
	
		for(i=1;i<=m.fila;i++){
			for(j=1;j<=m.columna;j++){
				resultado->MatrizEnteros[i][j]=(m.MatrizEnteros[i][j]+n.MatrizEnteros[i][j]);
			}
		}
	}
}
	
void productoEscalar(Matriz m, int escalar, Matriz *resultado){
	int i,j;
	resultado->fila=m.fila;
	resultado->columna=m.columna;
	
	for(i=1;i<=m.fila;i++){
		for(j=1;j<=m.columna;j++){
			resultado->MatrizEnteros[i][j]=m.MatrizEnteros[i][j]*escalar;
		}
	}
}
	
void productoMatrices(Matriz m, Matriz n, Matriz *resultado){
	if(m.columna == n.fila){
		int i,j,r,acomulador;
		resultado->fila=m.fila;
		resultado->columna=n.columna;
		
		for(i=1;i<=m.fila;i++){
			for(j=1;j<=n.columna;j++){
				acomulador=0;
				for(r=1;r<=n.fila;r++){
					acomulador=acomulador + (m.MatrizEnteros[i][r]*n.MatrizEnteros[r][j]);
				}
				resultado->MatrizEnteros[i][j]=acomulador;
			}
		}
	}
}
	
void restaMatrices(Matriz m, Matriz n, Matriz *resultado){
	if(m.fila==n.fila && m.columna==n.columna){
		resultado->fila=m.fila;
		resultado->columna=m.columna;
		
		Matriz auxiliar;
		iniciaMatriz(&auxiliar,m.fila,m.columna);
		
		productoEscalar(n,-1,&auxiliar);
		sumarMatrices(m,n,resultado);
	}
}
	
void copiaMatriz(Matriz m, Matriz *resultado){
	int i,j;
	resultado->fila=m.fila;
	resultado->columna=m.columna;
		
	for(i=1;i<=m.fila;i++){
		for(j=1;j<=m.columna;j++){
			resultado->MatrizEnteros[i][j]=m.MatrizEnteros[i][j];
		}
	}
}
	
int igualdadMatrices(Matriz m, Matriz n){
	int i,j,b;
	
	b=1;
	if(m.fila==n.fila){
		if(m.columna==n.columna){
			for(i=1;i<=m.fila;i++){
				for(j=1;j<=m.columna;j++){
					if(m.MatrizEnteros[i][j]!=n.MatrizEnteros[i][j])
						b=0;
				}
			}
		}else{
			b=0;
		}
	}else{
		b=0;
	}
	
	return b;
}

int cantidadFilas(Matriz m){
	return m.fila;
}
	
int cantidadColumnas(Matriz m){
	return m.columna;
}
	
int esCuadrada(Matriz m){
	if(m.fila == m.columna)
		return 1;
	else
		return 0;
}
