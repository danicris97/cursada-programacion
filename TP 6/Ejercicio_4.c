#include <stdio.h>

void mostrarDigitos(int);
int cantidadDigitosPares(int,int);
int determinaPertenece(int,int);
int retornaDigitoSignificativo(int);
int mayorDigito(int,int);
int sumaDigitosImpares(int,int);

int main(){
    int entero,digito;

    printf("\nINGRESE UN NUMERO: ");
    scanf("%d",&entero);

    printf("\nDigitos: ");
    mostrarDigitos(entero);
    printf("\nCantidad de digitos pares: %d",cantidadDigitosPares(entero,0));
    printf("\nIngrese el digito a buscar: ");
    scanf("%d",&digito);

    if(determinaPertenece(entero,digito)==1){
        printf("\nEl digito %d pertenece al numero %d",digito,entero);
    }else{
        printf("\nNo pertenece al entero");
    }

    printf("\nDigito mas significativo: %d",retornaDigitoSignificativo(entero));

    printf("\nDigito mayor del numero: %d",mayorDigito(entero,0));

    printf("\nSuma de los digitos: %d",sumaDigitosImpares(entero,0));

    return 0;
}

void mostrarDigitos(int numero){
    if(numero!=0){
        int d;
        d=numero%10;
        mostrarDigitos(numero/10);
        printf("%d - ",d);
    }
}

int cantidadDigitosPares(int numero, int contador){
    if(numero!=0){
        int digito;
        digito=numero%10;
        if(digito%2==0){
           return cantidadDigitosPares(numero/10,contador+1);
        }else{
           return cantidadDigitosPares(numero/10,contador);
        }
    }
    else{
        return contador;
    }
}

int determinaPertenece(int numero, int buscado){
    if(buscado!=numero%10 && numero>0){
        return determinaPertenece((numero/10),buscado);
    }else if(numero>0){
        return 1;
    }else{
        return 0;
    }
    
}

int retornaDigitoSignificativo(int numero){
    if(numero>10){
        return retornaDigitoSignificativo(numero/10);
    }else {
        return numero;
    }
}

int mayorDigito(int numero, int mayor){
    if(numero!=0){
        int d;
        d=numero%10;
        if(d>mayor){
            return mayorDigito(numero/10,d);
        }else{
            return mayorDigito(numero/10,mayor);
        }
    }else{
        return mayor;
    }
}

int sumaDigitosImpares(int numero, int acomulador){
    if(numero!=0){
        return sumaDigitosImpares(numero/10,(acomulador+numero%10));
    }else{
        return acomulador;
    }
}
