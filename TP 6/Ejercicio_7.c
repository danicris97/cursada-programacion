#include <stdio.h>

void fbomba(int,int);

int main(){
    int n,b;

    printf("\nIngrese un numero entero: ");
    scanf("%d",&n);

    do{
        printf("\nIngrese un numero entero: ");
        scanf("%d",&b);
    }while (b>=n);

    fbomba(n,b);

    return 0;
}

void fbomba(int numero, int bomba){
    printf("\nnumero: %d",numero);
    printf("\nbomba: %d",bomba);
    if(numero>bomba){
        printf("\nPUM! bomba de flagracion se obtienen 2 fragmentos");
        fbomba(numero/bomba,bomba);
        fbomba(numero - (numero/bomba),bomba);
    }else{
        printf("\nFin");
    }
}