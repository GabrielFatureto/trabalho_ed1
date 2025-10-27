#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


typedef struct No{
    void* dado;      
    struct No* proximo;
} No;

typedef struct {
    No* frente;      
    No* tras;        
    int tamanho;
} Fila;


FILA fila_criar() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->frente = NULL;
        f->tras = NULL;
        f->tamanho = 0;
    }
    return (FILA)f;
}


bool fila_enfileirar (FILA f, void* dado) {
    Fila* f_interno = (Fila*)f;
    if (f_interno == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        return false; 
    }

    novo_no->dado = dado;
    novo_no->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f_interno->frente = novo_no;
        f_interno->tras = novo_no;
    } else {
        f_interno->tras->proximo = novo_no;
        f_interno->tras = novo_no;
    }

    f_interno->tamanho++;
    return true;
}

void* fila_desenfileirar(FILA f) {
    Fila* f_interno = (Fila*)f;
    if (f_interno == NULL || fila_esta_vazia(f)) {
        return NULL;
    }

    No* no_removido = f_interno->frente;
    void* dado_retornado = no_removido->dado;

    f_interno->frente = f_interno->frente->proximo;

    if (f_interno->frente == NULL) {
        f_interno->tras = NULL;
    }

    f_interno->tamanho--;

    return dado_retornado;
}

void* fila_frente(FILA f) {
    Fila* f_interno = (Fila*)f;
    if (f_interno == NULL || fila_esta_vazia(f)) {
        return NULL;
    }
    return f_interno->frente->dado;
}

int fila_tamanho(FILA f) {
    Fila* f_interno = (Fila*)f;
    if (f_interno == NULL) return 0;
    return f_interno->tamanho;
}

No* getProxNode(No* no_atual) {
    if (no_atual == NULL) {
        return NULL;
    }
    return no_atual->proximo;
}

void* getItemNode(No* no_atual) {
    if (no_atual == NULL) {
        return NULL;
    }
    return no_atual->dado;
}

bool fila_esta_vazia(FILA f) {
    Fila* f_interno = (Fila*)f;
    if (f_interno == NULL) return true;
    return f_interno->tamanho == 0;
}

void destruir_fila(FILA f, void (*excluir_dado)(void*)) {
    while (!fila_esta_vazia(f)) {
        void* dado = fila_desenfileirar(f); // Pega o dado
        if (excluir_dado != NULL) {
            excluir_dado(dado); // Libera o dado
        }
    }
    free(f); // Libera a fila
}