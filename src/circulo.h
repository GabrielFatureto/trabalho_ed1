#ifndef circulo_h
#define circulo_h

typedef void* CIRCULO;

/*
 Um Círculo é uma forma geométrica posicionada em um plano bidimensional.
 É identificado por um número inteiro (i), e definido por um ponto central, posicionado na coordenada (x,y), cuja distância até a borda do é definida pelo raio (r).
 Um Círculo possui uma cor de borda (corb), e uma cor de preenchimento (corp).
 As cores são definidas usando o padrão sRGB de 6 dígitos.
 (Exemplo: #FFFFFF)
*/

/**
 /// @brief Cria uma estrutura (círculo) com os parâmetros fornecidos
 /// @param i Número de identificação da forma criada
 /// @param x Coordenada x do centro do círculo
 /// @param y Coordenada y do centro do círculo
 /// @param r Raio do círculo
 /// @param Corb Cor da borda do círculo
 /// @param Corp Cor de preenchimento do círculo
 /// @return Retorna o círculo criado pelos parâmetros informados 
*/
CIRCULO cria_circulo(int i, double x, double y, double r, char* corb, char* corp);

/**
 /// @brief Obtém o identificador da forma 
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Identificador da forma
*/
int get_i(CIRCULO c);

/**
 /// @brief Obtém a coordenada x do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Coordenada x do círculo que será criado
 */
double get_x_circulo(CIRCULO c);

/** 
 /// @brief Obtém a coordenada y do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Coordenada y do círculo que será criado
 */
double get_y_circulo(CIRCULO c);

/**
 /// @brief Obtém o raio do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Raio do círculo
 */
double get_r(CIRCULO c);

/**
 /// @brief Obtém a cor da borda do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Retorna a cor da borda do círculo
 */
char* get_corb(CIRCULO c);

/**
 /// @brief Obtém a cor de preenchimento do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Retorna a cor de preenchimento do círculo
 */
char* get_corp(CIRCULO c);

/**
 /// @brief Calcula a área do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Retorna a área do círculo
 */
double get_area(CIRCULO c);

/**
 /// @brief Define o identificador do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param i Novo identificador
*/
void set_i (CIRCULO c, int i);

/**
 /// @brief Define a coordenada x do centro do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param x Nova coordenada x dentro do círculo
 */ 
void set_x_circulo(CIRCULO c, double x);

/**
 /// @brief Define a coordenada y do centro do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param y Nova coordenada y dentro do círculo
 */
void set_y_circulo(CIRCULO c, double y);

/**
 /// @brief Define a cor da borda do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param corb Nova cor para a borda do círculo
 */
void set_corb(CIRCULO c, char* corb);

/**
 /// @brief Define a cor de preenchimento do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param corp Nova cor para o preenchimento do círculo
 */
void set_corp(CIRCULO c, char* corp);

/**
 /// @brief Libera a memória alocada para a estrutura do círculo
 /// @param c Ponteiro para a estrutura do círculo
 */
void excluir_circulo(CIRCULO c);

#endif