#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include <stdlib.h>


/** 
 /// @brief Abre o arquivo SVG
 /// @param svg Ponteiro para o arquivo SVG aberto
 */
void abrir_SVG(FILE* svg);

/** 
 /// @brief Desenha um círculo no SVG
 /// @param svg Ponteiro para o arquivo SVG aberto
 /// @param c Círculo a ser desenhado
 */ 
void desenhar_CirculoSVG(FILE* svg, CIRCULO c);

/** 
 /// @brief Desenha um retângulo no SVG
 /// @param svg Ponteiro para o arquivo SVG aberto
 /// @param r Retângulo a ser desenhado
 */ 
void desenhar_RetanguloSVG(FILE* svg, RETANGULO r);

/** 
 /// @brief Desenha uma linha no SVG
 /// @param svg Ponteiro para o arquivo SVG aberto
 /// @param l Linha a ser desenhada
 */ 
void desenhar_LinhaSVG(FILE* svg, LINHA l);

/** 
 /// @brief Desenha um texto no SVG
 /// @param svg Ponteiro para o arquivo SVG aberto
 /// @param t Texto a ser desenhado
 /// @param e Estilo do texto a ser desenhado
 */ 
void desenhar_TextoSVG(FILE* svg, TEXTO t, ESTILO e);

/** 
 /// @brief Fecha o arquivo SVG
 /// @param svg Ponteiro para o arquivo SVG aberto
 */ 
void fechar_SVG(FILE* svg);

#endif