#include "LDE.h"

#define SUCCESS 0
#define ERROR 1
#define WORD_LENGTH_DEFAULT 15

typedef struct node {
    char *palavra;
    int numero_ocorrencias;
    Lista *ocorrencias;
} Node;

int readFile(void);
