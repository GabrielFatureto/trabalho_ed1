#include "sobreposição.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

#include <math.h>


static double distancia_quadrada(double x1, double y1, double x2, double y2) {
    double deltaX = x1 - x2;
    double deltaY = y1 - y2;
    return (deltaX * deltaX) + (deltaY * deltaY);
}

bool formasSobrepoem(FORMA *f1, FORMA *f2) {
    tipoForma tipo1 = get_tipo_Forma(f1);
    tipoForma tipo2 = get_tipo_Forma(f2);
    void *dados1 = getFormaDados(f1);
    void *dados2 = getFormaDados(f2);

    switch (tipo1) {
        case circulo:
            switch (tipo2) {
                case circulo: return sobrepoe_circulo_circulo((CIRCULO*)dados1, (CIRCULO*)dados2);
                case retangulo: return sobrepoe_circulo_retangulo((CIRCULO*)dados1, (RETANGULO*)dados2);
                case linha: return sobrepoe_circulo_linhaOUtexto((CIRCULO*)dados1, (LINHA*)dados2);
                case texto: return sobrepoe_texto_circulo((TEXTO*)dados2, (CIRCULO*)dados1);
                default: return false;
            }

        case retangulo:
            switch (tipo2) {
                case circulo: return sobrepoe_circulo_retangulo((CIRCULO*)dados2, (RETANGULO*)dados1);
                case retangulo: return sobrepoe_retangulo_retangulo((RETANGULO*)dados1, (RETANGULO*)dados2);
                case linha: return sobrepoe_retangulo_linha((RETANGULO*)dados1, (LINHA*)dados2);
                case texto: return sobrepoe_texto_retangulo((TEXTO*)dados2, (RETANGULO*)dados1);
                default: return false;
            }

        case linha:
            switch (tipo2) {
                case circulo: return sobrepoe_circulo_linhaOUtexto((CIRCULO*)dados2, (LINHA*)dados1);
                case retangulo: return sobrepoe_retangulo_linha((RETANGULO*)dados2, (LINHA*)dados1);
                case linha: return sobrepoe_linha_linha((LINHA*)dados1, (LINHA*)dados2);
                case texto: return sobrepoe_linha_texto((LINHA*)dados1, (TEXTO*)dados2);
                default: return false;
            }

        case texto:
            switch (tipo2) {
                case circulo: return sobrepoe_texto_circulo((TEXTO*)dados1, (CIRCULO*)dados2);
                case retangulo: return sobrepoe_texto_retangulo((TEXTO*)dados1, (RETANGULO*)dados2);
                case linha: return sobrepoe_linha_texto((LINHA*)dados2, (TEXTO*)dados1);
                case texto: return  sobrepoe_texto_texto((TEXTO*)dados1, (TEXTO*)dados2);
                default: return false;
            }

        default: return false;
    }
}

bool sobrepoe_texto_circulo(TEXTO *txt, CIRCULO *circ) {
    LINHA *temp_linha = cria_linha(-1, 0, 0, 0, 0, "temp");
    converter_texto_para_linha(txt, temp_linha);
    bool resultado = sobrepoe_circulo_linhaOUtexto(circ, temp_linha);
    excluir_linha (temp_linha);
    return resultado;
}

bool sobrepoe_texto_retangulo(TEXTO *txt, RETANGULO *ret) {
    LINHA *temp_linha = cria_linha(-1, 0, 0, 0, 0, "temp");
    converter_texto_para_linha(txt, temp_linha);
    bool resultado = sobrepoe_retangulo_linha(ret, temp_linha);
    excluir_linha (temp_linha);
    return resultado;
}

bool sobrepoe_texto_texto(TEXTO *txt1, TEXTO *txt2) {
    LINHA *temp1 = cria_linha(-1, 0, 0, 0, 0, "temp");
    LINHA *temp2 = cria_linha(-1, 0, 0, 0, 0, "temp");
    converter_texto_para_linha(txt1, temp1);
    converter_texto_para_linha(txt2, temp2);
    bool resultado = sobrepoe_linha_linha(temp1, temp2);
    excluir_linha(temp1);
    excluir_linha(temp2);
    return resultado;
}

bool sobrepoe_circulo_circulo(CIRCULO *c1, CIRCULO *c2) {
    double x1 = get_x_circulo(c1);
    double y1 = get_y_circulo(c1);
    double r1 = get_r(c1);

    double x2 = get_x_circulo(c2);
    double y2 = get_y_circulo(c2);
    double r2 = get_r(c2);

    double distanciaEntreCentros = distancia_quadrada(x1, y1, x2, y2);

    double somaRaiosAoQuadrado = (r1 + r2) * (r1 + r2);

    return distanciaEntreCentros <= somaRaiosAoQuadrado;

}

