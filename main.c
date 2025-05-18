/**
 * @file main.c
 * @author Pedro Rocha a23009
 * @brief IPCA - Projeto de Estruturas de Dados
 * @brief Programa principal para análise de grafos entre antenas (Fase 2)
 * @version 2.0
 * @date 2025-05-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "lista.h"
#include "grafos.h"

/**
 * @brief Função principal do programa para executar as operações da Fase 2.
 * 
 * - Constrói um grafo com base nas antenas carregadas.
 * - Executa procura em profundidade (DFS) e largura (BFS).
 * - Identifica todos os caminhos possíveis entre duas antenas.
 * - Procura interseções entre antenas de frequências distintas.
 * 
 * @return int Código de saída do programa
 */
int main() {
    // Carregar antenas da fase 1
    Antena* lista = carregarAntenas("antenas.txt");
    printf("Antenas carregadas da Fase 1:\n");
    imprimirAntenas(lista);

    // Construir grafo a partir da lista de antenas
    Grafo* g = construirGrafo(lista);

    // Fase 2 - a) DFS a partir de uma antena
    printf("\n[FASE 2 - a] DFS a partir da antena em (6,5):\n");
    Antena* resDFS = dfs(g, 6, 5);
    imprimirAntenas(resDFS);

    // Fase 2 - b) BFS a partir de uma antena
    printf("\n[FASE 2 - b] BFS a partir da antena em (6,5):\n");
    Antena* resBFS = bfs(g, 6, 5);
    imprimirAntenas(resBFS);

    // Fase 2 - c) Todos os caminhos possíveis entre duas antenas
    printf("\n[FASE 2 - c] Caminhos entre antenas em (6,5) e (9,9):\n");
    Caminho* caminhos = caminhosEntre(g, 6, 5, 9, 9);
    int contador = 1;
    for (Caminho* c = caminhos; c; c = c->prox) {
        printf("Caminho %d:\n", contador++);
        imprimirAntenas(c->lista);
    }

    // Fase 2 - d) Interseções entre antenas com frequências diferentes 'A' e '0'
    printf("\n[FASE 2 - d] Intersecoes entre antenas 'A' e '0':\n");
    Antena* inter = intersecoes(g, 'A', '0');
    imprimirAntenas(inter);

    return 0;
}
