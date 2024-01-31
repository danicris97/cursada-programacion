#include <stdio.h>
#include <stdlib.h>

#define TMAX 240

typedef char Cadena[TMAX];
typedef struct nodo{
	long dni;
	Cadena nombre;
	Cadena apellido;
	Cadena mail;
	char tipoAsistente;
	struct nodo* sig;
}TNodo;
typedef TNodo* TPtr;

void leeCad(Cadena, int);
TPtr cargarLista();
void muestraLista(TPtr);

int main() {
	TPtr lista;
	
	
	return 0;
}

void vaciabuffer(){
	int ch;
	while((ch=getchar())!='\n' && ch!=EOF);
}
	
void leeCad(Cadena cadena, int tam){
	int j,m;
		
	//INGRESA CADENA
	j=0;
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		cadena[j]=m;
		j++;
	}
	
	cadena[j]='\0';
		
	//LIMPIA BUFFER
	if(m!=EOF && m!='\n'){
		while((m=getchar())!=EOF && m!='n');
	}
}

void cargarElemento(TNodo *elemento){
	printf("\nIngrese el documento: ");
	scanf("%ld",&elemento->dni);
	
	vaciabuffer();
	printf("\nIngrese el nombre: ");
	leeCad(elemento->nombre,TMAX);
	
	vaciabuffer();
	printf("\nIngrese el apellido: ");
	leeCad(elemento->apellido,TMAX);
	
	vaciabuffer();
	printf("\nIngrese el correo: ");
	leeCad(elemento->mail,TMAX);
	
	vaciabuffer();
	printf("\nIngrese el tipo de asistente (char): ");
	scanf("%c",&elemento->tipoAsistente);
}

TPtr cargarLista(){
	int i,n;
	TNodo *x;
	TPtr list;
	
	list=NULL;
	printf("\nIngrese la cantidad de elementos: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		x=(TNodo *)malloc(sizeof(TNodo));
		cargarElemento(x);
		x->sig = list;
		list = x;
	}
	
	return list;
}

void muestraElemento(TNodo x){
	printf("\ndni: %ld",x.dni);
	printf("\nnombre: %s",x.nombre);
	printf("\napellido: %s",x.apellido);
	printf("\nmail: %s",x.mail);
	printf("\nTipo de asistente: %c",x.tipoAsistente);
}
		
void muestraLista(TPtr a){
	while(a!=NULL){
		muestraElemento(*a);
		a=a->sig;
	}
}
