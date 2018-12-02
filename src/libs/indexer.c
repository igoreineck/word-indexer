#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexer.h"

void mostra_char(void *info) {
    char *p = info;
    printf("%s\n", p);
}

void mostra_int(void *info) {
    int *p = info;
    printf("%ls\n", p);
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
    int lineIterator = 1;

    while (!feof(arquivo)) {
        char c = fgetc(arquivo);

        if (c != ' ' && c != '\n' && c != ',' && c != '.') {
            strAux[stringIterator] = c;
            stringIterator++;
        } else {
            Node no;
            Lista ocorrenciasWord;

            inicializaLista(&ocorrenciasWord, sizeof(int));

            no.palavra = strAux;

            insereNoFim(&ocorrenciasWord, &lineIterator);

            insereNoFim(&listaDeStrings, &no);

            memset(strAux, 0, strlen(strAux)*sizeof(char));

            destroy(&ocorrenciasWord);

            stringIterator = 0;

            if (c == '\n')
                lineIterator++;
        }

        iterator++;
    }

    mostraLista(listaDeStrings, mostra_char);
    destroy(&listaDeStrings);

    fclose(arquivo);

    return EXIT_SUCCESS;
}