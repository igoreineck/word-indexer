#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexer.h"

// abrir arquivo
// fazer varredura no arquivo
// armazenar em memória o conteúdo do arquivo
// direcionar o conteúdo para o indexador
// retornar o conteúdo do indexador para o usuário

int processar(char *path) {
    FILE *arquivo;

    char conteudo;

    if ((arquivo = fopen(path, "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return ERROR;
    }

    fscanf(arquivo, "%s", &conteudo);

    fclose(arquivo);

    return SUCCESS;
}