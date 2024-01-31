#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cantClientes();
void trabajaLista(int);

int main() {
	int n;
	
	srand(time(NULL));
	n=cantClientes();
	trabajaLista(n);
	
	return 0;
}

int cantClientes(){
	int c;
	
	do{
		printf("\nINGRESE LA CANTIDAD DE CLIENTES: ");
		scanf("%d",&c);
	}while(c<=0);
	
	return c;
}

int generaNumero(){
	int ran;
	
	ran=rand()%(30-1+1)+1;
	
	return ran;
}
	
void detMayorMenor(int *may, int *men, int num, int i){
	if (i!=1){
		if(num>*may)
			*may=num;
		else if(num<*men)
			*men=num;
	}
	else{
		*may=num;
		*men=num;
	}
}
	
int calculaProm(int n, int i, int *acu){
	int p;
	
	if(i!=1){
		*acu=*acu+n;
		p=*acu/i;
	}
	else{
	   *acu=n;
		p=n;
	}
	
	return p;
}
	
void muestraFinal(int may, int men, int prom){
	printf("\nEL MAYOR TIEMPO DE ESPERA DE LA LISTA ES: %d",may);
	printf("\nEL MENOR TIEMPO DE ESPERA DE LA LISTA ES: %d",men);
	printf("\nEL PROMEDIO DE TIEMPO DE ESPERA: %d",prom);
}
	
void trabajaLista(int n){
	int i,num,may,men,prom,acu;
	
	for(i=1;i<=n;i++){
		num=generaNumero();
		detMayorMenor(&may,&men,num,i);
		prom=calculaProm(num,i,&acu);
	}
	
	muestraFinal(may,men,prom);
}
