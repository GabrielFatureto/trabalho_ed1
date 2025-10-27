#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "forma.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "disparador.h"
#include "pilha.h"
#include "fila.h"
#include "svg.h"

typedef struct {
    FORMA geometrica;
    tipoForma tipo;
    void* dados;
} Forma;

FORMA cria_Forma_circulo (char tipo, int id, double x, double y, double r, char* corb, char* corp) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da Forma. \n");
        exit (1);
    }
    F->geometrica = cria_circulo (id, x, y, r, corb, corp);
    F->tipo = 'c';
    F->dados = F->geometrica;
    return ((Forma*)F);
}

FORMA cria_Forma_retangulo (char tipo, int id, double x, double y, double w, double h, char* corb, char* corp) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da Forma. \n");
        exit (1);
    }
    F->geometrica = cria_retangulo (id, x, y, w, h, corb, corp);
    F->tipo = 'r';
    return ((Forma*)F);
}

FORMA cria_Forma_linha (char tipo, int id, double x1, double y1, double x2, double y2, char *cor) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da Forma. \n");
        exit (1);
    }
    F->geometrica = cria_linha (id, x1, y1, x2, y2, cor);
    F->tipo = 'l';
    return ((Forma*)F);
}

FORMA cria_Forma_texto (char tipo, int id, double x, double y, char *corb, char *corp, char a, char *txto, ESTILO ts) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
    if (F == NULL){
        printf("Erro na alocação de memória para a criação da Forma. \n");
        exit (1);
    }
    F->geometrica = criarTexto (id, x, y, corb, corp, a, txto);
    F->tipo = 't';
    return ((Forma*)F);
}

void *getFormaDados(FORMA f) {
    Forma *F = (Forma*)malloc(sizeof(Forma));
	return F -> dados;
}

char get_tipo_Forma (FORMA F) {
    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }
    return ((Forma*)F)->tipo;
}

int get_id_Forma (FORMA F) {
    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    char tipo = ((Forma*)F)->tipo;
    FORMA geo = ((Forma*)F)->geometrica; 

    if (tipo == 'c') {
        return get_i(geo); 
    }
    else if (tipo == 'r') {
        return get_i_retangulo(geo); 
    }
    else if (tipo == 'l') {
        return get_i_linha(geo);
    }
    else if (tipo == 't') {
        return get_i_texto(geo);
    }
    
    // Se chegar aqui, o tipo é desconhecido
    return -1; 
}

void escreveDadosFormaTxt(FORMA *f, FILE *txt, char *reportDaFuncaoQRY) {
    tipoForma tipo = getTipoForma(f);
    void* dados = getFormaDados(f);

    const char* report_safe = (reportDaFuncaoQRY != NULL) ? reportDaFuncaoQRY : "";

    switch (tipo) {
        case circulo: {
            fprintf(txt, "%s\n Círculo\n ID: %i\n Âncora em: (%.2lf, %.2lf)\n Raio: %lf\n Cor de borda: %s\n Cor de preenchimento: %s\n",
                report_safe,
                get_id_forma(f),
                get_x_circulo(dados),
                get_y_circulo(dados),
                get_r(dados),
                get_corb(dados),
                get_corp(dados));
            break;
        }

        case retangulo: {
            fprintf(txt, "%s\n Retângulo\n ID: %i\n Âncora em: (%.2lf, %.2lf)\n Largura: %lf\n Altura %lf\n Cor de borda: %s\n Cor de preenchimento: %s\n",
                report_safe,
                get_id_forma(f),
                get_x_retangulo(dados),
                get_y_retangulo(dados),
                get_w(dados),
                get_h(dados),
                get_corb(dados),
                get_corp(dados));
            break;
        }

        case linha: {
            fprintf(txt, "%s\n Linha\n ID: %i\n Âncora de início em: (%.2lf, %.2lf)\n Âncora de fim em: (%.2lf, %.2lf)\n Cor: %s\n",
                report_safe,
                get_id_forma(f),
                get_x1_linha(dados),
                get_y1_linha(dados),
                get_x2_linha(dados),
                get_y2_linha(dados),
                get_cor_linha(dados));
            break;
        }

        case texto: {
            TEXTO* t = (TEXTO*)dados;
            ESTILO* e = getEstiloTexto(t);

            fprintf(txt, "%s Texto\n ID: %d\n Âncora em: (%.2f, %.2f)\n Posição da Âncora: %c\n Conteúdo: \"%s\"\n Cor de borda: %s\n Cor de preenchimento: %s\n",
                report_safe,
                get_id_forma(f),
                get_x_texto(t),
                get_y_texto(t),
                get_a(t),
                get_txt(t),
                get_corb_texto(dados),
                get_corp_texto(dados));

            if (e != NULL) {
                fprintf(txt, " Família da fonte: %s\n Peso da fonte: %s\n Tamanho da fonte: %s\n\n",
                    get_fFamily(e),
                    get_fWeight(e),
                    get_fSize(e));
            } else {
                fprintf(txt, "\n");
            }
            break;
        }

        default:
            fprintf(txt, "Tipo de forma desconhecida!\n");
            break;
    }
}

