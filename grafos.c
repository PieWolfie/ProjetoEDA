/**
 * @file grafo.c
 * @author Pedro Rocha a23009
 * @brief IPCA - Projeto de Estruturas de Dados
 * @details Implementação das funções para análise de grafos entre antenas (Fase 2)
 * @version 2.0
 * @date 2025-05-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "grafos.h"

/**
 * @brief Representa uma visita a uma posição (x, y) no grafo.
 */
typedef struct Visita {
    int x, y;
    struct Visita* prox;
} Visita;

/**
 * @brief Nó de uma fila de vértices para BFS.
 */
typedef struct NoFila {
    Vertice* v;
    struct NoFila* prox;
} NoFila;

/**
 * @brief Cria um novo vértice.
 * @param freq Frequência da antena
 * @param x Coordenada x
 * @param y Coordenada y
 * @return Apontador para o novo vértice criado
 */
static Vertice* criarVertice(char freq, int x, int y) {
    Vertice* v = malloc(sizeof(Vertice));
    if (!v) return NULL;
    v->freq = freq;
    v->x = x;
    v->y = y;
    v->arestas = NULL;
    v->prox = NULL;
    return v;
}

/**
 * @brief Adiciona uma aresta entre dois vértices.
 * @param origem Vértice de origem
 * @param destino Vértice de destino
 */
static void adicionarAresta(Vertice* origem, Vertice* destino) {
    Aresta* nova = malloc(sizeof(Aresta));
    nova->destino = destino;
    nova->prox = origem->arestas;
    origem->arestas = nova;
}

/**
 * @brief Procura um vértice pelas coordenadas.
 * @param g Grafo a percorrer
 * @param x Coordenada x
 * @param y Coordenada y
 * @return Apontador para o vértice encontrado ou NULL
 */
static Vertice* encontrarVertice(Grafo* g, int x, int y) {
    for (Vertice* v = g->vertices; v; v = v->prox)
        if (v->x == x && v->y == y)
            return v;
    return NULL;
}

/**
 * @brief Verifica se uma posição já foi visitada.
 * @param x Coordenada x
 * @param y Coordenada y
 * @param lista Lista de visitas
 * @return 1 se já foi visitada, 0 caso contrário
 */
static int jaVisitado(int x, int y, Visita* lista) {
    for (Visita* v = lista; v; v = v->prox)
        if (v->x == x && v->y == y)
            return 1;
    return 0;
}

/**
 * @brief Guarda um caminho encontrado.
 * @param lista Lista de antenas que forma o caminho
 * @param caminhos Apontador para lista de caminhos
 */
static void guardar(Antena* lista, Caminho** caminhos) {
    Caminho* novo = malloc(sizeof(Caminho));
    novo->lista = NULL;
    for (Antena* a = lista; a; a = a->prox) {
        Antena* c = malloc(sizeof(Antena));
        *c = *a;
        c->prox = novo->lista;
        novo->lista = c;
    }
    novo->prox = *caminhos;
    *caminhos = novo;
}

/**
 * @brief Constrói o grafo a partir da lista de antenas.
 * @param lista Lista ligada de antenas
 * @return Apontador para o grafo criado
 */
Grafo* construirGrafo(Antena* lista) {
    Grafo* g = malloc(sizeof(Grafo));
    g->vertices = NULL;

    for (Antena* a = lista; a; a = a->prox) {
        Vertice* v = criarVertice(a->frequencia, a->x, a->y);
        v->prox = g->vertices;
        g->vertices = v;
    }

    for (Vertice* v1 = g->vertices; v1; v1 = v1->prox)
        for (Vertice* v2 = g->vertices; v2; v2 = v2->prox)
            if (v1 != v2 && v1->freq == v2->freq)
                adicionarAresta(v1, v2);

    return g;
}

/**
 * @brief Função recursiva auxiliar para DFS.
 * @param v Vértice atual
 * @param ctx Contexto com ponteiros para resultado e visitas
 */
typedef struct {
    Antena** resultado;
    Visita** visitados;
} DfsContext;

