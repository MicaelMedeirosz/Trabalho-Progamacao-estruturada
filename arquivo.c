/* arquivo.c - leitura e gravacao dos arquivos de texto. */
#include <stdio.h>
#include "arquivo.h"

/* Micael: carrega os livros armazenados no arquivo livros.txt. */
void carregarLivros(Livro livros[], int *quantidade) {
    FILE *arquivo;
    int i;

    /* Se o arquivo ainda nao existe, e a primeira execucao do sistema. */
    arquivo = fopen("livros.txt", "r");
    if (arquivo == NULL) {
        return;
    }

    i = 0;
    /* Micael: le cada linha do arquivo ate o final ou encher o array. */
    while (i < MAX_LIVROS &&
           fscanf(arquivo, "%d;%99[^;];%99[^;];%d;%d",
                  &livros[i].codigo, livros[i].titulo, livros[i].autor,
                  &livros[i].ano, &livros[i].quantidade) == 5) {
        i++;
    }

    *quantidade = i;
    fclose(arquivo);
}

/* Micael: salva os livros no arquivo de texto. */
void salvarLivros(Livro livros[], int quantidade) {
    FILE *arquivo;
    int i;

    arquivo = fopen("livros.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d;%s;%s;%d;%d\n",
                livros[i].codigo, livros[i].titulo,
                livros[i].autor, livros[i].ano, livros[i].quantidade);
    }

    fclose(arquivo);
}

/* Micael: carrega os usuarios armazenados no arquivo usuarios.txt. */
void carregarUsuarios(Usuario usuarios[], int *quantidade) {
    FILE *arquivo;
    int i;

    /* Se o arquivo ainda nao existe, e a primeira execucao do sistema. */
    arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        return;
    }

    i = 0;
    /* Micael: le cada linha do arquivo ate o final ou encher o array. */
    while (i < MAX_USUARIOS &&
           fscanf(arquivo, "%d;%99[^;];%99[^\n]",
                  &usuarios[i].matricula, usuarios[i].nome, usuarios[i].curso) == 3) {
        i++;
    }

    *quantidade = i;
    fclose(arquivo);
}

/* Micael: salva os usuarios no arquivo de texto. */
void salvarUsuarios(Usuario usuarios[], int quantidade) {
    FILE *arquivo;
    int i;

    arquivo = fopen("usuarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d;%s;%s\n",
                usuarios[i].matricula, usuarios[i].nome, usuarios[i].curso);
    }

    fclose(arquivo);
}

/* Micael: carrega os emprestimos armazenados no arquivo emprestimos.txt. */
void carregarEmprestimos(Emprestimo emprestimos[], int *quantidade) {
    /* Implementacao na etapa 7. */
}

/* Micael: salva os emprestimos no arquivo de texto. */
void salvarEmprestimos(Emprestimo emprestimos[], int quantidade) {
    /* Implementacao na etapa 7. */
}
