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
char hexToBin(char * hex){
    int i = 0;
    char final[16];
    char finalbueno[10];
    while (hex[i]) {
        switch (hex[i]) {
            case '0':
                strcat(final, "0000");
                break;
            case '1':
                strcat(final, "0001");
                break;
            case '2':
                strcat(final, "0010");
                break;
            case '3':
                strcat(final, "0011");
                break;
            case '4':
                strcat(final, "0100");
                break;
            case '5':
                strcat(final, "0101");
                break;
            case '6':
                strcat(final, "0110");
                break;
            case '7':
                strcat(final, "0111");
                break;
            case '8':
                strcat(final, "1000");
                break;
            case '9':
                strcat(final, "1001");
                break;
            case 'A':
                strcat(final, "1010");
                break;
            case 'B':
                strcat(final, "1011");
                break;
            case 'C':
                strcat(final, "1100");
                break;
            case 'D':
                strcat(final, "1101");
                break;
            case 'E':
                strcat(final, "1110");
                break;
            case 'F':
                strcat(final, "1111");
                break;
        }
        i++;
    }
    for (int j = 0; j < 11; ++j) {
        finalbueno[j]=final[j+7];
    }
    return finalbueno;
}
int comprobarETQ(char * ETQ,char * bloque,T_LINEA_CACHE * linea){
int i;
    if (bloque[0]=='0'){
        if (bloque[1]=='0'){
            i=0;
        } else if (bloque[1]=='1'){
            i=1;
        }
    } else if (bloque[0]=='1'){
        if (bloque[1]=='0'){
            i=2;
        } else if (bloque[1]=='1'){
            i=3;
        }
    }

    if (linea[i].ETQ==ETQ){
        return 1;
    } else{
        return 0;
    }
}
