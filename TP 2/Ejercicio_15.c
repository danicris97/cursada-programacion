#include <stdio.h> /*para windows*/
/*#include <stdio_ext.h> *//*para linux*/

int ingresaNat();
void ingresaCadena(int ,int *);

int main() {
	int n,cant;
	
	cant=0;
	n=ingresaNat();
	ingresaCadena(n,&cant);
	printf("\nLA CANTIDAD DE NUMEROS NATURALES EN EL PARRAFO ES: %d",cant);
	
	return 0;
}

int ingresaNat(){
	int n;
	
	do{
		printf("\nINGRESA NUMERO NATURAL: ");
		scanf("%d",&n);
	} while(n<=0);
	
	return n;
}
	
char leeChar(){
	char letra;
	
	fflush(stdin);/*solo en windows*/
	/*__fpurge(stdin);*//*solo en linux*/
	printf("\nINGRESE UN CARACTER: ");
	letra=getchar();
	
	return letra;
}
	
void ingresaCadena(int n, int *cant){
	int i;
	char c;
	
	for (i=1;i<=n;i++){
		c=leeChar();
		if((c>=48)&&(c<=57))
			*cant=*cant+1;
	}
}
