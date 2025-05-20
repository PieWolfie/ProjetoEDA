/**
 * @file lista.c
 * @author Pedro Rocha a23009
 * @brief IPCA - Projeto de Estruturas de Dados
 * @brief Implementação das funções para manipulação de listas ligadas e matriz
 * @version 1.0
 * @date 2025-03-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"
#include "lista.h"

/**
 * @brief Cria uma nova antena.
 */
Antena* criarAntena(char freq, int x, int y) {
    Antena* nova = (Antena*)malloc(sizeof(Antena));
    if (!nova) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    nova->frequencia = freq;
    nova->x = x;
    nova->y = y;
    nova->prox = NULL;
    return nova;
}

/**
 * @brief Insere uma antena na lista ligada.
 */
int inserirAntena(Antena** lista, char freq, int x, int y) {
    Antena* nova = criarAntena(freq, x, y);
    if (!nova) return 0;
    nova->prox = *lista;
    *lista = nova;
    return 1;
}

/**
 * @brief Carrega as antenas de um ficheiro de texto.
 */
Antena* carregarAntenas(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o ficheiro!\n");
        return NULL;
    }
    Antena* lista = NULL;
    char linha[100];
    for (int y = 0; fgets(linha, sizeof(linha), file); y++) {
        for (int x = 0; linha[x] != '\0' && linha[x] != '\n'; x++) {
            if (linha[x] != '.') inserirAntena(&lista, linha[x], x, y);
        }
    }
    fclose(file);
    return lista;
}

/**
 * @brief Guarda a lista de antenas num ficheiro binário.
 */
int guardarAntenasBin(const char* ficheiro, Antena* lista) {
    FILE* f = fopen(ficheiro, "wb");
    if (!f) return 0;

    for (Antena* a = lista; a; a = a->prox)
        if (fwrite(a, sizeof(Antena), 1, f) != 1) {
            fclose(f);
            return 0;
        }

    fclose(f);
    return 1;
}

/**
 * @brief Carrega antenas de um ficheiro binário.
 */
Antena* carregarAntenasBin(const char* ficheiro) {
    FILE* f = fopen(ficheiro, "rb");
    if (!f) return NULL;

    Antena* lista = NULL;
    Antena temp;

    while (fread(&temp, sizeof(Antena), 1, f) == 1) {
        Antena* novo = malloc(sizeof(Antena));
        if (!novo) break;
        *novo = temp;
        novo->prox = lista;
        lista = novo;
    }

    fclose(f);
    return lista;
}

/**
 * @brief Imprime a lista de antenas.
 */
int imprimirAntenas(Antena* lista) {
    printf("\nLista de Antenas:\n");
    printf("Frequencia | Coordenadas\n");
    printf("------------------------\n");
    while (lista) {
        printf("    %c      | (X:%d, Y:%d)\n", lista->frequencia, lista->x, lista->y);
        lista = lista->prox;
    }
    printf("------------------------\n");
    return 1;
}

