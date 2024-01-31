#include <stdio.h>

int ingresaNumNatural();
void muestraPrimosAnteriores(int);

int main() {
	int num;
	
	num=ingresaNumNatural();
	muestraPrimosAnteriores(num);
	
	return 0;
}

int ingresaNumNatural(){
	int n;
	
	do{
		printf("\nINGRESA UN NUMERO NATURAL: ");
		scanf("%d",&n);
	}while(n<=0);
	
	return n;
}

int determinaPrimo(int x){
	int pd;
	
	pd=2;
	while((pd<=x/2)&&(x%pd!=0))
		pd++;
	
	if(pd>x/2)
		return 1;
	else
		return 0;
}
	
void muestraPrimosAnteriores(int num){
	int i;
	
	if(num>2){
		printf("\nLOS NUMEROS PRIMOS ANTECEDENTES A %d SON: ",num);
		for(i=2;i<=(num-1);i++){
			if(determinaPrimo(i)==1)
				printf("%d, ",i);
		}
	}
	else
	   printf("\nEL NUMERO INGRESADO NO TIENE NUMEROS PRIMOS ANTECEDENTES");
}
