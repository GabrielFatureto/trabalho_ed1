#ifndef CARREGADOR_H
#define CARREGADOR_H
                                                                
#include "pilha.h"

/*
 Arquivo que vai representar os Carregadores de formas que municiam os disparadores.
 Um Carregador vai atuar como uma pilha, estrutura LIFO (Last In, First Out), colocando e retirando elementos do topo
*/

typedef void* CARREGADOR;

/**
 /// @brief Cria um Carregador vazio.
 /// @return Ponteiro para o novo Carregador. 
 */
CARREGADOR criar_Carregador();



/**
 /// @brief Função que empilha uma forma geométrica no topo do Carregador.
 /// @param Carregador Ponteiro para o Carregador analisado.
 /// @param Forma Ponteiro genérico para a forma que será colocada.
 */
void push_topo (CARREGADOR c, void *Forma);

/**
 /// @brief Função que desempilha uma forma geométrica no topo do Carregador.
 /// @param Carregador Ponteiro para o Carregador analisado.
 */
void* pop_topo (CARREGADOR c);

/**
 /// @brief Função para 'pegar' (sem tirar do Carregador) do topo
 /// @param c Ponteiro para o Carregador analisado
 /// @return Ponteiro para a forma que está no topo
 */
void* get_topo (CARREGADOR c);

/**
 /// @brief Função que vai mostrar se o Carregador está vazio ou não
 /// @param c Ponteiro para o Carregador analisado
 /// @return Retorna 1 se estiver vazio e 0 se não estiver
 */
int CarregadorVazio (CARREGADOR c);

/**
 /// @brief Libera a memória associada ao Carregador e aos elementos contidos nele
 /// @param c Ponteiro para o Carregador analisado
 */
void destruir_carregador (CARREGADOR c);


#endif