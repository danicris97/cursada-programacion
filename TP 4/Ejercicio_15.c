#include <stdio.h>
#define TMAX 130
#define TMAXP 1000

typedef struct{
	int dia;
	int mes;
	int anio;
}TFecha;

typedef char TCadena[TMAX];
void leeCad(TCadena,int);

typedef struct{
	TCadena nombre;
	TFecha fechaNacimiento;
}TPersona;

TPersona cargarPersona();
void muestraPersona(TPersona);
void modificarPersonaNombre(TPersona*, TCadena);
void modificarPersonaFechaNac(TPersona*, TFecha);
void muestraCumpleaniosPorMes(TPersona[], int, int);
int ingresaMes();
TFecha ingresarFecha();

int main() {
	TPersona p1;
	TCadena aux;
	
	p1=cargarPersona();
	muestraPersona(p1);
	printf("\nIngrese el nuevo nombre: ");
	leeCad(aux,TMAX);
	modificarPersonaNombre(&p1,aux);
	muestraPersona(p1);
	
	TPersona p2=cargarPersona();
	printf("\nIngrese la nueva fecha...");
	modificarPersonaFechaNac(&p1, ingresarFecha());
	muestraPersona(p2);
	
	TPersona l[TMAXP];
	l[1]=p1;
	l[2]=p2;
	
	printf("\nIngrese un mes: ");
	muestraCumpleaniosPorMes(l, 2,ingresaMes());
	
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
	
int ingresaMes(){
	int mes;
	
	do{
		printf("\nMES: ");
		scanf("%d",&mes);
	}while(mes<=0 || mes>=13);
	
	return mes;
}

TFecha ingresarFecha(){
	TFecha f;
	
	printf("\nANIO: ");
	scanf("%d",&f.anio);
	
	f.mes = ingresaMes();
	
	if(f.mes==1 || f.mes==3 || f.mes==5 || f.mes==7 || f.mes==8 || f.mes==10 || f.mes==12){
		do{
			printf("\nDIA: ");
			scanf("%d",&f.dia);
		}while(f.dia<=0 || f.dia>=32);
	}else if(f.mes==2){
		if(f.anio%4!=0)
			do{
				printf("\nDIA: ");
				scanf("%d",&f.dia);
			}while(f.dia<=0 || f.dia>=29);
		else{
			do{
				printf("\nDIA: ");
				scanf("%d",&f.dia);
			}while(f.dia<=0 || f.dia>=30);
		}
	}else{
		do{
			printf("\nDIA: ");
			scanf("%d",&f.dia);
		}while(f.dia<=0 || f.dia>=31);
	}
	
	return f;
}
	
TPersona cargarPersona(){
	TPersona persona;
	
	printf("\nINGRESE EL NOMBRE DE LA PERSONA: ");
	leeCad(persona.nombre,TMAX);
	
	printf("\nINGRESE LA FECHA DE NACIMIENTO DE LA PERSONA...");
	persona.fechaNacimiento = ingresarFecha();
	
	vaciabuffer();
	
	return persona;
}
	
void muestraFecha(TFecha fecha){
	printf("DIA: %d, MES: %d, ANIO: %d",fecha.dia,fecha.mes,fecha.anio);
}
	
void muestraPersona(TPersona persona){
	printf("\nNOMBRE: %s",persona.nombre);
	printf("\nFECHA DE NACIMIENTO: ");
	muestraFecha(persona.fechaNacimiento);
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
	
void modificarPersonaNombre(TPersona *persona, TCadena nombre){
	copyCadena(nombre,persona->nombre);
}
	
void modificarPersonaFechaNac(TPersona *persona, TFecha fecha){
	persona->fechaNacimiento = fecha;
}
	
void muestraCumpleaniosPorMes(TPersona persona[TMAXP], int tam, int mes){
	int i;
	TFecha aux;
	
	printf("CUMPLEN ANIOS EN ESTE MES %d...",mes);
	for(i=1;i<=tam;i++){
		aux = persona[i].fechaNacimiento;
		if(aux.mes == mes){
			muestraPersona(persona[i]);
		}
	}
}
