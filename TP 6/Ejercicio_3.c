#include <stdio.h>

int calculaResto(int,int);

int main() {
	int x,y;
	
	printf("\nINGRESE UN NUMERO: ");
	scanf("%d",&x);
	
	printf("\nINGRESE OTRO NUMERO: ");
	scanf("%d",&y);
	
	printf("\nRESTO: %d",calculaResto(x,y));
	
	return 0;
}

int calculaResto(int a, int b){
	if(a<b){
		return a;
	}else{
		calculaResto(a-b,b);
	}
}
