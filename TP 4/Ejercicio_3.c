#include <stdio.h>
#define TMAX 1000

int ingreseNroNatural();
void ingresaLista(int[], int);
int alturaModal(int[], int);
int cantAlturaModal(int[], int, int);
void eliminarAlturaModal(int[], int*, int);

int main() {
	int tamA, altModA/*, tamB, altModB*/;
	int listaA[TMAX]/*,listaB[]*/;
	
	printf("TRABAJANDO LA LISTA A...");
	tamA=ingreseNroNatural();
	ingresaLista(listaA,tamA);
	altModA = alturaModal(listaA,tamA);
	printf("\nALTURA MODAL DE LA LISTA A: %d",altModA);
	printf("\nEL TOTAL DE CHICOS CON ALTURA MODAL ES: %d",cantAlturaModal(listaA,tamA,altModA));
	printf("\nELIMINADO ALTURA MODAL...");
	eliminarAlturaModal(listaA,&tamA,altModA);
	
	printf("TRABAJANDO LA LISTA B...");
	tamA=ingreseNroNatural();
	ingresaLista(listaA,tamA);
	altModA = alturaModal(listaA,tamA);
	printf("\nALTURA MODAL DE LA LISTA A: %d",altModA);
	printf("\nEL TOTAL DE CHICOS CON ALTURA MODAL ES: %d",cantAlturaModal(listaA,tamA,altModA));
	printf("\nELIMINADO ALTURA MODAL...");
	eliminarAlturaModal(listaA,&tamA,altModA);
	
	return 0;
}

int ingreseNroNatural(){
	int n;
	
	do{
		printf("\nINGRESE UN NUMERO NATURAL: ");
		scanf("%d",&n);
	}while(n<0);
	
	return n;
}

void ingresaLista(int lista[], int tam){
	int i;
	
	printf("\nINGRESE LA LISTA DE MEDIDAS");
	for(i=1;i<=tam;i++)
		lista[i]=ingreseNroNatural();
	
}

void eliminaElemento(int aux[], int *tam, int pos){
	int i;
	
	for(i=pos;i<*tam;i++){
		aux[i]=aux[i+1];
	}
	*tam = *tam-1;
}
	
void copyVector(int lista[], int aux[], int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		aux[i]=lista[i];
	}
}
	
void armarVectoresFrecuencia(int lista[], int tam, int arrayElementos[], int arrayFrecuencia[], int *k){
	int i,j,c;
	int aux[TMAX];
	copyVector(lista,aux,tam);
	
	*k=1;
	i=1;
	while(i<tam){
		j=1;
		while(aux[i]!=aux[j] && j<=i+1){
			j++;
		}
		if(j<=i+1){
			c=1;
			j=i+1;
			while(j<=tam){
				if(aux[i]==aux[j]){
					c++;
					eliminaElemento(aux,&tam,j);
				}else
					j++;
			}
			*k=*k+1;
			arrayElementos[*k]=aux[i];
			arrayFrecuencia[*k]=c;
		}
		i++;
	}
}
	
int determinaMayor(int lista[], int tam){
	int may,i,pos;
	may=-1;
	
	for(i=1;i<=tam;i++){
		if(lista[i]>may){
			may=lista[i];
			pos=i;
		}
	}
	
	return pos;
}
	
int alturaModal(int lista[], int tam){
	int alturaModal,k,pos;
	int arrayElementos[TMAX], arrayFrecuencia[TMAX];
	
	armarVectoresFrecuencia(lista,tam,arrayElementos,arrayFrecuencia,&k);
	pos = determinaMayor(arrayFrecuencia,k);
	alturaModal = arrayElementos[pos];
	
	return alturaModal;
}
	
int cantAlturaModal(int lista[], int tam, int altModal){
	int i,contador;
	contador=0;
	
	for(i=1;i<=tam;i++){
		if(lista[i]==altModal)
			contador++;
	}
	
	return contador;
}

void eliminarAlturaModal(int lista[], int *tam, int altModal){
	int i;
	
	i=1;
	while(i<=*tam){
		if(lista[i]==altModal)
			eliminaElemento(lista,tam,i);
		i++;
	}
}
