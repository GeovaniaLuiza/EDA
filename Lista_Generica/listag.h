#include "boolean.h"

typedef struct {
    struct No* anterior; //ponteiro para o n� anterior da lista
    struct No* proximo; //ponteiro para o pr�ximo n� da lista
    void *v; //conte�do de um n� arbitr�rio da lista
} No;

typedef struct lista {
    No* cabeca; //inicio da lista
    No* cauda; //fim da lista
    int tamanho; //tamanho do conte�do em bytes
} Lista;

void adicionaInicio(Lista *l, void *v);
void adicionaFim(Lista *l, void *v);
void percorre(Lista *l, void (callback)(void*);
