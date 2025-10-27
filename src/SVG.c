#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "svg.h"

void abrir_SVG(FILE* svg) {
    fprintf(svg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
}   

void desenhar_CirculoSVG(FILE* svg, CIRCULO c) {
    fprintf(svg, "<circle id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\" />\n", get_i(c), get_corp(c), get_corb(c), get_r(c), get_y_circulo(c), get_x_circulo(c));
}

void desenhar_RetanguloSVG(FILE* svg, RETANGULO r) {
    fprintf(svg, "<rect id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" />\n", get_i_retangulo(r), get_corp(r), get_corb(r), get_h(r), get_w(r), get_y_retangulo(r), get_x_retangulo(r), 1.0);
}

void desenhar_LinhaSVG(FILE* svg, LINHA l) {
    fprintf(svg, "<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"%lf\" />\n", get_i_linha(l), get_x1_linha(l), get_y1_linha(l), get_x2_linha(l), get_y2_linha(l), get_cor_linha(l), 1.0);
}

void desenhar_TextoSVG(FILE* svg, TEXTO t, ESTILO e) {
    char a = get_a(t);
    switch(a) {
        case 'i':
            fprintf(svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"start\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_i_texto(t), get_fSize(e), get_corp_texto(t), get_corb_texto(t), get_fFamily(e), get_y_texto(t), get_x_texto(t), 1.0, get_txt(t));
            break;
        case 'm':
            fprintf(svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"middle\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_i_texto(t), get_fSize(e), get_corp_texto(t), get_corb_texto(t), get_fFamily(e), get_y_texto(t), get_x_texto(t), 1.0, get_txt(t));
            break;
        case 'f':
            fprintf(svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"end\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_i_texto(t), get_fSize(e), get_corp_texto(t), get_corb_texto(t), get_fFamily(e), get_y_texto(t), get_x_texto(t), 1.0, get_txt(t));
            break;
    }
}

void fechar_SVG(FILE* svg) {
    fprintf(svg, "</svg>\n");
    fclose(svg);
}


