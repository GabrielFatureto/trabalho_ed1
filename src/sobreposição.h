#ifndef SOBREPOSICAO_H
#define SOBREPOSICAO_H

#include <stdbool.h>

#include "forma.h"
#include "linha.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"

/* ------- TAD SOBREPOSIÇÃO -------
 * Basicamente, o TAD apresentado contém funções
 * que verificam se existe sobreposição entre
 * variados tipos de formas (Círculo, retângulo,
 * TEXTO, LINHA).
 *
 * Contém uma função mestre que obtém os tipos
 * das formas apresentadas nos parâmetros e
 * decide qual função especialista irá delegar
 * para tal verificação.
 *
 * Como essas verificações são feitas, é trivial.
 */



/// @brief: Checa se duas formas genéricas se sobrepõem num plano. Função mestre que chama as outras funções especialistas.
/// @param f1: Ponteiro para a primeira forma genérica.
/// @param f2: Ponteiro para a segunda forma genérica.
/// @return: True se há sobreposição, false caso contrário.
bool formasSobrepoem(FORMA *f1, FORMA *f2);


/// @brief: Checa se dois círculos se sobrepõem.
/// @param c1: Ponteiro void para o primeiro objeto círculo.
/// @param c2: Ponteiro void para o segundo objeto círculo.
/// @return: true se há sobreposição, false caso contrário.
bool sobrepoe_circulo_circulo(CIRCULO *c1, CIRCULO *c2);

/// @brief: Checa se um círculo e um retângulo se sobrepõem.
/// @param c1: Ponteiro para o objeto círculo.
/// @param r: Ponteiro para o objeto retângulo.
/// @return: true se há sobreposição, false caso contrário.
bool sobrepoe_circulo_retangulo(CIRCULO *c1, RETANGULO *r);

/// @brief: Checa se um círculo e um segmento de reta se sobrepõem. Usado para LINHA e TEXTO.
/// @param c: Ponteiro para o objeto círculo.
/// @param l: Ponteiro para o objeto LINHA (pode ser uma LINHA real ou uma temporária convertida de um TEXTO).
/// @return: true se há sobreposição, false caso contrário.
bool sobrepoe_circulo_linhaOUtexto(CIRCULO *c, LINHA *l);

/// @brief: Checa se dois retângulos alinhados aos eixos se sobrepõem.
/// @param r1: Ponteiro para o primeiro objeto retângulo.
/// @param r2: Ponteiro para o segundo objeto retângulo.
/// @return: true se há sobreposição, false caso contrário.
bool sobrepoe_retangulo_retangulo(RETANGULO *r1, RETANGULO *r2);

/// @brief: Checa se dois segmentos de reta se sobrepõem (interceptam).
/// @param l1: Ponteiro para o primeiro objeto LINHA.
/// @param l2: Ponteiro para o segundo objeto LINHA.
/// @return: true se há sobreposição, false caso contrário.
bool sobrepoe_linha_linha(LINHA *l1, LINHA *l2);

/// @brief: Checa a sobreposição entre uma LINHA e um TEXTO, convertendo o TEXTO para uma LINHA temporária.
/// @param l: Ponteiro para o objeto LINHA.
/// @param t: Ponteiro para o objeto TEXTO.
/// @return: true se há sobreposição, false caso contrário.
bool sobrepoe_linha_texto(LINHA *l, TEXTO *t);

/// @brief: Checa a sobreposição entre um retângulo e um segmento de reta.
/// @param r: Ponteiro para o objeto retângulo.
/// @param l: Ponteiro para o objeto LINHA.
/// @return: true se há sobreposição, false caso contrário.
bool sobrepoe_retangulo_linha(RETANGULO *r, LINHA *l);

/// @brief: Função auxiliar na verificação da sobreposição entre TEXTO e círculo.
/// @param txt: O objeto TEXTO.
/// @param circ: O objeto CIRCULO.
/// @return: true caso haja sobreposição e false caso o contrário.
bool sobrepoe_texto_circulo(TEXTO *txt, CIRCULO *circ);

/// @brief: Função auxiliar para a verificação da sobreposição entre TEXTO e retângulo.
/// @param txt: Objeto TEXTO.
/// @param ret: Objeto retângulo.
/// @return: true caso haja sobreposição e false caso o contrário.
bool sobrepoe_texto_retangulo(TEXTO *txt, RETANGULO *ret);

/// @brief: Função auxiliar para a verficação da sobreposição entre TEXTO e TEXTO.
/// @param txt1: Texto 1.
/// @param txt2: Texto 2.
/// @return: true caso haja sobreposição e false caso o contrário.
bool sobrepoe_texto_texto(TEXTO *txt1, TEXTO *txt2);

/// @brief: Converte um objeto TEXTO em um segmento de reta, preenchendo um objeto LINHA existente.
/// @param t: Ponteiro para o objeto TEXTO de origem.
/// @param l_out: Ponteiro para o objeto LINHA de destino que será preenchido com as coordenadas.
void converter_texto_para_linha(TEXTO *t, LINHA *l_out);

/// @brief: Determina a orientação de um trio ordenado de pontos (p, q, r).
/// @param px: Coordenada X do primeiro ponto.
/// @param py: Coordenada Y do primeiro ponto.
/// @param qx: Coordenada X do segundo ponto.
/// @param qy: Coordenada Y do segundo ponto.
/// @param rx: Coordenada X do terceiro ponto.
/// @param ry: Coordenada Y do terceiro ponto.
/// @return: 0 para colinear, 1 para horário, 2 para anti-horário.
int orientacao(double px, double py, double qx, double qy, double rx, double ry);

/// @brief: Verifica se um ponto q está no segmento de reta pr, assumindo que os três são colineares.
/// @param px: Coordenada X do ponto p (extremidade do segmento).
/// @param py: Coordenada Y do ponto p.
/// @param qx: Coordenada X do ponto q (ponto a ser verificado).
/// @param qy: Coordenada Y do ponto q.
/// @param rx: Coordenada X do ponto r (outra extremidade do segmento).
/// @param ry: Coordenada y do ponto r.
/// @return: true se o ponto q está no segmento pr, false caso contrário.
bool pontoEstaNoSegmento(double px, double py, double qx, double qy, double rx, double ry);

#endif