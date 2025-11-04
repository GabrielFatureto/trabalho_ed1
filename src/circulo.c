
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

#define pi 3.1415926535897

typedef struct Circle{
    int i;
    double x, y, r;
    char *corb, *corp;
} circulo;

circulo* criaCirculo(int i, double x, double y, double r, char* corb, char* corp){
    circulo* c = (circulo*)malloc(sizeof(circulo));
    if(c == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    c->i = i;
    c->x = x;
    c->y = y;
    c->r = r;

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

    return (circulo*) c;
}

int getIDCirculo(circulo* c){
    return ((circulo*)c)->i;
}

double getXCirculo(circulo* c){
    return ((circulo*)c)->x;
}

double getYCirculo(circulo* c){
    return ((circulo*)c)->y;
}

double getRaioCirculo(circulo* c){
    return ((circulo*)c)->r;
}

char* getCorbCirculo(circulo* c){
    return ((circulo*)c)->corb;
}

char* getCorpCirculo(circulo* c){
    return ((circulo*)c)->corp;
}

void setIDCirculo (circulo* c, int i){
    ((circulo*)c)->i = i;
}

void setXCirculo(circulo* c, double x){
    ((circulo*)c)->x = x;
}

void setYCirculo(circulo* c, double y){
    ((circulo*)c)->y = y;
}

void setRaioCirculo(circulo* c, double r){
    ((circulo*)c)->r = r;
}

void setCorbCirculo(circulo* c, char* corb){
    strcpy(((circulo*)c)->corb, corb);
}

void setCorpCirculo(circulo* c, char* corp){
    strcpy(((circulo*)c)->corp, corp);
}

double calcAreaCirculo(circulo *c) {
	return pi * ((c -> r) * (c -> r));
}

void destrutorCirculo(circulo* c){
    free(((circulo*)c)->corb);
    free(((circulo*)c)->corp);
    free(c);
}