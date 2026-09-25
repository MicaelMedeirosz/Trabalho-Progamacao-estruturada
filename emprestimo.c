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
    if (livros[posLivro].quantidade <= 0) {
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
    int codigoLivro;
    int matricula;
    int posLivro;
    int i;
    int posEmprestimo;

    printf("\nCodigo do livro: ");
    scanf("%d", &codigoLivro);
    printf("Matricula do usuario: ");
    scanf("%d", &matricula);

    /* Micael: busca sequencial de um emprestimo ativo desse livro com esse usuario. */
    posEmprestimo = -1;
    for (i = 0; i < quantidade; i++) {
        if (emprestimos[i].codigoLivro == codigoLivro &&
            emprestimos[i].matriculaUsuario == matricula &&
            emprestimos[i].ativo == 1) {
            posEmprestimo = i;
            break;
        }
    }

    if (posEmprestimo == -1) {
        /* Micael: sem emprestimo ativo, verifica se existe um ja devolvido. */
        for (i = 0; i < quantidade; i++) {
            if (emprestimos[i].codigoLivro == codigoLivro &&
                emprestimos[i].matriculaUsuario == matricula) {
                printf("Este emprestimo ja foi devolvido.\n");
                return;
            }
        }
        printf("Emprestimo nao encontrado.\n");
        return;
    }

    /* Micael: marca como devolvido e devolve uma unidade ao acervo. */
    emprestimos[posEmprestimo].ativo = 0;

    posLivro = buscarLivroPorCodigo(livros, quantidadeLivros, codigoLivro);
    livros[posLivro].quantidade++;

    printf("Devolucao registrada com sucesso.\n");
}

/* Micael: lista os emprestimos registrados com a situacao atual. */
void listarEmprestimos(Emprestimo emprestimos[], int quantidade) {
    int i;

    /* Micael: se nenhum emprestimo foi registrado, avisa e volta pro menu. */
    if (quantidade == 0) {
        printf("\nNenhum emprestimo registrado.\n");
        return;
    }

    printf("\n%-16s %-22s %s\n", "Codigo do livro", "Matricula do usuario", "Situacao");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < quantidade; i++) {
        if (emprestimos[i].ativo == 1) {
            printf("%-16d %-22d Emprestado\n",
                   emprestimos[i].codigoLivro,
                   emprestimos[i].matriculaUsuario);
        } else {
            printf("%-16d %-22d Devolvido\n",
                   emprestimos[i].codigoLivro,
                   emprestimos[i].matriculaUsuario);
        }
    }
}
