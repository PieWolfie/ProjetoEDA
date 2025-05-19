/**
 * @file lista.h
 * @author Pedro Rocha a23009
 * @brief IPCA - Projeto de Estruturas de Dados
 * @brief Cabeçalhos das funções para manipulação de listas ligadas e matriz
 * @version 1.0
 * @date 2025-03-27
 */

#include "estrutura.h"

/**
 * @brief Tamanho máximo de linhas da matriz
 */
#define MAX_LINHAS 100

/**
 * @brief Tamanho máximo de colunas da matriz
 */
#define MAX_COLUNAS 100

/**
 * @brief Cria uma nova antena.
 * 
 * @param freq Frequência da antena.
 * @param x Coordenada x da antena.
 * @param y Coordenada y da antena.
 * @return Antena* Apontador para a antena criada.
 */
Antena* criarAntena(char freq, int x, int y);

/**
 * @brief Cria um novo efeito nefasto.
 * 
 * @param x Coordenada x do efeito nefasto.
 * @param y Coordenada y do efeito nefasto.
 * @return Nefasto* Apontador para o efeito nefasto criado.
 */
Nefasto* criarNefasto(int x, int y);

/**
 * @brief Insere uma antena na lista ligada.
 * 
 * @param lista Apontador para a lista de antenas.
 * @param freq Frequência da antena a inserir.
 * @param x Coordenada x da antena a inserir.
 * @param y Coordenada y da antena a inserir.
 * @return int 1 se a antena foi inserida com sucesso, 0 caso contrário.
 */
int inserirAntena(Antena** lista, char freq, int x, int y);

/**
 * @brief Insere um efeito nefasto na lista ligada.
 * 
 * @param lista Apontador para a lista de efeitos nefastos.
 * @param x Coordenada x do efeito nefasto a inserir.
 * @param y Coordenada y do efeito nefasto a inserir.
 * @return int 1 se o efeito nefasto foi inserido com sucesso, 0 caso contrário.
 */
int inserirNefasto(Nefasto** lista, int x, int y);

/**
 * @brief Remove uma antena da lista ligada e liberta a memória.
 * 
 * @param lista Apontador para a lista de antenas.
 * @param x Coordenada x da antena a remover.
 * @param y Coordenada y da antena a remover.
 * @return int 1 se a antena foi removida com sucesso, 0 caso contrário.
 */
int removerAntena(Antena** lista, int x, int y);

/**
 * @brief Carrega as antenas de um ficheiro para uma lista ligada.
 * 
 * @param filename Nome do ficheiro a carregar.
 * @return Antena* Lista de antenas carregada.
 */
Antena* carregarAntenas(const char* filename);

/**
 * @brief Calcula os efeitos nefastos das antenas.
 * 
 * @param lista Lista de antenas.
 * @return Nefasto* Lista de efeitos nefastos.
 */
Nefasto* detetarEfeitosNefastos(Antena* lista);

/**
 * @brief Imprime a lista de antenas.
 * 
 * @param lista Lista de antenas.
 */
int imprimirAntenas(Antena* lista);

/**
 * @brief Imprime a lista de efeitos nefastos.
 * 
 * @param lista Lista de efeitos nefastos.
 */
int imprimirEfeitosNefastos(Nefasto* lista);

/**
 * @brief Carrega a matriz de um ficheiro.
 * 
 * @param filename Nome do ficheiro a carregar.
 * @return char** Matriz carregada.
 */
char** carregarMatriz(const char* filename);

/**
 * @brief Liberta a memória alocada para a matriz.
 * 
 * @param matriz Matriz a libertar.
 * @param linhas Número de linhas da matriz.
 */
int libertarMatriz(char** matriz, int linhas);

/**
 * @brief Insere um caractere numa posição da matriz.
 * 
 * @param matriz Matriz onde inserir o caractere.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param x Coordenada x onde inserir o caractere.
 * @param y Coordenada y onde inserir o caractere.
 * @param c Caractere a inserir.
 * @return int 1 se o caractere foi inserido com sucesso, 0 caso contrário.
 */
int inserirNaMatriz(char** matriz, int linhas, int colunas, int x, int y, char c);

/**
 * @brief Remove um caractere da matriz.
 * 
 * @param matriz Matriz onde remover o caractere.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param x Coordenada x onde remover o caractere.
 * @param y Coordenada y onde remover o caractere.
 * @return int 1 se o caractere foi removido com sucesso, 0 caso contrário.
 */
int removerDaMatriz(char** matriz, int linhas, int colunas, int x, int y);

/**
 * @brief Limpa a matriz.
 * 
 * @param matriz Matriz a limpar.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 */
int limparMatriz(char** matriz, int linhas, int colunas);

/**
 * @brief Atualiza a matriz com as antenas e os efeitos nefastos.
 * 
 * @param matriz Matriz a atualizar.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param lista Lista de antenas.
 * @param efeitos Lista de efeitos nefastos.
 * @return int 1 se a matriz foi atualizada com sucesso.
 */
int atualizarMatriz(char** matriz, int linhas, int colunas, Antena* lista, Nefasto* efeitos);

/**
 * @brief Imprime a matriz.
 * 
 * @param matriz Matriz a imprimir.
 * @param linhas Número de linhas da matriz.
 */
int imprimirMatriz(char** matriz, int linhas);

/**
 * @brief Conta o número de linhas de um ficheiro.
 * 
 * @param filename Nome do ficheiro a contar as linhas.
 * @return int Número de linhas do ficheiro.
 */
int contarLinhas(const char* filename);

/**
 * @brief Conta o número de colunas de um ficheiro.
 * 
 * @param filename Nome do ficheiro a contar as colunas.
 * @return int Número de colunas do ficheiro.
 */
int contarColunas(const char* filename);

/**
 * @brief Guarda a lista de antenas num ficheiro binário.
 * @param ficheiro Nome do ficheiro a criar
 * @param lista Lista ligada de antenas a guardar
 * @return 1 em caso de sucesso, 0 caso contrário
 */
int guardarAntenasBin(const char* ficheiro, Antena* lista);

/**
 * @brief Carrega uma lista de antenas a partir de um ficheiro binário.
 * @param ficheiro Nome do ficheiro binário
 * @return Lista ligada de antenas carregadas ou NULL se falhar
 */
Antena* carregarAntenasBin(const char* ficheiro);
