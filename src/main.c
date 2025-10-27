#include <stdio.h>
#include <string.h>

#include "fila.h"
#include "chao.h"
#include "arena.h"
#include "geo.h"
#include "qry.h"
#include "svg.h"

static void montaCaminho(char* path_completo, const char* base_dir, const char* nome_arquivo) {
    if (base_dir != NULL && strlen(base_dir) > 0) {
        sprintf(path_completo, "%s/%s", base_dir, nome_arquivo);
    } else {
        strcpy(path_completo, nome_arquivo);
    }
}

int main(int argc, char *argv[]) {

    // --- 1. Processamento dos Parâmetros da Linha de Comando ---
    char* dir_entrada = NULL;
    char* arq_geo_nome = NULL;
    char* dir_saida = NULL;
    char* arq_qry_nome = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            dir_entrada = argv[++i];
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            arq_geo_nome = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            dir_saida = argv[++i];
        } else if (strcmp(argv[i], "-q") == 0 && i + 1 < argc) {
            arq_qry_nome = argv[++i];
        }
    }

    if (arq_geo_nome == NULL || dir_saida == NULL) {
        printf("ERRO: Parâmetros obrigatórios -f e -o não foram fornecidos.\n");
        printf("Uso: ./ted -f arq.geo -o dir_saida [-e dir_entrada] [-q arq.qry]\n");
        return 1;
    }

    // --- 2. Montagem dos Nomes e Caminhos dos Arquivos ---
    char path_geo_completo[512];
    montaCaminho(path_geo_completo, dir_entrada, arq_geo_nome);

    char nome_base_geo[256];
    // Lógica para extrair o nome base do arquivo, ex: "t1.geo" -> "t1"
    char* ultimo_slash = strrchr(arq_geo_nome, '/');
    strcpy(nome_base_geo, ultimo_slash ? ultimo_slash + 1 : arq_geo_nome);
    char* ponto_ext = strrchr(nome_base_geo, '.');
    if (ponto_ext) *ponto_ext = '\0';

    char path_svg_inicial[512];
    sprintf(path_svg_inicial, "%s/%s.svg", dir_saida, nome_base_geo);

    // --- 3. Inicialização das Estruturas de Dados ---
    arena* minha_arena = criaArena();
    repositorio* repo = criarRepositorio();
    FILA* anotacoes_svg = fila_criar();
    double pontuacao = 0.0;
    int formas_clonadas = 0, formas_esmagadas = 0;

    // --- 4. Execução do ProcessaGeo ---
    printf("Abrindo arquivo .geo: %s\n", path_geo_completo);

FILE* geo_file = fopen(path_geo_completo, "r");
if (geo_file == NULL) {
    fprintf(stderr, "ERRO: Não foi possível abrir o arquivo .geo em: %s\n", path_geo_completo);
    // Libera o que já foi alocado antes de sair
    destrutorArena(&minha_arena);
    destrutorRepositorio(repo);
    destruir_fila(anotacoes_svg);
    return 1;
}

printf("Lendo o arquivo .geo e adicionando as formas ao chão...\n");
chao *meu_chao = ler_geo(geo_file); // <--- Passa o FILE*
fclose(geo_file); // <--- Fecha o arquivo após a leitura

if (meu_chao == NULL) {
    fprintf(stderr,"Falha critica ao processar o .geo (%s)\n", path_geo_completo);

    // --- 5. Geração do SVG Inicial ---
    printf("Gerando SVG inicial: %s\n", path_svg_inicial);
    gerarArquivoSvg(path_svg_inicial, getFilaDoChao(meu_chao));

    // --- 6. Execução do ProcessaQry (se aplicável) ---
    if (arq_qry_nome != NULL) {
        char path_qry_completo[512];
        montaCaminho(path_qry_completo, dir_entrada, arq_qry_nome);

        char nome_base_qry[256];
        char* ultimo_slash_qry = strrchr(arq_qry_nome, '/');
        strcpy(nome_base_qry, ultimo_slash_qry ? ultimo_slash_qry + 1 : arq_qry_nome);
        ponto_ext = strrchr(nome_base_qry, '.');
        if (ponto_ext) *ponto_ext = '\0';

        char path_svg_final[520];
        char path_txt_final[520];
        sprintf(path_svg_final, "%s/%s-%s.svg", dir_saida, nome_base_geo, nome_base_qry);
        sprintf(path_txt_final, "%s/%s-%s.txt", dir_saida, nome_base_geo, nome_base_qry);

        printf("Processando arquivo .qry: %s\n", path_qry_completo);
        processaQry(repo, path_qry_completo, path_txt_final,
                            minha_arena, meu_chao, &pontuacao, anotacoes_svg,
                            &formas_clonadas, &formas_esmagadas);


        while (!fila_esta_vazia(anotacoes_svg)) {
            FORMA *anotacao = fila_desenfileirar(anotacoes_svg);
            adicionaNoChao(meu_chao, anotacao);
        }


        printf("Gerando SVG final: %s\n", path_svg_final);
        gerarArquivoSvg(path_svg_final, getFilaDoChao(meu_chao));
    }


    // --- 7. Liberação de Toda a Memória ---
    printf("Finalizando e liberando memória...\n");
    devolveFormasCarregadoresParaChao(repo, meu_chao);
    devolveFormasDisparadoresParaChao(repo, meu_chao);
    destrutorRepositorio(repo);
    destrutorChao(meu_chao);
    destrutorArena(&minha_arena);
    destruir_fila(anotacoes_svg);
    printf("Programa finalizado com sucesso.\n");

    return 0;
}
}