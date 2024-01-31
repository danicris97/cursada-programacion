#include <stdio.h>
#include <math.h>
#define TMAX 15

typedef char TCadena[TMAX];
void leeCad(TCadena,int);
void convertirALong(TCadena,long*,long*);

int main() {
	TCadena numeroCel;
	long codigoArea, numeroCelular;
	
	printf("INGRESE EL NUMERO DE CELULAR (MAX 13 DIGITOS): ");
	leeCad(numeroCel,TMAX);
	
	codigoArea=0;
	numeroCelular=0;
	convertirALong(numeroCel,&codigoArea,&numeroCelular);
	printf("\nCODIGO DE AREA: %ld",codigoArea);
	printf("\nNUMERO DE TELEFONO: %ld",numeroCelular);
	
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

void convertirALong(TCadena cadena, long *codigoArea, long *numeroTelefono){
	int i,dig;
	
	for(i=0;i<=5;i++){
		dig = cadena[i] - 48;
		*codigoArea = *codigoArea *10 + dig;
	}
	
	for(i=6;i<=13;i++){
		dig = cadena[i] - 48;
		*numeroTelefono = *numeroTelefono *10 + dig;
	}
}
