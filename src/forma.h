#ifndef FORMA_H
#define FORMA_H

typedef void* FORMA;

FORMA cria_Forma_circulo (char tipo, int id, double x, double y, double r, char *corb, char *corp);

FORMA cria_Forma_retangulo (char tipo, int id, double x, double y, double w, double h, char *corb, char *corp);

FORMA cria_Forma_linha (char tipo, int id, double x1, double y1, double x2, double y2, char *cor);

FORMA cria_Forma_texto (char tipo, int id, double x, double y, char *corb, char *corp, char a, char *txto, ESTILO ts);

char get_tipo_Forma (FORMA F);

double get_x_Forma (FORMA F);

double get_y_Forma (FORMA F);

#endif