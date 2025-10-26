#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


typedef struct No{
    void* dado;       
    struct No* proximo;
} No;


typedef struct {
    No* topo;         
    int tamanho;
} Pilha;

PILHA pilha_criar() {
    Pilha* p_interno = (Pilha*) malloc(sizeof(Pilha));
    if (p_interno != NULL) {
        p_interno->topo = NULL;
        p_interno->tamanho = 0;
    }
    return (PILHA)p_interno;
}

bool pilha_empilhar(PILHA p, void* dado) {
    Pilha* p_interno = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        return false; 
    }

    novo_no->dado = dado;
    novo_no->proximo = p_interno->topo; 
    p_interno->topo = novo_no;          
    p_interno->tamanho++;

    return true;
}

void* pilha_desempilhar(PILHA p) {
    Pilha* p_interno = (Pilha*)p;
    if (p == NULL || pilha_esta_vazia(p)) {
        return NULL;
    }

    No* no_removido = p_interno->topo;
    void* dado_retornado = no_removido->dado;

    p_interno->topo = p_interno->topo->proximo; 

    free(no_removido); 
    p_interno->tamanho--;

    return dado_retornado;
}

void* pilha_topo(PILHA p) {
    Pilha* p_interno = (Pilha*)p;
    if (p_interno == NULL || pilha_esta_vazia(p)) {
        return NULL;
    }
    return p_interno->topo->dado;
}

int pilha_tamanho(PILHA p) {
    Pilha* p_interno = (Pilha*)p;
    if (p_interno == NULL) return 0;
    return p_interno->tamanho;
}

bool pilha_esta_vazia(PILHA p) {
    Pilha* p_interno = (Pilha*)p;
    if (p_interno == NULL) return true;
    return p_interno->tamanho == 0;
}

void destruir_pilha(PILHA p){
    while(!pilha_esta_vazia(p)){
        pilha_desempilhar(p);
    }
    free(p);
}