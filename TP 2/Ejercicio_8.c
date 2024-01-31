#include <stdio.h>

int ingresaNumero();
void calculaPromList(int ,int *,int *,int *,int *,int *);
void muestraPromedios(int ,int, int, int, int);

int main() {
	int n,pcu,pdt,pcc,pss,pon;
	//promedio pcu cero uno, pdt dos tres, pcc cuatro cinco, pss seis siete, pon ocho nueve

	printf("\nINGRESE EL TAMANIO DE LA LISTA");
	n=ingresaNumero();
	calculaPromList(n,&pcu,&pdt,&pcc,&pss,&pon);
	muestraPromedios(pcu,pdt,pcc,pss,pon);
	
	return 0;
}

int ingresaNumero(){
	int cant;
	
	do{
		printf("\nINGRESE UN NUMERO: ");
		scanf("%d",&cant);
	}while(cant<=0);
	
	return cant;
}

int determinaUltDigito(int n){
	int d;
	d=0;
	
	d=n%10;
	
	return d;
}
	
void acomulayCuenta(int *acu, int *cont, int num){
	if(*cont!=0){
		*acu=*acu+num;
		*cont=*cont+1;
	}
	else{
		*acu=num;
		*cont=*cont+1;
	}
}
	
int calculaProm(int prom, int n){
	return (prom/n);
}

void calculaPromList(int n, int *cu, int *dt, int *cc, int *ss, int *on){
	int num,i,a,b,co,d,e;
	
	*cu=0;*dt=0;*cc=0;*ss=0;*on=0;
	a=0;b=0;co=0;d=0;e=0;
	
	for (i=1;i<=n;i++){
		num=ingresaNum();
		switch(determinaUltDigito(num)){
			case 0: //acomula y cuenta numeros terminados en ceros y unos
			case 1: acomulayCuenta(cu,&a,num);
			break;
			
			case 2: //acomula y cuenta numeros terminados en dos y tres
			case 3: acomulayCuenta(dt,&b,num);
			break;
			
			case 4: //acomula y cuenta numeros terminados en cuatro y cinco
			case 5: acomulayCuenta(cc,&co,num);
			break;
			
			case 6: //acomula y cuenta numeros terminados en seis y siete
			case 7: acomulayCuenta(ss,&d,num);
			break;
			
			case 8: //acomula y cuenta numeros terminados en ocho y nueve
			case 9: acomulayCuenta(on,&e,num);
			break;
		}
	}
	
	if(a!=0)
		*cu=calculaProm(*cu,a);
	else if(b!=0)
		*dt=calculaProm(*dt,b);
	else if(co!=0)
		*cc=calculaProm(*cc,co);
	else if(d!=0)
		*ss=calculaProm(*ss,d);
	else if(e!=0)
		*on=calculaProm(*on,e);
}

void muestraPromedios(int proma, int promb, int promc, int promd, int prome){
	printf("\nEL PROMEDIO DE LOS NUMEROS TERMINADOS EN 0 Y 1 ES: %d",proma);
	printf("\nEL PROMEDIO DE LOS NUMEROS TERMINADOS EN 2 Y 3 ES: %d",promb);
	printf("\nEL PROMEDIO DE LOS NUMEROS TERMINADOS EN 4 Y 5 ES: %d",promc);
	printf("\nEL PROMEDIO DE LOS NUMEROS TERMINADOS EN 6 Y 7 ES: %d",promd);
	printf("\nEL PROMEDIO DE LOS NUMEROS TERMINADOS EN 8 Y 9 ES: %d",prome);
}
