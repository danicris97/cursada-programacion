#ifndef ANGULO_H
#define ANGULO_H

typedef struct{
	int angulo;
	int minuto;
	int segundo;
}TAngulo;

TAngulo crearAngulo();
void cargarAngulo(TAngulo *);
TAngulo sumarAngulo(TAngulo,TAngulo);
TAngulo restarAngulo(TAngulo,TAngulo);
long convertirASegundos(TAngulo);
TAngulo convertirAAngulo(long);
void mostrarAngulo(TAngulo);

#endif
