#ifndef PERSONA_H
#define PERSONA_H

#include "cadena_interfaz.h"

typedef struct{
	TCadena nombre;
	TCadena apellido;
	long dni;
	TCadena domicilio;
	TCadena numeroCelular;
	TCadena email;
}TPersona;

void iniciaPersona(TPersona*);
void cargarPersona(TPersona*);
void mostrarPersona(TPersona);
int comparaPersona(TPersona,TPersona);
long getDniPersona(TPersona);
void getNombre(TPersona,TCadena);
void getApellido(TPersona,TCadena);
void getDomicilio(TPersona,TCadena);
void getNumeroCelular(TPersona,TCadena);
void getEmail(TPersona,TCadena);

#endif
