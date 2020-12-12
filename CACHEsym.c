#include "CACHEsym.h"
int binToDec(char * bin){
  int decNumber, intBin;
  intBin = atoi(bin);
  for(int i = 0; intBin; i++, intBin /= 10){
        if (intBin % 10){
            decNumber = decNumber + pow(2, i);
        }
      }
  printf("%d", decNumber);
  return decNumber;
}
void actualizadorCache(char * accesoBinario, T_LINEA_CACHE * cache, unsigned char * RAM){
  char bloque[2] = {accesoBinario[5], accesoBinario[6]};
  int decBlock = binToDec(bloque);
  char etqBin[5] = {accesoBinario[0], accesoBinario[1], accesoBinario[2], accesoBinario[3], accesoBinario[4]};
  int decEtq = binToDec(etqBin);
  printf("Cagando el bloque %d en la linea %d", decBlock, decBlock);
  cache[decBlock].ETQ = decEtq;
  cache[decBlock].Datos = {RAM[(decBlock * 8) + 7], RAM[(decBlock * 8) + 6], RAM[(decBlock * 8) + 5], RAM[(decBlock * 8) + 4], RAM[(decBlock * 8) + 3], RAM[(decBlock * 8) + 2], RAM[(decBlock * 8) + 1], RAM[(decBlock * 8)]};
}

char lectorAcceso(char * accesoBinario, T_LINEA_CACHE * cache){
  char bloque[2] = {accesoBinario[5], accesoBinario[6]};
  int decBlock = binToDec(bloque);
  char palabraBin[3] = {accesoBinario[7], accesoBinario[8], accesoBinario[9]};
  int decPalabra = binToDec(palabraBin);
  char palabraCache = cache[decBlock].Datos[decPalabra];
  return palabraCache;
}

//Poner esto en el bucle while una vez comprobado que la palabra existe en ram o en cache
void actualizadorTexto(char * texto, char palabra, int posicion /*Contador de iteraciones de accesos*/){
  texto[posicion] = palabra;
}
