#include <stdio.h>
#include <string.h>
#include "CACHEsym.h"
typedef struct {
    short int ETQ;
    short int Datos[8];
} T_LINEA_CACHE;


int main() {
  int tiempoglobal = 0;
  int numfallos = 0;
  FILE *fp;
  FILE *fRAM;
  //Inicialización de la CACHE
  for (int i = 0; i < 4; ++i) {
      T_LINEA_CACHE linea[i];
      linea[i].ETQ = 0xFF;
      for (int j = 0; j < 8; ++j) {
          linea[i].Datos[j]=0;
      }
  }
  //Cargar Accesos a memoria
  fp = fopen("accesos_memoria.txt","r");
  int numero_accesos = 0;
  char c;
  if (fp == NULL) {
    printf("No se ha podido abrir accesos a memoria");
    return 0;
  }
  for (c = getc(fp); c != EOF; c = getc(fp)){
    if (c == '\n'){
      numero_accesos = numero_accesos + 1;
    }
  }
  numero_accesos = numero_accesos + 1; //se repite una vez más porque el ultimo acceso no tiene \n
  printf("Numero de accesos %d\n", numero_accesos);

  rewind(fp);
  int MAXCHAR = (numero_accesos * 5) - 1;
  char arrayAccesos[MAXCHAR];
  while (fgets(arrayAccesos, MAXCHAR, fp) != NULL){
    printf("%s", arrayAccesos);
  }
  fclose(fp);
  char arbolAccesos[numero_accesos][4];
  int general_counter = 0;
  for(int x = 0; x < numero_accesos; x++){
    for(int y = 0; y < 4; y++){
      if(arrayAccesos[general_counter] != '\n')
        arbolAccesos[x][y] = arrayAccesos[general_counter];
      general_counter++;
    }
  }//ME HE IDO A CENAR, ESTO ESTA A MEDIAS, PERO TENGO INTENCION DE TERMINAR PARA ESTA NOCHE EL LECTOR DE ACCESOS A MEMORIA PARA GUARDARLO EN MEMORIA
  //Leer Accesos a memoria (Debug, Borrar despues)
  /*
  while(fgets(line, sizeof(line) / sizeof(line[0]), fptr) != NULL)
  printf("%s\n", fp);
  */
  /*
  fRAM = fopen("RAM.bin", "rb");
  unsigned char RAM[1024];
  fread(RAM ,sizeof(RAM), 1 , fRAM);
  printf("%s\n", RAM[1]);
  */
  return 0;
}
