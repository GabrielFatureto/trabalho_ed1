#ifndef FORMA_H
#define FORMA_H

#include "texto.h"
#include "svg.h"


typedef void* FORMA;

typedef enum EnumtipoForma {
    circulo,
    retangulo,
    linha,
    texto
} tipoForma;

/**
 /// @brief Cria um wrapper (invólucro) de Forma para um Círculo.
 /// @param tipo Caractere identificador 'c'.
 /// @param id ID numérico do círculo.
 /// @param x Coordenada X do centro.
 /// @param y Coordenada Y do centro.
 /// @param r Raio.
 /// @param corb Cor da borda.
 /// @param corp Cor de preenchimento.
 /// @return Um ponteiro FORMA para o wrapper criado.
 */
FORMA cria_Forma_circulo (char tipo, int id, double x, double y, double r, char *corb, char *corp);

/**
 /// @brief Cria um wrapper (invólucro) de Forma para um Retângulo.
 /// @param tipo Caractere identificador 'r'.
 /// @param id ID numérico do retângulo.
 /// @param x Coordenada X da âncora.
 /// @param y Coordenada Y da âncora.
 /// @param w Largura.
 /// @param h Altura.
 /// @param corb Cor da borda.
 /// @param corp Cor de preenchimento.
 /// @return Um ponteiro FORMA para o wrapper criado.
 */
FORMA cria_Forma_retangulo (char tipo, int id, double x, double y, double w, double h, char *corb, char *corp);

/**
 /// @brief Cria um wrapper (invólucro) de Forma para uma Linha.
 /// @param tipo Caractere identificador 'l'.
 /// @param id ID numérico da linha.
 /// @param x1 Coordenada X do ponto 1.
 /// @param y1 Coordenada Y do ponto 1.
 /// @param x2 Coordenada X do ponto 2.
 /// @param y2 Coordenada Y do ponto 2.
 /// @param cor Cor da linha.
 /// @return Um ponteiro FORMA para o wrapper criado.
 */
FORMA cria_Forma_linha (char tipo, int id, double x1, double y1, double x2, double y2, char *cor);

/**
 /// @brief Cria um wrapper (invólucro) de Forma para um Texto.
 /// @param tipo Caractere identificador 't'.
 /// @param id ID numérico do texto.
 /// @param x Coordenada X da âncora.
 /// @param y Coordenada Y da âncora.
 /// @param corb Cor da borda (contorno).
 /// @param corp Cor de preenchimento.
 /// @param a Caractere de alinhamento.
 /// @param txto String do texto.
 /// @param ts Estilo do texto (definido em texto.h).
 /// @return Um ponteiro FORMA para o wrapper criado.
 */
FORMA cria_Forma_texto (TEXTO t);


/// @brief Obtém os dados internos da forma encapsulada.
/// @param f Ponteiro para a Forma.
/// @return Retorna um ponteiro para os dados internos da forma.
void *getFormaDados(FORMA F);

/**
 /// @brief Obtém o caractere que identifica o tipo da forma.
 /// @param F Ponteiro para a Forma.
 /// @return O caractere do tipo ('c', 'r', 'l', 't').
 */
char get_tipo_Forma (FORMA F);

/**
 /// @brief Obtém o ID numérico da forma geométrica interna.
 /// @param F Ponteiro para a Forma.
 /// @return O ID (int) da forma.
 */
int get_id_Forma (FORMA F);

/**
 /// @brief Obtém a coordenada X da âncora da forma.
 /// @param F Ponteiro para a Forma.
 /// @return Coordenada X (double).
 */
double get_x_Forma (FORMA F);

/**
 /// @brief Obtém a coordenada Y da âncora da forma.
 /// @param F Ponteiro para a Forma.
 /// @return Coordenada Y (double).
 */
double get_y_Forma (FORMA F);

/**
 /// @brief Obtém a cor de borda da forma.
 /// @param F Ponteiro para a Forma.
 /// @return String da cor de borda. (Para Linha, retorna a cor principal).
 */
char* get_corb_Forma (FORMA F);

/**
 /// @brief Obtém a cor de preenchimento da forma.
 /// @param F Ponteiro para a Forma.
 /// @return String da cor de preenchimento. (Retorna NULL se a forma não tiver, ex: Linha).
 */
char* get_corp_Forma (FORMA F);

/**
 /// @brief Calcula a área da forma.
 /// @param F Ponteiro para a Forma.
 /// @return A área (double). (Retorna 0.0 para formas sem área, como Linha ou Texto).
 */
double get_area_Forma (FORMA F);

/**
 /// @brief Desenha a forma no arquivo SVG fornecido.
 /// @param f Ponteiro para a Forma.
 /// @param svg Arquivo SVG aberto para escrita.
 */
void desenhaFormaSvg(FORMA f, FILE *svg);

/**
 /// @brief Calcula a cor complementar de uma cor hexadecimal.
 /// @param cor_hexa_original String da cor hexadecimal (ex: "#ff5733" ou "ff5733").
 /// @return String alocada dinamicamente com a cor complementar em hexadecimal.
 */
char *getCorComplementar(char *cor_hexa_original);

/**
 /// @brief Define a cor de preenchimento da forma.
 /// @param f Ponteiro para a Forma.
 /// @param novaCor String da nova cor de preenchimento.
 */
void setCorpFormas(FORMA *f, char *novaCor);

/**
 /// @brief Define a cor de borda da forma.
 /// @param f Ponteiro para a Forma.
 /// @param novaCor String da nova cor de borda.
 */
void setCorbFormas(FORMA *f, char *novaCor);

/**
 /// @brief Clona uma Forma, criando uma cópia independente.
 /// @param f_original Ponteiro para a Forma original.
 /// @return Ponteiro para a nova Forma clonada.
 */
FORMA *clonarForma(FORMA *f_original);

/**
 /// @brief Libera toda a memória associada à Forma.
 /// Esta função chama o destrutor específico (ex: excluir_circulo)
 /// e depois libera o próprio wrapper da Forma.
 /// @param F Ponteiro para a Forma a ser excluída.
 */
void excluir_Forma (FORMA F);

#endif