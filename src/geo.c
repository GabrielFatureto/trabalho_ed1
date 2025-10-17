#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "fila.h"
#include "geo.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"


#define MAX_SIZE 1024;


FILA ler_geo (FILE* arqgeo){
    FILA f = fila_criar();

    FILE* svg = fopen("saida.svg", "w");
    abrir_SVG(svg);

    double x, y, x1, y1, r, x2, y2, w, h;
    int i;
    char corb[20], corp[20], cor[20], comando[10];

    ESTILO e = criar_estilo("sans", "b", "12px");

    char linha[MAX_SIZE];
    char temp[MAX_SIZE];

    while(fgets(linha, MAX_SIZE, arqgeo)){
        linha[strcspn(linha, "\r\n")] = '\0';
        if (linha[0] == '\0' || linha[0] == '\n') continue;
        aux[0] = '\0';
        comando[0] = '\0';
        strcpy(aux, linha);
        sscanf(aux, "%s", comando);

        if(strcmp(comando, "c") == 0){
            sscanf(aux, "%s %d %lf %lf %lf %s %s", comando, &i, &x, &y, &r, corb, corp);
            CIRCULO c = cria_circulo(i, x, y, r, corb, corp);
            fila_enfileirar(f, c);

            desenhar_CirculoSVG(svg, c);
        }
        else if(strcmp(comando, "r") == 0){
            sscanf(aux, "%s %d %lf %lf %lf %lf %s %s", comando, &i, &x, &y, &w, &h, corb, corp);
            RETANGULO r = cria_retangulo(i, x, y, w, h, corb, corp);
            fila_enfileirar(f, r);

            desenhar_RetanguloSVG(svg, r);
        }
        else if(strcmp(comando, "l") == 0){
            sscanf(aux, "%s %d %lf %lf %lf %lf %s", comando, &i, &x1, &y1, &x2, &y2, cor);
            LINHA l = cria_linha(i, x1, y1, x2, y2, cor);
            fila_enfileirar(f, l);

            desenhar_LinhaSVG(svg, l);
        }
        else if(strcmp(comando, "t") == 0){
            sscanf(aux, "%s %d %lf %lf %s %s %c \"%[^\"]\"", comando, &i, &x, &y, corb, corp, &a, txt);
            TEXTO t = criarTexto(i, x, y, corb, corp, a, txt);
            fila_enfileirar(f, t);

            desenhar_TextoSVG(svg, t, e);
        }
        else if(strcmp(comando, "ts") == 0){
            sscanf(aux, "%s %s %s %s", comando, fFamily, fWeight, fSize);
            set_fFamily(e, fFamily);
            set_fWeight(e, fWeight);
            set_fSize(e, fSize);
        }
        else{
            printf("Comando desconhecido: %s\n", comando);
        }

        fechar_SVG(svg);
    }


}
