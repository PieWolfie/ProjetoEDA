/**
 * @file main.c
 * @author Pedro Rocha a23009
 * @brief IPCA - Projeto de Estruturas de Dados
 * @brief Programa principal para gestão de antenas e detecção de efeitos nefastos
 * @version 1.0
 * @date 2025-03-27
 */

#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "lista.h"

/**
 * @brief Função para inicializar o programa
 * 
 * @param ficheiro Nome do ficheiro de entrada
 * @return Antena* Lista de antenas carregadas
 */
Antena* inicializarPrograma(const char* ficheiro) {
    Antena* lista = carregarAntenas(ficheiro);
    if (!lista) {
        fprintf(stderr, "Erro ao carregar antenas.\n");
        exit(1);
    }
    printf("Antenas carregadas:\n");
    imprimirAntenas(lista);
    return lista;
}

/**
 * @brief Função para carregar e imprimir a matriz inicial
 * 
 * @param ficheiro Nome do ficheiro de entrada
 * @param linhas Ponteiro para armazenar o número de linhas
 * @param colunas Ponteiro para armazenar o número de colunas
 * @return char** Matriz carregada
 */
char** carregarEImprimirMatriz(const char* ficheiro, int* linhas, int* colunas) {
    char** matriz = carregarMatriz(ficheiro);
    if (!matriz) {
        fprintf(stderr, "Erro ao carregar matriz.\n");
        exit(1);
    }
    *linhas = contarLinhas(ficheiro);
    *colunas = contarColunas(ficheiro);
    printf("\nMatriz inicial:\n");
    imprimirMatriz(matriz, *linhas);
    return matriz;
}

/**
 * @brief Função principal do programa
 * 
 * @return int Código de saída do programa
 */
int main() {
    // Nome do ficheiro de entrada
    const char ficheiro[] = "antenas.txt";

    // Inicializar programa e carregar antenas
    Antena* lista = inicializarPrograma(ficheiro);

    // Carregar e imprimir matriz inicial
    int linhas, colunas;
    char** matriz = carregarEImprimirMatriz(ficheiro, &linhas, &colunas);

    // Teste de inserção de uma nova antena
    inserirAntena(&lista, 'B', 5, 5);
    printf("\nApos insercao de antena:\n");
    imprimirAntenas(lista);

    // Detecção de efeitos nefastos
    Nefasto* efeitos = detetarEfeitosNefastos(lista);
    printf("\nEfeitos nefastos detetados:\n");
    imprimirEfeitosNefastos(efeitos);

    // Atualizar a matriz com os efeitos nefastos
    atualizarMatriz(matriz, linhas, colunas, lista, efeitos);
    printf("\nMatriz apos atualizacao:\n");
    imprimirMatriz(matriz, linhas);

    // Teste de remoção de antenas
    removerAntena(&lista, 5, 5);
    removerAntena(&lista, 6, 5);
    printf("\nApos remocao de antenas:\n");
    imprimirAntenas(lista);

    // Recalcular efeitos nefastos após remoção
    efeitos = detetarEfeitosNefastos(lista);
    printf("\nEfeitos nefastos apos remocao:\n");
    imprimirEfeitosNefastos(efeitos);

    // Atualizar a matriz novamente
    atualizarMatriz(matriz, linhas, colunas, lista, efeitos);
    printf("\nMatriz final:\n");
    imprimirMatriz(matriz, linhas);

    // Libertar memória alocada para a matriz
    libertarMatriz(matriz, linhas);

    return 0;
}
