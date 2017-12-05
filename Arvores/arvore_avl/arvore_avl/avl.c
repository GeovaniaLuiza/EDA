#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/* FB � Fator de balanceamento */
int fb(No* no) {
    int esquerda = 0, direita = 0;

    if (no->esquerda != NULL)
        esquerda = altura(no->esquerda) + 1;

    if (no->direita != NULL)
        direita = altura(no->direita) + 1;

    return (esquerda - direita);
}

int altura(No* no) {
    int esquerda = 0, direita = 0;

    if (no->esquerda != NULL)
        esquerda = altura(no->esquerda) + 1;

    if (no->direita != NULL)
        direita = altura(no->direita) + 1;

    return (esquerda > direita ? esquerda : direita); // express�o tern�ria
}

/* RSE � Rota��o Simples a Esquerda */
No* rse(No* no) {
    printf("\nRSE: %f", no->valor);

    No* pai = no->pai;
    No* direita = no->direita;

    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    return direita;
}

/* RSD � Rota��o Simples a Direita */
No* rsd(No* no) {
    printf("\nRSD: %f", no->valor);

    No* pai = no->pai;
    No* esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    return esquerda;
}

/* RDE � Rota��o Dupla a Esquerda */
No* rde(No* no) {
    no->direita = rsd(no->direita);
    return rse(no);
}

/* RDD � Rota��o Dupla a Direita */
No* rdd(No* no) {
    no->esquerda = rse(no->esquerda);
    return rsd(no);
}
