#include <stdio.h>

int ingresaCota(int);
void ingresaLista(int ,int ,int *,int *);
void muestraPrimos(int, int);

int main() {
	int a,b,may,men;
	
	printf("\nINGRESE EL INTERVALO [A,B]...");
	a=ingresaCota(0);
	b=ingresaCota(a);
	printf("\nINGRESE LA LISTA DE NUMEROS QUE PERTENECEN A [%d,%d]",a,b);
	ingresaLista(a,b,&men,&may);
	
	printf("\nMENOR: %d",men);
	printf("\nMAYOR: %d",may);
	
	muestraPrimos(a,b);
	
	return 0;
}

int ingresaCota(int a){
	int num;
	
	do{
		printf("\nINGRESE UN NUMERO NATURAL: ");
		scanf("%d",&num);
	} while((num<1)||(num<a));
	
	return num;
}

int ingresaNumeroLista(int a, int b){
	int num;
	
	printf("\nINGRESE UN NUMERO NATURAL: ");
	scanf("%d",&num);
	
	return num;
}
	
short determinaPrimo(int n){
	int pd;
	
	pd=2;
	while((pd<=n/2)&&(n%pd!=0))
		pd++;
	if((pd>n/2)&&(n!=1))
		return 1;
	else
		return 0;
}
	
void determinaMayMenPrimo(int n, int *men, int *may){
	if(determinaPrimo(n)==1){
		if(n>*may)
			*may=n;
		else if(n<*men)
			*men=n;
	}
}
	
void ingresaLista(int a, int b, int *men, int *may){
	int n;
	
	printf("\nPARA TERMINAR EL INGRESO DEBE INGRESAR UN NUMERO NEGATIVO O 0");
	n=ingresaNumeroLista(a,b);
	*men=n;
	*may=n;
	
	while(n>=1 && n>=a && n<=b){
		determinaMayMenPrimo(n,men,may);
		n=ingresaNumeroLista(a,b);
	}
}
	
void muestraPrimos(int a, int b){
	int i;
	
	printf("\nLISTA DE PRIMOS ENTRE [%d,%d]: ",a,b);
	for(i=a;i<=b;i++){
		if(determinaPrimo(i)==1){
			printf("%d, ",i);
		}
	}
}
