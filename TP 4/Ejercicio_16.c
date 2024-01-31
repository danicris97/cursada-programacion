#include <stdio.h>
#include <stdlib.h>

typedef char cadena60[60];
typedef struct	{
	cadena60 artista;
	cadena60 titulo;
	int duracion;
} mp3;
typedef struct {
	int minutos;
	int segundos;
}tiempo;
typedef struct {
	cadena60 ARTISTA;
	cadena60 TITULO;
	tiempo DURACION;
}MP3;

short menu();
void leeCad(char *, int);
void carga(mp3*);
void cargaMP3(MP3*);
void muestra(mp3);
void muestraMP3(MP3);
void modifica(mp3*);

int main() {
	mp3 musica;
	MP3 mus;
	short opcion;
	
	do{
		/*WINDOWS: */system ("CLS");/*LINUX: system("clear")*/
		opcion=menu();
		switch (opcion){
		case 1: carga(&musica);
				muestra(musica);
				modifica(&musica);
				muestra(musica);
				break;
		case 2: cargaMP3(&mus);
				muestraMP3(mus);
				break;
		}
		
		system ("PAUSE");
	} while(opcion!=0);
	
	
	return 0;
}

short menu(){
	short op;
	
	do{
		printf("\n1- EJERCICIO 16 INCISO A");
		printf("\n2- EJERCICIO 16 INCISO B");
		printf("\n0- SALIR");
		printf("\nINGRESE OPCION: ");
		scanf("%hd",&op);
	} while(op<0||op>2);
	
	return op;
}
void leeCad(char *cadena, int tam){
	int j,m;
	j=0;
	
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		cadena[j]=m;
		j++;
	}
	cadena[j]='\0';
	
	if (m!=EOF && m!='\n')
		while((m=getchar())!=EOF&&m!='\n');
}

void carga(mp3 *m){
	fflush(stdin);
	printf("Ingrese el artista de la musica: ");
	leeCad(m->artista,60);
	fflush(stdin);
	printf("\nIngrese el nombre de la musica: ");
	leeCad(m->titulo,60);
	printf("\nIngrese la duracion del tema: ");
	scanf("%d",&m->duracion);
}

void muestra(mp3 m){
	printf("\nArtista: %s",m.artista);
	printf("\nTitulo: %s",m.titulo);
	printf("\nDuracion: %d\n",m.duracion);
}

void modifica(mp3 *m){
	printf("\nIngrese de nuevo la duracion del tema: ");
	scanf("%d",&m->duracion);
}
void cargaMP3(MP3 *mus){
	fflush(stdin);
	printf("Ingrese el artista de la musica: ");
	leeCad(mus->ARTISTA,60);
	fflush(stdin);
	printf("\nIngrese el nombre de la musica: ");
	leeCad(mus->TITULO,60);
	do{
		printf("\nIngrese la duracion del tema(segundos): ");
		scanf("%d",&mus->DURACION.segundos);
	}while(mus->DURACION.segundos>60);
	printf("\nIngrese la duracion del tema(minutos): ");
	scanf("%d",&mus->DURACION.minutos);
}

void muestraMP3(MP3 mus){
	printf("\nArtista: %s",mus.ARTISTA);
	printf("\nTitulo: %s",mus.TITULO);
	printf("\nDuracion: %d:%d\n",mus.DURACION.minutos,mus.DURACION.segundos);
}
