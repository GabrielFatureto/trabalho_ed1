#ifndef SVG_H
#define SVG_H
#include <stdio.h>

#include "retangulo.h"
#include "circulo.h"
#include "fila.h"
#include "linha.h"
#include "texto.h"

/*
 * ------- MÓDULO DE SAÍDA SVG -------
 * Este módulo funciona como uma biblioteca de funções utilitárias
 * responsável por gerar e escrever o arquivo de saída no formato SVG.
 * Ele provê funcionalidades para:
 *
 * Gerenciamento de Arquivo: Controlar o ciclo de vida do arquivo SVG,
 * incluindo sua criação ('abreSvgEscrita'), a escrita do cabeçalho
 * padrão ('printaCabecalhoSvg') e o seu fechamento ('fechaSVG');
 *
 * Desenho de Formas: Converter os dados de TADs de formas específicas
 * (círculo, retângulo, etc.) em suas respectivas tags de texto no
 * padrão SVG, desenhando-as no arquivo;
 *
 * Abstração da Sintaxe SVG: Esconder a complexidade da sintaxe SVG,
 * permitindo que o resto do programa desenhe formas simplesmente
 * chamando uma função, sem precisar conhecer os detalhes das tags
 * '<rect>', '<circle>', etc.
 */


/// @brief: Cria, abre e inicializa um arquivo SVG com o cabeçalho padrão.
/// @param caminhoArquivo: O nome/caminho do arquivo a ser criado.
/// @return: Retorna um ponteiro para o arquivo (FILE*) pronto para escrita, ou NULL se ocorrer um erro.
FILE* inicializaSvg(const char* caminhoArquivo);

/// @brief: Desenha um retângulo no arquivo SVG.
/// @param svg: Ponteiro para o arquivo SVG aberto para escrita.
/// @param r: Ponteiro para a struct 'RETANGULO' com os dados a serem desenhados.
void insereRetangulo(FILE *svg, RETANGULO r);

/// @brief: Desenha um círculo no arquivo SVG.
/// @param svg: Ponteiro para o arquivo SVG aberto para escrita.
/// @param c: Ponteiro para a struct 'CIRCULO' com os dados a serem desenhados.
void insereCirculo(FILE *svg, CIRCULO c);

/// @brief: Escreve um objeto de texto no arquivo SVG.
/// @param svg: Ponteiro para o arquivo SVG aberto para escrita.
/// @param t: Ponteiro para a struct 'texto' que contém os dados a serem escritos.
void insereTexto(FILE *svg, TEXTO t);

/// @brief: Desenha uma linha no arquivo SVG.
/// @param svg: Ponteiro para o arquivo SVG aberto para escrita.
/// @param l: Ponteiro para a struct 'linha' com os dados a serem desenhados.
void insereLinha(FILE *svg, LINHA l);

/// @brief: Finaliza e fecha o arquivo SVG.
/// @param svg: Ponteiro para o arquivo SVG a ser fechado.
void fechaSVG(FILE *svg);

/// @brief: Função auxiliar que recebe um dado e se possível, o desenha no arquivo .svg
/// @param item: Dado a ser desenhado.
/// @param aux: Dado auxiliar, caso necessário.
void acao_desenhar(void* item, void* aux);

/// @brief: Função que recebe as formas que serão adicionadas ao .svg criado.
/// @param nome_svg: Nome do arquivo .svg.
/// @param filaDeFormas: Fila contendo as formas que serão adicionadas ao .svg.
void gerarArquivoSvg(const char *nome_svg, FILA filaDeFormas);

#endif 