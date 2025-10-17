#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disparador.h"
#include "carregador.h"
#include "pilha.h"
#include "fila.h"

typedef struct {
    int i;
    double x, y;
    CARREGADOR car_esq;
    CARREGADOR car_dir;
} Disparador;

DISPARADOR cria_disparador (int id, double x, double y) {
    Disparador* d = (Disparador*)malloc(sizeof(Disparador));
    if (d == NULL) {
        printf("Erro ao tentar alocar memória para o disparador.\n");
        exit(1);
    }
    d->id = id;
    d->x = x;
    d->y = y;
    return d;
}

void pd (DISPARADOR d, double x, double y) {
    ((Disparador*)d)->x = x;
    ((Disparador*)d)->y = y;
}

void atch (DISPARADOR d, CARREGADOR car_esq, CARREGADOR car_dir) {
    ((Disparador*)d)->car_esq = car_esq;
    ((Disparador*)d)->car_dir = car_dir;
}

void shft (DISPARADOR d, char lado, int n) {
    if (lado == 'd') { 
        if (((Disparador*)d)->pd != NULL) {
            pilha_empilhar (((Disparador*)d)->car_esq, ((Disparador*)d)->pd);
        }
        ((Disparador*)d)->pd = get_conteudo_pilha (((Disparador*)d)->car_dir);
        pilha_desempilhar (((Disparador*)d)->car_dir);
        for (int i = 0; i < n-1; i++) {
            pilha_empilhar (((Disparador*)d)->car_esq, ((Disparador*)d)->pd);
            ((Disparador*)d)->pd = get_conteudo_pilha (((Disparador*)d)->car_dir);
            pilha_desempilhar (((Disparador*)d)->car_dir);
        }
    }
    if (lado == 'e') {
        if (((Disparador*)d)->pd != NULL) {
            pilha_empilhar (((Disparador*)d)->car_dir, ((Disparador*)d)->pd);
        }
        ((Disparador*)d)->pd = pilha_topo (((Disparador*)d)->car_esq);
        pilha_desempilhar (((Disparador*)d)->car_esq);
        for (int i = 0; i < n-1; i++) {
            insere_pilha (((Disparador*)d)->car_dir, ((Disparador*)d)->pd);
            ((Disparador*)d)->pd = pilha_topo (((Disparador*)d)->car_esq);
            pilha_desempilhar (((Disparador*)d)->car_esq);
        }
    } else {
        printf ("ERRO. Não foi possível identifical qual botão deveria ser apertado.\n");
        exit(1);
    }
}

void dsp (DISPARADOR d, double dx, double dy) {
    ((Disparador*)d)->pd->x = ((Disparador*)d)->x + dx;
    ((Disparador*)d)->pd->y = ((Disparador*)d)->y + dy;
    fila_enfileirar (arena, ((Disparador*)d)->pd);
    ((Disparador*)d)->pd = NULL;
}

double get_x_disparador (DISPARADOR d) {
    return ((Disparador*)d)->x;
}

double get_y_disparador (DISPARADOR d) {
    return ((Disparador*)d)->y;
}

void libera_memoria_disparador (DISPARADOR d) {}