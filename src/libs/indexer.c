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

void mostra_lista(Lista lista) {
    Elemento *p = lista.cabeca;

    while (p != NULL) {
        printf("%p\n", p->info);
        p = p->proximo;
    }
}

int readFile(void) {
    FILE *arquivo;
    Lista listaDeStrings;

    inicializaLista(&listaDeStrings, sizeof(Node));

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
            // int n_ocorrencias = 0;
            Lista ocorrencias;

            inicializaLista(&ocorrencias, sizeof(int));

            insereNoFim(&ocorrencias, &lineIterator);

            // int search = buscaString(listaDeStrings, strAux);

            // if (search != 0) {
            //     strcpy(no.palavra, strAux);
            //     n_ocorrencias++;
            // } else {
            //     n_ocorrencias += 2;
            // }

            // no.numero_ocorrencias = n_ocorrencias;
            no.ocorrencias = &ocorrencias;

            insereNoFim(&listaDeStrings, &no);

            memset(strAux, 0, strlen(strAux)*sizeof(char));

            // destroy(&ocorrencias);

            stringIterator = 0;

            if (c == '\n')
                lineIterator++;
        }

        iterator++;
    }

    mostraListaComStruct(listaDeStrings, mostra_char, mostra_int, mostra_lista);
    destroy(&listaDeStrings);

    fclose(arquivo);

    return EXIT_SUCCESS;
}