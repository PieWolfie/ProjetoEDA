# Sistema de Gestão de Antenas e Deteção de Efeitos Nefastos
<!-- Título principal com # -->

## Descrição
<!-- Subtítulo com ## -->

Este repositório contém a implementação da **Fase 1** do projeto de avaliação da Unidade Curricular **Estruturas de Dados Avançadas (EDA)**, parte do 2º semestre do 1º ano no **IPCA, Barcelos**.  
<!-- ** para negrito -->
O objetivo é aplicar conceitos de estruturas de dados dinâmicas em C, especificamente listas ligadas, para gerenciar antenas em uma cidade fictícia, detectar efeitos nefastos causados por interferências de frequência e exibir os resultados em formato tabular.

O sistema carrega dados de um arquivo de texto (`antenas.txt`), permite inserção e remoção de antenas, calcula efeitos nefastos baseados em pares de antenas com a mesma frequência (onde uma está duas vezes mais distante da outra) e apresenta os resultados na consola. O projeto foi desenvolvido com modularização e documentação no formato Doxygen, conforme exigido no enunciado.

**Data de Entrega:** 30 de Março de 2025 Fase 1  
**Autor:** Pedro Rocha

---

## Estrutura do Repositório
<!-- Linha horizontal com --- -->

- **`estrutura.h`**: Definição das estruturas `Antena` e `Nefasto` como listas ligadas.
- **`lista.h`**: Declaração das funções para manipulação das listas e matriz.
- **`lista.c`**: Implementação das funções, incluindo carregamento, inserção, remoção e detecção de efeitos.
- **`main.c`**: Programa principal que integra as funcionalidades e testa o sistema com `antenas.txt`.
- **`antenas.txt`**: Arquivo de entrada com uma matriz 12x12 contendo antenas '0' e 'A'.
- **`README.md`**: Este arquivo.
<!-- Lista não ordenada com - e negrito com ** -->

---

## Requisitos

- **Compilador C**: GCC ou equivalente (ex.: MinGW para Windows).
- **Sistema Operacional**: Windows.
- **Ferramentas**: Visual Studio Code (recomendado) com extensões Git para controlo de versão.

