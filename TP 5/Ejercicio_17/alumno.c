#include "alumno.h"
#include <stdio.h>

void iniciaAlumno(TAlumno *alumno){
	cadenaVacia(alumno->nombre);
	cadenaVacia(alumno->apellido);
	alumno->dni=0;
	alumno->lu=0;
	cadenaVacia(alumno->carrera);
	alumno->tipo=5;
	alumno->cantidadMaterias=1;
	alumno->notas[1]=0;
}
	
void cargaAlumno(TAlumno *alumno){
	printf("\nINGRESE DATOS...");
	printf("\nNOMBRE: ");
	leeCad(alumno->nombre);
	printf("\nAPELLIDO: ");
	leeCad(alumno->apellido);
	printf("\nDNI: ");
	scanf("%ld",&alumno->dni);
	printf("\nLU: ");
	scanf("%ld",&alumno->lu);
	printf("\nCARRERA: ");
	leeCad(alumno->carrera);
	do{
		printf("\nTIPO DE CARRERA (0 tec, 1 lic, 2 ing): ");
		scanf("%d",&alumno->tipo);
	}while(alumno->tipo<0 || alumno->tipo>2);
	if(alumno->tipo == 0){
		alumno->cantidadMaterias=17;
	}else if(alumno->tipo == 1){
		alumno->cantidadMaterias=25;
	}else{
		alumno->cantidadMaterias=30;
	}
	cargarNotas(alumno);
}
	
void cargarNotas(TAlumno *alumno){
	int n,i;
	
	for(i=1;i<=alumno->cantidadMaterias;i++){
		alumno->notas[i]=-1;
	}
	
	printf("\nINGRESE LAS NOTAS...");
	do{
		printf("\nINGRESE LA CANTIDAD DE NOTAS: ");
		scanf("%d",&n);
	} while(n>0 || n<alumno->cantidadMaterias);
	
	for(i=1;i<=alumno->cantidadMaterias;i++){
		do{
			printf("\nINGRESE NOTA: ");
			scanf("%d",&alumno->notas[i]);
		}while(alumno->notas[i]<0 || alumno->notas[i]>100);
	}
}
	
void cargarNota(TAlumno *alumno, int materia, int nota)	{
	if(materia>0 && materia<=alumno->cantidadMaterias){
		if(nota>=0 && nota<=100){
			alumno->notas[materia]=nota;
		}else{
			printf("\nERROR: NOTA NO VALIDA");
		}
	}else{
		printf("\nERROR: MATERIA NO EXISTENTE");
	}
}

void mostrarNotas(int notas[], int cantidad){
	int i;
	
	for(i=1;i<=cantidad;i++){
		if(notas[i]!=-1)
			printf("\nMATERIA %d: %d",i,notas[i]);
	}
}

void muestraAlumno(TAlumno alumno){
	printf("\nDATOS...");
	printf("\nNOMBRE: %s",alumno.nombre);
	printf("\nAPELLIDO: %s",alumno.apellido);
	printf("\nDNI: %ld",alumno.dni);
	printf("\nLU: %ld",alumno.lu);
	printf("\nCARRERA: %s",alumno.carrera);
	printf("\nNOTAS... ");
	mostrarNotas(alumno.notas,alumno.cantidadMaterias);
}

int comparaAlumno(TAlumno alumno1, TAlumno alumno2){
	if(alumno1.lu==alumno2.lu){
		return 1;
	}else{
		return 0;
	}
}
