#include "LDE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Elemento *aloca_elemento(void *x, int tamanho);

Elemento *aloca_elemento(void *x, int tamanho) {
	Elemento *p = malloc(sizeof(Elemento));

	if (p == NULL)
		return NULL;

	p->info = malloc(tamanho);

	if (p->info == NULL) {
		free(p);

		return NULL;
	}

	memcpy(p->info, x, tamanho);

	return p;
}

void inicializaLista(Lista *lista, int tamanho) {
	lista->tamanhoInfo = tamanho;
	lista->cabeca = NULL;
}

int listaVazia(Lista lista) {
	return lista.cabeca == NULL;
}

int insereNoInicio(Lista *lista, void *info) {
	Elemento *p = aloca_elemento(info, lista->tamanhoInfo);

	p->info = malloc(lista->tamanhoInfo);

	if (p->info == NULL) {
		free(p);

		return 0;
	}

	memcpy(p->info, info, lista->tamanhoInfo);
	p->proximo = lista->cabeca;
	p->anterior = NULL;
	lista->cabeca = p;

	return 1;
}

int removeDoInicio(Lista *lista, void *info) {
	if (listaVazia(*lista))
		return ERRO_LISTA_VAZIA;

	Elemento *elemento_existente = lista->cabeca;

	lista->cabeca = elemento_existente->proximo;
	memcpy(info, elemento_existente->info, lista->tamanhoInfo);
	free(elemento_existente->info);
	free(elemento_existente);

	if (lista->cabeca != NULL)
		lista->cabeca->anterior = NULL;

	return 1;
}

int insereNoFim(Lista *lista, void *info) {
	if (listaVazia(*lista))
		return insereNoInicio(lista, info);

	Elemento *p = lista->cabeca;

	while (p->proximo != NULL) {
		p = p->proximo;
	}

	Elemento *novo = aloca_elemento(info, lista->tamanhoInfo);

	if (novo == NULL)
		return 0;

	p->proximo = novo;
	novo->anterior = p;
	novo->proximo = NULL;

	return 1;
}

int removeDoFim(Lista *lista, void *info) {
	if (listaVazia(*lista))
		return ERRO_LISTA_VAZIA;

	if (lista->cabeca->proximo == NULL)
		return removeDoInicio(lista, info);

	Elemento *p = lista->cabeca;

	while (p->proximo->proximo != NULL) {
		p = p->proximo;
	}

	memcpy(info, p->proximo->info, lista->tamanhoInfo);
	free(p->proximo->info);
	free(p->proximo);

	p->proximo = NULL;

	return 1;
}

void mostraLista(Lista lista, void (*mostraInfo)(void *)) {
	if (listaVazia(lista)) {
		printf("Lista vazia!\n");
	} else {

		Elemento *p = lista.cabeca;

		while (p != NULL) {
			mostraInfo(p->info);
			p = p->proximo;
		}
	}
}

void mostraListaComStruct(Lista lista, void (*mostraInfoComStr)(void *), void (*mostraInfoComInt)(void *), void (*mostraInfoComLista)(void *)) {
	if (listaVazia(lista)) {
	    printf("Lista vazia!\n");
	} else {
		Elemento *el = lista.cabeca;

		while (el != NULL) {
			el = el->proximo;

			Node *conteudoStruct = el->info;

			mostraInfoComStr(conteudoStruct->palavra);
			mostraInfoComInt(conteudoStruct->numero_ocorrencias);
			// mostraInfoComLista(conteudoStruct->ocorrencias);

		}
	}
}

int destroy(Lista *lista) {
	Elemento *p = lista->cabeca;

	while (p != NULL) {
		p = p->proximo;
	}

	while (p != NULL) {
		p = p->anterior;
		free(p->proximo);
	}

	return EXIT_SUCCESS;
}

int buscaString(Lista lista, char string) {
	Elemento *p = lista.cabeca;

	while (p != NULL) {
		p = p->proximo;

		if (strcmp(p->info, string) == 0)
			return EXIT_SUCCESS;

		return EXIT_FAILURE;
	}
}