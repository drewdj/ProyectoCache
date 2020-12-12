#include <stdio.h>
#include <string.h>
#include <math.h>
#define RAM_SIZE 1024
typedef struct {
    short int ETQ;
    short int Datos[8];
} T_LINEA_CACHE;
char hexToBin(char * hex);
int comprobarETQ(char * ETQ,char * bloque,T_LINEA_CACHE * linea);

void actualizadorCache(int * accesoBinario, T_LINEA_CACHE * linea, unsigned char * RAM);
int binToDec(int * bin);
char lectorAcceso(char * accesoBinario, T_LINEA_CACHE * cache);
void actualizadorTexto(char * texto, char palabra, int posicion /*Contador de iteraciones de accesos*/);
