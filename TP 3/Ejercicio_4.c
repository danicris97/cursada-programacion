#include <stdio.h>
#include <math.h>

int contarDivisores(int);
int cambiarBaseA(int, int);
short determinaPrimo(int);
void ingresaNumero(int *);

int main() {
	int n;
	
	ingresaNumero(&n);
	if(determinaPrimo(n)==1)
		printf("\nEL NUMERO EN BASE 9 ES: %d",cambiarBaseA(9,n));
	else
		printf("\nFIN - EL NUMERO NO ES PRIMO");
	
	return 0;
}

void ingresaNumero(int *num){
	printf("\nINGRESA UN NUMERO ENTERO: ");
	scanf("%d",num);
}
	
int contarDivisores(int n){
	int c,pd;
	c=0;
	pd=1;
	
	while(pd<=(n/2)){
		pd++;
		if((n%pd==0))
			c++;
	}
	
	return c;
}
	
int cambiarBaseA(int b, int num){
	/*DE BASE 10 A CUALQUIER BASE*/
	int i,n;
	n=0;
	i=0;
	
	if((b<10)&&(b>1)){
		while(num>=b){
			n=n+((num%b)*(pow(10,i)));
			i++;
			num=num/b;
		}
		if(num!=0){
			n=n+(num*pow(10,i));
		}
		return n;
	}
	else
		return 0;
}
	
short determinaPrimo(int num){
	int pd;
	pd=2;
	
	while((pd<=num/2)&&(num%pd!=0))
		pd++;
	if((pd>num/2)&&(num!=1))
		return 1;
	else
		return 0;
}
