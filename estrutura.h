/**
 * @file estrutura.h
 * @author Pedro Rocha
 * @brief Definição das estruturas de dados utilizadas no projeto.
 * @version 1.0
 * @date 2025-03-27
 */

#ifndef ANTENAS_H
#define ANTENAS_H

/**
 * @brief Estrutura que representa uma antena.
 * 
 * Cada antena possui uma frequência, coordenadas (x, y) e um apontador
 * para a próxima antena na lista.
 * 
 * @struct Antena
 * @param frequencia Frequência da antena (caractere).
 * @param x Coordenada x da antena (inteiro não negativo).
 * @param y Coordenada y da antena (inteiro não negativo).
 * @param prox Apontador para a próxima antena na lista.
 */
typedef struct Antena {
    char frequencia;
    int x, y;
    struct Antena *prox;
} Antena;

/**
 * @brief Estrutura que representa um nefasto.
 * 
 * Cada nefasto possui coordenadas (x, y) e um apontador
 * para o próximo nefasto na lista.
 * 
 * @struct Nefasto
 * @param x Coordenada x do nefasto (inteiro não negativo).
 * @param y Coordenada y do nefasto (inteiro não negativo).
 * @param prox Apontador para o próximo nefasto na lista.
 */
typedef struct Nefasto {
    int x, y;
    struct Nefasto *prox;
} Nefasto;

#endif