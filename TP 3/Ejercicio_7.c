#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
short ingresaOpcion();
short generaNumero();
void resultado(short, short);

int main() {
	
	srand(time(NULL));
	printf("BIENVENIDO A PIEDRA, PAPEL O TIJERA");
	menu();
	
	return 0;
}

void menu(){
	short o,opc;
	
	printf("\nPARA JUGAR PERSIONE CUALQUIER BOTON");
	printf("\nPARA SALIR PRESIONE 0");
	
	while(ingresaOpcion()!=0){
		printf("\nPARA JUGAR PRESIONE...");
		printf("\n1=PIEDRA\n2=PAPEL\n3=TIJERA");
		do{
			o=ingresaOpcion();
		} while((o<1)&&(o>3));
		
		opc=generaNumero();
		
		resultado(o,opc);
		printf("\n\nPRESIONE 0 SI DESEA SALIR\n");
	}
}
	
short ingresaOpcion(){
	int i;
	
	fflush(stdin);
	printf("\nINGRESA OPCION: ");
	scanf("%d",&i);
	
	return i;
}
	
short generaNumero(){return rand()%(3-1+1)+1;}
	
void resultado(short o, short opc){
	switch(o){
		case 1: printf("\nELEGISTE PIEDRA");
				switch(opc){
					case 1: printf("\nPC ELIGE PIEDRA");
							printf("\nEMPATE");
							break;
					case 2: printf("\nPC ELIGE PAPEL");
							printf("\nPIERDES");
							break;
					case 3: printf("\nPC ELIGE TIJERA");
							printf("\nGANAS");
							break;
				}
				break;
		case 2: printf("\nELEGISTE PAPEL");
				switch(opc){
					case 1: printf("\nPC ELIGE PIEDRA");
							printf("\nGANAS");
							break;
					case 2: printf("\nPC ELIGE PAPEL");
							printf("\nEMPATE");
							break;
					case 3: printf("\nPC ELIGE TIJERA");
							printf("\nPIERDES");
							break;
				}
				break;
		case 3: printf("\nELEGISTE TIJERA");
				switch(opc){
					case 1: printf("\nPC ELIGE PIEDRA");
							printf("\nPIERDES");
							break;
					case 2: printf("\nPC ELIGE PAPEL");
							printf("\nGANAS");
							break;
					case 3: printf("\nPC ELIGE TIJERA");
							printf("\nEMPATE");
							break;
				}
				break;
		default: break;
	}
}
