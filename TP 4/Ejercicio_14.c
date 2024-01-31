#include <stdio.h>
#include <math.h>

typedef struct {
	float x;
	float y;
}TPunto;

float ingresaReal();
TPunto cargaPunto();
void mostrarTPunto(TPunto);
void modificarTPunto(TPunto*,float,float);
float distanciaDosPuntos(TPunto,TPunto);
void intercambiaPuntos(TPunto*,TPunto*);

int main() {
	TPunto a,b;
	
	a = cargaPunto();
	mostrarTPunto(a);
	printf("\nPunto modificado...");
	modificarTPunto(&a,a.x,8);
	b = cargaPunto();
	printf("\nDistancia entre puntos: %f",distanciaDosPuntos(a,b));
	intercambiaPuntos(&a,&b);
	
	return 0;
}

float ingresaReal(){
	float r;
	
	printf("\nINGRESE NUMERO REAL: ");
	scanf("%f",&r);
	
	return r;
}

TPunto cargaPunto(){
	TPunto punto;
	
	printf("\nINGRESE NUMERO X...");
	punto.x = ingresaReal();
	
	printf("\nINGRESE NUMERO Y...");
	punto.y = ingresaReal();
	
	return punto;
}

void mostrarTPunto(TPunto punto){
	printf("\nVALOR DEL PUNTO: (%f,%f)",punto.x,punto.y);
}
	
void modificarTPunto(TPunto *punto, float a, float b){
	punto->x = a;
	punto->y = b;
	mostrarTPunto(*punto);
}

float distanciaDosPuntos(TPunto A, TPunto B){
	return sqrt(pow((B.x - A.x),2) + pow((B.y - A.y),2));
}
	
void intercambiaPuntos(TPunto *a, TPunto *b){
	TPunto aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
