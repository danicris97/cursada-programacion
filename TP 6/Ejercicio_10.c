#include <stdio.h>
#define TMAX 250

void cargaVector(int [], int);
int determinaUltimoPar(int [], int n);

int main(){
    int n;
    int v[TMAX];

    printf("\nIngrese la cantidad de elementos del vector: ");
    scanf("%d",&n);

    cargaVector(v,n);

    printf("\nUltimo par: %d",determinaUltimoPar(v,n));

    return 0;
}

void cargaVector(int vector[], int tam){
    if(tam!=0){
        cargaVector(vector,tam-1);
        int numero;

        printf("\nIngrese el %d numero de la lista: ",tam);
        scanf("%d",&numero);

        vector[tam]=numero;
    }
}

int determinaUltimoPar(int vector[], int tam){
    if(tam!=0){
        if(vector[tam]%2==0){
            return vector[tam];
        }else{
            return determinaUltimoPar(vector,tam-1);
        }
    }else{
        printf("\nNo hay numeros pares en la lista");
        return -1;
    }
}
