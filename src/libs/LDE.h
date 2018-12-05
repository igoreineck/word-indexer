#define ERRO_LISTA_VAZIA -1
#define WORD_LENGTH_DEFAULT 15

typedef struct elemento {
	void *info;
	struct elemento *anterior, *proximo;
} Elemento;

typedef struct {
	int tamanhoInfo;
	Elemento *cabeca;
} Lista;

typedef struct {
    char palavra[WORD_LENGTH_DEFAULT];
    int numero_ocorrencias;
    Lista *ocorrencias;
} Node;

void inicializaLista(Lista *lista, int tamanho);
int listaVazia(Lista lista);
int insereNoInicio(Lista *lista, void *info);
int removeDoInicio(Lista *lista, void *info);
int insereNoFim(Lista *lista, void *info);
int removeDoFim(Lista *lista, void *info);
void mostraLista(Lista lista, void (*mostraInfo)(void *));
void mostraListaComStruct(Lista lista, void (*mostraInfoComStr)(void *), void (*mostraInfoComInt)(void *), void (*mostraInfoComLista)(void *));
int buscaString(Lista lista, char string);
int destroy(Lista *lista);
// void inverte(Lista *lista);