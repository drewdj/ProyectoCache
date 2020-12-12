#include <stdio.h>
#include <string.h>
#include <math.h>
#define RAM_SIZE 1024
typedef struct {
    short int ETQ;
    short int Datos[8];
} T_LINEA_CACHE;
int comprobarEtiqueta();
void actualizadorCache(int accesoBinario, T_LINEA_CACHE * linea, unsigned char * RAM);
int binToDec(int * bin);
/*Los traductores lo hacemos por paso por referencia o paso por valor?*/
