#include <stdio.h>
#define TMAX 100

//PROTOTIPOS DE FUNCIONES
int ingresaNatural();
void ingresaMatriz(int [][TMAX],int,int);
int notaMaxima(int [][TMAX],int,int);
int promedioExamenes(int [][TMAX],int,int);

int main() {
	int n,m;
	int matriz[TMAX][TMAX];
	
	printf("\nINGRESE LA CANTIDAD DE ALUMNOS...");
	n=ingresaNatural();
	
	printf("\nINGRESE LA CANTIDAD DE NOTAS...");
	m=ingresaNatural();
	
	ingresaMatriz(matriz,n,m);
	
	printf("\nNOTA MAXIMA: %d",notaMaxima(matriz,n,m));
	printf("\nPROMEDIO: %d",promedioExamenes(matriz,n,m));
	
	return 0;
}

int ingresaNatural(){
	int n;
	
	do{
		printf("\nINGRESE UN NUMERO NATURAL: ");
		scanf("%d",&n);
	} while(n<=0);
	
	return n;
}
	
int ingresaNota(){
	int nota;
	
	do{
		printf("\nINGRESE LA NOTA: ");
		scanf("%d",&nota);
	} while(nota<0 || nota>100);
	
	return nota;
}
	
void ingresaMatriz(int matriz[][TMAX], int filas, int columnas){
	int i,j;
	
	printf("\nINGRESE LA MATRIZ...");
	for(i=1;i<=filas;i++){
		for(j=1;j<=columnas;j++){
			matriz[i][j] = ingresaNota();
		}
	}
}
	
int notaMaxima(int matriz[][TMAX],int filas, int columnas){
	int i,j,maximo;
	
	maximo=0;
	for(i=1;i<=filas;i++){
		for(j=1;j<=columnas;j++){
			if(matriz[i][j]>maximo){
				maximo = matriz[i][j];
			}
		}
	}
	
	return maximo;
}
	
int promedioExamenes(int matriz[][TMAX], int filas, int columnas){
	int i,j,acomulador;
	
	acomulador=0;
	for(i=1;i<=filas;i++){
		for(j=1;j<=columnas;j++){
			acomulador = acomulador + matriz[i][j];
		}
	}
	
	return (acomulador/(filas*columnas));
}
