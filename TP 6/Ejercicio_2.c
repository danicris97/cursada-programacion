#include <stdio.h>

int c_d(int,int);
int c_r(int,int,int);

int main() {
	int x,y;
	
	printf("\nINGRESE UN NUMERO: ");
	scanf("%d",&x);
	
	printf("\nINGRESE OTRO NUMERO: ");
	scanf("%d",&y);
	
	printf("\nEL RESULTADO ES: %d",c_d(x,y));
	
	return 0;
}

int c_r(int a, int b, int d){
	if(d>a || d>b){
		return 0;
	}else if((a%d)==0 && (b%d)==0){
		return 1+c_r(a,b,d+1);
	}else{
		return c_r(a,b,d+1);
	}
}
	
int c_d(int x, int y){
	return c_r(x,y,1);
}

