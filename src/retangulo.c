#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "retangulo.h"

typedef struct Rectangle{
    int i;
    double x, y, w, h;
    char *corb, *corp;
} retangulo;

retangulo* criaRetangulo(int i, double x, double y, double w, double h, char* corb, char* corp) {
    retangulo* r = (retangulo*)malloc(sizeof(retangulo));
    if(r == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    r->i = i;
    r->x = x;
    r->y = y;
    r->w = w;
    r->h = h;

    r->corb = (char*)malloc(strlen(corb)+1);
    if(r->corb == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(r->corb, corb);

    r->corp = (char*)malloc(strlen(corp)+1);
    if(r->corp == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(r->corp, corp);

    return (retangulo*) r;
}

int getIDretangulo (retangulo* r){
    return ((retangulo*)r)->i;
}

double getXretangulo (retangulo* r){
    return ((retangulo*)r)->x;
}

double getYretangulo (retangulo* r){
    return ((retangulo*)r)->y;
}

double getLarguraRetangulo (retangulo* r){
    return ((retangulo*)r)->w;
}

double getAlturaRetangulo (retangulo* r){
    return ((retangulo*)r)->h;
}

char* getCorbRetangulo (retangulo* r){
    return ((retangulo*)r)->corb;
}

char* getCorpRetangulo (retangulo* r){
    return ((retangulo*)r)->corp;
}

void setIDRetangulo (retangulo* r, int i){
    ((retangulo*)r)->i = i;
}

void setXretangulo (retangulo* r, double x){
    ((retangulo*)r)->x = x;
}

void setYretangulo (retangulo* r, double y){
    ((retangulo*)r)->y = y;
}

void setLarguraRetangulo (retangulo* r, double w){
    ((retangulo*)r)->w = w;
}

void setAlturaRetangulo (retangulo* r, double h){
    ((retangulo*)r)->h = h;
}

void setCorbRetangulo (retangulo* r, char* corb){
    strcpy(((retangulo*)r)->corb, corb);
}

void setCorpRetangulo (retangulo* r, char* corp){
    strcpy(((retangulo*)r)->corp, corp);
}

double calcAreaRetangulo(retangulo *r) {
	return ((r -> w) * (r -> h));
}

void destrutorRetangulo (retangulo* r){
    free(((retangulo*)r)->corb);
    free(((retangulo*)r)->corp);
    free(r);
}