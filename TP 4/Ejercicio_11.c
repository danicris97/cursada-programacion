#include <stdio.h>
#define TMAX 130

typedef char TCadena[TMAX];
void leeCad(TCadena,int);
int determineCantCaracteres(TCadena);
char caracterMasRepetido(TCadena);
void cantMayusMin(TCadena,int*,int*);
int cantidadPalabras(TCadena);

int main() {
	TCadena string;
	
	printf("\nIngrese una cadena: ");
	leeCad(string,TMAX);
	
	printf("\nLa cantidad de caracteres que tiene es: %d",determineCantCaracteres(string));
	printf("\nCaracter mas repetido es: %c",caracterMasRepetido(string));
	
	int cmin,cmay;
	cantMayusMin(string,&cmay,&cmin);
	printf("\nCantidad de minusculas: %d",cmin);
	printf("\nCantidad de mayusculas: %d",cmay);
	
	printf("\nCantidad de palabras: %d", cantidadPalabras(string));
	
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

int determineCantCaracteres(TCadena cadena){
	int i,c;
	
	i=0;
	c=0;
	while(cadena[i]!='\0'){
		if(cadena[i]!=' '){
			c++;
		}
		i++;
	}
	
	return c;
}
	
short estaCaracter(char reg[1000], int tam, char bus){
	int i=1;
	
	while(reg[i]!=bus && i<=tam){
		i++;
	}
	
	if(reg[i]==bus)
		return i;
	else
		return 0;
}
	
int detMayor(int lista[1000], int tam){
	int i,may;
	may=0;
	
	for (i=1;i<=tam;i++){
		if(lista[i]>may){
			may=i;
		}
	}
	
	return may;
}

char caracterMasRepetido(TCadena cadena){
	if(cadena[0]!='\0'){
		char caracteres[1000];
		int frecuencia[1000];
		int tam=1;
		int i=0;
		int pos;
		
		caracteres[1]=cadena[0];
		frecuencia[1]=1;
		
		while(cadena[i]!='\0'){
			pos=estaCaracter(caracteres,tam,cadena[i]);
			if(pos!=0){
				frecuencia[pos]=frecuencia[pos]+1;
			}else{
				caracteres[tam+1]=cadena[i];
				frecuencia[tam+1]=1;
				tam++;
			}
			i++;
		}
		
		return caracteres[detMayor(frecuencia,tam)];
	}else{
		return '\0';
	}
	
}

void cantMayusMin(TCadena cadena, int *mayusculas, int *minuscula){
	*mayusculas = 0;
	*minuscula = 0;
	int i=0;
	
	while(cadena[i]!='\0'){
		if(cadena[i]<=90 && cadena[i]>=65){
			*mayusculas = *mayusculas + 1;
		}else if(cadena[i]>=97 && cadena[i]<=122){
			*minuscula = *minuscula + 1;
		}
		i++;
	}
	
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
