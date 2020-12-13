#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#define RAM_SIZE 1024
#define DIR_SIZE 5

typedef struct {
    short int ETQ;
    short int Datos[8];
} T_LINEA_CACHE;

void hexToBin(char * hex,char * accesoArray);

int binToDec(char * bin);

int comprobarETQ(int ETQ,char * bloque,T_LINEA_CACHE * linea);

void actualizadorCache(int ETQ,int bloque, T_LINEA_CACHE * linea, unsigned char * RAM);

char lectorAcceso(int decBlock,int decPalabra, T_LINEA_CACHE * cache);


