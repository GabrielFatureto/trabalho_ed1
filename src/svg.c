#include "svg.h"

#include <stdio.h>
#include "fila.h"
#include "forma.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"

FILE* inicializaSvg(const char* caminhoArquivo) {
	FILE* svg = fopen(caminhoArquivo, "w");
	if (svg == NULL) {
		perror("ERRO ao abrir o arquivo SVG");
		return NULL;
	}

	fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
	fprintf(svg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" width=\"1000\" height=\"1000\">\n");

	fprintf(svg, "<g>\n");

	return svg;
}

void insereCirculo(FILE *svg, CIRCULO c) {
	fprintf(svg, " <circle id=\"%i\" cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\" opacity=\"%lf\" stroke-width=\"%lf\" />\n",
	get_i(c),
	get_x_circulo(c),
	get_y_circulo(c),
	get_r(c),
	get_corb(c),
	get_corp(c), 0.5, 1.5);
}

void insereRetangulo(FILE *svg, RETANGULO r) {
	fprintf(svg, "\t<rect id=\"%d\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\" opacity=\"%lf\" stroke-width=\"%lf\" />\n",
		get_i_retangulo(r),
		get_x_retangulo(r),
		get_y_retangulo(r),
		get_w(r),
		get_h(r),
		get_corb(r),
		get_corp(r), 0.5, 1.5);
}

void insereLinha(FILE *svg, LINHA l) {
	if (getEh_pontilhada(l)) {
		fprintf(svg, "\t<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-dasharray=\"1, 1\" stroke-width=\"%lf\" />\n",
			get_i_linha(l),
			get_x1_linha(l),
			get_y1_linha(l),
			get_x2_linha(l),
			get_y2_linha(l),
			get_cor_linha(l), 1.5);
	}

	else {
		fprintf(svg, "\t<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"%lf\" />\n",
			get_i_linha(l),
			get_x1_linha(l),
			get_y1_linha(l),
			get_x2_linha(l),
			get_y2_linha(l),
			get_cor_linha(l), 1.5);
	}
}

void insereTexto(FILE *svg, TEXTO t) {
	if (t == NULL) return;

	ESTILO* e = getEstiloTexto(t);
	if (e == NULL) return;

	fprintf(svg, "\t<text id=\"%d\" x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\" font-family=\"%s\" font-weight=\"%s\" font-size=\"%spt\" ",
		get_i_texto(t),
		get_x_texto(t),
		get_y_texto(t),
		get_corb_texto(t),
		get_corp_texto(t),
		get_fFamily(e),
		get_fWeight(e),
		get_fSize(e));

	char ancora = get_a (t);
	switch (ancora) {
		case 'm':
			fprintf(svg, "text-anchor=\"middle\"");
			break;
		case 'f':
			fprintf(svg, "text-anchor=\"end\"");
			break;
		case 'i':
		default:
			fprintf(svg, "text-anchor=\"start\"");
			break;
	}

	fprintf(svg, ">%s</text>\n", get_txt(t));
}

void fechaSVG(FILE *svg) {
	if (svg == NULL) return;

	fprintf(svg, "</g>\n");

	fprintf(svg, "</svg>\n");

	fclose(svg);
}

void acao_desenhar(void* item, void* aux) {
	FILE* arquivo_svg = (FILE*)aux;
	desenhaFormaSvg((FORMA*)item, arquivo_svg);
}

void gerarArquivoSvg(const char *nome_svg, FILA filaDeFormas) {
	if (filaDeFormas == NULL) {
		fprintf(stderr, "Aviso: filaDeFormas NULL em gerarArquivoSvg(%s)\n", nome_svg);
		return;
	}

	FILE *arquivo_svg = inicializaSvg(nome_svg);
	if (!arquivo_svg) {
		printf("Erro ao abrir o arquivo svg!\n");
		return;
	}

	No *no_atual = fila_frente(filaDeFormas);

	while (no_atual != NULL) {
		FORMA *f = getItemNode(no_atual);

		desenhaFormaSvg(f, arquivo_svg);

		no_atual = getProxNode(no_atual);
	}

	fechaSVG(arquivo_svg);

	printf("Arquivo .svg gerado com sucesso!\n");

}