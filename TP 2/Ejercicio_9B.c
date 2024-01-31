#include <stdio.h>

int ingresaTamLista();
float detPromedioDigPares(int);

int main() {
	int n;
	float prom;
	
	n=ingresaTamLista();
	prom=detPromedioDigPares(n);
	printf("\nEL PROMEDIO DE LOS NUMEROS FORMADOS POR DIGITOS PARES ES: %f",prom);
	
	return 0;
}

int ingresaTamLista(){
	int tam;
	
	do{
		printf("\nINGRESE EL TAMANIO DE LA LISTA: ");
		scanf("%d",&tam);
	}while(tam<=0);
	
	return tam;
}

float ingresaNumRealPositivo(){
	float r;
	
	printf("\nINGRESE UN NUMERO DE LA LISTA: ");
	scanf("%f",&r);
	
	return r;
}
	
int determinaDigPares(float real){
	int dig,i,num;
	i=1;
	
	while((num!=0)&&(i==1)){
		dig=num%10;
		if((dig%2)!=0)
			i=0;
		else
			num=num/10;
	}
	
	return i;
}
	
float detPromedioDigPares(int n){
	int i,total;
	float num,acu;
	
	total=0;
	acu=0;
	
	for (i=1;i<=n;i++){
		num=ingresaNumRealPositivo();
		if(determinaDigPares(num)==1){
			total++;
			acu=acu+num;
		}
	}
	
	return (acu/total);
}
