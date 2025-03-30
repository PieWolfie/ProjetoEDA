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
 * @brief Função principal do programa
 * 
 * @return int Código de saída do programa
 */
int main() {
    // Nome do ficheiro de entrada
    char ficheiro[] = "antenas.txt";

    // Carregar lista de antenas a partir do ficheiro
    Antena* lista = carregarAntenas(ficheiro);
    if (!lista) {
        fprintf(stderr, "Erro ao carregar antenas.\n");
        return 1;
    }
    printf("Antenas carregadas:\n");
    imprimirAntenas(lista);

    // Carregar matriz a partir do ficheiro
    char** matriz = carregarMatriz(ficheiro);
    if (!matriz) {
        fprintf(stderr, "Erro ao carregar matriz.\n");
        return 1;
    }
    int linhas = contarLinhas(ficheiro);
    int colunas = contarColunas(ficheiro);
    printf("\nMatriz inicial:\n");
    imprimirMatriz(matriz, linhas);

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
