/**
 * @file lista.h
 * @author Pedro Rocha a23009
 * @brief IPCA - Projeto de Estruturas de Dados
 * @brief Cabeçalhos das funções para manipulação de listas ligadas e matriz
 * @version 1.0
 * @date 2025-03-27
 */

#ifndef LISTA_H
#define LISTA_H

#include "estrutura.h"

/**
 * @brief Cria uma nova antena.
 * @param freq Frequência da antena.
 * @param x Coordenada x da antena.
 * @param y Coordenada y da antena.
 * @return Apontador para a antena criada.
 */
Antena* criarAntena(char freq, int x, int y);

/**
 * @brief Insere uma antena na lista ligada.
 * @param lista Apontador para a lista de antenas.
 * @param freq Frequência da antena a inserir.
 * @param x Coordenada x da antena a inserir.
 * @param y Coordenada y da antena a inserir.
 * @return 1 se a antena foi inserida com sucesso, 0 caso contrário.
 */
int inserirAntena(Antena** lista, char freq, int x, int y);

/**
 * @brief Carrega as antenas de um ficheiro para uma lista ligada.
 * @param filename Nome do ficheiro a carregar.
 * @return Lista de antenas carregada.
 */
Antena* carregarAntenas(const char* filename);

/**
 * @brief Imprime a lista de antenas.
 * @param lista Lista de antenas.
 */
int imprimirAntenas(Antena* lista);

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

#endif
