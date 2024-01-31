#include <stdio.h>

int ingresarCantidad();
void calcularPromedio(int,int *,int *,int *);
void muestraResultados(int,int,int);

int main() {
	int n,mayor,menor,prom;
	
	n=ingresarCantidad();
	calcularPromedio(n,&mayor,&menor,&prom);
	muestraResultados(mayor,menor,prom);
	
	return 0;
}

int ingresarCantidad(){
	int c;
	
	printf("\nINGRESE LA CANTIDAD TOTAL DE DEPORTISTAS: ");
	scanf("%d",&c);
	
	return c;
}

void edadMenor(int *men, int i, int edad){
	if(i!=1){
		if(edad<*men)
			*men=edad;
	}
	else
	   *men=edad;
}

void edadMayor(int *may, int i, int edad){
	if(i!=1){
		if(edad>*may)
			*may=edad;
	}
	else
	   *may=edad;
}
	
void calcularPromedio(int n, int *may, int *men, int *promedio){
	int edad,i,acu;
	
	acu=0;
	
	for (i=1;i<=n;i++){
		do{
			printf("\nINGRESE LA EDAD DEL DEPORTISTA (MAYOR DE 3): ");
			scanf("%d",&edad);
		}while(edad<=3);
			
		edadMenor(men,i,edad);
		edadMayor(may,i,edad);
		
		acu=acu+edad;
	}
	
	*promedio=(acu/n);
}
	
void muestraResultados(int mayor, int menor, int prom){
	printf("\nLA EDAD MAYOR INGRESADA ES: %d",mayor);
	printf("\nLA EDAD MENOR INGRESADA ES: %d",menor);
	printf("\nEL PROMEDIO DE EDAD ES: %d",prom);
}
