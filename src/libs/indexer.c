#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexer.h"

void mostra_float(void *info) {
    char *p = (char *) info;
    printf("%s\n", p);
}

int readFile(void) {
    FILE *arquivo;
    Lista listaDeStrings;

    inicializaLista(&listaDeStrings, sizeof(char));

    char strAux[10];

    if ((arquivo = fopen("../datafiles/text.txt", "r+")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return ERROR;
    }

    int iterator = 0;
    int stringIterator = 0;
    while (!feof(arquivo)) {
        char c = fgetc(arquivo);

        if (c != ' ' && c != '\n' && c != ',' && c != '.') {
            strAux[stringIterator] = c;
            stringIterator++;
        } else {
            insereNoFim(&listaDeStrings, &strAux);
            // printf("%s\n", strAux);
            memset(strAux, 0, strlen(strAux)*sizeof(char));
            stringIterator = 0;
        }

        iterator++;
    }

    mostraLista(listaDeStrings, mostra_float);

    fclose(arquivo);

    return SUCCESS;
}