#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


typedef struct {
    void* dado;       
    struct No* proximo;
} No;


typedef struct {
    No* topo;         
    int tamanho;
} Pilha;

PILHA pilha_criar() {
    PILHA p = (PILHA) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
        p->tamanho = 0;
    }
    return p;
}

bool pilha_empilhar(PILHA p, void* dado) {
    if (p == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        return false; 
    }

    novo_no->dado = dado;
    novo_no->proximo = p->topo; 
    p->topo = novo_no;          
    p->tamanho++;

    return true;
}

void* pilha_desempilhar(PILHA p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        return NULL;
    }

    No* no_removido = p->topo;
    void* dado_retornado = no_removido->dado;

    p->topo = p->topo->proximo; 

    free(no_removido); 
    p->tamanho--;

    return dado_retornado;
}

void* pilha_topo(PILHA p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        return NULL;
    }
    return p->topo->dado;
}

int pilha_tamanho(PILHA p) {
    if (p == NULL) return 0;
    return p->tamanho;
}

bool pilha_esta_vazia(PILHA p) {
    if (p == NULL) return true;
    return p->tamanho == 0;
}

void destruir_pilha(PILHA p){
    while(!pilha_esta_vazia(p)){
        pilha_desempilhar(p);
    }
    free(p);
}