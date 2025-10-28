#ifndef FILA_H
#define FILA_H

#include <stdbool.h> 



typedef void* FILA;

typedef struct No No;

/**
 /// @brief Cria e inicializa uma nova fila vazia.
 /// @return Um ponteiro para a nova Fila alocada, ou NULL se a alocação falhar.
 */
FILA fila_criar();

/**
 /// @brief Adiciona um elemento ao final da fila (enqueue).
 /// @param f Ponteiro para a Fila.
 /// @param dado Ponteiro para o dado a ser inserido.
 /// @return 'true' se a inserção for bem-sucedida, 'false' caso contrário.
 */
bool fila_enfileirar(FILA f, void* dado);

/**
 /// @brief Remove e retorna o elemento do início da fila (dequeue).
 /// @param f Ponteiro para a Fila.
 /// @return O ponteiro para o dado removido, ou NULL se a fila estiver vazia.
 */
void* fila_desenfileirar(FILA f);

/**
 /// @brief Retorna o elemento na frente da fila sem removê-lo.
 /// @param f Ponteiro para a Fila.
 /// @return O ponteiro para o dado na frente, ou NULL se a fila estiver vazia.
 */
void* fila_frente(FILA f);

/**
 /// @brief Retorna o número de elementos na fila.
 /// @param f Ponteiro para a Fila.
 /// @return O tamanho da fila.
 */
int fila_tamanho(FILA f);

/**
 ///// @brief Verifica se a fila está vazia.
 /// @param f Ponteiro para a Fila.
 /// @return 'true' se a fila estiver vazia, 'false' caso contrário.
 */
bool fila_esta_vazia(FILA f);


/** 
 /// @brief Obtém o proximo nó na fila.
 /// @param no_atual Nó do qual o dado será obtido.
 /// @return Retorna um ponteiro para o próximo nó, ou NULL se o nó for NULL.
 */ 
No* getProxNode(No* no_atual);

/** 
 /// @brief Obtém o dado armazenado em um nó da fila.
 /// @param no_atual Nó do qual o dado será obtido.
 /// @return Retorna um ponteiro para o dado armazenado no nó, ou NULL se o nó for NULL.
 */
void* getItemNode(No* no_atual);

/** 
 /// @brief Destroi a fila e libera a memória alocada
 /// @param f Ponteiro para a fila a ser destruída
 */ 
void destruir_fila(FILA f);

#endif