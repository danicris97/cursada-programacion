#ifndef CONJCAR_H
#define CONJCAR_H

typedef char conjcar[255];

void iniciarVacio(conjcar);
void agregarCaracter(conjcar, char);
void quitarCaracter(conjcar, char);
void mostrarConjunto(conjcar);
void unionConjunto(conjcar, conjcar, conjcar);
void interConjunto(conjcar, conjcar, conjcar);
void restaConjunto(conjcar, conjcar, conjcar);

#endif
