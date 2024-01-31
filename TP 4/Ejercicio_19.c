#include <stdio.h>
#define TMAX 130
#define TMAXA 1000

typedef char TCadena[TMAX];

typedef struct{
	TCadena nombre;
	TCadena apellido;
	TCadena direccion;
	long telefono;
}TContacto;

typedef TContacto listaContactos[TMAXA];

void agregarContacto(listaContactos,int*);
void eliminarContacto(listaContactos,int*,TCadena,TCadena);
void modificarContacto(listaContactos,int,TCadena,TCadena);
void mostrarContactoBuscado(listaContactos,int,TCadena,TCadena);
void mostrarAgenda(listaContactos,int);
short menu();

int main() {
	
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

TContacto crearContacto(){
	TContacto contacto;
	
	printf("\nINGRESE DATOS DEL CONTACTO...");
	printf("\nNOMBRE: ");
	leeCad(contacto.nombre,TMAX);
	
	printf("\nAPELLIDO: ");
	leeCad(contacto.apellido,TMAX);
	
	printf("\nDIRECCION: ");
	leeCad(contacto.direccion,TMAX);
	
	printf("\nTELEFONO: ");
	scanf("%ld",&contacto.telefono);
	
	return contacto;
}

void mostrarContacto(TContacto contacto){
	printf("\nDATOS DEL CONTACTO...");
	printf("\nNOMBRE: %s",contacto.nombre);
	printf("\nAPELLIDO: %s",contacto.apellido);
	printf("\nDIRECCION: %s",contacto.direccion);
	printf("\nTELEFONO: %ld",contacto.telefono);
}
	
short menu(){
	short op;
	
	do{
		printf("\n1. AGREGAR CONTACTO");
		printf("\n2. ELIMINAR CONTACTO");
		printf("\n3. MODIFICAR CONTACTO");
		printf("\n4. MOSTRAR CONTACTO");
		printf("\n5. MOSTRAR AGENDA");
		printf("\n0. SALIR");
		scanf("%hd",&op);
	}while(op<0 || op>5);
	
	return op;
}
short determinaMayor(TCadena cadena1, TCadena cadena2){
	int i,b;
		
	b=0;
	i=0;
	while(cadena1[i]!='\0' && cadena2[i]!='\0' && b==0){
		if(cadena1[i]<cadena2[i]){
			b=1;
		}else if(cadena1[i]>cadena2[i]){
			b=-1;
		}
		i++;
	}
		
	if(cadena1[i]=='\0'){
		b=1;
	}else if(cadena2[i]=='\0'){
		b=-1;
	}
		
	return b;
}
	
void ordenaListaContactos(listaContactos contactos, int tam){
	int i,j;
	TContacto aux;
	
	for(i=1;i<=tam-1;i++){
		for(j=i+1;j<=tam;j++){
			if(determinaMayor(contactos[j].apellido,contactos[i].apellido)==1){
				aux=contactos[j];
				contactos[j]=contactos[i];
				contactos[i]=aux;
			}else if(determinaMayor(contactos[j].nombre,contactos[i].nombre)==1) {
				aux=contactos[j];
				contactos[j]=contactos[i];
				contactos[i]=aux;
			}
		}
	}
}
	
short compareString(TCadena cadena1, TCadena cadena2){
	int i;
		
	i=0;
	while(cadena1[i]!='\0' && cadena2[i]!='\0' && cadena1[i]==cadena2[i]){
		i++;
	}
		
	if(cadena1[i]==cadena2[i]){
		return 1;
	}else{
		return 0;
	}
}

int buscarContacto(listaContactos contactos, int tam, TCadena nomb, TCadena apell){
	int ini,fin,med;
	ini=1;
	fin=tam;
	med=(ini+fin)/2;
	
	while((ini<fin)&&(compareString(contactos[med].apellido,apell)!=1||compareString(contactos[med].nombre,nomb)!=1)){
		if(determinaMayor(contactos[med].apellido,apell)==1){
			fin=med-1;
		}else{
			ini=med+1;
		}
		med=(ini+fin)/2;
	}
	
	if(ini<=tam){
		return med;
	}else{
		return -1;
	}
}
	
void agregarContacto(listaContactos contactos, int *tam){
	printf("\nAGREGA CONTACTO...");
	if(*tam<TMAXA){
		contactos[*tam+1] = crearContacto();
		*tam = *tam+1;
		ordenaListaContactos(contactos,*tam);
	}else{
		printf("\nTOPE MAXIMO DE CONTACTOS ALCANZADO 1000");
	}
}

void eliminarContacto(listaContactos contactos, int *tam, TCadena nombre, TCadena apellido){
	int pos,i;
	
	pos=buscarContacto(contactos,*tam,nombre,apellido);
	if(pos!=-1){
		for(i=pos;i<=*tam;i++){
			contactos[i]=contactos[i+1];
		}
		*tam=*tam-1;
	}else{
		printf("\nEL CONTACTO BUSCADO NO EXISTE");
	}
}
	
void modificarContacto(listaContactos contactos, int tam, TCadena nombre, TCadena apellido){
	int pos;

	pos=buscarContacto(contactos,tam,nombre,apellido);
	if(pos!=-1){
		contactos[pos]=crearContacto();
	}else{
		printf("\nEL CONTACTO BUSCADO NO EXISTE");
	}
}

void mostrarContactoBuscado(listaContactos contactos, int tam, TCadena nombre, TCadena apellido){
	int pos;
	
	pos=buscarContacto(contactos,tam,nombre,apellido);
	if(pos!=-1){
		mostrarContacto(contactos[pos]);
	}else{
		printf("\nEL CONTACTO BUSCADO NO EXISTE");
	}
}
	
void mostrarAgenda(listaContactos contactos, int tam){
	int i;
	
	if(tam<=TMAXA){
		for(i=1;i<=tam;i++){
			mostrarContacto(contactos[i]);
		}
	}else{
		printf("\nERROR");
	}
}
