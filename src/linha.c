#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linha.h"

typedef struct {
    int i;
    double x1, y1, x2, y2;
    char *cor;
    bool eh_pontilhada;
} Line;

LINHA cria_linha(int i, double x1, double y1, double x2, double y2, char* cor) {
    Line* l = (Line*)malloc(sizeof(Line));
    if(l == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    l->i = i;
    l->x1 = x1;
    l->y1 = y1;
    l->x2 = x2;
    l->y2 = y2;

    l->cor = (char*)malloc(strlen(cor)+1);
    if(l->cor == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(l->cor, cor);

    return (LINHA) l;
}

int get_i_linha (LINHA l){
    return ((Line*)l)->i;
}

double get_x1_linha (LINHA l){
    return ((Line*)l)->x1;
}

double get_y1_linha (LINHA l){
    return ((Line*)l)->y1;
}

double get_x2_linha (LINHA l){
    return ((Line*)l)->x2;
}

double get_y2_linha (LINHA l){
    return ((Line*)l)->y2;
}

char* get_cor_linha (LINHA l){
    return ((Line*)l)->cor;
}

bool getEh_pontilhada(LINHA l) {
	return ((Line*)l)-> eh_pontilhada;
}

void set_x1_linha (LINHA l, double x1){
    ((Line*)l)->x1 = x1;
}

void set_x2_linha (LINHA l, double x2){
    ((Line*)l)->x2 = x2;
}

void set_y1_linha (LINHA l, double y1){
    ((Line*)l)->y1 = y1;
}

void set_y2_linha (LINHA l, double y2){
    ((Line*)l)->y2 = y2;
}

void excluir_linha (LINHA l){
    free(((Line*)l)->cor);
    free(l);
}