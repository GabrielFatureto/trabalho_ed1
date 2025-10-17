#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "retangulo.h"

typedef struct {
    int i;
    double x, y, w, h;
    char *corb, *corp;
} Rectangle;

RETANGULO cria_retangulo(int i, double x, double y, double w, double h, char* corb, char* corp) {
    Rectangle* r = (Rectangle*)malloc(sizeof(Rectangle));
    if(r == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    r->i = i;
    r->x = x;
    r->y = y;
    r->w = w;
    r->h = h;

    c->corb = (char*)malloc(strlen(corb)+1);
    if(c->corb == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(c->corb, corb);

    c->corp = (char*)malloc(strlen(corp)+1);
    if(c->corp == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(c->corp, corp);

    return (RETANGULO) r;
}

int get_i_retangulo (RETANGULO r){
    return ((Rectangle*)r)->i;
}

double get_x_retangulo (RETANGULO r){
    return ((Rectangle*)r)->x;
}

double get_y_retangulo (RETANGULO r){
    return ((Rectangle*)r)->y;
}

double get_w (RETANGULO r){
    return ((Rectangle*)r)->h;
}

double get_h (RETANGULO r){
    return ((Rectangle*)r)->h;
}

char* get_corb (RETANGULO r){
    return ((Rectangle*)r)->corb;
}

char* get_corp (RETANGULO r){
    return ((Rectangle*)r)->corp;
}

double get_area (RETANGULO r){
    return ((Rectangle*)r)->w * ((Rectangle*)r)->h;
}

void set_i (RETANGULO r, int i){
    ((Rectangle*)r)->i = i;
}

void set_x_retangulo (RETANGULO r, double x){
    ((Rectangle*)r)->x = x;
}

void set_y_retangulo (RETANGULO r, double y){
    ((Rectangle*)r)->y = y;
}

void set_w (RETANGULO r, double w){
    ((Rectangle*)r)->w = w;
}

void set_h (RETANGULO r, double h){
    ((Rectangle*)r)->h = h;
}

void set_corb (RETANGULO r, char* corb){
    strcpy(((Rectangle*)r)->corb, corb);
}

void set_corp (RETANGULO r, char* corp){
    strcpy(((Rectangle*)r)->corp, corp);
}

void excluir_retangulo (RETANGULO r){
    free(((Rectangle*)r)->corb);
    free(((Rectangle*)r)->corp);
    free(r);
}