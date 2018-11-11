#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexer.h"

// abrir arquivo
// fazer varredura no arquivo
// armazenar em memória o conteúdo do arquivo
// direcionar o conteúdo para o indexador
// retornar o conteúdo do indexador para o usuário
void mostra_lista(void *info) {
    char *p = (char *) info;
    printf("%s\n", p);
}

int processar(void) {
    FILE *arquivo;
    Lista listaDeStrings;

    inicializaLista(&listaDeStrings, sizeof(char));

    char buffer[100];

    if ((arquivo = fopen("../datafiles/text.txt", "r+")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return ERROR;
    }

    fread(buffer, sizeof(buffer), 1, arquivo);

    for (int i = 0; i < strlen(buffer); i++) {
        char strAux;

        if (buffer[i] != ' ' && buffer[i] != '\n') {
            strcat(strAux, buffer[i]);
        } else {
            // insereNoFim(&listaDeStrings, &strAux);
            // strAux = NULL;
        }
    }

    // mostraLista(listaDeStrings, mostra_lista);

    fclose(arquivo);

    return SUCCESS;
}