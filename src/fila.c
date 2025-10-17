#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


typedef struct {
    void* dado;      
    struct No* proximo;
} No;

typedef struct {
    No* frente;      
    No* tras;        
    int tamanho;
} Fila;


FILA fila_criar() {
    Fila f = (FILA) malloc(sizeof(Fila));
    if (f != NULL) {
        f->frente = NULL;
        f->tras = NULL;
        f->tamanho = 0;
    }
    return f;
}


bool fila_enfileirar (FILA f, void* dado) {
    if (f == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        return false; 
    }

    novo_no->dado = dado;
    novo_no->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f->frente = novo_no;
        f->tras = novo_no;
    } else {
        f->tras->proximo = novo_no;
        f->tras = novo_no;
    }

    f->tamanho++;
    return true;
}

void* fila_desenfileirar(FILA f) {
    if (f == NULL || fila_esta_vazia(f)) {
        return NULL;
    }

    No* no_removido = f->frente;
    void* dado_retornado = no_removido->dado;

    f->frente = f->frente->proximo;

    if (f->frente == NULL) {
        f->tras = NULL;
    }

    f->tamanho--;

    return dado_retornado;
}

void* fila_frente(FILA f) {
    if (f == NULL || fila_esta_vazia(f)) {
        return NULL;
    }
    return f->frente->dado;
}

int fila_tamanho(FILA f) {
    if (f == NULL) return 0;
    return f->tamanho;
}

bool fila_esta_vazia(FILA f) {
    if (f == NULL) return true;
    return f->tamanho == 0;
}

void destruir_fila(FILA f){
    while(!fila_esta_vazia(f)){
        fila_desenfileirar(f);
    }
    free(f);
}