/* arquivo.c - leitura e gravacao dos arquivos de texto. */
#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

/* Micael: carrega os livros armazenados no arquivo livros.txt. */
void carregarLivros(Livro **livros, int *quantidade, int *capacidade) {
    FILE *arquivo;
    int capacidadeAtual = CAPACIDADE_INICIAL_LIVROS;
    Livro *array = (Livro *)malloc(capacidadeAtual * sizeof(Livro));
    int i = 0;

    if (array == NULL) {
        printf("Erro: memoria insuficiente para carregar livros.\n");
        return;
    }

    /* Se o arquivo ainda nao existe, e a primeira execucao do sistema. */
    arquivo = fopen("livros.txt", "r");
    if (arquivo == NULL) {
        *livros = array;
        *quantidade = 0;
        *capacidade = capacidadeAtual;
        return;
    }

    /* Micael: le cada linha do arquivo, redimensionando quando necessario. */
    while (fscanf(arquivo, "%d;%99[^;];%99[^;];%d;%d",
                  &array[i].codigo, array[i].titulo, array[i].autor,
                  &array[i].ano, &array[i].quantidade) == 5) {
        i++;
        if (i >= capacidadeAtual) {
            int novaCapacidade = capacidadeAtual * 2;
            Livro *novoArray = (Livro *)realloc(array, novaCapacidade * sizeof(Livro));
            if (novoArray == NULL) {
                printf("Erro: memoria insuficiente para carregar livros.\n");
                free(array);
                fclose(arquivo);
                return;
            }
            array = novoArray;
            capacidadeAtual = novaCapacidade;
        }
    }

    *quantidade = i;
    *capacidade = capacidadeAtual;
    *livros = array;
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
void carregarUsuarios(Usuario **usuarios, int *quantidade, int *capacidade) {
    FILE *arquivo;
    int capacidadeAtual = CAPACIDADE_INICIAL_USUARIOS;
    Usuario *array = (Usuario *)malloc(capacidadeAtual * sizeof(Usuario));
    int i = 0;

    if (array == NULL) {
        printf("Erro: memoria insuficiente para carregar usuarios.\n");
        return;
    }

    /* Se o arquivo ainda nao existe, e a primeira execucao do sistema. */
    arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        *usuarios = array;
        *quantidade = 0;
        *capacidade = capacidadeAtual;
        return;
    }

    /* Micael: le cada linha do arquivo, redimensionando quando necessario. */
    while (fscanf(arquivo, "%d;%99[^;];%99[^\n]",
                  &array[i].matricula, array[i].nome, array[i].curso) == 3) {
        i++;
        if (i >= capacidadeAtual) {
            int novaCapacidade = capacidadeAtual * 2;
            Usuario *novoArray = (Usuario *)realloc(array, novaCapacidade * sizeof(Usuario));
            if (novoArray == NULL) {
                printf("Erro: memoria insuficiente para carregar usuarios.\n");
                free(array);
                fclose(arquivo);
                return;
            }
            array = novoArray;
            capacidadeAtual = novaCapacidade;
        }
    }

    *quantidade = i;
    *capacidade = capacidadeAtual;
    *usuarios = array;
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
void carregarEmprestimos(Emprestimo **emprestimos, int *quantidade, int *capacidade) {
    FILE *arquivo;
    int capacidadeAtual = CAPACIDADE_INICIAL_EMPRESTIMOS;
    Emprestimo *array = (Emprestimo *)malloc(capacidadeAtual * sizeof(Emprestimo));
    int i = 0;

    if (array == NULL) {
        printf("Erro: memoria insuficiente para carregar emprestimos.\n");
        return;
    }

    /* Se o arquivo ainda nao existe, e a primeira execucao do sistema. */
    arquivo = fopen("emprestimos.txt", "r");
    if (arquivo == NULL) {
        *emprestimos = array;
        *quantidade = 0;
        *capacidade = capacidadeAtual;
        return;
    }

    /* Micael: le cada linha do arquivo, redimensionando quando necessario. */
    while (fscanf(arquivo, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d",
                  &array[i].codigoLivro,
                  &array[i].matriculaUsuario,
                  &array[i].ativo,
                  &array[i].diaEmp,
                  &array[i].mesEmp,
                  &array[i].anoEmp,
                  &array[i].diaPrev,
                  &array[i].mesPrev,
                  &array[i].anoPrev,
                  &array[i].diaDev,
                  &array[i].mesDev,
                  &array[i].anoDev) == 12) {
        i++;
        if (i >= capacidadeAtual) {
            int novaCapacidade = capacidadeAtual * 2;
            Emprestimo *novoArray = (Emprestimo *)realloc(array, novaCapacidade * sizeof(Emprestimo));
            if (novoArray == NULL) {
                printf("Erro: memoria insuficiente para carregar emprestimos.\n");
                free(array);
                fclose(arquivo);
                return;
            }
            array = novoArray;
            capacidadeAtual = novaCapacidade;
        }
    }

    *quantidade = i;
    *capacidade = capacidadeAtual;
    *emprestimos = array;
    fclose(arquivo);
}

/* Micael: salva os emprestimos no arquivo de texto. */
void salvarEmprestimos(Emprestimo emprestimos[], int quantidade) {
    FILE *arquivo;
    int i;

    arquivo = fopen("emprestimos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de emprestimos.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n",
                emprestimos[i].codigoLivro,
                emprestimos[i].matriculaUsuario,
                emprestimos[i].ativo,
                emprestimos[i].diaEmp,
                emprestimos[i].mesEmp,
                emprestimos[i].anoEmp,
                emprestimos[i].diaPrev,
                emprestimos[i].mesPrev,
                emprestimos[i].anoPrev,
                emprestimos[i].diaDev,
                emprestimos[i].mesDev,
                emprestimos[i].anoDev);
    }

    fclose(arquivo);
}
