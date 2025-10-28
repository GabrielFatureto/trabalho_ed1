#ifndef linha_h
#define linha_h

#include <stdbool.h>

typedef void* LINHA;

/*
 Uma Linha é uma forma geométrica posicionada em um plano bidimensional.
 É identificado por um número inteiro (i), e definido por dois pontos, posicionado nas coordenadas (x1,y1) e (x2,y2).
 Uma Linha possui uma cor (cor).
 As cores são definidas usando o padrão sRGB de 6 dígitos.
 (Exemplo: #FFFFFF)
*/

/**
 /// @brief Cria uma estrutura (linha) com os parâmetros fornecidos
 /// @param i Número de identificação da forma criada
 /// @param x1 Coordenada x do ponto 1 da linha
 /// @param y1 Coordenada y do ponto 1 da linha
 /// @param x2 Coordenada x do ponto 2 da linha
 /// @param y2 Coordenada y do ponto 2 da linha
 /// @param cor Cor da linha
 /// @return Retorna a linha criada pelos parâmetros fornecidos
 */
LINHA cria_linha(int i, double x1, double y1, double x2, double y2, char* cor, bool eh_pontilhada);

/**
 /// @brief Obtém o identificador da forma 
 /// @param l Ponteiro para a estrutura da linha
 /// @return Identificador da forma
 */
int get_i_linha (LINHA l);

/**
 /// @brief Obtém a coordenada x1 da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @return Retorna a coordenada x1
 */
double get_x1_linha (LINHA l);

/**
 /// @brief Obtém a coordenada y1 da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @return Retorna a coordenada y1
 */
double get_x2_linha (LINHA l);

/**
 /// @brief Obtém a coordenada y1 da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @return Retorna a coordenada y1
 */
double get_y1_linha (LINHA l);

/**
 /// @brief Obtém a coordenada y2 da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @return Retorna a coordenada y2
 */
double get_y2_linha (LINHA l);

/**
 /// @brief Obtém a cor da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @return Retorna a cor da linha
 */
char* get_cor_linha (LINHA l);

/**
 /// @brief Verifica se a linha é pontilhada
 /// @param l Ponteiro para a estrutura da linha
 /// @return Retorna true se a linha for pontilhada, false caso contrário
 */
bool getEh_pontilhada(LINHA l);

/**
 /// @brief Define o valor da coordenada x1 da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @param x1 Novo valor de x1 para a linha
 */
void set_x1_linha (LINHA l, double x1);

/**
 /// @brief Define o valor da coordenada x2 da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @param x2 Novo valor de x2 para a linha
 */
void set_x2_linha (LINHA l, double x2);

/**
 /// @brief Define o valor da coordenada y1 da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @param y1 Novo valor de y1 para a linha
 */
void set_y1_linha (LINHA l, double y1);

/**
 /// @brief Define o valor da coordenada y2 da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @param y2 Novo valor de y2 para a linha
 */
void set_y2_linha (LINHA l, double y2);

/**
 /// @brief Define a cor da linha
 /// @param l Ponteiro para a estrutura da linha
 /// @param cor Nova cor para a linha
 */
void set_cor_linha (LINHA l, char* cor);

/**
 /// @brief Libera a memória alocada para a estrutura da linha
 /// @param l Ponteiro para a estrutura da linha
 */
void excluir_linha (LINHA l);

#endif