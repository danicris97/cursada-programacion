#include <stdio.h>
/*#define TMAX 1000]*/

int ingresaNumeroNatural();
void cargaLista(int [], int n);
int cuentaRepeticiones(int [], int, int);
void eliminaElemento(int [], int, int*);
void agregaElementoalFinal(int [], int, int*);
void muestraLista(int [], int);

int main() {
	/*int lista[TMAX];*/
	int n,elemento;
	n=ingresaNumeroNatural();
	
	int lista[n];
	cargaLista(lista,n);
	
	printf("\nINGRESE UN NUMERO DE LA LISTA...");	
	elemento=ingresaNumeroNatural();
	printf("\nLA CANTIDAD DE VECES QUE APARECE %d ES: %d",elemento,cuentaRepeticiones(lista,elemento,n));
	
	printf("\nLISTA...: ");
	muestraLista(lista,n);
	
	printf("\nINGRESE UN NUMERO A ELIMINAR DE LA LISTA...");
	eliminaElemento(lista,ingresaNumeroNatural(),&n);
	
	printf("\nLISTA ACTUALIZADA...: ");
	muestraLista(lista,n);
	
	return 0;
}

int ingresaNumeroNatural(){
	int numero;
	
	do{
		printf("\nINGRESA UN NUMERO NATURAL: ");
		scanf("%d",&numero);
	} while(numero<=0);
	
	return numero;
}
	
void cargaLista(int LISTA[], int n){
	int i;
	
	for(i=1;i<=n;i++){
		printf("\nINGRESE UN NUMERO DE LA LISTA: ");
		scanf("%d",&LISTA[i]);
	}
}

int cuentaRepeticiones(int LISTA[], int elemento, int n){
	int apariciones,i;
	apariciones=0;
	
	for(i=1;i<=n;i++){
		if(LISTA[i]==elemento)
			apariciones++;
	}
	
	return apariciones;
}

void eliminaElemento(int LISTA[], int elemento, int *n){
	int i,j;
	i=1;
	
	while(i<=*n){
		if(LISTA[i]==elemento){
			for(j=i+1;j<=*n;j++)
				LISTA[i]=LISTA[j];
			*n=*n-1;
		}
		i++;
	}
}
	
void muestraLista(int lista[], int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		printf("%d, ",lista[i]);
	}
}
