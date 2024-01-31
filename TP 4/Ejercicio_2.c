#include <stdio.h>
/*#include <stdio_ext.h> EN LINUX*/
#define TMAX 1000

int ingresaCantidadChar();
void cargaLista(char[], int);
void ordenaDeMenorAMayor(char[], int);
int buscarCaracter(char, char[], int);
void insertarCaracter(char, char[], int *);
char ingresaCaracter();
void muestraVector(char[], int);
void muestraVectorSinVocales(char[], int);

int main() {
	int cantChar,pos;
	char cadena[TMAX];
	
	cantChar=ingresaCantidadChar();
	cargaLista(cadena,cantChar);
	muestraVector(cadena,cantChar);
	ordenaDeMenorAMayor(cadena,cantChar);
	muestraVector(cadena,cantChar);
	pos=buscarCaracter(ingresaCaracter(),cadena,cantChar);
	//
	if(pos!=-1)
		printf("\nEL CARACTER SI SE ENCUENTRA EN EL VECTOR EN POSICION: %d",pos);
	else
		printf("\nEL CARACTER BUSCADO NO ESTA EN EL VECTOR");
	//
	insertarCaracter(ingresaCaracter(),cadena,&cantChar);
	muestraVector(cadena,cantChar);
	ordenaDeMenorAMayor(cadena,cantChar);
	muestraVector(cadena,cantChar);
	muestraVectorSinVocales(cadena,cantChar);
	
	return 0;
}

int ingresaCantidadChar(){
	int n;
	
	printf("INGRESE LA CANTIDAD DE CARACTERS DE LA CADENA: ");
	scanf("%d",&n);
	
	return n;
}

/*void cargaLista(char cadena[], int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		//fflush(stdin);
		//__fpurge(stdin);(EN LINUX)
		printf("INGRESE UN CARACTER DE LA CADENA: ");
		cadena[i]=getchar();
	}
}*/
	
void vaciabuffer(){
	int ch;
	while((ch=getchar())!='\n' && ch!=EOF);
}

char ingresaCaracter(){
	//char c;
	vaciabuffer();
	printf("\nINGRESE UN CARACTER: ");
	
	return getchar();
}
	
	
void cargaLista(char cadena[], int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		vaciabuffer();
		printf("INGRESE UN CARACTER DE LA CADENA: ");
		cadena[i] = getchar();
	}
}

void muestraVector(char cadena[], int tam){
	int i;
	
	printf("\nCADENA: ");
	for(i=1;i<=tam;i++){
		printf("%c",cadena[i]);
	}
}

void ordenaDeMenorAMayor(char cadena[], int tam){
	int i,j;
	char aux;
	
	for(i=1;i<tam;i++){
		for(j=i+1;j<=tam;j++){
			if(cadena[j]<cadena[i]){
				aux=cadena[j];
				cadena[j]=cadena[i];
				cadena[i]=aux;
			}
		}
	}
}
	
int buscarCaracter(char ch, char cadena[], int tam){
	int pos=1;
	
	while((pos<=tam)&&(cadena[pos]!=ch)){
		pos++;
	}
	if(pos<=tam)
		return pos;
	else
		return -1;
}

void insertarCaracter(char ch, char cadena[], int *tam){
	if(*tam<=TMAX){
		cadena[*tam+1] = ch;
		*tam = *tam+1;
	}else
	   printf("\nERROR: LIMITE SUPERADO");
}

void muestraVectorSinVocales(char cadena[], int tam){
	int i;
	
	printf("\nCADENA SIN VOCALES: ");
	for(i=1;i<=tam;i++){
		if((cadena[i]!='A')&&(cadena[i]!='E')&&(cadena[i]!='I')&&(cadena[i]!='O')&&(cadena[i]!='U')&&(cadena[i]!='a')&&(cadena[i]!='e')&&(cadena[i]!='i')&&(cadena[i]!='o')&&(cadena[i]!='u')){
			printf("%c",cadena[i]);
		}
	}
}
