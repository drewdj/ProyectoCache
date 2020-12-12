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
void actualizadorCache(char accesoBinario[10], T_LINEA_CACHE * cache, unsigned char * RAM){
  char bloque[2] = {accesoBinario[5], accesoBinario[6]};
  int decBlock = binToDec(bloque);
  printf("Cagando el bloque %d en la linea %d", decBlock, decBlock % 4);
  cache[decBlock % 4].ETQ = decBlock;
  cache[decBlock % 4].Datos = {RAM[(decBlock * 8) + 7], RAM[(decBlock * 8) + 6], RAM[(decBlock * 8) + 5], RAM[(decBlock * 8) + 4], RAM[(decBlock * 8) + 3], RAM[(decBlock * 8) + 2], RAM[(decBlock * 8) + 1], RAM[(decBlock * 8)]}
}