bool sobrepoe_circulo_retangulo(CIRCULO *c1, RETANGULO *r) {
    double xCirculo = get_x_circulo(c1);
    double yCirculo = get_y_circulo(c1);
    double raio = get_r(c1);

    double xRetangulo = get_x_retangulo(r);
    double yRetangulo = get_y_retangulo(r);
    double altura = get_h(r);
    double largura = get_w(r);

    double x_min = xRetangulo;
    double x_max = xRetangulo + largura;
    double y_min = yRetangulo - altura;
    double y_max = yRetangulo;

    double px, py;
    if (xCirculo < x_min) {
        px = x_min;
    }

    else if (xCirculo > x_max) {
        px = x_max;
    }

    else {
        px = xCirculo;
    }

    if (yCirculo < y_min) {
        py = y_min;
    }

    else if (yCirculo > y_max) {
        py = y_max;
    }

    else {
        py = yCirculo;
    }

    double distanciaAoQuadrado = distancia_quadrada(xCirculo, yCirculo, px, py);

    return distanciaAoQuadrado <= (raio * raio);

}

static bool ponto_dentro_retangulo(RETANGULO *r, double px, double py) {
    double rx_min = get_x_retangulo(r);
    double rx_max = get_x_retangulo(r) + get_w(r);

    double ry_min = get_y_retangulo(r) - get_h(r);
    double ry_max = get_y_retangulo(r);

    bool dentroX = (px >= rx_min) && (px <= rx_max);
    bool dentroY = (py >= ry_min) && (py <= ry_max);

    return dentroX && dentroY;
}

bool sobrepoe_circulo_linhaOUtexto(CIRCULO *c, LINHA *l) {
    double cx = get_x_circulo(c);
    double cy = get_y_circulo(c);
    double cr = get_r(c);

    double lx1 = get_x1_linha(l);
    double lx2 = get_x2_linha(l);
    double ly1 = get_y1_linha(l);
    double ly2 = get_y2_linha(l);

    double distP1Linha = distancia_quadrada(cx, cy, lx1, ly1);
    double distP2Linha = distancia_quadrada(cx, cy, lx2, ly2);
    double raioAoQuadrado = cr * cr;

    if (distP1Linha <= raioAoQuadrado || distP2Linha <= raioAoQuadrado) {
        return true;
    }

    double comprimentoAoQuadrado = distancia_quadrada(lx1, ly1, lx2, ly2);
    if (comprimentoAoQuadrado == 0.0) {
        return distP1Linha <= raioAoQuadrado;
    }

    double t = ((cx - lx1) * (lx2 - lx1) + (cy - ly1) * (ly2 - ly1)) / comprimentoAoQuadrado;

    t = fmax(0.0, fmin(1.0, t));

    double px = lx1 + t * (lx2 - lx1);
    double py = ly1 + t * (ly2 - ly1);
    double distanciaAoQuadradoDoCirculo = distancia_quadrada(cx, cy, px, py);

    return distanciaAoQuadradoDoCirculo <= raioAoQuadrado;
}

bool sobrepoe_retangulo_retangulo(RETANGULO *r1, RETANGULO *r2) {
    double r1x = get_x_retangulo(r1);
    double r1y = get_y_retangulo(r1);
    double r1h = get_h(r1);
    double r1w = get_w(r1);

    double r2x = get_x_retangulo(r2);
    double r2y = get_y_retangulo(r2);
    double r2h = get_h(r2);
    double r2w = get_w(r2);

    double intervaloR1x = r1x + r1w;
    double intervaloR2x = r2x + r2w;

    bool sobrepoeX = ((r1x  < intervaloR2x) && (intervaloR1x > r2x));

    double intervaloR1y = r1y - r1h;
    double intervaloR2y = r2y - r2h;

    bool sobrepoeY = ((intervaloR1y < r2y)) && ((r1y > intervaloR2y));

    return sobrepoeX && sobrepoeY;

}

int orientacao(double px, double py, double qx, double qy, double rx, double ry) {
    double val = (qy - py) * (rx - qx) - (qx - px) * (ry - qy);
    if (fabs(val) < 1e-10) return 0;
    return (val > 0) ? 1 : 2;
}

bool pontoEstaNoSegmento(double px, double py, double qx, double qy, double rx, double ry) {
    return (qx <= fmax(px, rx) && qx >= fmin(px, rx) && qy <= fmax(py, ry) && qy >= fmin(py, ry));
}

