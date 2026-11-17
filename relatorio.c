/* relatorio.c - relatorio de desempenho do sistema de biblioteca (Parte 2). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorio.h"

/* Troca auxiliar para o selection sort local. */
static void trocarLivrosLocal(Livro *a, Livro *b) {
    Livro temp = *a;
    *a = *b;
    *b = temp;
}

/* Selection sort local por titulo (usado apenas para comparacao no relatorio). */
static void selectionSortLivrosTituloLocal(Livro livros[], int quantidade) {
    int i, j, minIdx;

    for (i = 0; i < quantidade - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < quantidade; j++) {
            if (strcmp(livros[j].titulo, livros[minIdx].titulo) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            trocarLivrosLocal(&livros[i], &livros[minIdx]);
        }
    }
}

/* Mede tempo de execucao da busca sequencial por titulo. */
static double medirBuscaSequencial(Livro livros[], int quantidade, char titulo[]) {
    clock_t inicio, fim;

    inicio = clock();
    buscarLivroPorTitulo(livros, quantidade, titulo);
    fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* Mede tempo de execucao da busca binaria por titulo.
   Requer que livros estejam ordenados por titulo. */
static double medirBuscaBinaria(Livro livros[], int quantidade, char titulo[]) {
    clock_t inicio, fim;

    inicio = clock();
    buscarLivroPorTituloBinario(livros, quantidade, titulo);
    fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* Mede tempo de execucao do bubble sort por titulo. */
static double medirBubbleSort(Livro livros[], int quantidade) {
    clock_t inicio, fim;

    inicio = clock();
    ordenarLivrosPorTitulo(livros, quantidade);
    fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* Mede tempo de execucao do selection sort por titulo. */
static double medirSelectionSort(Livro livros[], int quantidade) {
    clock_t inicio, fim;

    inicio = clock();
    selectionSortLivrosTituloLocal(livros, quantidade);
    fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* Gera e exibe o relatorio de desempenho, salvando-o em relatorio_desempenho.txt. */
void gerarRelatorioDesempenho(Livro livros[], int quantidadeLivros,
                              Usuario usuarios[], int quantidadeUsuarios,
                              Emprestimo emprestimos[], int quantidadeEmprestimos) {
    FILE *arquivo;
    Livro *copia = NULL;
    double tempoBubble, tempoSelection, tempoSeq, tempoBin;
    char tituloAlvo[TAM_TITULO] = "";

    (void)usuarios;
    (void)emprestimos;

    if (quantidadeLivros == 0) {
        printf("\nNenhum livro cadastrado para gerar relatorio de desempenho.\n");
        return;
    }

    /* Usa o titulo do ultimo livro como alvo de busca (existe no array). */
    strcpy(tituloAlvo, livros[quantidadeLivros - 1].titulo);

    /* --- Comparacao de ordenacao --- */
    /* Copia os livros para testar selection sort sem destruir os originais. */
    copia = (Livro *)malloc(quantidadeLivros * sizeof(Livro));
    if (copia == NULL) {
        printf("Erro: memoria insuficiente para gerar relatorio.\n");
        return;
    }
    memcpy(copia, livros, quantidadeLivros * sizeof(Livro));

    tempoBubble = medirBubbleSort(livros, quantidadeLivros);

    /* Restaura a copia original para o selection sort. */
    memcpy(livros, copia, quantidadeLivros * sizeof(Livro));
    tempoSelection = medirSelectionSort(copia, quantidadeLivros);

    free(copia);
    copia = NULL;

    /* --- Comparacao de busca --- */
    /* Livros ja estao ordenados por titulo (bubble sort executou acima). */
    tempoSeq = medirBuscaSequencial(livros, quantidadeLivros, tituloAlvo);
    tempoBin = medirBuscaBinaria(livros, quantidadeLivros, tituloAlvo);

    /* --- Emite relatorio na tela --- */
    printf("\n========================================\n");
    printf("       RELATORIO DE DESEMPENHO\n");
    printf("========================================\n");
    printf("Quantidade de livros:    %d\n", quantidadeLivros);
    printf("Quantidade de usuarios:  %d\n", quantidadeUsuarios);
    printf("Quantidade de emprestimos: %d\n", quantidadeEmprestimos);
    printf("\n--- ORDENACAO (por titulo) ---\n");
    printf("Bubble Sort:     %.6f segundos\n", tempoBubble);
    printf("Selection Sort:  %.6f segundos\n", tempoSelection);
    if (tempoBubble < tempoSelection) {
        printf("Conclusao: Bubble Sort foi mais rapido neste cenario.\n");
    } else if (tempoSelection < tempoBubble) {
        printf("Conclusao: Selection Sort foi mais rapido neste cenario.\n");
    } else {
        printf("Conclusao: tempos semelhantes.\n");
    }
    printf("\n--- BUSCA (por titulo: \"%s\") ---\n", tituloAlvo);
    printf("Busca sequencial: %.6f segundos\n", tempoSeq);
    printf("Busca binaria:    %.6f segundos\n", tempoBin);
    if (tempoBin < tempoSeq) {
        printf("Conclusao: Busca binaria foi mais rapida (dados ordenados).\n");
    } else {
        printf("Conclusao: Busca sequencial foi mais rapida ou semelhante.\n");
    }

    /* --- Salva em arquivo .txt --- */
    arquivo = fopen("relatorio_desempenho.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar relatorio em arquivo.\n");
        return;
    }

    fprintf(arquivo, "RELATORIO DE DESEMPENHO - SISTEMA DE BIBLIOTECA\n");
    fprintf(arquivo, "==============================================\n\n");
    fprintf(arquivo, "Quantidade de livros:    %d\n", quantidadeLivros);
    fprintf(arquivo, "Quantidade de usuarios:  %d\n", quantidadeUsuarios);
    fprintf(arquivo, "Quantidade de emprestimos: %d\n\n", quantidadeEmprestimos);
    fprintf(arquivo, "ORDENACAO (por titulo)\n");
    fprintf(arquivo, "Bubble Sort:     %.6f segundos\n", tempoBubble);
    fprintf(arquivo, "Selection Sort:  %.6f segundos\n", tempoSelection);
    fprintf(arquivo, "Algoritmo mais rapido: ");
    if (tempoBubble < tempoSelection) {
        fprintf(arquivo, "Bubble Sort\n");
    } else if (tempoSelection < tempoBubble) {
        fprintf(arquivo, "Selection Sort\n");
    } else {
        fprintf(arquivo, "Empate\n");
    }
    fprintf(arquivo, "\nBUSCA (por titulo: \"%s\")\n", tituloAlvo);
    fprintf(arquivo, "Busca sequencial: %.6f segundos\n", tempoSeq);
    fprintf(arquivo, "Busca binaria:    %.6f segundos\n", tempoBin);
    fprintf(arquivo, "Algoritmo mais rapido: ");
    if (tempoBin < tempoSeq) {
        fprintf(arquivo, "Busca binaria\n");
    } else {
        fprintf(arquivo, "Busca sequencial\n");
    }

    fclose(arquivo);
    printf("\nRelatorio salvo em 'relatorio_desempenho.txt'.\n");
}
