#ifndef CADENA_H
#define CADENA_H
#define TMAX 240

typedef char TCadena[TMAX];

void vaciabuffer();
void leeCad(TCadena);
void cadenaVacia(TCadena);
void insertaCaracter(TCadena,char);
void eliminaCaracter(TCadena,char);
void remplazaCaracter(TCadena,char,char);
void copiaCadena(TCadena,TCadena);
void concantenacion(TCadena,TCadena,TCadena);
void interseccionCadena(TCadena,TCadena,TCadena);
void diferenciaCadena(TCadena,TCadena,TCadena);
int buscaCaracter(TCadena,char);
int comparaCadena(TCadena,TCadena);
int cantidadCaracteres(TCadena);
int determinaMayor(TCadena,TCadena);
int cantidadPalabras(TCadena);
char caracterMasRepetido(TCadena);
void mostrarCadena(TCadena);

#endif
