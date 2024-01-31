#include "angulo.h"
#include <stdio.h>
#include <math.h>

TAngulo crearAngulo(){
	TAngulo angulo;
	
	angulo.angulo=0;
	angulo.minuto=0;
	angulo.segundo=0;
	
	return angulo;
}
	
void cargarAngulo(TAngulo *angulo){
	int n;
	
	printf("\nINGRESA EL ANGULO EN FORMATO ANGULO - MINUTOS - SEGUNDOS ...");
	do{
		printf("\nANGULO: ");
		scanf("%d",&n);
	}while(n<=0 && n>=360);
	angulo->angulo=n;
	
	do{
		printf("\nMINUTOS: ");
		scanf("%d",&n);
	}while(n<=0 && n>=60);
	angulo->angulo=n;
	
	do{
		printf("\nSEGUNDOS: ");
		scanf("%d",&n);
	}while(n<=0 && n>=60);
	angulo->angulo=n;
}

TAngulo sumarAngulo(TAngulo anguloA, TAngulo anguloB){
	TAngulo resultado;
	int aux;
	
	resultado=crearAngulo();
	
	resultado.segundo = anguloA.segundo + anguloB.segundo;
	if(resultado.segundo>=60){
		resultado.minuto = resultado.segundo/60;
		resultado.angulo = resultado.minuto/60;
		resultado.minuto = resultado.minuto%60;
		resultado.segundo = resultado.segundo%60;
	}
	
	resultado.minuto = resultado.minuto + anguloA.minuto + anguloB.minuto;
	if(resultado.minuto>=60){
		aux=resultado.angulo;
		resultado.angulo = resultado.minuto/60;
		resultado.minuto = resultado.minuto%60;
		resultado.angulo = resultado.angulo + aux;
	}
	resultado.angulo = resultado.angulo + anguloA.angulo + anguloB.angulo;
	
	return resultado;
}
	
TAngulo restarAngulo(TAngulo anguloA, TAngulo anguloB){
	TAngulo resultado;
	
	resultado.segundo = abs(anguloA.segundo - anguloB.segundo);
	resultado.minuto = abs(anguloA.minuto - anguloB.minuto);
	resultado.angulo = abs(anguloA.angulo - anguloB.angulo);
	
	return resultado;
}
	
long convertirASegundos(TAngulo angulo){
	return ((angulo.angulo*3600) + (angulo.minuto*60) + angulo.segundo);
}
	
TAngulo convertirAAngulo(long segundos){
	TAngulo angulo;
	int a,m,s;
	
	m = segundos/60;
	a = m/60;
	m = m%60;
	s = segundos%60;
	
	angulo.segundo=s;
	angulo.minuto=m;
	angulo.angulo=a;
	
	return angulo;
}
	
void mostrarAngulo(TAngulo angulo){
	printf("\nANGULO: %d",angulo.angulo);
	printf("\nMINUTO: %d",angulo.minuto);
	printf("\nSEGUNDO: %d",angulo.segundo);
}
