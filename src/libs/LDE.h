#define ERRO_LISTA_VAZIA -1

typedef struct elemento {
	void *info;
	struct elemento *anterior, *proximo;
} Elemento;

typedef struct {
	int tamanhoInfo;
	Elemento *cabeca;
} Lista;

void inicializaLista(Lista *lista, int tamanho);
int listaVazia(Lista lista);
int insereNoInicio(Lista *lista, void *info);
int removeDoInicio(Lista *lista, void *info);
int insereNoFim(Lista *lista, void *info);
int removeDoFim(Lista *lista, void *info);
void mostraLista(Lista lista, void (*mostraInfo)(void *));
// void inverte(Lista *lista);