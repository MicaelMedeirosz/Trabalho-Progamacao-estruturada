/* emprestimo.h - struct Emprestimo e prototipos das funcoes. */
#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "livro.h"
#include "usuario.h"

#define MAX_EMPRESTIMOS 100

/* Micael: struct que representa um emprestimo de livro. */
/* ativo: 1 = emprestado, 0 = devolvido. */
typedef struct {
    int codigoLivro;
    int matriculaUsuario;
    int ativo;
} Emprestimo;

void registrarEmprestimo(Emprestimo emprestimos[], int *quantidade,
                         Livro livros[], int quantidadeLivros,
                         Usuario usuarios[], int quantidadeUsuarios);

void registrarDevolucao(Emprestimo emprestimos[], int quantidade,
                        Livro livros[], int quantidadeLivros);

void listarEmprestimos(Emprestimo emprestimos[], int quantidade);

#endif
