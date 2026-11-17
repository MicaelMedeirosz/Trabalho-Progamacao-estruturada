/* emprestimo.c - funcoes de emprestimo e devolucao de livros. */
#include <stdio.h>
#include <stdlib.h>
#include "emprestimo.h"

/* Micael: registra o emprestimo de um livro para um usuario. */
void registrarEmprestimo(Emprestimo **emprestimos, int *quantidade, int *capacidade,
                         Livro livros[], int quantidadeLivros,
                         Usuario usuarios[], int quantidadeUsuarios) {
    int codigoLivro;
    int matricula;
    int posLivro;
    int posUsuario;
    int prazoDias;
    int diaPrev, mesPrev, anoPrev;

    /* Se atingiu a capacidade, redimensiona com realloc. */
    if (*quantidade >= *capacidade) {
        int novaCapacidade = *capacidade * 2;
        Emprestimo *novoArray = (Emprestimo *)realloc(*emprestimos, novaCapacidade * sizeof(Emprestimo));
        if (novoArray == NULL) {
            printf("Erro: memoria insuficiente para registrar emprestimo.\n");
            return;
        }
        *emprestimos = novoArray;
        *capacidade = novaCapacidade;
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

    printf("Data do emprestimo (dd mm aaaa): ");
    scanf("%d %d %d", &(*emprestimos)[*quantidade].diaEmp,
              &(*emprestimos)[*quantidade].mesEmp,
              &(*emprestimos)[*quantidade].anoEmp);

    printf("Prazo para devolucao em dias: ");
    scanf("%d", &prazoDias);

    /* Calcula data prevista de devolucao (simples: soma dias ao dia). */
    diaPrev = (*emprestimos)[*quantidade].diaEmp + prazoDias;
    mesPrev = (*emprestimos)[*quantidade].mesEmp;
    anoPrev = (*emprestimos)[*quantidade].anoEmp;
    while (diaPrev > 30) {
        diaPrev -= 30;
        mesPrev++;
        if (mesPrev > 12) {
            mesPrev = 1;
            anoPrev++;
        }
    }
    (*emprestimos)[*quantidade].diaPrev = diaPrev;
    (*emprestimos)[*quantidade].mesPrev = mesPrev;
    (*emprestimos)[*quantidade].anoPrev = anoPrev;

    (*emprestimos)[*quantidade].diaDev = 0;
    (*emprestimos)[*quantidade].mesDev = 0;
    (*emprestimos)[*quantidade].anoDev = 0;

    /* Micael: registra o emprestimo e diminui uma unidade do acervo. */
    (*emprestimos)[*quantidade].codigoLivro = codigoLivro;
    (*emprestimos)[*quantidade].matriculaUsuario = matricula;
    (*emprestimos)[*quantidade].ativo = 1;
    (*quantidade)++;

    livros[posLivro].quantidade--;

    printf("Emprestimo registrado com sucesso.\n");
    printf("Data prevista para devolucao: %02d/%02d/%04d\n",
           (*emprestimos)[*quantidade - 1].diaPrev,
           (*emprestimos)[*quantidade - 1].mesPrev,
           (*emprestimos)[*quantidade - 1].anoPrev);
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

    printf("Data da devolucao (dd mm aaaa): ");
    scanf("%d %d %d", &emprestimos[posEmprestimo].diaDev,
              &emprestimos[posEmprestimo].mesDev,
              &emprestimos[posEmprestimo].anoDev);

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

/* Calcula a diferenca aproximada de dias entre a data prevista e a data real. */
int calcularDiasAtraso(Emprestimo e) {
    int diasPrev, diasDev, atraso;

    if (e.diaDev == 0 && e.mesDev == 0 && e.anoDev == 0) {
        return 0;
    }

    diasPrev = e.anoPrev * 360 + e.mesPrev * 30 + e.diaPrev;
    diasDev = e.anoDev * 360 + e.mesDev * 30 + e.diaDev;

    atraso = diasDev - diasPrev;
    if (atraso < 0) {
        atraso = 0;
    }
    return atraso;
}

/* Calcula o valor da multa com base nos dias de atraso e taxa diaria. */
float calcularMulta(Emprestimo e) {
    int atraso = calcularDiasAtraso(e);
    return atraso * TAXA_MULTA_DIARIA;
}

/* Consulta e exibe a multa de um emprestimo especificado pelo usuario. */
void consultarMultaEmprestimo(Emprestimo emprestimos[], int quantidade) {
    int codigoLivro;
    int matricula;
    int i;
    int achou = 0;

    printf("\nCodigo do livro: ");
    scanf("%d", &codigoLivro);
    printf("Matricula do usuario: ");
    scanf("%d", &matricula);

    for (i = 0; i < quantidade; i++) {
        if (emprestimos[i].codigoLivro == codigoLivro &&
            emprestimos[i].matriculaUsuario == matricula) {
            achou = 1;
            printf("\nEmprestimo encontrado.\n");
            printf("Codigo do livro: %d\n", emprestimos[i].codigoLivro);
            printf("Matricula do usuario: %d\n", emprestimos[i].matriculaUsuario);
            printf("Situacao: %s\n", emprestimos[i].ativo == 1 ? "Emprestado" : "Devolvido");
            if (emprestimos[i].ativo == 1) {
                printf("Data prevista para devolucao: %02d/%02d/%04d\n",
                       emprestimos[i].diaPrev, emprestimos[i].mesPrev, emprestimos[i].anoPrev);
            } else {
                printf("Data real da devolucao: %02d/%02d/%04d\n",
                       emprestimos[i].diaDev, emprestimos[i].mesDev, emprestimos[i].anoDev);
                printf("Dias de atraso: %d\n", calcularDiasAtraso(emprestimos[i]));
                printf("Valor da multa: R$ %.2f\n", calcularMulta(emprestimos[i]));
            }
            break;
        }
    }

    if (!achou) {
        printf("Emprestimo nao encontrado.\n");
    }
}

/* Parte 2: lista o historico completo de emprestimos de um usuario. */
/* Aproveita a estrutura existente de Emprestimo, sem criar estrutura paralela. */
void listarHistoricoUsuario(Emprestimo emprestimos[], int quantidade,
                            Usuario usuarios[], int quantidadeUsuarios,
                            Livro livros[], int quantidadeLivros) {
    int matricula;
    int i;
    int posUsuario;
    int temEmprestimo = 0;

    (void)livros;
    (void)quantidadeLivros;

    if (quantidadeUsuarios == 0) {
        printf("\nNenhum usuario cadastrado.\n");
        return;
    }

    printf("\nMatricula do usuario: ");
    scanf("%d", &matricula);

    /* Verifica se o usuario existe. */
    posUsuario = buscarUsuarioPorMatricula(usuarios, quantidadeUsuarios, matricula);
    if (posUsuario == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    printf("\n========================================\n");
    printf("   HISTORICO DE EMPRESTIMOS - USUARIO\n");
    printf("========================================\n");
    printf("Matricula: %d\n", usuarios[posUsuario].matricula);
    printf("Nome: %s\n", usuarios[posUsuario].nome);
    printf("Curso: %s\n", usuarios[posUsuario].curso);
    printf("----------------------------------------\n");

    for (i = 0; i < quantidade; i++) {
        if (emprestimos[i].matriculaUsuario == matricula) {
            temEmprestimo = 1;
            printf("Codigo do livro: %d\n", emprestimos[i].codigoLivro);
            printf("Situacao: %s\n", emprestimos[i].ativo == 1 ? "Emprestado" : "Devolvido");
            if (emprestimos[i].ativo == 1) {
                printf("Data do emprestimo: %02d/%02d/%04d\n",
                       emprestimos[i].diaEmp, emprestimos[i].mesEmp, emprestimos[i].anoEmp);
                printf("Data prevista devolucao: %02d/%02d/%04d\n",
                       emprestimos[i].diaPrev, emprestimos[i].mesPrev, emprestimos[i].anoPrev);
            } else {
                printf("Data da devolucao: %02d/%02d/%04d\n",
                       emprestimos[i].diaDev, emprestimos[i].mesDev, emprestimos[i].anoDev);
                printf("Dias de atraso: %d\n", calcularDiasAtraso(emprestimos[i]));
                printf("Valor da multa: R$ %.2f\n", calcularMulta(emprestimos[i]));
            }
            printf("----------------------------------------\n");
        }
    }

    if (!temEmprestimo) {
        printf("Nenhum emprestimo registrado para este usuario.\n");
    }
}
