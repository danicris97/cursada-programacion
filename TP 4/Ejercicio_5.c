#include <stdio.h>
#define TMAX 10000

int ingresaNumeroNatural();
int ingesaNota();
void ingresaListaNotas(int[] ,int);
void armarVectorFrecuencia(int[], int*);
int determinaModa(int[], int);
int medidaAritmeticaProm(int[], int);
void muestraVector(int[], int);

int main() {
	int n,moda,promedio;
	int notas[TMAX];
	
	printf("\nINGRESE LA MAXIMA CANTIDAD DE NOTAS...");
	n=ingresaNumeroNatural();
	
	printf("\nINGRESE LA LISTA DE NOTAS...");
	ingresaListaNotas(notas,n);
	muestraVector(notas,n);
	
	printf("\nTRABAJANDO LISTA...");
	armarVectorFrecuencia(notas,&n);
	muestraVector(notas,n);
	
	moda=determinaModa(notas,n);
	promedio=medidaAritmeticaProm(notas,n);
	
	if(moda>=promedio){
		printf("\nLA NOTA MODA ES MAYOR AL PROMEDIO");
	}else{
		printf("\nLA NOTA MODA ES MENOR AL PROMEDIO");
	}
	
	printf("\nNOTA MODA: %d",moda);
	printf("\nPROMEDIO: %d",promedio);
	
	return 0;
}

int ingresaNumeroNatural(){
	int n;
	
	do{
		printf("\nINGRESE UN NUMERO NATURAL: ");
		scanf("%d",&n);
	} while(n<0);
	
	return n;
}

int ingresaNota(){
	int n;
	
	do{
		printf("\nINGRESE NOTA DEL ALUMNO: ");
		scanf("%d",&n);
	} while(n<=0 || n>=100);
	
	return n;
}
	
void ingresaListaNotas(int notas[], int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		notas[i] = ingresaNota();
	}
}
	
void eliminaElemento(int notas[], int *tam, int pos){
	int i;
	
	for(i=pos;i<*tam;i++){
		notas[i]=notas[i+1];
	}
	*tam=*tam-1;
}
	
void insertarElemento(int notas[], int *tam, int pos, int notaContar){
	int i,contador;
	
	contador = 1;
	for(i=*tam;i>=pos;i--){
		if(notaContar==notas[i]){
			eliminaElemento(notas,tam,i);
			contador++;
		}
		notas[i+1]=notas[i];
	}
	
	notas[pos]=contador;
	*tam=*tam+1;
	
}
	
void armarVectorFrecuencia(int notas[], int *tam){
	int i;
	
	i=1;
	while(i<=*tam){
		insertarElemento(notas,tam,i+1,notas[i]);
		i=i+2;
	}
}
	
int determinaModa(int notas[], int tam){
	int moda,i,indice;
	
	indice=0;
	moda=0;
	i=2;
	while(i<=tam){
		if(notas[i]<moda){
			moda=notas[i];
			indice=i;
		}
		i=i+2;
	}
	
	return notas[indice-1];
}
	
int medidaAritmeticaProm(int notas[], int tam){
	int acomulador,i,sumador;
	
	acomulador=0;
	sumador=0;
	i=1;
	while(i<=tam){
		acomulador = (notas[i]*notas[i+1]);
		sumador = sumador + notas[i+1];
		i=i+2;
	}
	
	return (acomulador/sumador);
}
	
void muestraVector(int notas[], int tam){
	int i;
		
	printf("\nLISTA NOTAS: ");
	for(i=1;i<=tam;i++){
		printf("%d, ",notas[i]);
	}
}	
