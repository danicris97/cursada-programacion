#include <stdio.h>
#include "cadena_interfaz.h"

void vaciabuffer(){
	int ch;
	while((ch=getchar())!='\n' && ch!=EOF);
}
	
void leeCad(TCadena cadena){
	int j,m,tam;
	tam = TMAX;
		
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
	
void cadenaVacia(TCadena cadena){
	cadena[0]='\0';
}
	
void insertaCaracter(TCadena cadena, char caracter){
	int cant;
	
	cant=cantidadCaracteres(cadena);
	if(cant<TMAX){
		cadena[cant]=caracter;
		cadena[cant+1]='\0';
	}else{
		printf("\nLA LONGITUD DE LA CADENA SUPERA LA CANTIDAD MAXIMA");
	}
}
	
void eliminaCaracter(TCadena cadena, char caracter){
	if(buscaCaracter(cadena,caracter)!=-1){
		int i,j,tam;
		tam=cantidadCaracteres(cadena);
		
		i=0;
		while(cadena[i]!='\0'){
			while(cadena[i]!=caracter && cadena[i]!='\0'){
				i++;
			}
			for(j=i;j<tam-1;j++){
				cadena[j]=cadena[j+1];
			}
			tam--;
		}
		
	}else{
		printf("EL CARACTER QUE QUIERE ELIMINAR NO ESTA EN LA CADENA");
	}
}
	
void remplazaCaracter(TCadena cadena, char caracter, char caraterRemplazo){
	if(buscaCaracter(cadena,caracter)!=-1){
		int i;
			
		i=0;
		while(cadena[i]!='\0'){
			while(cadena[i]!=caracter && cadena[i]!='\0'){
				i++;
			}
			cadena[i]=caraterRemplazo;
		}
			
	}else{
		printf("EL CARACTER QUE QUIERE REEMPLAZAR NO ESTA EN LA CADENA");
	}
}
	
void copiaCadena(TCadena cadenaOriginal, TCadena cadenaCopia){
	int i;
	
	i=0;
	while(cadenaOriginal[i]!='\0'){
		cadenaCopia[i]=cadenaOriginal[i];
		i++;
	}
	cadenaCopia[i]='\0';
}
	
void concantenacion(TCadena cadenaA, TCadena cadenaB, TCadena cadenaResultado){
	int i,j;
	
	copiaCadena(cadenaA,cadenaResultado);
	i=cantidadCaracteres(cadenaResultado);
	if(i<TMAX){
		j=0;
		while(cadenaB[j]!='\0' && i<TMAX){
			cadenaResultado[i]=cadenaB[j];
			j++;
			i++;
		}
		cadenaResultado[i]='\0';
	}
}
	
void interseccionCadena(TCadena cadenaA, TCadena cadenaB, TCadena cadenaResultado){
	int i,j;
	
	i=0;
	j=0;
	while(cadenaA[i]!='\0' && cadenaB[i]!='\0'){
		if(cadenaA[i]==cadenaB[i]){
			cadenaResultado[j]=cadenaA[i];
			j++;
		}
		i++;
	}
	cadenaResultado[j]='\0';
	
/*	if(cantidadCaracteres(cadenaResultado)==0)*/
/*		printf("INTERSECCION VACIA");*/
}
	
void diferenciaCadena(TCadena cadenaA, TCadena cadenaB, TCadena cadenaResultado){
	int i,j;
	
	i=0;
	j=0;
	while(cadenaA[i]!='\0' && cadenaB[i]!='\0'){
		if(buscaCaracter(cadenaB,cadenaA[i])==-1){
			cadenaResultado[j]=cadenaA[i];
			j++;
		}
		i++;
	}
	cadenaResultado[j]='\0';
}
	
int comparaCadena(TCadena cadenaA, TCadena cadenaB){
	if(cantidadCaracteres(cadenaA)==cantidadCaracteres(cadenaB)){
		int i;
		
		i=0;
		while(cadenaA[i]==cadenaB[i]){
			i++;
		}
		
		if(i==cantidadCaracteres(cadenaA)){
			return 1;
		}else
			return 0;
		
	}else{
		return 0;
	}
}
	
int determinaMayor(TCadena cadena1, TCadena cadena2){
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

int buscaCaracter(TCadena cadena, char caracter){
	int i;
	
	i=0;
	while(cadena[i]!=caracter && cadena[i]!='\0'){
		i++;
	}
	
	if(cadena[i]!='\0'){
		return i;
	}else{
		return -1;
	}
}
	
int cantidadCaracteres(TCadena cadena){
	int i;
	
	i=0;
	while(cadena[i]!='\0'){
		i++;
	}
	
	return i;
}
	
int cantidadPalabras(TCadena cadena){
	int i,c;
		
	c=0;
	i=0;
	while(cadena[i]!='\0'){
		if(cadena[i]==32){
			if(i!=0){
				c++;
			}else if(cadena[i-1]!=32){
				c++;
			}
		}
		i++;
	}
		
	return c;
}
	
char caracterMasRepetido(TCadena cadena){
	char caracteres[TMAX];
	int cantidad[TMAX];
	int i,j,k,c,may,r;
		
	c=0;
	k=0;
	i=0;
	while(cadena[i]!='\0'){
		j=1;
		while(cadena[i]!=cadena[j] && j<=i+1){
			j++;
		}
		if(j<=i+1){
			c=0;
		}
		j=i+1;
		while(cadena[j]!='\0'){
			if(cadena[i]==cadena[j]){
				c++;
			}
			j++;
		}
		k++;
		caracteres[k]=cadena[i];
		cantidad[k]=c;
		i++;
	}
		
	r=0;
	may=0;
	for(i=1;i<=k;i++){
		if(cantidad[i]<may){
			may=cantidad[i];
			r=i;
		}
	}
		
	return caracteres[r];
}

void mostrarCadena(TCadena cadena){
	printf("%s",cadena);
}
