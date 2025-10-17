#ifndef DISPARADOR_H
#define DISPARADOR_H

#include "carregador.h"

/*
 Arquivo que vai representar os Disparadores de formas que vão desenhar as formas geométricas no SVG.
 Um Disparador vai atuar como uma pilha, estrutura LIFO (Last In, First Out), colocando e retirando elementos do topo
*/

typedef void* DISPARADOR;

/** 
 /// @brief Cria um Disparador vazio.
 /// @param i Identificador do Disparador
 /// @param x Coordenada x do Disparador
 /// @param y Coordenada y do Disparador
 /// @return Retorna um ponteiro para o Disparador criado
 */
DISPARADOR cria_Disparador(int i, double x, double y);

/** 
 /// @brief Define a posição do Disparador.
 /// @param d Disparador
 /// @param x Nova coordenada x do Disparador
 /// @param y Nova coordenada y do Disparador
 */
void pd (DISPARADOR d, double x, double y);

/** 
 /// @brief Anexa carregadores ao Disparador.
 /// @param d Disparador
 /// @param car_esq Carregador da esquerda
 /// @param car_dir Carregador da direita
 */
void atch (DISPARADOR d, CARREGADOR car_esq, CARREGADOR car_dir);

/** 
 /// @brief Realiza o shift dos elementos entre os carregadores do Disparador.
 /// @param d Disparador
 /// @param lado Lado do carregador ('e' para esquerda, 'd' para direita)
 /// @param n Número de elementos a serem deslocados
 */
void shft (DISPARADOR d, char lado, int n);

/**
 /// @brief Dispara o elemento no Disparador, desenhando-o na arena.
 /// @param d Disparador
 /// @param dx Coordenada x do deslocamento
 /// @param dy Coordenada y do deslocamento
 */
void dsp (DISPARADOR d, double dx, double dy);

/**
 /// @brief Libera a memória alocada para o Disparador.
 /// @param d Disparador
 */
void libera_memoria_disparador (DISPARADOR d);

#endif


