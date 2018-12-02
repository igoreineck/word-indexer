#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexer.h"

void mostra_char(void *info) {
    char *p = info;
    printf("%s\n", p);
}

void mostra_int(void *info) {
    int p* = info;
    printf("%d\n", p);
}

int readFile(void) {
    FILE *arquivo;
    Lista listaDeStrings;

    inicializaLista(&listaDeStrings, sizeof(char)*WORD_LENGTH_DEFAULT);

    char strAux[WORD_LENGTH_DEFAULT] = {' '};

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
            memset(strAux, 0, strlen(strAux)*sizeof(char));
            stringIterator = 0;
        }

        iterator++;
    }

    mostraLista(listaDeStrings, mostra_char);
    destroy(&listaDeStrings);

    fclose(arquivo);

    return EXIT_SUCCESS;
}