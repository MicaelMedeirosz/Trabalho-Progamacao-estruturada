/* emprestimo.c - funcoes de emprestimo e devolucao de livros. */
#include <stdio.h>
#include "emprestimo.h"

/* Micael: registra o emprestimo de um livro para um usuario. */
void registrarEmprestimo(Emprestimo emprestimos[], int *quantidade,
                         Livro livros[], int quantidadeLivros,
                         Usuario usuarios[], int quantidadeUsuarios) {
    int codigoLivro;
    int matricula;
    int posLivro;
    int posUsuario;

    /* Micael: verifica se o array de emprestimos ja esta cheio. */
    if (*quantidade >= MAX_EMPRESTIMOS) {
        printf("Nao e possivel registrar mais emprestimos. Limite alcancado.\n");
        return;
    }

    printf("\nCodigo do livro: ");
    scanf("%d", &codigoLivro);
    printf("Matricula do usuario: ");
    scanf("%d", &matricula);

    /* Micael: busca sequencial do livro pelo codigo informado. */
    posLivro = buscarLivroPorCodigo(livros, quantidadeLivros, codigoLivro);
    if (posLivro == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    /* Micael: busca sequencial do usuario pela matricula informada. */
    posUsuario = buscarUsuarioPorMatricula(usuarios, quantidadeUsuarios, matricula);
    if (posUsuario == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    /* Micael: verifica se existe quantidade disponivel antes do emprestimo. */
    if (livros[poslivro].quantidade <= 0) {
        printf("Quantidade de livros indisponivel.\n");
        return;
    }

    /* Micael: registra o emprestimo e diminui uma unidade do acervo. */
    emprestimos[*quantidade].codigoLivro = codigoLivro;
    emprestimos[*quantidade].matriculaUsuario = matricula;
    emprestimos[*quantidade].ativo = 1;
    (*quantidade)++;

    livros[posLivro].quantidade--;

    printf("Emprestimo registrado com sucesso.\n");
}

/* Micael: registra a devolucao e devolve uma unidade ao acervo. */
void registrarDevolucao(Emprestimo emprestimos[], int quantidade,
                        Livro livros[], int quantidadeLivros) {
    /* Implementacao na etapa 6. */
}

/* Micael: lista os emprestimos registrados com a situacao atual. */
void listarEmprestimos(Emprestimo emprestimos[], int quantidade) {
    /* Implementacao na etapa 5. */
}
