#include <stdio.h>
#include <math.h>

void calculaCercanoOrigen(float *, float *);

int main() {
	float x,y;
	
	calculaCercanoOrigen(&x,&y);
	printf("\nEL PUNTO MAS CERCANO AL ORIGEN ES: (%f,%f)",x,y);
	
	return 0;
}
	
void ingresaPunto(float *x, float *y){
	printf("\nINGRESE EL VALOR X: ");
	scanf("%f",x);

	printf("\nINGRESE EL VALOR Y: ");
	scanf("%f",y);
}

float calculaDistancia(float x, float y){return sqrt(pow(x,2)+pow(y,2));}
	
void calculaCercanoOrigen(float *x, float *y){
	float xx,yy,dis,men;
	
	printf("\nINGRESE LOS PUNTOS DEL PLANO; PRIMERO EL VALOR X, DESPUES EL VALOR Y");
	printf("\nPARA DETENER EL INGRESO UTILICE EL ORIGEN COMO VALOR DE ENTRADA");

	ingresaPunto(&xx,&yy);
	men=calculaDistancia(xx,yy);
	
	while((xx!=0)||(yy!=0)){
		dis=calculaDistancia(xx,yy);
		if(dis<=men){
			men=dis;
			*x=xx;
			*y=yy;
		}
		ingresaPunto(&xx,&yy);
	}
}
