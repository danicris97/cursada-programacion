#include <stdio.h>
#include <math.h>

int ingresaNat();
void trabajaLista(int);

int main() {
	int n;
	
	n=ingresaNat();
	trabajaLista(n);
	
	return 0;
}

int ingresaNat(){
	int n;
	
	do{
		printf("\nINGRESA EL TAMANIO DE LA LISTA: ");
		scanf("%d",&n);
	} while(n<1);
	
	return n;
}
	
float ingresaReal(){
	float r;
	
	printf("\nINGRESA UN NUMERO REAL: ");
	scanf("%f",&r);
	
	return r;
}

short determinaParImpar(int n){
	if((n%2)!=0)
		return 1;
	else if(n==0)
		return 0;
	else
		return 2;
}
	
int obtienePrimerDecimal(float num){
	int n;
	
	num=num-((int)num);
	num=num*10;
	
	n=(int)num;
	
	return n;
}
	
float calculaNuevo(float num, short i){
	float nuevo;
	
	if(i==2)
		nuevo=pow(num,obtienePrimerDecimal(num));
	else if(i==1)
		nuevo=sqrt((int)num);
	else
		nuevo=log(num);
	
	return nuevo;
}
	
void trabajaLista(int n){
	int i;
	short b;
	float num;
	
	for (i=1;i<=n;i++){
		num=ingresaReal();
		b=determinaParImpar((int)num);
		printf("\nEL NUEVO NUMERO ES: %f\n",calculaNuevo(num,b));
	}
}
