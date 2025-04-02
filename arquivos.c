#include "aviao.h"
#include <stdio.h>
#include <curses.h>
#include <time.h>

int * leArquivoNumeros(char * nomeArquivo){
    FILE * arq = fopen(nomeArquivo, "r");
    //70 sempre será o tamanho do vetor

    char vet[70][7];
    char linha[7];
    int i = 0;
    while(!feof(arq))
    {
        fgets(vet[i], 11, arq);
        i++;
}
fclose(arq);
}
