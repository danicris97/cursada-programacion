#include <stdio.h>
#include <stdlib.h>
#define TFILA 5
#define TCOLUMNA 10

int ingresaPosicionF();
int ingresaPosicionC();
void armarSala(short [TFILA][TCOLUMNA]);
void reservarAsiento(short [TFILA][TCOLUMNA],int,int);
void cancelaReserva(short [TFILA][TCOLUMNA],int,int);
short estadoAsiento(short [TFILA][TCOLUMNA],int,int);
void mostrarMatriz(short [TFILA][TCOLUMNA]);
short menu();

int main() {
	short opcion,f,c;
	short sala[TFILA][TCOLUMNA];
	armarSala(sala);
	/*mostrarMatriz(sala);*/
	
	//MENU
	printf("\nBIENVENIDO AL SISTEMA DE RESERVAS DE ASIENTO DE SALA...\n");
	system("PAUSE");
	opcion=1;
	
	while(opcion!=0){
		system("CLS");
		opcion=menu();
		if(opcion!=0){
			f=ingresaPosicionF();
			c=ingresaPosicionC();
		}
		switch(opcion){
			case 1:reservarAsiento(sala,f,c);
			break;
			case 2:cancelaReserva(sala,f,c);
			break;
			case 3:if(estadoAsiento(sala,f,c)==0){
					printf("\nASIENTO LIBRE");
					}else{
					printf("\nASIENTO RESERVADO");
					}
			break;
			case 0: printf("\nSaliendo...");
			break;
			default: printf("\nOpcion ingresada incorrecta");
			break;
		}
		printf("\n");
		system("PAUSE");
	}
	
	return 0;
}

int ingresaPosicionF(){
	int f;
	
	do{
		printf("\nINGRESA LA FILA: ");
		scanf("%d",&f);
	}while(f<1||f>5);
	
	return f;
}

int ingresaPosicionC(){
	int c;
	
	do{
		printf("\nINGRESA LA COLUMNA: ");
		scanf("%d",&c);
	}while(c<1||c>10);
	
	return c;
}

short menu(){
	short op;
	
	do{
		printf("\n1- RESERVACION DE ASIENTO");
		printf("\n2- CANCELACION DE RESERVA");
		printf("\n3- ESTADO DE UN ASIENTO");
		printf("\n0- SALIR");
		printf("\nINGRESE UNA OPCION: ");
		scanf("%hd",&op);
	} while(op<0||op>3);
	
	return op;
}

void armarSala(short sala[TFILA][TCOLUMNA]){
	int i,j;
	
	for(i=1;i<=TFILA;i++){
		for(j=1;j<=TCOLUMNA;j++){
			sala[i][j]=0;
		}
	}
}
	
void reservarAsiento(short sala[TFILA][TCOLUMNA], int i, int j){
	if(estadoAsiento(sala,i,j)==0){
		sala[i][j]=1;
		printf("\nASIENTO %d,%d RESERVADO CORRECTAMENTE",i,j);
	}else{
		printf("\nEL ASIENTO YA ESTA RESERVADO");
	}
}
	
void cancelaReserva(short sala[TFILA][TCOLUMNA], int i, int j){
	if(estadoAsiento(sala,i,j)==1){
		sala[i][j]=0;
		printf("\nSE CANCELO CORRECTAMENTE LA RESERVA... ASIENTO %d,%d DISPONIBLE",i,j);
	}else{
		printf("\nEL ASIENTO YA ESTA DISPONIBLE");
	}
}
	
short estadoAsiento(short sala[TFILA][TCOLUMNA], int i, int j){return sala[i][j];}
	
void mostrarMatriz(short sala[TFILA][TCOLUMNA]){
	int i,j;
		
	printf("\n");
	for(i=1;i<=TFILA;i++){
		for(j=1;j<=TCOLUMNA;j++){
			printf("%d ",sala[i][j]);
		}
		printf("\n");
	}
}
