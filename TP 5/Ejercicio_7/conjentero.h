#ifndef CONJENTERO_H
#define CONJENTERO_H

typedef struct{
	int conjunto[250];
	int cardinal;
}conjentero;

conjentero iniciavacio();
void agregaentero(conjentero *, int);
void quitaentero(conjentero *, int);
void mostrarconj(conjentero);
conjentero unionconj(conjentero, conjentero);
conjentero interconj(conjentero, conjentero);
conjentero restaconj(conjentero, conjentero);

int getcardinal(conjentero);

#endif
