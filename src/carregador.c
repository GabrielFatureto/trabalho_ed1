#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carregador.h"
#include "pilha.h"
#include "forma.h"


CARREGADOR criar_Carregador() {
    return pilha_criar();
}

void push_topo (CARREGADOR c, void *Forma) {
    pilha_empilhar((PILHA)c, Forma);
}

void* pop_topo (CARREGADOR c) {
    return pilha_desempilhar((PILHA)c);
}

void* get_topo (CARREGADOR c) {
    return pilha_topo((PILHA)c);
}

int CarregadorVazio (CARREGADOR c) {
    return pilha_esta_vazia((PILHA)c);
}

void destruir_carregador (CARREGADOR c) {
    destruir_pilha((PILHA)c);
}
