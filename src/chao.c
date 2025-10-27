#include "chao.h"
#include "fila.h"
#include "forma.h"
#include <stdio.h>
#include <stdlib.h>

struct stChao {
    FILA *filaChao;
};

chao *criaChao() {
    chao *c = (chao*) malloc(sizeof(chao));
    if (c == NULL) {
        printf("Erro ao criar o chao!\n");
        return NULL;
    }
    c->filaChao = fila_criar();
    printf("Chão criado com sucesso!\n");
    return c;
}


void adicionaNoChao(chao *c, FORMA *f) {
    if (c == NULL || f == NULL) {
        return;
    }

    fila_enfileirar(c->filaChao, f);
}

FORMA *retiraDoChao(chao *c) {
    if (c == NULL) return NULL;

    FORMA *removido = fila_desenfileirar(c -> filaChao);

    return removido;
}

void destrutorChao(chao *chao) {
    if (chao == NULL) return;


    if (chao -> filaChao != NULL) {
        destruir_fila(chao -> filaChao);
        chao -> filaChao = NULL;
    }

    free(chao);
}


FILA *getFilaDoChao(chao *c) {
    if (c == NULL) return NULL;
    return c -> filaChao;
}

bool chaoEstaVazio(chao *c) {
    if (c == NULL) return true;
    return fila_esta_vazia(c -> filaChao);
}