#include "LDE.h"

#define SUCCESS 0
#define ERROR 1

typedef struct no {
    void *palavra;
    int numero_ocorrencias;
    Lista *ocorrencias;
} No;

int processar(void);