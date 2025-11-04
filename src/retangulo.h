#ifndef retangulo_h
#define retangulo_h

typedef struct Rectangle retangulo;

/*
 Um Retângulo é uma forma geométrica posicionada em um plano bidimensional.
 É identificado por um número inteiro (i) e definido por quatro pontos, sendo um deles a âncora (ponto de referência), posicionado na coordenada (x,y), e a posição dos outros pontos é definida pela largura (w) e altura (h).
 Um Retângulo possui uma cor de borda (corb), e uma cor de preenchimento (corp).
 As cores são definidas usando o padrão sRGB de 6 dígitos.
 (Exemplo: #FFFFFF)

 As operações descritas nesse arquivo incluem:
 - Criação de um retângulo com todos os atributos informados.
 - Obtenção do Identificador, coordenadas, dimensões, cores e área do retângulo.
 - Modificação das coordenadas e cores do retângulo.
 - Liberação da memória alocada para o retângulo.
*/

/**
 /// @brief Cria uma estrutura (retângulo) com os parâmetros fornecidos
 /// @param i Número de identificação da forma criada
 /// @param x Coordenada x da âncora do retângulo
 /// @param y Coordenada y da âncora do retângulo
 /// @param w Largura do retângulo
 /// @param h Altura do retângulo
 /// @param Corb Cor da borda do retângulo
 /// @param Corp Cor de preenchimento do retângulo
 /// @return Retorna o retângulo criado pelos parâmetros informados 
 */
retangulo* criaRetangulo(int i, double x, double y, double w, double h, char* corb, char* corp);

/**
 /// @brief Obtém o identificador da forma 
 /// @param r Ponteiro para a estrutura do retângulo
 /// @return Identificador da forma
 */
int getIDretangulo (retangulo* r);

/**
 /// @brief Obtém a coordenada x da âncora do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @return Retorna a coordenada x
 */
double getXretangulo (retangulo* r);

/**
 /// @brief Obtém a coordenada y da âncora do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @return Retorna a coordenada y
 */
double getYretangulo (retangulo* r);

/**
/// @brief Obtém a largura do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @return Retorna a largura w
 */
double getLarguraRetangulo (retangulo* r);

/**
 /// @brief Obtém a altura do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @return Retorna a altura h
 */
double getAlturaRetangulo (retangulo* r);

/**
 /// @brief Obtém a cor da borda do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @return Retorna a cor da borda
 */
char *getCorbRetangulo (retangulo* r);

/**
 /// @brief Obtém a cor de preenchimento do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @return Retorna a cor de preenchimento
 */
char *getCorpRetangulo (retangulo* r);

/**
 /// @brief Define o identificador do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @param i Novo identificador do retângulo
 */
void setIDRetangulo (retangulo* r, int i);

/**
 /// @brief Define o x da âncora do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @param x Novo valor de x para a âncora do retângulo
 */
void setXretangulo (retangulo* r, double x);

/**
 /// @brief Define o y da âncora do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @param y Novo valor de y para a âncora do retângulo
 */
void setYretangulo (retangulo* r, double y);

/**
 /// @brief Define a largura do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @param w Nova largura w do retângulo
 */
void setLarguraRetangulo (retangulo* r, double w);

/**
 /// @brief Define a altura do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @param h Nova altura h do retângulo
 */
void setAlturaRetangulo (retangulo* r, double h);

/**
 /// @brief Define a cor da borda do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @param corb Nova cor para a borda do retângulo
 */
void setCorbRetangulo (retangulo* r, char* corb);

/**
 /// @brief Define a cor de preenchimento do retângulo
 /// @param r Ponteiro para a estrutura retângulo
 /// @param corp Nova cor para o preenchimento do retângulo
 */
void setCorpRetangulo (retangulo* r, char* corp);

/**
 /// @brief Calcula a área do retângulo
 /// @param r Ponteiro para a estrutura do retângulo
 /// @return Retorna a área do retângulo
 */
double calcAreaRetangulo(retangulo *r);

/**
 /// @brief Libera a memória alocada para a estrutura do retângulo
 /// @param r Ponteiro para a estrutura retângulo
 */
void destrutorRetangulo (retangulo* r);

#endif