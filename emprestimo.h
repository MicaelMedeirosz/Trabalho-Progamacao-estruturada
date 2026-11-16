/* emprestimo.h - struct Emprestimo e prototipos das funcoes. */
#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "livro.h"
#include "usuario.h"

#define MAX_EMPRESTIMOS 100

/* Capacidade inicial do array dinamico de emprestimos. */
#define CAPACIDADE_INICIAL_EMPRESTIMOS 10

/* Taxa diaria de multa por atraso (configuravel). */
#define TAXA_MULTA_DIARIA 2.00f

/* Micael: struct que representa um emprestimo de livro. */
/* ativo: 1 = emprestado, 0 = devolvido. */
typedef struct {
    int codigoLivro;
    int matriculaUsuario;
    int ativo;
    /* Data do emprestimo. */
    int diaEmp;
    int mesEmp;
    int anoEmp;
    /* Data prevista para devolucao. */
    int diaPrev;
    int mesPrev;
    int anoPrev;
    /* Data real da devolucao (0 = ainda nao devolvido). */
    int diaDev;
    int mesDev;
    int anoDev;
} Emprestimo;

void registrarEmprestimo(Emprestimo **emprestimos, int *quantidade, int *capacidade,
                         Livro livros[], int quantidadeLivros,
                         Usuario usuarios[], int quantidadeUsuarios);

void registrarDevolucao(Emprestimo emprestimos[], int quantidade,
                        Livro livros[], int quantidadeLivros);

void listarEmprestimos(Emprestimo emprestimos[], int quantidade);

/* Funcoes de controle de atrasos e multa (Parte 2). */
int calcularDiasAtraso(Emprestimo e);

float calcularMulta(Emprestimo e);

void consultarMultaEmprestimo(Emprestimo emprestimos[], int quantidade);

#endif
