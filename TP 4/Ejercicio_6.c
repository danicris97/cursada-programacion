#include <stdio.h>
#define TMAX 100

int ingresaNatural();
int ingresaFilaColumna(int);
void cargaMatriz(int [][TMAX],int,int);
void mostrarMatriz(int [][TMAX],int,int);
void eliminaFilaMatriz(int [][TMAX],int*,int,int);
void insertaFilaMatriz(int [][TMAX],int*,int,int);
void insertaColumnaMatriz(int [][TMAX],int,int*,int);
void ordenarSoloUnaFila(int [][TMAX],int,int,int);
void ordenarFilaPreservandoColumna(int [][TMAX],int,int,int);

int main() {
	int n,m,f,c;
	int matriz[TMAX][TMAX];
	
	printf("INGRESE LA CANTIDAD DE FILAS...");
	n=ingresaNatural();
	
	printf("\nINGRESE LA CANTIDAD DE COLUMNAS...");
	m=ingresaNatural();
	
	printf("\nINGRESA LA MATRIZ...");
	cargaMatriz(matriz,n,m);
	mostrarMatriz(matriz,n,m);
	
	printf("\nINGRESE LA FILA QUE DESEA ELIMINAR...");
	f=ingresaNatural();
	eliminaFilaMatriz(matriz,&n,m,f);
	mostrarMatriz(matriz,n,m);
	
	printf("\nINGRESE LA FILA QUE DESEA AGREGAR...");
	f=ingresaFilaColumna(n);
	insertaFilaMatriz(matriz,&n,m,f);
	mostrarMatriz(matriz,n,m);
	
	printf("\nINGRESE LA COLUMNA QUE DESEA AGREGAR...");
	c=ingresaFilaColumna(c);
	insertaColumnaMatriz(matriz,n,&m,c);
	mostrarMatriz(matriz,n,m);
	
	printf("\nINGRESE LA FILA A ORDENAR...");
	ordenarSoloUnaFila(matriz,n,m,ingresaNatural());
	mostrarMatriz(matriz,n,m);
	
	printf("\nINGRESE LA FILA A ORDENAR SIN DESORDENAR...");
	ordenarFilaPreservandoColumna(matriz,n,m,ingresaNatural());
	mostrarMatriz(matriz,n,m);
	
	return 0;
}

int ingresaFilaColumna(int maximo){
	int n;
	
	do{
		printf("\nINGRESE UN NUMERO NATURAL: ");
		scanf("%d",&n);
	} while(n<=0 && n>=maximo);
	
	return n;
}

int ingresaNatural(){
	int n;
	
	do{
		printf("\nINGRESE UN NUMERO NATURAL: ");
		scanf("%d",&n);
	}while(n<=0);
	
	return n;
}
	
void cargaMatriz(int matriz[][TMAX], int filas, int columnas){
	int i,j;
	
	for(i=1;i<=filas;i++){
		for(j=1;j<=columnas;j++){
			matriz[i][j]=ingresaNatural();
		}
	}
}
	
void mostrarMatriz(int matriz[][TMAX], int filas, int columnas){
	int i,j;
	
	printf("\n");
	for(i=1;i<=filas;i++){
		for(j=1;j<=columnas;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}

void eliminaFilaMatriz(int matriz[][TMAX],int *filas, int columnas, int pos){
	int i,j;
	
	for(i=pos;i<*filas;i++){
		for(j=1;j<=columnas;j++){
			matriz[i][j] = matriz[i+1][j];
		}	
	}
	
	*filas = *filas-1;
}
	
void insertaFilaMatriz(int matriz[][TMAX],int *filas, int columnas, int pos){
	int i,j;
	
	for(i=*filas;i>=pos;i--){
		for(j=columnas;j>=1;j--){
			matriz[i+1][j] = matriz[i][j];
		}
	}
	
	printf("\nINGRESE LA FILA...");
	for(j=1;j<=columnas;j++){
		matriz[pos][j] = ingresaNatural();
	}
	
	*filas = *filas+1;
}

void insertaColumnaMatriz(int matriz[][TMAX],int filas, int *columnas, int pos){
	int i,j;
		
	for(j=*columnas;j>=pos;j--){
		for(i=filas;j>=1;j--){
			matriz[i][j+1] = matriz[i][j];
		}
	}
		
	printf("\nINGRESE LA COLUMNA...");
	for(i=1;i<=filas;i++){
		matriz[i][pos] = ingresaNatural();
	}
		
	*columnas = *columnas+1;
}

void ordenarSoloUnaFila(int matriz[][TMAX], int filas, int columnas, int pos){
	int j,k,aux;
	
	for(j=1;j<columnas;j++){
		for(k=j+1;k<=columnas;k++){
			if(matriz[pos][k]<matriz[pos][j]){
				aux = matriz[pos][k];
				matriz[pos][k] = matriz[pos][j];
				matriz[pos][j] = aux;
			}
		}
	}
}

void ordenarFilaPreservandoColumna(int matriz[][TMAX], int filas, int columnas, int pos){
	int i,j,k,aux;
	
	for(j=1;j<columnas;j++){
		for(k=j+1;k<=columnas;k++){
			if(matriz[pos][k]<matriz[pos][j]){
				for(i=1;i<=filas;i++){
					aux = matriz[i][k];
					matriz[i][k] = matriz[i][j];
					matriz[i][j] = aux;
				}
			}
		}
	}
}
