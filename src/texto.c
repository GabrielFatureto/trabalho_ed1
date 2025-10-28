#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "texto.h"

typedef struct Text{
    int i;
    double x, y;
    char* corb;
    char* corp;
    char a;
    char* texto;
    ESTILO e;
} Text;

typedef struct Stileq{
    char* fFamily;
    char* fWeight;
    char* fSize;
} Stile;

ESTILO criar_estilo (char* fFamily, char* fWeight, char* fSize) {
    Stile* e = (Stile*)malloc(sizeof(Stile));
    if(e == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }

    e->fFamily = (char*)malloc(strlen(fFamily)+1);
    if(e->fFamily == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(e->fFamily, fFamily);

    e->fWeight = (char*)malloc(strlen(fWeight)+1);
    if(e->fWeight == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(e->fWeight, fWeight);

    e->fSize = (char*)malloc(strlen(fSize)+1);
    if(e->fSize == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(e->fSize, fSize);

    return (ESTILO) e;
}

ESTILO criaCopiaEstilo(Stile *original) {
	if (original == NULL) {
		return NULL;
	}

	return criar_estilo(original -> fFamily, original -> fWeight, original -> fSize);
}

char* get_fFamily (ESTILO e){
    return ((Stile*)e)->fFamily;
}

char* get_fWeight (ESTILO e){
    return ((Stile*)e)->fWeight;
}

char* get_fSize (ESTILO e){
    return ((Stile*)e)->fSize;
}

void set_fFamily (ESTILO e, char* fFamily){
    
    ((Stile*)e)->fFamily = (char*)malloc(strlen(fFamily)+1);
    if(((Stile*)e)->fFamily == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(((Stile*)e)->fFamily, fFamily);
}

void set_fWeight (ESTILO e, char* fWeight){
    ((Stile*)e)->fWeight = (char*)malloc(strlen(fWeight)+1);
    if(((Stile*)e)->fWeight == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(((Stile*)e)->fWeight, fWeight);
}

void set_fSize (ESTILO e, char* fSize){
    ((Stile*)e)->fSize = (char*)malloc(strlen(fSize)+1);
    if(((Stile*)e)->fSize == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(((Stile*)e)->fSize, fSize);
}


TEXTO criarTexto(int i, double x, double y, char* corb, char* corp, char a, char* texto, ESTILO e) {
    Text* t = (Text*)malloc(sizeof(Text));
    if(t == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    t->i = i;
    t->x = x;
    t->y = y;

    t->corb = (char*)malloc(strlen(corb)+1);
    if(t->corb == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(t->corb, corb);

    t->corp = (char*)malloc(strlen(corp)+1);
    if(t->corp == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(t->corp, corp);

    t->a = a;

    t->texto = (char*)malloc(strlen(texto)+1);
    if(t->texto == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(t->texto, texto);

    t->e = e;

    return t;
}

int get_i_texto (TEXTO t){
    return ((Text*)t)->i;
}

ESTILO getEstiloTexto(TEXTO t) {
	return ((Text*)t)->e;
}

double get_x_texto (TEXTO t){
    return ((Text*)t)->x;
}

double get_y_texto (TEXTO t){
    return ((Text*)t)->y;
}

char* get_corb_texto (TEXTO t){
    return ((Text*)t)->corb;
}

char* get_corp_texto (TEXTO t){
    return ((Text*)t)->corp;
}

char get_a (TEXTO t){
    return ((Text*)t)->a;
}

char* get_txt (TEXTO t){
    return ((Text*)t)->texto;
}

int get_tamanho_texto(TEXTO t) {
    return strlen(((Text*)t)->texto);
}

void set_i_texto (TEXTO t, int id){
    ((Text*)t)->i = id;
}

void set_x_texto (TEXTO t, double x){
    ((Text*)t)->x = x;
}

void set_y_texto (TEXTO t, double y){
    ((Text*)t)->y = y;
}

void set_corb_texto (TEXTO t, char* corb){
    ((Text*)t)->corb = (char*)malloc(strlen(corb)+1);
    if(((Text*)t)->corb == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(((Text*)t)->corb, corb);
}

void set_corp_texto (TEXTO t, char* corp){
    ((Text*)t)->corp = (char*)malloc(strlen(corp)+1);
    if(((Text*)t)->corp == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(((Text*)t)->corp, corp);
}

void set_a (TEXTO t, char a){
    ((Text*)t)->a = a;
}

void set_txt (TEXTO t, char* texto){
    ((Text*)t)->texto = (char*)malloc(strlen(texto)+1);
    if(((Text*)t)->texto == NULL){
        printf("Erro na alocação de memória!!\n");
        exit(1);
    }
    strcpy(((Text*)t)->texto, texto);
}

void excluir_texto (TEXTO t){
    free(((Text*)t)->corb);
    free(((Text*)t)->corp);
    free(((Text*)t)->texto);
    free(t);
}

void excluir_estilo(ESTILO e) {
    Stile* s = (Stile*)e;
    if (s == NULL) return;
    
    free(s->fFamily);
    free(s->fWeight);
    free(s->fSize);
    free(s);
}


