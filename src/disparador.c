#include "DISPARADOR.h"
#include "CARREGADOR.h"
#include "forma.h"
#include "arena.h"
#include "fila.h"

#include <stdio.h>
#include <stdlib.h>


typedef struct Disparador {
	int i;
	double x, y;
	Forma *formaEmDisparo;
	CARREGADOR *esq, *dir;
} Disparador;

DISPARADOR *criaDisparador(int i, double x, double y, CARREGADOR *esq, CARREGADOR *dir) {
	DISPARADOR *d = malloc (sizeof(DISPARADOR));
	if (d == NULL) {
		printf("Erro ao criar o DISPARADOR!\n");
		return NULL;
	}

	d -> i = i;
	d -> x = x;
	d -> y = y;
	d -> esq = esq;
	d -> dir = dir;
	d -> formaEmDisparo = NULL;

	printf("Disparador %i criado com sucesso!\n", d -> i);

	return d;

}

int getIDDISPARADOR(DISPARADOR *d) {
	return d -> i;
}

void posicionaDisparador(DISPARADOR *d, double x, double y) {
	if (d == NULL) {
		printf("Disparador nulo passado para a função de posicionamento!\n");
		return;
	}

	d -> x = x;
	d -> y = y;

}

void attachDisparador(DISPARADOR *d, CARREGADOR *esq, CARREGADOR *dir) {
	if (d == NULL) {
		printf("Disparador NULL foi passado para a função attachDisparador!\n");
		return;
	}

	if (esq == NULL || dir == NULL) {
		printf("CARREGADOR NULL passado para a funcao attachDisparador!\n");
		return;
	}


	d -> esq = esq;
	d -> dir = dir;

	d -> formaEmDisparo = NULL;

}

forma* shiftDisparador(DISPARADOR *d, char botao, int n) {
    if (d == NULL || n < 0) {
        return NULL;
    }

    forma *forma_anterior = d->formaEmDisparo;

    for (int i = 0; i < n; i++) {
        switch (botao) {
            case 'd': {

                if (forma_anterior != NULL) {
                    adicionaFormaCARREGADOR(d->dir, forma_anterior);
                    forma_anterior = NULL;
                }

                if (CARREGADOREstaVazio(d -> esq)) {
                    d->formaEmDisparo = NULL;
                    return NULL;
                }

                forma_anterior = removeDoCARREGADOR(d -> esq);
                d->formaEmDisparo = forma_anterior;
                break;
            }

            case 'e': {

                if (forma_anterior != NULL) {
                    adicionaFormaCARREGADOR(d->esq, forma_anterior);
                    forma_anterior = NULL;
                }

                if (CARREGADOREstaVazio(d -> dir)) {
                    d->formaEmDisparo = NULL;
                    return NULL;
                }

                forma_anterior = removeDoCARREGADOR(d -> dir);
                d->formaEmDisparo = forma_anterior;
                break;
            }

            default: {
                return NULL;
            }
        }
    }


    return forma_anterior;
}


forma *disparaDisparador(DISPARADOR *d, double dx, double dy) {
	if (d == NULL) {
		printf("Disparador inexistente passado para a função disparaDisparador!\n");
		return NULL;
	}


	if (d -> formaEmDisparo == NULL) {
		printf("Nenhuma forma está na posição de disparo!\n");
		return NULL;
	}

	forma *formaDisparada = d -> formaEmDisparo;
	d -> formaEmDisparo = NULL;

	double x_DISPARADOR = getXDISPARADOR(d);
	double y_DISPARADOR = getYDISPARADOR(d);

	double posicaoFinalX = dx + x_DISPARADOR;
	double posicaoFinalY = dy + y_DISPARADOR;

	setPosicaoForma(formaDisparada, posicaoFinalX, posicaoFinalY);


	return formaDisparada;

}

fila *rajadaDisparador(DISPARADOR *d, char botao, double dx, double dy, double ix, double iy, arena *a) {
	if (d == NULL || a == NULL) {
		return NULL;
	}

	double x_original = getXDISPARADOR(d);
	double y_original = getYDISPARADOR(d);

	fila *fila_disparos = criaFila();
	int formas_disparadas = 0;


	for (int i = 0; ; i++) {

		forma *formaAtual = shiftDisparador(d, botao, 1);
		if (formaAtual == NULL) {
			break;
		}

		double dx_atual = dx + (i * ix);
		double dy_atual = dy + (i * iy);

		forma *formaDisparada = disparaDisparador(d, dx_atual, dy_atual);

		if (formaDisparada != NULL) {

			adicionaFormaArena(a, formaDisparada);
			enqueue(fila_disparos, formaDisparada);
			formas_disparadas++;
		}
	}

	posicionaDisparador(d, x_original, y_original);

	return fila_disparos;
}


forma *getFormaEmDisparo(DISPARADOR *d) {
	if (d == NULL || d -> formaEmDisparo == NULL) {
		return NULL;
	}

	return d -> formaEmDisparo;
}

double getXDISPARADOR(DISPARADOR *d) {
	return d -> x;
}

double getYDISPARADOR(DISPARADOR *d) {
	return d -> y;
}

void limpaFormaDoDisparador(DISPARADOR *d, forma *f) {
	if (d == NULL || f == NULL) {
		return;
	}

	if (d -> formaEmDisparo == f) {
		d -> formaEmDisparo = NULL;
	}
}


void destrutorDisparador(DISPARADOR **ptr_DISPARADOR) {
	if (ptr_DISPARADOR == NULL || *ptr_DISPARADOR == NULL) return;

	DISPARADOR* d = *ptr_DISPARADOR;

	free(d);
	*ptr_DISPARADOR = NULL;
}