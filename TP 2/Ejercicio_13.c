#include <stdio.h>

void detCapicuaLista(int *);

int main() {
	int cont;
	
	cont=0;
	detCapicuaLista(&cont);
	printf("\nLA CANTIDAD DE NUMEROS CAPICUAS ES: %d",cont);
	
	return 0;
}

int ingresaNum(){
	int n;
	
	printf("\nINGRESA UN NUMERO NATURAL: ");
	scanf("%d",&n);
	
	return n;
}

short detCapicua(int num){
	int inver,dig,aux;
	aux=num;
	inver=0;
	
	while(num!=0){
		dig=num%10;
		inver=(inver*10)+dig;
		num=num/10;
	}
	
	if(aux==inver)
		return 1;
	else
		return 0;
}
	
short digitosImpares(int n){
	int d,b;
	b=1;
	
	while((n!=0)&&(b==1)){
		d=n%10;
		if((d==1)||(d==3)||(d==5)||(d==7)||(d==9))
			b=1;
		else
			b=0;
		n=n/10;
	}
	
	if(b==1)
		return 1;
	else
		return 0;
}
	
void detCapicuaLista(int *c){
	int n;
	
	printf("\nPARA DETENER EL INGRESO DEBE INGRESAR UN NUMERO NEGATIVO O 0");
	n=ingresaNum();
	b=0;
	
	while(n>0){
		if(detCapicua(n)==1){
			*c=*c+1;
			if(digitosImpares(n)==1)
				printf("%d ",n);
		}
		n=ingresaNum();
	}
}
