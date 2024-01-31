#include <stdio.h>
#include <stdlib.h>

void modificaNumeros(int *, int *);
int ingresaNumero();
void muestra(int ,int);

int main(){
	int a,b;
	
	a=ingresaNumero();
	b=ingresaNumero();
	
	modificaNumeros(&a,&b);
	
	muestra(a,b);
	
	return 0;
}

int ingresaNumero(){
	int num;
	
	printf("\nINGRESE UN NUMERO ENTERO: ");
	scanf("%d",&num);
	
	return num;
}
	
void separaDigitos(int *num, int *d){
	int aux;
	if(*num>=0){
		*d=*num%10;
		*num=*num/10;
	}else{
		aux=abs(*num);
		*d=aux%10;
		aux=aux/10;
		*num=aux*-1;
	}
}
	
void armaNumero(int *num, int d){
	int aux;
	if(*num>=0){
		*num=*num*10;
		*num=*num+d;
	}else{
		aux=abs(*num);
		aux=aux*10;
		aux=aux+d;
		*num=aux*-1;
	}
}
	
void modificaNumeros(int *a, int *b){
	int d;
	separaDigitos(a,&d);
	armaNumero(b,d);
}
	
int rearmaDigito(int b){
	int aux,d;
	d=0;
	aux=0;
	
	while(b!=0){
		separaDigitos(&b,&d);
		aux=(aux*10)+d;
	}
	
	return aux;
}
	
void muestra(int a, int b){
	printf("\nEL NUMERO A RESULTA: %d",a);
	printf("\nEL NUMERO B RESULTA: %d",b);
	printf("\nEL NUMERO B INVERTIDO: %d",rearmaDigito(b));
}
