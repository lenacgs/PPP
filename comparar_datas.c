// compara datas. retorna 1 se a segunda data for menos que a primeira
#include <stdio.h>
#include <stdlib.h>

int comparar_datas(Data data1, Data data2) {
  if (data1.ano < data2.ano)
    return -1;
  else if (data1.ano > data2.ano)
    return 1;

  if (data1.ano == data2.ano) {
     if (data1.mes < data2.mes)
          return -1;
     else if (data1.mes > data2.mes)
          return 1;
     else if (data1.dia < data2.dia)
          return -1;
     else if(data1.dia > data2.dia)
          return 1;
     else
          return 0;
  }
  return 0;
}
