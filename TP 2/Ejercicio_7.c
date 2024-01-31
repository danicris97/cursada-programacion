#include <stdio.h>

void ingresoDatos(int *, int *, int *);
void analizaLista(int *, int *, int , int, int);

int main() {
	int a,b,n,ca,cb;
	
	ingresoDatos(&a,&b,&n);
	analizaLista(&ca,&cb,a,b,n);
	
	printf("\nLA CANTIDAD DE NUMEROS MULTIPLOS DE %d ES: %d",a,ca);
	printf("\nLA CANTIDAD DE NUMEROS MULTIPLOS DE %d ES: %d",b,cb);
	
	return 0;
}

void ingresoDatos(int *a, int *b, int *n){
	do{
		printf("\nINGRESE UN NUMERO NATURAL: ");
		scanf("%d",a);
	}while(*a<0);
	
	do{
		printf("\nINGRESE OTRO NUMERO NATURAL: ");
		scanf("%d",b);
	}while(*b<0);
	
	do{
		printf("\nINGRESE EL TAMANIO DE LA LISTA: ");
		scanf("%d",n);
	}while(*n<=0);
}

void sumaMultip(int *cont, int num, int m){
	if((num%m)==0)
		*cont=*cont+1;
}
	
void analizaLista(int *ca, int *cb, int a, int b, int n){
	int i,num;
	*ca=0;
	*cb=0;
	
	for (i=1;i<=n;i++){
		printf("\nINGRESE UN NUMERO DE LA LISTA: ");
		scanf("%d",&num);
		
		sumaMultip(ca,num,a);
		sumaMultip(cb,num,b);
	}
}
