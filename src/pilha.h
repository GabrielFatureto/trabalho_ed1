#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <stddef.h>




typedef void* PILHA;


/**
 /// @brief Cria e inicializa uma nova pilha vazia.
 /// @return Um ponteiro para a nova Pilha alocada, ou NULL se a alocação falhar.
 */
PILHA pilha_criar();

/**
 /// @brief Adiciona um elemento no topo da pilha (push)
 /// @param p Ponteiro para a Pilha
 /// @param dado Ponteiro para o dado a ser inserido
 /// @return 'true' se a inserção for bem-sucedida, 'false' em caso de falha na alocação
 */
bool pilha_empilhar(PILHA p, void* dado);

/**
 /// @brief Remove e retorna o elemento do topo da pilha (pop)
 /// @param p Ponteiro para a Pilha
 /// @return O ponteiro para o dado removido, ou NULL se a pilha estiver vazia
 */
void* pilha_desempilhar(PILHA p);

/**
 /// @brief Retorna o elemento no topo da pilha sem removê-lo (peek/top)
 /// @param p Ponteiro para a Pilha
 /// @return O ponteiro para o dado no topo, ou NULL se a pilha estiver vazia
 */
void* pilha_topo(PILHA p);

/**
 /// @brief Retorna o número de elementos na pilha
 /// @param p Ponteiro para a Pilha  
 /// @return O tamanho da pilha
 */
int pilha_tamanho(PILHA p);

/**
 /// @brief Verifica se a pilha está vazia
 /// @param p Ponteiro para a Pilha  
 /// @return Retorna 'true' se a pilha estiver vazia, 'false' caso contrário
 */
bool pilha_vazia(PILHA p);

/** 
 /// @brief Destroi a pilha e libera a memória alocada
 /// @param p Ponteiro para a Pilha a ser destruída
 */ 
void destruir_pilha(PILHA p);

#endif 