#include "Entero.h"

void mostrarDigitos(entero numero){
    if(numero!=0){
        entero d;
        d=numero%10;
        mostrarDigitos(numero/10);
        printf("%d - ",d);
    }
}

entero cantidadDigitosPares(entero numero, entero contador){
    if(numero!=0){
        entero digito;
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

entero determinaPertenece(entero numero, entero buscado){
    if(buscado!=numero%10 && numero>0){
        return determinaPertenece((numero/10),buscado);
    }else if(numero>0){
        return 1;
    }else{
        return 0;
    }
    
}

entero retornaDigitoSignificativo(entero numero){
    if(numero>10){
        return retornaDigitoSignificativo(numero/10);
    }else {
        return numero;
    }
}

entero mayorDigito(entero numero, entero mayor){
    if(numero!=0){
        entero d;
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

entero sumaDigitosImpares(entero numero, entero acomulador){
    if(numero!=0){
        return sumaDigitosImpares(numero/10,(acomulador+numero%10));
    }else{
        return acomulador;
    }
}
