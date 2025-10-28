#include "arena.h"
#include "fila.h"
#include "forma.h"
#include "sobreposição.h"
#include "chao.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct stArena {
    FILA *filaArena;
}arena;

arena *criaArena() {
    arena *a = (arena*) malloc (sizeof(arena));
    if (a == NULL) {
        printf("Erro ao criar a arena!\n");
        return NULL;
    }

    a -> filaArena = fila_criar();

    printf("Arena criada com sucesso!\n");

    return a;
}

FORMA *adicionaFormaArena(arena *a, FORMA *f) {
    if (f == NULL) {
        return NULL;
    }

    if (a == NULL) {
        printf("Arena inexistente passada para a função 'adicionaFormaArena'\n");
        return NULL;
    }

    fila_enfileirar(a -> filaArena, f);

    return f;
}

FORMA *removeFormaArena(arena *a) {
    if (a == NULL ) return NULL;

    FORMA *removido = fila_desenfileirar(a -> filaArena);

    return removido;
}

bool arenaEstaVazia(arena *a) {
    if (a == NULL) return true;

    return fila_esta_vazia(a -> filaArena);
}

void destrutorArena(arena **a_ptr) {
    if (a_ptr == NULL || *a_ptr == NULL) {
        return;
    }
    arena* a = *a_ptr;

    destruir_fila(a -> filaArena);

    free(a);
    *a_ptr = NULL;
}

int getArenaNumFormas(arena *a) {
    return fila_tamanho(a -> filaArena);
}

int getTamArena(arena *a) {
    if (a == NULL) {
        return -1;
    }

    return fila_tamanho(a -> filaArena);
}

void processaArena(arena *a, chao *c, double *pontuacao_total, FILA *anotacoes_svg,
                   FILE *arquivo_txt, int *formas_clonadas, int *formas_esmagadas, repositorio *repo) {
    if (c == NULL || a == NULL || arquivo_txt == NULL) {
        printf("Erro: Parâmetros nulos passados para processaArena!\n");
        return;
    }

    *pontuacao_total = 0.0;
    double area_esmagada_round = 0.0;

    if (formas_clonadas != NULL) *formas_clonadas = 0;
    if (formas_esmagadas != NULL) *formas_esmagadas = 0;

        printf("\n=== INICIANDO PROCESSAMENTO DA ARENA ===\n");
    while (getTamArena(a) >= 2) {
        FORMA *forma_I = removeFormaArena(a);
        FORMA *forma_J = removeFormaArena(a);

        if (formasSobrepoem(forma_I, forma_J)) {

            printf("\nSobreposição detectada!\n");

            double area_I = get_area_Forma(forma_I);
            double area_J = get_area_Forma(forma_J);

            fprintf(arquivo_txt, "Forma %d (I) vs Forma %d (J). HOUVE SOBREPOSIÇÃO.\n",
                    get_id_Forma(forma_I), get_id_Forma(forma_J));

            if (area_I < area_J) {
                printf("=== I < J ===\n ID = %d (I) (área %.2f) foi esmagada por ID = %d (J) (área %.2f).\n",
                        get_id_Forma(forma_I), area_I, get_id_Forma(forma_J), area_J);
                fprintf(arquivo_txt, "<<<-- I < J -->>> FORMA %d (I) (área %.2f) foi esmagada por FORMA %d (J) (área %.2f).\n",
                        get_id_Forma(forma_I), area_I, get_id_Forma(forma_J), area_J);

                if (repo != NULL) {
                    limpaFormaDeTodosDisparadores(repo, forma_I);
                }

                double x_esmagada = get_x_Forma(forma_I);
                double y_esmagada = get_y_Forma(forma_I);

                ESTILO *estilo_asterisco = criar_estilo("sans-serif", "bold", "30px");
                TEXTO* asterisco = criarTexto(-1, x_esmagada, y_esmagada, "red", "black", 'm', "*", estilo_asterisco);
                excluir_estilo(estilo_asterisco);
                fila_enfileirar(anotacoes_svg, cria_Forma_texto(asterisco));

                *pontuacao_total += area_I;
                area_esmagada_round += area_I;
                if (formas_esmagadas != NULL) (*formas_esmagadas)++;

                excluir_Forma(forma_I);
                adicionaNoChao(c, forma_J);
            }
            else if (area_I >= area_J) {
                printf("=== I >= J ===\n ID = %d (I) (área %.2f) modificou a ID = %d (J) (área %.2f).\n\n",
                    get_id_Forma(forma_I), area_I, get_id_Forma(forma_J), area_J);
                fprintf(arquivo_txt, "<<<-- I >= J -->>>\n FORMA %d (I) (área %.2f) modificou a FORMA %d (J) (área %.2f).\n\n",
                        get_id_Forma(forma_I), area_I, get_id_Forma(forma_J), area_J);

                FORMA *clone_I = NULL;

                if (get_tipo_Forma(forma_I) == linha) {
                    char *corLinha = get_cor_linha(getFormaDados(forma_I));
                    char *cor_complementar_linha = getCorComplementar(corLinha);

                    setCorbFormas(forma_J, cor_complementar_linha);

                    clone_I = clonarForma(forma_I);

                    void *dados_clone = getFormaDados(clone_I);
                    if (dados_clone != NULL) {
                        setCorLinha((LINHA*)dados_clone, cor_complementar_linha);
                    }

                    free(corLinha);
                    free(cor_complementar_linha);
                } else {
                    setCorbFormas(forma_J, getCorpForma(forma_I));
                    clone_I = clonarForma(forma_I);
                    alterna_cores_forma(clone_I);
                }

                if (formas_clonadas != NULL) (*formas_clonadas)++;

                adicionaNoChao(c, forma_I);
                adicionaNoChao(c, forma_J);
                if (clone_I != NULL) {
                    adicionaNoChao(c, clone_I);
                }
            }
        }
        else {
            fprintf(arquivo_txt, "Forma %d (I) vs Forma %d (J). NÃO HOUVE SOBREPOSIÇÃO.\n",
                    get_id_Forma(forma_I), get_id_Forma(forma_J));
            adicionaNoChao(c, forma_I);
            adicionaNoChao(c, forma_J);
        }
    }

    if (!arenaEstaVazia(a)) {
        adicionaNoChao(c, removeFormaArena(a));
    }

    fprintf(arquivo_txt, "Área total esmagada no round: %.2f\n", area_esmagada_round);
}