#ifndef texto_h
#define texto_h

typedef void* TEXTO;
typedef void* ESTILO;

/*
 A estrutura Texto representa um texto no plano bidimensional, com atributos como identificador (id),
 coordenadas (x, y), cor da borda (corb), cor de preenchimento (corp), âncora (a), conteúdo do texto (txt),
 família da fonte (fFamily), peso da fonte (fWeight) e tamanho da fonte (fSize). 
*/

typedef struct Text Text;
typedef struct Stile Stile;

/*
--------------------------------------------------- Funções de Estilo ---------------------------------------------------
*/


/**
 /// @brief Cria um estilo de texto com os atributos especificados
 /// @param fFamily String referente à font-family
 /// @param fWeight String referente à font-weight
 /// @param fSize String referente à font-size
 /// @return Um ponteiro para a estrutura ESTILO criada
 */
ESTILO criar_estilo (char* fFamily, char* fWeight, char* fSize);

/**
 /// @brief Cria uma cópia de um estilo de texto existente
 /// @param original Ponteiro para a estrutura ESTILO original
 /// @return Retorna um ponteiro para a nova estrutura ESTILO criada como cópia
 */
ESTILO criaCopiaEstilo(Stile *original);

/**
 /// @brief Obtém a font-Family do estilo de texto
 /// @param e Ponteiro para a estrutura ESTILO
 /// @return Retorna a font-Family
 */ 
char* get_fFamily (ESTILO e);

/**
 /// @brief Obtém a font-Weight do estilo de texto
 /// @param e Ponteiro para a estrutura ESTILO
 /// @return Retorna a font-Weight
 */ 
char* get_fWeight (ESTILO e);

/**
 /// @brief Obtém a font-Size do estilo de texto
 /// @param e Ponteiro para a estrutura ESTILO
 /// @return Retorna a font-Size
 */ 
char* get_fSize (ESTILO e);

/**
 /// @brief Define a font-Family do estilo de texto
 /// @param e Ponteiro para a estrutura ESTILO
 /// @param fFamily Nova font-Family
 */
void set_fFamily (ESTILO e, char* fFamily);

/**
 /// @brief Define a font-Weight do estilo de texto
 /// @param e Ponteiro para a estrutura ESTILO
 /// @param fWeight Nova font-Weight
 */
void set_fWeight (ESTILO e, char* fWeight);

/**
 /// @brief Define a font-Size do estilo de texto
 /// @param e Ponteiro para a estrutura ESTILO
 /// @param fSize Nova font-Size
 */
void set_fSize (ESTILO e, char* fSize);


/*
--------------------------------------------------- Funções de Texto ---------------------------------------------------
*/


/**
 /// @brief Cria um texto com os atributos especificados
 /// @param i Identificador do texto
 /// @param x Coordenada x da ancora do texto
 /// @param y Coordenada y da ancora do texto
 /// @param corb Cor da borda do texto
 /// @param corp Cor de preenchimento do texto
 /// @param a Define a âncora do texto (meio, inicio, fim) 
 /// @param txt Conteúdo do texto
 /// @return Retorna um ponteiro para a estrutura TEXTO criada
 */
TEXTO criarTexto (int i, double x, double y, char* corb, char* corp, char a, char* txt, ESTILO e);

/**  
 /// @brief Obtém o identificador do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @return Retorna o identificador do texto
 */
int get_i_texto (TEXTO t);

/**
 /// @brief 
 /// @param t 
 /// @return 
 */
ESTILO getEstiloTexto(TEXTO t);

/** 
 /// @brief Obtém a coordenada x da âncora do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @return Retorna o valor de x
 */
double get_x_texto (TEXTO t);

/** 
 /// @brief Obtém a coordenada y da âncora do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @return Retorna o valor de y
 */
double get_y_texto (TEXTO t);

/** 
 /// @brief Obtém a cor da borda do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @return Retorna a cor da borda
 */
char* get_corb_texto (TEXTO t);

/** 
 /// @brief Obtém a cor de preenchimento do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @return Retorna a cor de preenchimento
 */
char* get_corp_texto (TEXTO t);

/**
 /// @brief Obtém a âncora do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @return Retorna a âncora do texto
 */
char get_a (TEXTO t);

/**
 /// @brief Obtém o conteúdo do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @return Returna o conteúdo do texto
 */
char* get_txt (TEXTO t);

/**
 /// @brief Obtém o tamanho do conteúdo do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @return Retorna o tamanho do conteúdo do texto
 */
int get_tamanho_texto(TEXTO t);


/**
 /// @brief Define o identificador do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @param id Novo identificador do texto
 */
void set_i_texto (TEXTO t, int id);

/**
 /// @brief Define o x da âncora do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @param x Novo valor de x para a âncora do texto
 */
void set_x_texto (TEXTO t, double x);

/**
 /// @brief Define o y da âncora do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @param y Novo valor de y para a âncora do texto
 */
void set_y_texto (TEXTO t, double y);

/**
 /// @brief Define a cor da borda do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @param corb Nova cor da borda do texto
 */
void set_corb_texto (TEXTO t, char* corb);

/**
 /// @brief Define a cor de preenchimento do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @param corp Nova cor de preenchimento do texto
 */
void set_corp_texto (TEXTO t, char* corp);

/**
 /// @brief Define a âncora do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @param a Nova âncora do texto (meio, inicio, fim)
 */
void set_a (TEXTO t, char a);

/**
 /// @brief Define o conteúdo do texto
 /// @param t Ponteiro para a estrutura TEXTO
 /// @param txt Novo conteúdo do texto
 */
void set_txt (TEXTO t, char* txt);

/**
 /// @brief Libera a memória alocada para a estrutura TEXTO
 /// @param t Ponteiro para a estrutura TEXTO
 */
void excluir_texto (TEXTO t);

/**
 /// @brief Libera a memória alocada para a estrutura ESTILO
 /// @param t Ponteiro para a estrutura ESTILO
 */
void excluir_estilo (ESTILO e);

#endif