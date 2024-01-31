#include <stdio.h>
#define TMAX 130
//DEFINICION DEL TIPO CADENA
typedef char TCadena[TMAX];

//DEFINICION DE PROTOTIPOS
void leeCad(TCadena,int);
short determinaMayor(TCadena,TCadena);
int cantidadCaracteres(TCadena);
void copyCadena(TCadena,TCadena);

int main() {
	TCadena cadena1,cadena2,cadena3;
	
	printf("INGRESE LA PRIMERA CADENA: ");
	leeCad(cadena1,TMAX);
	printf("\nCADENA INGRESADA: %s",cadena1);
	
	printf("\nINGRESE LA SEGUNDA CADENA: ");
	leeCad(cadena2,TMAX);
	printf("\nCADENA INGRESADA: %s",cadena2);
	
	if(determinaMayor(cadena1,cadena2)==1){
		printf("\n%s ES MAYOR ALFABETICAMENTE A %s",cadena1,cadena2);
	}else if(determinaMayor(cadena1,cadena2)==-1){
		printf("\n%s ES MAYOR ALFABETICAMENTE A %s",cadena2,cadena1);
	}else{
		printf("\nLAS CADENAS SON IGUALES: %s , %s",cadena1,cadena2);
	}
	
	printf("\nLA CANTIDAD DE CARACTERES DE %s ES: %d",cadena1, cantidadCaracteres(cadena1));
	printf("\nLA CANTIDAD DE CARACTERES DE %s ES: %d",cadena2, cantidadCaracteres(cadena2));
	
	copyCadena(cadena1,cadena3);
	printf("\nCOPIA: %s",cadena3);
	
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

int cantidadCaracteres(TCadena cadena){
	int contador;
	
	contador=0;
	while(cadena[contador]!='\0'){
		contador++;
	}
	
	return contador;
}
	
void copyCadena(TCadena cadenaOriginal, TCadena cadenaCopia){
	int i;
	
	i=0;
	while(cadenaOriginal[i]!='\0'){
		cadenaCopia[i]=cadenaOriginal[i];
		i++;
	}
	
	cadenaCopia[i]='\0';
}
