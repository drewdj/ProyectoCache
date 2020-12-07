#include <stdio.h>
#include <string.h>

typedef struct {
    short int ETQ;
    short int Datos[8];
} T_LINEA_CACHE;


int main() {
int tiempoglobal = 0;
int numfallos = 0;
FILE *fp;

fp = fopen("E:\\ProyectoCache\\accesos_memoria.txt","r");

    for (int i = 0; i < 4; ++i) {
        T_LINEA_CACHE linea[i];
        linea[i].ETQ = 0xFF;
        for (int j = 0; j < 8; ++j) {
            linea[i].Datos[j]=0;
        }
    }

    return 0;
}
