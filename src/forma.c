#include <stdio.h>
#include <math.h>
#include "Forma.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "disparador.h"
#include "pilha.h"

typedef struct {
    FORMA geometrica;
    char tipo;
} Forma;

FORMA cria_Forma_circulo (char tipo, int id, double x, double y, double r, char* corb, char* corp) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da Forma. \n");
        exit (1);
    }
    F->geometrica = cria_circulo (id, x, y, r, corb, corp);
    F->tipo = 'c';
    return ((Forma*)F);
}

FORMA cria_Forma_retangulo (char tipo, int id, double x, double y, double w, double h, char* corb, char* corp) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da Forma. \n");
        exit (1);
    }
    F->geometrica = cria_retangulo (id, x, y, w, h, corb, corp);
    F->tipo = 'r';
    return ((Forma*)F);
}

FORMA cria_Forma_linha (char tipo, int id, double x1, double y1, double x2, double y2, char *cor) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da Forma. \n");
        exit (1);
    }
    F->geometrica = cria_linha (id, x1, y1, x2, y2, cor);
    F->tipo = 'l';
    return ((Forma*)F);
}

FORMA cria_Forma_texto (char tipo, int id, double x, double y, char *corb, char *corp, char a, char *txto, Estilo ts) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da Forma. \n");
        exit (1);
    }
    F->geometrica = cria_texto (id, x, y, corb, corp, a, txto, ts);
    F->tipo = 't';
    return ((Forma*)F);
}


char get_tipo_Forma (FORMA F) {

    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((Forma*)F)->tipo == 'c') {
        return get_i_circulo( ((Forma*)F)->geometrica );
    }
    else if (((Forma*)F)->tipo == 'r') {
        return get_i_retangulo( ((Forma*)F)->geometrica ); 
    }
    else if (((Forma*)F)->tipo == 'l') {
        return get_i_linha (( ((Forma*)F)->geometrica ));
    }
    else if (((Forma*)F)->tipo == 't') {
        return get_i_texto (( ((Forma*)F)->geometrica) );
    }
}

double get_x_Forma(FORMA F){

    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((Forma*)F)->tipo == 'c') {
        return get_x_circulo( ((Forma*)F)->geometrica );
    }
    else if (((Forma*)F)->tipo == 'r') {
        return get_x_retangulo( ((Forma*)F)->geometrica ); 
    }
    else if (((Forma*)F)->tipo == 'l') {
        return get_x1_linha (( ((Forma*)F)->geometrica ));
    }
    else if (((Forma*)F)->tipo == 't') {
        return get_x_texto (( ((Forma*)F)->geometrica) );
    }
}

double get_y_Forma(FORMA F){

    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((Forma*)F)->tipo == 'c') {
        return get_y_circulo( ((Forma*)F)->geometrica );
    }
    else if (((Forma*)F)->tipo == 'r') {
        return get_y_retangulo( ((Forma*)F)->geometrica ); 
    }
    else if (((Forma*)F)->tipo == 'l') {
        return get_y1_linha (( ((Forma*)F)->geometrica ));
    }
    else if (((Forma*)F)->tipo == 't') {
        return get_y_texto (( ((Forma*)F)->geometrica) );
    }
}