static void visitar(Vertice* v, DfsContext* ctx) {
    if (jaVisitado(v->x, v->y, *(ctx->visitados))) return;

    Visita* novo = malloc(sizeof(Visita));
    novo->x = v->x; novo->y = v->y; novo->prox = *(ctx->visitados);
    *(ctx->visitados) = novo;

    Antena* a = malloc(sizeof(Antena));
    a->frequencia = v->freq;
    a->x = v->x;
    a->y = v->y;
    a->prox = *(ctx->resultado);
    *(ctx->resultado) = a;

    for (Aresta* ar = v->arestas; ar; ar = ar->prox)
        visitar(ar->destino, ctx);
}

/**
 * @brief Busca em profundidade (DFS) a partir de uma posição.
 * @param g Grafo
 * @param x Coordenada x da antena inicial
 * @param y Coordenada y da antena inicial
 * @return Lista ligada de antenas visitadas
 */
Antena* dfs(Grafo* g, int x, int y) {
    Antena* resultado = NULL;
    Visita* visitados = NULL;
    DfsContext ctx = { &resultado, &visitados };

    Vertice* vInicio = encontrarVertice(g, x, y);
    if (vInicio) visitar(vInicio, &ctx);
    return resultado;
}

/**
 * @brief Busca em largura (BFS) a partir de uma posição.
 */
Antena* bfs(Grafo* g, int x, int y) {
    Antena* resultado = NULL;
    Visita* visitados = NULL;
    NoFila *fila = NULL, *fim = NULL;

    Vertice* vInicio = encontrarVertice(g, x, y);
    if (!vInicio) return NULL;

    NoFila* n = malloc(sizeof(NoFila));
    n->v = vInicio; n->prox = NULL;
    fila = fim = n;

    while (fila) {
        Vertice* atual = fila->v;

        if (!jaVisitado(atual->x, atual->y, visitados)) {
            Visita* novo = malloc(sizeof(Visita));
            novo->x = atual->x; novo->y = atual->y; novo->prox = visitados;
            visitados = novo;

            Antena* a = malloc(sizeof(Antena));
            a->frequencia = atual->freq;
            a->x = atual->x;
            a->y = atual->y;
            a->prox = resultado;
            resultado = a;

            for (Aresta* ar = atual->arestas; ar; ar = ar->prox) {
                NoFila* novoNo = malloc(sizeof(NoFila));
                novoNo->v = ar->destino;
                novoNo->prox = NULL;
                fim->prox = novoNo;
                fim = novoNo;
            }
        }

        NoFila* temp = fila;
        fila = fila->prox;
        free(temp);
    }

    return resultado;
}

/**
 * @brief Encontra interseções entre antenas de duas frequências.
 */
Antena* intersecoes(Grafo* g, char f1, char f2) {
    Antena* inter = NULL;
    for (Vertice* a = g->vertices; a; a = a->prox) {
        if (a->freq != f1) continue;
        for (Vertice* b = g->vertices; b; b = b->prox) {
            if (b->freq == f2 && a->x == b->x && a->y == b->y) {
                Antena* nova = malloc(sizeof(Antena));
                nova->frequencia = a->freq;
                nova->x = a->x;
                nova->y = a->y;
                nova->prox = inter;
                inter = nova;
            }
        }
    }
    return inter;
}

/**
 * @brief Função recursiva auxiliar para encontrar todos os caminhos entre dois vértices.
 */
static void dfsCaminho(Vertice* atual, Antena* caminho, Visita* visitados, int x2, int y2, Caminho** caminhos) {
    if (jaVisitado(atual->x, atual->y, visitados)) return;

    Visita* novo = malloc(sizeof(Visita));
    novo->x = atual->x; novo->y = atual->y; novo->prox = visitados;

    Antena* a = malloc(sizeof(Antena));
    a->frequencia = atual->freq;
    a->x = atual->x; a->y = atual->y; a->prox = caminho;

    if (atual->x == x2 && atual->y == y2) guardar(a, caminhos);
    else for (Aresta* ar = atual->arestas; ar; ar = ar->prox)
        dfsCaminho(ar->destino, a, novo, x2, y2, caminhos);

    free(a);
    free(novo);
}

/**
 * @brief Encontra todos os caminhos entre duas posições.
 */
Caminho* caminhosEntre(Grafo* g, int x1, int y1, int x2, int y2) {
    Caminho* caminhos = NULL;

    Vertice* vOrigem = encontrarVertice(g, x1, y1);
    if (vOrigem) dfsCaminho(vOrigem, NULL, NULL, x2, y2, &caminhos);

    return caminhos;
}
