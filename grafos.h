/**
 * @file grafo.h
 * @author Pedro Rocha a23009
 * @brief IPCA - Projeto de Estruturas de Dados
 * @details Cabeçalhos das funções e estruturas para grafos (Fase 2)
 * @version 2.0
 * @date 2025-05-13
 */

#ifndef GRAFO_H
#define GRAFO_H

#include "estrutura.h"

/**
 * @brief Estrutura de aresta do grafo
 */
typedef struct Aresta {
    struct Vertice* destino; /**< Vértice de destino */
    struct Aresta* prox;     /**< Próxima aresta */
} Aresta;

/**
 * @brief Estrutura de vértice do grafo
 */
typedef struct Vertice {
    char freq;           /**< Frequência da antena */
    int x, y;            /**< Coordenadas da antena */
    Aresta* arestas;     /**< Lista de arestas ligadas */
    struct Vertice* prox;/**< Próximo vértice */
} Vertice;

/**
 * @brief Estrutura principal do grafo
 */
typedef struct Grafo {
    Vertice* vertices; /**< Lista de vértices */
} Grafo;

/**
 * @brief Lista de caminhos possíveis (cada nó contém uma lista de antenas)
 */
typedef struct Caminho {
    Antena* lista;           /**< Caminho representado por lista de antenas */
    struct Caminho* prox;    /**< Próximo caminho */
} Caminho;

/**
 * @brief Constrói um grafo a partir da lista de antenas.
 * @param lista Lista ligada de antenas
 * @return Apontador para grafo criado
 */
Grafo* construirGrafo(Antena* lista);

/**
 * @brief Executa busca em profundidade (DFS) a partir de uma antena.
 * @param g Grafo
 * @param x Coordenada x da antena
 * @param y Coordenada y da antena
 * @return Lista ligada de antenas visitadas
 */
Antena* dfs(Grafo* g, int x, int y);

/**
 * @brief Executa busca em largura (BFS) a partir de uma antena.
 * @param g Grafo
 * @param x Coordenada x da antena
 * @param y Coordenada y da antena
 * @return Lista ligada de antenas visitadas
 */
Antena* bfs(Grafo* g, int x, int y);

/**
 * @brief Identifica interseções de antenas com frequências diferentes nas mesmas coordenadas.
 * @param g Grafo
 * @param f1 Primeira frequência
 * @param f2 Segunda frequência
 * @return Lista de antenas com interseções
 */
Antena* intersecoes(Grafo* g, char f1, char f2);

/**
 * @brief Retorna todos os caminhos possíveis entre duas antenas.
 * @param g Grafo
 * @param x1 Coordenada x da antena origem
 * @param y1 Coordenada y da antena origem
 * @param x2 Coordenada x da antena destino
 * @param y2 Coordenada y da antena destino
 * @return Lista de caminhos (cada caminho é uma lista de antenas)
 */
Caminho* caminhosEntre(Grafo* g, int x1, int y1, int x2, int y2);

#endif // GRAFO_H

