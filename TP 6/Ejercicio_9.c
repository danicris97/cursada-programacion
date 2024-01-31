#include <stdio.h>

void cambio(int,int *,int *,int *, int *);

int main(){
    int m,d,c,dos,u;

    printf("\nIngrese la cantidad de dinero: ");
    scanf("%d",&m);

    //contadores
    d=0;
    c=0;
    dos=0;
    u=0;
    //
    cambio(m,&d,&c,&dos,&u);

    printf("\nBilletes necesarios: %d - $10, %d - $5, %d - $2, %d - $1",d,c,dos,u);

    return 0;
}

void cambio(int dinero, int *diez, int *cinco,int *dos, int *uno){
    if(dinero!=0){
        if(dinero-10>=0){
            *diez=*diez+1;
            cambio(dinero-10,diez,cinco,dos,uno);
        }else if(dinero-5>=0){
            *cinco=*cinco+1;
            cambio(dinero-5,diez,cinco,dos,uno);
        }else if(dinero-2>=0){
            *dos=*dos+1;
            cambio(dinero-2,diez,cinco,dos,uno);
        }else{
            *uno=dinero;
            dinero=0;
        }
    }
}