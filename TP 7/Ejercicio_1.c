#include <stdio.h>
#include <stdlib.h>
#define TMAX 240

typedef char TCadena[TMAX];
typedef struct nodo{
	int idFabricante;
	TCadena nombre;
	int cantidad;
	float precioUnitario;
	struct nodo *sig;
}TNodo;
typedef TNodo* TPtr;

void leeCad(TCadena,int);
TPtr cargarLista();
void muestraLista(TPtr);

int main() {
	TPtr lista;
	
	lista=cargarLista();
	muestraLista(lista);
	
	return 0;
}

void vaciabuffer(){
	int ch;
	while((ch=getchar())!='\n' && ch!=EOF);
}
	
void leeCad(TCadena cadena, int tam){
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

void cargaElemento(TNodo *x){
	printf("\nINGRESE ID DE FABRICANTE: ");
	scanf("%d",&x->idFabricante);
	
	fflush(stdin);
	printf("\nINGRESE EL NOMBRE DEL FABRICANTE: ");
	leeCad(x->nombre,TMAX);
	
	printf("\nINGRESE CANTIDAD: ");
	scanf("%d",&x->cantidad);
	
	printf("\nINGRESE PRECIO UNITARIO: ");
	scanf("%f",&x->precioUnitario);
}
	
TPtr cargarLista(){
	int i,n;
	TNodo *x;
	TPtr lis;
	
	lis=NULL;
	printf("\nINGRESE LA CANTIDAD DE ELEMENTOS: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		x=(TNodo*)malloc(sizeof(TNodo));
		cargaElemento(x);
		x->sig=lis;
		lis=x;
	}
	
	return lis;
}
	
void muestraElemento(TNodo x){
	printf("\nID: %d",x.idFabricante);
	printf("\nNOMBRE: %s",x.nombre);
	printf("\nCANTIDAD: %d",x.cantidad);
	printf("\nPRECIO UNITARIO: %.2f",x.precioUnitario);
}

void muestraLista(TPtr a){
	while(a!=NULL){
		muestraElemento(*a);
		a=a->sig;
	}
}
