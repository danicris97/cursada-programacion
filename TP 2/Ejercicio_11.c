#include <stdio.h>/*En windows se utiliza stdio.h y fflush*/
/*#include <stdio_ext.h> En linux se utiliza esta biblioteca que incluye __fpurge(stdin)*/

int ingresaNumNatural();
void muestraCantVocalesCons(int);

int main() {
	int num;
	
	num=ingresaNumNatural();
	muestraCantVocalesCons(num);
	
	return 0;
}

int ingresaNumNatural(){
	int n;
	
	do{
		printf("\nINGRESA LA CANTIDAD DE LETRAS DEL PARRAFO: ");
		scanf("%d",&n);
	} while(n<=0);
	
	return n;
}
	
char leeChar(){
	char letra;
	
	fflush(stdin);/*en windows funciona normalmente con stdio.h*/
	/*__fpurge(stdin);funciona en linux como fflush, se debe incluir stdio_ext.h*/
	printf("\nINGRESE LA LETRA: ");
	letra=getchar();

	return letra;
}
	
void muestraCantVocalesCons(int n){
	int i,cantV,cantC;
	char c;
	
	printf("\nINGRESE LA CADENA CARACTER POR CARACTER");
	
	cantV=0;cantC=0;
	
	for (i=1;i<=n;i++){
		c=leeChar();
		if(((c>=65)&&(c<=90))||((c>=97)&&(c<=122))){
			if((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u')||(c=='A')||(c=='E')||(c=='I')||(c=='O')||(c=='U'))
				cantV++;
			else
				cantC++;
		}
	}
	
	printf("\nLA CANTIDAD DE VOCALES ES: %d",cantV);
	printf("\nLA CANTIDAD DE CONSONANTES ES: %d",cantC);
}
	
