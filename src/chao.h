#ifndef CHAO_H
#define CHAO_H

#include "forma.h"
#include <stdbool.h>

#include "fila.h"


/* ------- TAD CHAO -------
 * O TAD Chão funciona como um repositório ou "inventário" para as
 * formas criadas, mas ainda não estão em jogo (ou seja,
 * ainda não foram colocadas em um carregador ou disparadas na arena).
 * Seus principais conceitos são:
 *
 * Armazenamento Primário: Serve como o local inicial de armazenamento
 * para todas as formas lidas do arquivo de entrada, antes de serem
 * distribuídas para os carregadores;
 *
 * Fonte de Munição: Atua como a fonte de onde as formas são retiradas
 * ('retiraChao') para serem inseridas nos carregadores dos
 * disparadores;
 *
 * Gerenciamento de Memória: É responsável pelo ciclo de vida das formas
 * que ainda não entraram no jogo. Ao ser destruído, todas as formas
 * restantes no chão também são liberadas da memória.
 */

typedef struct stChao chao;

/// @brief: Cria o chão (onde as formas ficam antes
/// de serem carregadas e disparadas na arena)
/// @return: Retorna um ponteiro para o chão criado.
chao *criaChao();

/// @brief: Verifica se o chão está vazio.
/// @param c: Ponteiro para o chão.
/// @return: TRUE se estiver vazio.
/// @return: FALSE se não estiver vazio.
bool chaoEstaVazio(chao *c);

/// @brief: Coloca uma FORMA no chão.
/// @param c: Ponteiro para o chão.
/// @param f: Ponteiro para a FORMA que será colocada no chão.
void adicionaNoChao(chao *c, FORMA *f);

/// @brief: Retira uma FORMA do chão.
/// @param c: Ponteiro para o chão.
/// @return: Retorna um ponteiro para a FORMA que foi retirada.
FORMA *retiraDoChao(chao *c);

/// @brief: Libera toda a memória do chão.
/// @param c: Ponteiro para o chão a ser liberado.
void destrutorChao(chao *c);

/// @brief: Pega e retorna a FILA do chão.
/// @param c: Ponteiro para o chão.
/// @return: Fila do chão.
FILA *getFilaDoChao(chao *c);

#endif