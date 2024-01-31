#include <stdio.h>
#define TMAX 1000

int recorreVectorBP(int[], int);
void cargaVector(int[], int);
void muestraVector(int[], int);
int determinaMonte(int[], int);//algun dia

int main() {
	int v[TMAX];
	int n;
	
	printf("\nINGRESE TAMAÑO DE LA LISTA: ");
	scanf("%d",&n);
	
	cargaVector(v,n);
	printf("\nULTIMO PAR: %d",recorreVectorBP(v,n));
	printf("\nVECTOR: ");
	muestraVector(v,n);
	
	return 0;
}

void cargaVector(int v[], int n){
	if(n==1){
		printf("\nINGRESE NUMERO DE LA LISTA: ");
		scanf("%d",&v[n]);
	}else{
		cargaVector(v,n-1);
		printf("\nINGRESE NUMERO DE LA LISTA: ");
		scanf("%d",&v[n]);
	}
}
	
void muestraVector(int v[], int n){
	if(n==1){
		printf("[%d]",v[n]);
	}else{
		muestraVector(v,n-1);
		printf(" [%d]",v[n]);
	}
}
	
int recorreVectorBP(int v[], int n){
	if(v[n]%2==0 && n!=0)
		return v[n];
	else
		return recorreVectorBP(v,n-1);
	
	if(n==0)
		return -1;
}

int determinaMonte(int v[], int n){
	return 0;
}
