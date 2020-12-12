#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define RAM_SIZE 1024
typedef struct {
    short int ETQ;
    short int Datos[8];
} T_LINEA_CACHE;
void hexToBin(char * hex,char * accesoArray);
int comprobarETQ(int ETQ,char * bloque,T_LINEA_CACHE * linea);

void actualizadorCache(int ETQ,int bloque, T_LINEA_CACHE * linea, unsigned char * RAM);
int binToDec(char * bin);
char lectorAcceso(int decBlock,int decPalabra, T_LINEA_CACHE * cache);
void actualizadorTexto(char * texto, char palabra, int posicion /*Contador de iteraciones de accesos*/);
