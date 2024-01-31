#ifndef CONJUNTOCHAR_INTERFAZ_H
#define CONJUNTOCHAR_INTERFAZ_H
#define TMAX 255

typedef char conjuntochar[TMAX];

void iniciarVacio(conjuntochar);
void agregarCaracter(conjuntochar,char);
void eliminarCaracter(conjuntochar,char);
void mostrarConjuntochar(conjuntochar);
void unionConjuntochar(conjuntochar,conjuntochar,conjuntochar);
void interseccionConjuntochar(conjuntochar,conjuntochar,conjuntochar);
void restaConjuntochar(conjuntochar,conjuntochar,conjuntochar);
int cantidadCaracteres(conjuntochar);
int existeCaracter(conjuntochar,char);

#endif