char* get_corb_Forma (FORMA F) {
    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    char tipo = ((Forma*)F)->tipo;
    FORMA geo = ((Forma*)F)->geometrica; 

    if (tipo == 'c') {
        return get_corb(geo); // de circulo.h
    }
    else if (tipo == 'r') {
        return get_corb(geo); // de retangulo.h
    }
    else if (tipo == 'l') {
        return get_cor_linha(geo); // de linha.h (assumindo que o nome seja este)
    }
    else if (tipo == 't') {
        return get_corb_texto(geo); // de texto.h (assumindo que o nome seja este)
    }
    
    return NULL; // Tipo desconhecido
}

char* get_corp_Forma (FORMA F) {
    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    char tipo = ((Forma*)F)->tipo;
    FORMA geo = ((Forma*)F)->geometrica; 

    if (tipo == 'c') {
        return get_corp(geo); // de circulo.h
    }
    else if (tipo == 'r') {
        return get_corp(geo); // de retangulo.h
    }
    else if (tipo == 'l') {
        return NULL; // Linha não tem cor de preenchimento
    }
    else if (tipo == 't') {
        return get_corp_texto(geo); // de texto.h (assumindo que o nome seja este)
    }
    
    return NULL; // Tipo desconhecido
}

double get_area_Forma (FORMA F) {
    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    char tipo = ((Forma*)F)->tipo;
    FORMA geo = ((Forma*)F)->geometrica; 

    if (tipo == 'c') {
        return get_area(geo); // de circulo.h
    }
    else if (tipo == 'r') {
        return get_area(geo); // de retangulo.h
    }
    else if (tipo == 'l') {
        return 0.0; // Linha não tem área
    }
    else if (tipo == 't') {
        return 0.0; // Texto não tem área
    }
    
    return 0.0; // Tipo desconhecido
}

double get_x_Forma(FORMA F){

    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((Forma*)F)->tipo == 'c') {
        return get_x_circulo( ((Forma*)F)->geometrica );
    }
    else if (((Forma*)F)->tipo == 'r') {
        return get_x_retangulo( ((Forma*)F)->geometrica ); 
    }
    else if (((Forma*)F)->tipo == 'l') {
        return get_x1_linha (( ((Forma*)F)->geometrica ));
    }
    else if (((Forma*)F)->tipo == 't') {
        return get_x_texto (( ((Forma*)F)->geometrica) );
    }
}

double get_y_Forma(FORMA F){

    if (F == NULL) {
        printf("Erro! A Forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((Forma*)F)->tipo == 'c') {
        return get_y_circulo( ((Forma*)F)->geometrica );
    }
    else if (((Forma*)F)->tipo == 'r') {
        return get_y_retangulo( ((Forma*)F)->geometrica ); 
    }
    else if (((Forma*)F)->tipo == 'l') {
        return get_y1_linha (( ((Forma*)F)->geometrica ));
    }
    else if (((Forma*)F)->tipo == 't') {
        return get_y_texto (( ((Forma*)F)->geometrica) );
    }
}

void desenhaFormaSvg(FORMA f, FILE *svg) {
	tipoForma tipo = getTipoForma(f);
	void *dados = getFormaDados(f);

	switch (tipo) {
		case circulo: {
			insereCirculo(svg, (CIRCULO)dados); break;
		}

		case retangulo: {
			insereRetangulo(svg, (RETANGULO)dados); break;
		}

		case linha: {
			insereLinha(svg, (LINHA)dados); break;
		}

		case texto: {
			insereTexto(svg, (TEXTO)dados); break;
		}

		default: break;
	}
}

void excluir_Forma (FORMA F) {
    if (F == NULL) {
        return; 
    }

    Forma* formaWrapper = (Forma*)F;
    char tipo = formaWrapper->tipo;
    FORMA geo = formaWrapper->geometrica; 

    if (tipo == 'c') {
        excluir_circulo(geo);
    }
    else if (tipo == 'r') {
        excluir_retangulo(geo);
    }
    else if (tipo == 'l') {
        excluir_linha(geo);
    }
    else if (tipo == 't') {
        excluir_texto(geo);
    }

    free(formaWrapper);
}