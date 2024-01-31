#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short determinaAmigo(int, int);
short determinaTipoNumero(int);
int ingresaNumero();
void ingresaRango(int *, int *);
int generaNumero(int, int);
short buscaAmigo(int, int, int);

int main() {
	int a,b,n,i,numero;
	
	ingresaRango(&a,&b);
	n=ingresaNumero();
	srand(time(NULL));
	
	for(i=1;i<=n;i++){
		numero=generaNumero(a,b);
		if((determinaTipoNumero(numero)!=1)&&(buscaAmigo(a,b,numero)==1))
			printf("%d - ",numero);
	}
	
	
	return 0;
}

short buscaAmigo(int a, int b, int numero){
	while((a<=b)&&(determinaAmigo(a,numero)!=1))
		a++;
	if(a<=b)
		return 1;
	else
		return 0;
}

void ingresaRango(int *a, int *b){
	do{
		printf("\nINGRESA EL MENOR NUMERO DEL RANGO: ");
		scanf("%d",a);
	} while(*a<0);
	
	do{
		printf("\nINGRESA EL NUMERO MAYOR DEL RANGO: ");
		scanf("%d",b);
	} while(*b<=*a);
}

int generaNumero(int a, int b){return rand()%(b-a+1)+a;}

int ingresaNumero(){
	int n;
	
	do{
		printf("\nINGRESE UN NUMERO NATURAL: ");
		scanf("%d",&n);
	}while(n<0);
	
	return n;
}

int acomulaDivisores(int numero, int i){
	int suma,pd;
	suma=0;
	pd=1;
	
	if(i==1){
		while(pd<=numero){
			if(numero%pd==0)
				suma=suma+pd;
			pd++;
		}
	}/*suma los divisores incluido a si mismo*/
	else if(i==2){
		while(pd<=numero/2){
			if(numero%pd==0)
				suma=suma+pd;
			pd++;
		}
	}/*suma los divisores excuyendo al numero*/
	
	return suma;
}

short determinaAmigo(int a, int b){
	int sumaA;
	int sumaB;
	
	sumaA=acomulaDivisores(a,1);
	sumaB=acomulaDivisores(b,1);
	
	if(sumaA==sumaB)
		return 1;
	else
		return 0;
}
	
short determinaTipoNumero(int n){
	int sumaN;
	
	sumaN=acomulaDivisores(n,2);
	if(sumaN<n)
		/*printf("\nEL NUMERO NATURAL %d ES DEFICIENTE",n);*/
		return 1;
	else if(sumaN>n)
		/*printf("\nEL NUMERO NATURAL %d ES ABUNDANTE",n);*/
		return 2;
	else
		/*printf("\nEL NUMERO NATURAL %d ES PERFECTO",n);*/
		return 3;
}
