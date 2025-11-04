#ifndef circulo_h
#define circulo_h

typedef struct Circle circulo;

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
circulo* criaCirculo(int i, double x, double y, double r, char* corb, char* corp);

/**
 /// @brief Obtém o identificador da forma 
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Identificador da forma
*/
int getIDCirculo(circulo* c);

/**
 /// @brief Obtém a coordenada x do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Coordenada x do círculo que será criado
 */
double getXCirculo(circulo* c);

/** 
 /// @brief Obtém a coordenada y do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Coordenada y do círculo que será criado
 */
double getYCirculo(circulo* c);

/**
 /// @brief Obtém o raio do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Raio do círculo
 */
double getRaioCirculo(circulo* c);

/**
 /// @brief Obtém a cor da borda do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Retorna a cor da borda do círculo
 */
char* getCorbCirculo(circulo* c);

/**
 /// @brief Obtém a cor de preenchimento do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Retorna a cor de preenchimento do círculo
 */
char* getCorpCirculo(circulo* c);

/**
 /// @brief Define o identificador do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param i Novo identificador
*/
void setIDCirculo (circulo* c, int i);

/**
 /// @brief Define a coordenada x do centro do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param x Nova coordenada x dentro do círculo
 */ 
void setXCirculo(circulo* c, double x);

/**
 /// @brief Define a coordenada y do centro do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param y Nova coordenada y dentro do círculo
 */
void setYCirculo(circulo* c, double y);

/**
 /// @brief Define o raio do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param r Novo raio do círculo
 */
void setRaioCirculo(circulo* c, double r);

/**
 /// @brief Define a cor da borda do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param corb Nova cor para a borda do círculo
 */
void setCorbCirculo(circulo* c, char* corb);

/**
 /// @brief Define a cor de preenchimento do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @param corp Nova cor para o preenchimento do círculo
 */
void setCorpCirculo(circulo* c, char* corp);

/**
 /// @brief Calcula a área do círculo
 /// @param c Ponteiro para a estrutura do círculo
 /// @return Retorna a área do círculo
 */
double calcAreaCirculo(circulo *c);

/**
 /// @brief Libera a memória alocada para a estrutura do círculo
 /// @param c Ponteiro para a estrutura do círculo
 */
void destrutorCirculo(circulo* c);

#endif