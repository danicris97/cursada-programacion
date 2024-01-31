#include "persona.h"
#include "cadena_interfaz.h"
#include <stdio.h>

void iniciaPersona(TPersona *persona){
	cadenaVacia(persona->nombre);
	cadenaVacia(persona->apellido);
	persona->dni=0;
	cadenaVacia(persona->domicilio);
	cadenaVacia(persona->numeroCelular);
	cadenaVacia(persona->email);
}
	
void cargarPersona(TPersona *persona){
	printf("\nINGRESE DATOS DE LA PERSONA...");
	printf("\nNOMBRE: ");
	leeCad(persona->nombre);
	printf("\nAPELLIDO: ");
	leeCad(persona->apellido);
	printf("\nDNI: ");
	scanf("%ld",persona->dni);
	printf("\nDOMICILIO: ");
	leeCad(persona->domicilio);
	printf("\nNUMERO CELULAR: ");
	leeCad(persona->numeroCelular);
	printf("\nEMAIL: ");
	leeCad(persona->email);
}
	
int comparaPersona(TPersona persona1, TPersona persona2){
	if(comparaCadena(persona1.nombre,persona2.nombre)==1){
		if(comparaCadena(persona1.apellido,persona2.apellido)==1){
			if(persona1.dni == persona2.dni){
				if(comparaCadena(persona1.domicilio,persona2.domicilio)==1){
					if(comparaCadena(persona1.numeroCelular,persona2.numeroCelular)==1){
						if(comparaCadena(persona1.email,persona2.email)==1){
							return 1;
						}else{
							return 0;
						}
					}else{
						return 0;
					}
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}
	
long getDniPersona(TPersona persona){
	return persona.dni;
}
	
void getApellido(TPersona persona, TCadena resultado){
	copiaCadena(persona.apellido,resultado);
}
	
void getNombre(TPersona persona, TCadena resultado){
	copiaCadena(persona.nombre,resultado);
}
	
void getDomicilio(TPersona persona, TCadena resultado){
	copiaCadena(persona.domicilio,resultado);
}

void getNumeroCelular(TPersona persona, TCadena resultado){
	copiaCadena(persona.numeroCelular,resultado);
}

void getEmail(TPersona persona, TCadena resultado){
	copiaCadena(persona.email,resultado);
}
	
void mostrarPersona(TPersona persona){
	printf("\nDATOS...");
	printf("\nNOMBRE: %s",persona.nombre);
	printf("\nAPELLIDO: %s",persona.apellido);
	printf("\nDNI: %ld",persona.dni);
	printf("\nDOMICILIO: %s",persona.domicilio);
	printf("\nNUMERO CELULAR: %s",persona.numeroCelular);
	printf("\nEMAIL: %s",persona.email);
}
