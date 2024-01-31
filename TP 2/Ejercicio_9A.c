#include <stdio.h>

int ingresaTamLista();
int detPromedioDigPares(int);

int main() {
	int n,prom;
	
	n=ingresaTamLista();
	prom=detPromedioDigPares(n);
	printf("\nEL PROMEDIO DE LOS NUMEROS FORMADOS POR DIGITOS PARES ES: %d",prom);
	
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

int ingresaNumEntero(){
	int e;
	
	printf("\nINGRESE UN NUMERO DE LA LISTA: ");
	scanf("%d",&e);
	
	return e;
}

int determinaDigPares(int num){
	int dig,i;
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
	
int detPromedioDigPares(int n){
	int num,i,acu,total;
	total=0;
	acu=0;
	
	for (i=1;i<=n;i++){
		num=ingresaNumEntero();
		if(determinaDigPares(num)==1){
			total++;
			acu=acu+num;
		}
	}
	
	return (acu/total);
}
