#include <stdio.h>
#define TMAX 130
#define TMAXC 1000

typedef char TCadena[TMAX];
void leeCad(TCadena,int);

typedef struct{
	TCadena calle;
	int numero;
	int codigoPostal;
	TCadena ciudad;
}TDomicilio;

typedef struct{
	TCadena nombre;
	TCadena apellido;
	long dni;
	TDomicilio domicilio;
}TCliente;

typedef struct{
	long numeroCuenta;
	long numeroCliente;
	TCliente cliente;
	float saldo;
}TCuenta;

typedef TCuenta listaCuentas[TMAXC];

TCuenta cargarCuenta();
TCliente cargarCliente();
TDomicilio cargarDomicilio();
void deposito(TCuenta*,float);
void retiro(TCuenta*,float);
void mostrarCliente(TCliente);
void mostrarClientePorNumero(listaCuentas,int,long);
void mostrarClientePorCiudad(listaCuentas,int,TCadena);
void mostrarCuenta(TCuenta);

int main() {
	TCuenta c;
	
	c=cargarCuenta();
	mostrarCliente(c.cliente);
	mostrarCuenta(c);
	
	return 0;
}

void vaciabuffer(){
	int ch;
	while((ch=getchar())!='\n' && ch!=EOF);
}

void leeCad(TCadena cadena, int tam){
	int j,m;
		
	//INGRESA CADENA
	j=0;
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		cadena[j]=m;
		j++;
	}
	cadena[j]='\0';
		
	//LIMPIA BUFFER
	if(m!=EOF && m!='\n'){
		while((m=getchar())!=EOF && m!='n');
	}
}

TCuenta cargarCuenta(){
	TCuenta cuenta;
	
	printf("\nINGRESE DATOS DE LA CUENTA");
	printf("\nNUMERO DE CUENTA: ");
	scanf("%ld",&cuenta.numeroCuenta);
	vaciabuffer();
	
	printf("\nNUMERO DE CLIENTE: ");
	scanf("%ld",&cuenta.numeroCliente);
	vaciabuffer();
	
	printf("\nSALDO: ");
	scanf("%f",&cuenta.saldo);
	vaciabuffer();
	
	cuenta.cliente = cargarCliente();
	
	return cuenta;
}
	
TCliente cargarCliente(){
	TCliente cliente;
	
	
	printf("\nINGRESE DATOS DEL CLIENTE...");
	printf("\nNOMBRE: ");
	leeCad(cliente.nombre,TMAX);
	
	printf("\nAPELLIDO: ");
	leeCad(cliente.apellido,TMAX);
	
	printf("\nDNI: ");
	scanf("%ld",&cliente.dni);
	vaciabuffer();
	
	cliente.domicilio = cargarDomicilio();
	
	return cliente;
}

TDomicilio cargarDomicilio(){
	TDomicilio domicilio;
	
	printf("\nINGRESE DATOS DEL DOMICILIO...");
	printf("\nCALLE: ");
	leeCad(domicilio.calle,TMAX);
	
	printf("\nNUMERO DE DOMICILIO: ");
	scanf("%d",&domicilio.numero);
	vaciabuffer();
	
	printf("\nCODIGO POSTAL: ");
	scanf("%d",&domicilio.codigoPostal);
	vaciabuffer();
	
	printf("\nCIUDAD: ");
	leeCad(domicilio.ciudad,TMAX);
	
	return domicilio;
}

void deposito(TCuenta *cuenta, float monto){
	if(monto>0)
		cuenta->saldo = cuenta->saldo + monto;
	else
		printf("\nEL MONTO INGRESADO NO ES VALIDO PARA LA OPERACION");
}
	
void retiro(TCuenta *cuenta, float monto){
	if(monto>0){
		if(monto<=cuenta->saldo){
			cuenta->saldo = cuenta->saldo - monto;
		}else{
			printf("\nEL MONTO INGRESADO ES SUPERIOR AL SALDO DE LA CUENTA");
		}
	}else{
		printf("\nEL MONTO INGRESADO NO ES VALIDO");
	}
}

void mostrarClientePorNumero(listaCuentas lista, int tam, long numCuenta){
	int i;
	
	for(i=1;i<=tam;i++){
		if(lista[i].numeroCuenta == numCuenta){
			mostrarCliente(lista[i].cliente);
		}
	}
}
	
short compareString(TCadena cadena1, TCadena cadena2){
	int i;
	
	i=0;
	while(cadena1[i]!='\0' && cadena2[i]!='\0' && cadena1[i]==cadena2[i]){
		i++;
	}
	
	if(cadena1[i]==cadena2[i]){
		return 1;
	}else{
		return 0;
	}
}
	
void mostrarClientePorCiudad(listaCuentas lista, int tam, TCadena ciudad){
	int i;
	
	for(i=1;i<=tam;i++){
		if(compareString((lista[i].cliente.domicilio.ciudad),ciudad)==1){
			mostrarCliente(lista[i].cliente);
		}
	}
}
	
void mostrarDomicilio(TDomicilio domicilio){
	printf("\nDOMICILIO...");
	printf("\nCALLE: %s",domicilio.calle);
	printf("\nDIRECCION: %d",domicilio.numero);
	printf("\nCODIGO POSTAL: %d",domicilio.codigoPostal);
	printf("\nCIUDAD: %s",domicilio.ciudad);
}

void mostrarCliente(TCliente cliente){
	printf("\nDATOS DEL CLIENTE...");
	printf("\nNOMBRE: %s",cliente.nombre);
	printf("\nAPELLIDO: %s",cliente.apellido);
	printf("\nDNI: %ld",cliente.dni);
	mostrarDomicilio(cliente.domicilio);
}
	
void mostrarCuenta(TCuenta cuenta){
	printf("\nDATOS DE LA CUENTA...");
	printf("\nNUMERO DE CUENTA: %ld",cuenta.numeroCuenta);
	printf("\nNUMERO DE CLIENTE: %ld",cuenta.numeroCliente);
	printf("\nSALDO: %f.2",cuenta.saldo);
	printf("\nDATOS DEL CLIENTE...");
	mostrarCliente(cuenta.cliente);
}
