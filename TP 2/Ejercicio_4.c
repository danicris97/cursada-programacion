#include <stdio.h>

float definirTarifaBasica();
void ingresoHoraES(int *, int *);
int ingresoTipo();
void muestraTarifaFinal(short, int, int, float);

int main() {
	float tb;
	int hi,he,tipo;
	
	tb = definirTarifaBasica();
	ingresoHoraES(&hi,&he);
	tipo = ingresoTipo();
	muestraTarifaFinal(tipo,hi,he,tb);
	
	return 0;
}

float definirTarifaBasica(){
	float TB;
	
	do{
		printf("\nINGRESE LA CANTIDAD LA TARIFA BASICA: $ ");
		scanf("%f",&TB);
	}while(TB<0);
	
	return TB;
}
	
void ingresoHoraES(int *HI, int *HE){
	printf("\nTENER EN CUENTA QUE EL FORMATO DE INGRESO DE LA HORA ES HHMM");
	
	do{
		printf("\nHORA DE INGRESO: ");
		scanf("%d",HI);
	}while((*HI<0)&&(*HI>2400));
	
	do{
		printf("\nHORA DE EGRESO: ");
		scanf("%d",HE);
	}while((*HE<0)&&(*HE>2400));
}
	
int ingresoTipo(){
	int t;
	
	do{
		printf("\nPARA INDICAR EL TIPO DE VEHICULO SE DEBE TENER EN CUENTA LOS SIGUIENTES VALORES \n1:MOTO\n2:AUTO\n3:CAMIONETA");
		printf("\nINGRESE EL TIPO DE VEHICULO: ");
		scanf("%d",&t);
	}while((t<=0)&&(t>4));
	
	return t;
}

int obtenerHora(int E, int S){
	int HF;
	
	HF=S-E;
	
	if((HF%100)!=0)
		HF=(HF/100)+1;
	else
		HF=(HF/100);
	
	return HF;
}
	
void muestraTarifaFinal(short tipo, int horaE, int horaS, float tarifaB){
	int horaF;
	
	horaF = obtenerHora(horaE,horaS);
	
	if(tipo==1)
		printf("\nIMPORTE A PAGAR: $ %0.2f",(tarifaB*horaF));
	else if (tipo==2)
		printf("\nIMPORTE A PAGAR: $ %0.2f",((tarifaB*2)*horaF));
	else if (tipo==3)
		printf("\nIMPORTE A PAGAR: $ %0.2f",((tarifaB*3)*horaF));
}
