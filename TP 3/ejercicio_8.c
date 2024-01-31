#include <stdio.h>

long int codificarNumeroBinario(long int numeroBinario);
long int ingresaNumeroBinario();

int main() {
	long int numeroBinario=ingresaNumeroBinario();
	printf("Número binario original: %ld\n", numeroBinario);
	
	long int resultadoCodificado = codificarNumeroBinario(numeroBinario);
	printf("Resultado codificado: %ld\n", resultadoCodificado);
	
	return 0;
}

short esBinario(long int numero){
	int b=1;
	while(numero!=0 && b!=0){
		if(numero%10!=0 && numero%10!=1){
			b=0;
		}
		numero=numero/10;
	}
	
	return b;
}

long int ingresaNumeroBinario(){
	long int numero;
	
	do{
		printf("\nIngrese un numero entero binario: ");
		scanf("%ld",&numero);
	} while(esBinario(numero)!=1);
	
	return numero;
}

long int codificarNumeroBinario(long int numeroBinario) {
	long int resultadoCodificado = 0;
	int contador = 0;
	int ultimoBit = -1;
	
	while (numeroBinario > 0) {
		int bitActual = numeroBinario % 2;
		numeroBinario /= 2;
		
		if (bitActual == ultimoBit || ultimoBit == -1) {
			contador++;
		} else {
			resultadoCodificado = resultadoCodificado * 100 + contador * 10 + ultimoBit;
			contador = 1;
		}
		
		ultimoBit = bitActual;
	}
	
	resultadoCodificado = resultadoCodificado * 100 + contador * 10 + ultimoBit;
	
	long int resultadoFinal = 0;
	while (resultadoCodificado > 0) {
		resultadoFinal = resultadoFinal * 10 + resultadoCodificado % 10;
		resultadoCodificado /= 10;
	}
	
	return resultadoFinal;
}
