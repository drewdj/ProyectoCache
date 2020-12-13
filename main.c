#include "CACHEsym.h"

int main() {
  int tiempoglobal = 0;
  int numfallos = 0;
  int iteracion = 0;
  char texto[100];
  char texto2[100];
  char accesoBinario[10];
  unsigned char RAM[RAM_SIZE];
  FILE *fp;
  FILE *fRAM;
  //Inicialización de la CACHE
  T_LINEA_CACHE linea[4];
  for (int i = 0; i < 4; ++i) {
      linea[i].ETQ = 0xFF;
      for (int j = 0; j < 8; ++j) {
          linea[i].Datos[j]=0;
      }
  }
  //Cargar RAM (Podemos hacer esto en una funcion para que quede más limpio)
  fRAM = fopen("E:\\ProyectoCache\\RAM.bin", "rb");
  fread(RAM ,sizeof(RAM), 1 , fRAM);
  if (fRAM == NULL) {
    printf("No se ha podido abrir RAM.bin");
    return 0;
  }
  //printf("%s\n", RAM);//Quitar al final, es un control

  fclose(fRAM);//ALMACENA 5 caracteres de más comprobar mañana

  //Cargar Accesos a memoria
  fp = fopen("E:\\ProyectoCache\\accesos_memoria.txt","r");
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
  //printf("Numero de accesos %d\n", numero_accesos);
  rewind(fp);
  int MAXCHAR = (numero_accesos * 5) - 1;
  char arrayAccesos[4];
  /*leer cada acceso de linea, como no podemos guardar en otro array o en el
  mismo array todos los accesos, sino de linea en linea, lo suyo sería trabajar con los accesos con el puntero de FILE*/

  while (fgets(arrayAccesos, MAXCHAR, fp) != NULL){
      arrayAccesos[4]='\0';
    hexToBin(arrayAccesos,accesoBinario);

    //division de binario en ETQ,linea y palabra
    char etqBin[6];
      for (int i = 0; i < 5; ++i) {
          etqBin[i]=accesoBinario[i];
      }
      char bloqueBin[3] = {accesoBinario[5],accesoBinario[6],'\0'};

    char palabraBin[4] = {accesoBinario[7], accesoBinario[8], accesoBinario[9],'\0'};



    int decEtq = binToDec(etqBin);

    int decBlock = binToDec(bloqueBin);
    int decPalabra = binToDec(palabraBin);
    int tf = comprobarETQ(decEtq,bloqueBin, linea);

    if (tf == 1){
      printf("Acierto de CACHE ADDR %s ETQ %d linea 0%d palabra 0%d DATO %x\n", arrayAccesos, decEtq, decBlock, decPalabra, linea[decBlock].Datos[decPalabra]);
    }
    else{
      numfallos += 1;
      printf("Fallo de CACHE %d ADDR %s ETQ %d linea 0%d palabra 0%d bloque 0%d\n", numfallos, arrayAccesos, decEtq, decBlock, decPalabra, decBlock);
      actualizadorCache(decEtq,decBlock, linea, RAM);
    }
    char palabraCache = lectorAcceso(decBlock,decPalabra, linea);
    texto[iteracion] = palabraCache;
      texto2[iteracion] = palabraCache;
    iteracion++;
  }
  fclose(fp);
  texto[iteracion]='\0';
  printf("%s",texto);
  return 0;
}
