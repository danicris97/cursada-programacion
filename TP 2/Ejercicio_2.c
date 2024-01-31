#include <stdio.h>

int ingresoseg(void);
void muestrahms(int);

int main() {
	muestrahms(ingresoseg());
	
	return 0;
}

int ingresoseg(){
	int s;
	
	do{
		printf("INGRESE LA CANTIDAD DE SEGUNDOS: ");
		scanf("%d",&s);
	}while(s<0);
	
	return s;
}

void muestrahms(int segundos){
	int h,m,s;
	
	m = segundos/60;
	h = m/60;
	m = m%60;
	s = segundos%60;
	
	printf("\nHORAS: %d",h);
	printf("\nMINUTOS: %d",m);
	printf("\nSEGUNDOS: %d",s);
}

