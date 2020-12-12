#include "CACHEsym.h"
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
  //Cargar RAM (Podemos hacer esto en una funcion para que quede más limpio)
  fRAM = fopen("RAM.bin", "rb");
  unsigned char RAM[1024];
  fread(RAM ,sizeof(RAM), 1 , fRAM);
  printf("%s\n", RAM);
  fclose(fRAM);//ALMACENA 5 caracteres de más comprobar mañana
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
  /*leer cada acceso de linea, como no podemos guardar en otro array o en el
  mismo array todos los accesos, sino de linea en linea, lo suyo sería trabajar con los accesos con el puntero de FILE*/
  while (fgets(arrayAccesos, MAXCHAR, fp) != NULL){
    printf("%s", arrayAccesos);
  }
  fclose(fp);
  return 0;
}