bool sobrepoe_linha_linha(LINHA *l1, LINHA *l2) {
    double l1x1 = get_x1_linha(l1);
    double l1y1 = get_y1_linha(l1);
    double l1x2 = get_x2_linha(l1);
    double l1y2 = get_y2_linha(l1);

    double l2x1 = get_x1_linha(l2);
    double l2y1 = get_y1_linha(l2);
    double l2x2 = get_x2_linha(l2);
    double l2y2 = get_y2_linha(l2);


    int o1 = orientacao(l1x1, l1y1, l1x2, l1y2, l2x1, l2y1);
    int o2 = orientacao(l1x1, l1y1, l1x2, l1y2, l2x2, l2y2);
    int o3 = orientacao(l2x1, l2y1, l2x2, l2y2, l1x1, l1y1);
    int o4 = orientacao(l2x1, l2y1, l2x2, l2y2, l1x2, l1y2);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && pontoEstaNoSegmento(l1x1, l1y1, l2x1, l2y1, l1x2, l1y2)) return true;
    if (o2 == 0 && pontoEstaNoSegmento(l1x1, l1y1, l2x2, l2y2, l1x2, l1y2)) return true;
    if (o3 == 0 && pontoEstaNoSegmento(l2x1, l2y1, l1x1, l1y1, l2x2, l2y2)) return true;
    if (o4 == 0 && pontoEstaNoSegmento(l2x1, l2y1, l1x2, l1y2, l2x2, l2y2)) return true;

    return false;
}

bool sobrepoe_linha_texto(LINHA *l, TEXTO *t) {
    double xt_ancora = get_x_texto(t);
    double yt_ancora = get_y_texto(t);
    char ancora_texto = get_a(t);
    int tamanho_texto = get_tamanho_texto(t);

    double comprimento_texto = 10.0 * tamanho_texto;

    double tx1, ty1, tx2, ty2;

    switch (ancora_texto) {
        case 'i': {
            tx1 = xt_ancora;
            ty1 = yt_ancora;
            tx2 = xt_ancora + comprimento_texto;
            ty2 = yt_ancora;
            break;
        }

        case 'm': {
            tx1 = xt_ancora - comprimento_texto / 2.0;
            ty1 = yt_ancora;
            tx2 = xt_ancora + comprimento_texto / 2.0;
            ty2 = yt_ancora;
            break;
        }

        case 'f': {
            tx1 = xt_ancora - comprimento_texto;
            ty1 = yt_ancora;
            tx2 = xt_ancora;
            ty2 = yt_ancora;
            break;
        }

        default:
            return false;
    }

    LINHA *linha_do_texto = cria_linha(-1, tx1, ty1, tx2, ty2, "temporario");

    bool resultado = sobrepoe_linha_linha(l, linha_do_texto);

    excluir_linha(linha_do_texto);

    return resultado;
}



bool sobrepoe_retangulo_linha(RETANGULO *r, LINHA *l) {
    double lx1 = get_x1_linha(l);
    double ly1 = get_y1_linha(l);
    double lx2 = get_x2_linha(l);
    double ly2 = get_y2_linha(l);

    if (ponto_dentro_retangulo(r, lx1, ly1) || ponto_dentro_retangulo(r, lx2, ly2)) {
        return true;
    }

    double rx = get_x_retangulo(r);
    double ry = get_y_retangulo(r);
    double rw = get_w(r);
    double rh = get_h(r);

    double cse_x = rx,      cse_y = ry - rh;
    double csd_x = rx + rw, csd_y = ry - rh;
    double cie_x = rx,      cie_y = ry;
    double cid_x = rx + rw, cid_y = ry;

    LINHA *borda_cima = cria_linha(-1, cse_x, cse_y, csd_x, csd_y, "temp");
    LINHA *borda_direita = cria_linha(-1, csd_x, csd_y, cid_x, cid_y, "temp");
    LINHA *borda_baixo = cria_linha(-1, cid_x, cid_y, cie_x, cie_y, "temp");
    LINHA *borda_esquerda = cria_linha(-1, cie_x, cie_y, cse_x, cse_y, "temp");

    bool resultado = (sobrepoe_linha_linha(l, borda_cima) ||
                     sobrepoe_linha_linha(l, borda_direita) ||
                     sobrepoe_linha_linha(l, borda_baixo) ||
                     sobrepoe_linha_linha(l, borda_esquerda));

    excluir_linha(borda_cima);
    excluir_linha(borda_direita);
    excluir_linha(borda_baixo);
    excluir_linha(borda_esquerda);

    return resultado;
}

void converter_texto_para_linha(TEXTO *t, LINHA *l_out) {
    double xt_ancora = get_x_texto(t);
    double yt_ancora = get_y_texto(t);
    char ancora_texto = get_a(t);
    int num_chars = get_tamanho_texto(t);

    double comprimento = 10.0 * num_chars;
    double tx1, ty1, tx2, ty2;

    ty1 = yt_ancora;
    ty2 = yt_ancora;


    switch (ancora_texto) {
        case 'i':
            tx1 = xt_ancora;
            tx2 = xt_ancora + comprimento;
            break;
        case 'm':
            tx1 = xt_ancora - (comprimento / 2.0);
            tx2 = xt_ancora + (comprimento / 2.0);
            break;
        case 'f':
            tx1 = xt_ancora - comprimento;
            tx2 = xt_ancora;
            break;

        default:

            tx1 = xt_ancora;
            tx2 = xt_ancora;
            break;
    }

    set_x1_linha(l_out, tx1);
    set_y1_linha(l_out, ty1);
    set_x2_linha(l_out, tx2);
    set_y2_linha(l_out, ty2);
}