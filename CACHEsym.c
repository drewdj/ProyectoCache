#include "CACHEsym.h"

void hexToBin(char * hex,char * accesoArray){//"mascara DIY" entra un char con la direccion en HEX y paso por referencia a BIN
    int i = 0;
    char final[16]="\0";
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
        accesoArray[j]=final[j+6];
    }
}

int binToDec(char * bin){//Conversion BIN a DEC
  int decNumber=0;
  int intBin;
  intBin = atoi(bin);
  for(int i = 0; intBin; i++, intBin /= 10){//suma de potencias de 2 en funcion de la posicion del 1 en BIN
        if (intBin % 10){
            decNumber = decNumber + pow(2, i);
        }
      }

  return decNumber;
}

int comprobarETQ(int ETQ,char * bloque,T_LINEA_CACHE * linea){//Paso de ETQ de BIN a DEC y comparacion con la linea en Cache
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

void actualizadorCache(int decEtq,int decBlock, T_LINEA_CACHE * cache, unsigned char * RAM){//Acualizar cache con los valores buscadon en RAM
  printf("Cargando el bloque %d en la linea %d\n", decBlock, decBlock);
  cache[decBlock].ETQ = decEtq;
  cache[decBlock].Datos[0] = RAM[(decBlock * 8 + decEtq*32) + 7];
  cache[decBlock].Datos[1] = RAM[(decBlock * 8 + decEtq*32) + 6];
  cache[decBlock].Datos[2] = RAM[(decBlock * 8 + decEtq*32) + 5];
  cache[decBlock].Datos[3] = RAM[(decBlock * 8 + decEtq*32) + 4];
  cache[decBlock].Datos[4] = RAM[(decBlock * 8 + decEtq*32) + 3];
  cache[decBlock].Datos[5] = RAM[(decBlock * 8 + decEtq*32) + 2];
  cache[decBlock].Datos[6] = RAM[(decBlock * 8 + decEtq*32) + 1];
  cache[decBlock].Datos[7] = RAM[decBlock * 8 + decEtq*32];
}

char lectorAcceso(int decBlock,int decPalabra, T_LINEA_CACHE * cache){//Lee cache para devolver la palabra accedida
  char palabraCache = cache[decBlock].Datos[decPalabra];
  return palabraCache;
}
