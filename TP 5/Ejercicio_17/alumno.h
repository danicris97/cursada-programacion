#ifndef ALUMNO_H
#define ALUMNO_H

#define CMMAX 70

#include "cadena_interfaz.h"

typedef struct{
	TCadena nombre;
	TCadena apellido;
	long dni;
	long lu;
	TCadena carrera;
	int cantidadMaterias;
	int tipo;
	int notas[CMMAX];
}TAlumno;

void iniciaAlumno(TAlumno *);
void cargaAlumno(TAlumno *);
void muestraAlumno(TAlumno);
int comparaAlumno(TAlumno,TAlumno);
void cargarNotas(TAlumno *);
void cargarNota(TAlumno *, int, int);

#endif
