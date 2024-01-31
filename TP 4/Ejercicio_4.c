#include <stdio.h>
#define TMAX 1000

int ingresaNumeroNatural();
void ingresarCadena(char[], int);
void ordenaDeMenorAMayor(char[], int);
int buscarH(char[], int);
char ingresaLetra();
void agregaLetraOrdenCorrecto(char[], int*, char);
void muestraVector(char[], int);

int main() {
	int n,cantAlumnos,i,contador;
	
	printf("\nINGRESE LA CANTIDAD DE ALUMNOS...");
	cantAlumnos = ingresaNumeroNatural();
	
	contador = 0;
	for(i=1;i<=cantAlumnos;i++){
		printf("%d° ALUMNO",i);
		char listaLetras[TMAX];
		printf("\nINGRESE LA CANTIDAD DE LETRAS...");
		n = ingresaNumeroNatural();
		ingresarCadena(listaLetras,n);
		muestraVector(listaLetras,n);
		ordenaDeMenorAMayor(listaLetras,n);
		muestraVector(listaLetras,n);
		if(buscarH(listaLetras,n)!=-1){
			contador++;
		}
		
		agregaLetraOrdenCorrecto(listaLetras,&n,ingresaLetra());
	}
	
	printf("CANTIDAD DE ALUMNOS QUE INGRESARON LA H: %d",contador);
	
	return 0;
}

int ingresaNumeroNatural(){
	int n;
	
	do{
		printf("\nINGRESA NUMERO NATURAL: ");
		scanf("%d",&n);
	}while(n<0);
	
	return n;
}

void vaciabuffer(){
	int ch;
	while((ch=getchar())!='\n' && ch!=EOF);
}
	
char ingresaLetra(){
	char c;
	
	vaciabuffer();
	printf("\nINGRESE UNA LETRA DEL ABECEDARIO: ");
	c=getchar();
	
	return c;
}
	
void ingresarCadena(char lista[], int tam){
	int i;
	
	for(i=1;i<=tam;i++){
		lista[i] = ingresaLetra();
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

int buscarH(char cadena[], int tam){
	int i;
	
	i=1;
	while(i<=tam && cadena[i]!='h' && cadena[i]!='H'){
		i++;
	}
	
	if(i<=tam){
		return i;
	}else
	   return -1;
}

void agregaLetraOrdenCorrecto(char cadena[], int *tam, char c){
	if(*tam<=TMAX){
		cadena[*tam+1] = c;
		*tam = *tam+1;
	}else
	   printf("\nERROR: LIMITE SUPERADO");
	
	ordenaDeMenorAMayor(cadena,*tam);
}

void muestraVector(char cadena[], int tam){
	int i;
		
	printf("\nCADENA: ");
	for(i=1;i<=tam;i++){
		printf("%c",cadena[i]);
	}
}	
