/* usuario.c - funcoes de cadastro, listagem e busca de usuarios. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

/* Micael: cadastra um novo usuario no array dinamico de usuarios. */
void cadastrarUsuario(Usuario **usuarios, int *quantidade, int *capacidade) {
    /* Se atingiu a capacidade, redimensiona com realloc. */
    if (*quantidade >= *capacidade) {
        int novaCapacidade = *capacidade * 2;
        Usuario *novoArray = (Usuario *)realloc(*usuarios, novaCapacidade * sizeof(Usuario));
        if (novoArray == NULL) {
            printf("Erro: memoria insuficiente para cadastrar usuario.\n");
            return;
        }
        *usuarios = novoArray;
        *capacidade = novaCapacidade;
    }

    printf("\nMatricula: ");
    scanf("%d", &(*usuarios)[*quantidade].matricula);

    printf("Nome: ");
    scanf(" %[^\n]", (*usuarios)[*quantidade].nome);

    printf("Curso: ");
    scanf(" %[^\n]", (*usuarios)[*quantidade].curso);

    (*quantidade)++;
    printf("Usuario cadastrado com sucesso.\n");
}

/* Micael: lista todos os usuarios cadastrados. */
void listarUsuarios(Usuario usuarios[], int quantidade) {
    int i;

    /* Micael: se nenhum usuario foi cadastrado, avisa e volta pro menu. */
    if (quantidade == 0) {
        printf("\nNenhum usuario cadastrado.\n");
        return;
    }

    printf("\n%-12s %-30s %s\n", "Matricula", "Nome", "Curso");
    printf("--------------------------------------------------------------\n");

    for (i = 0; i < quantidade; i++) {
        printf("%-12d %-30s %s\n",
               usuarios[i].matricula,
               usuarios[i].nome,
               usuarios[i].curso);
    }
}

/* Micael: mostra os dados de um usuario na tela. */
void mostrarUsuario(Usuario usuario) {
    printf("\nMatricula: %d\n", usuario.matricula);
    printf("Nome: %s\n", usuario.nome);
    printf("Curso: %s\n", usuario.curso);
}

/* Micael: percorre o array comparando a matricula informada.
   Busca sequencial: comeca no primeiro usuario e vai ate o final do array. */
int buscarUsuarioPorMatricula(Usuario usuarios[], int quantidade, int matricula) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (usuarios[i].matricula == matricula) {
            return i;
        }
    }

    return -1;
}

/* Troca dois usuarios de posicao no array. */
void trocarUsuarios(Usuario *a, Usuario *b) {
    Usuario temp = *a;
    *a = *b;
    *b = temp;
}

/* Parte 2: Selection Sort - ordena usuarios por matricula (crescente). */
void ordenarUsuariosPorMatricula(Usuario usuarios[], int quantidade) {
    int i, j;
    int minIdx;

    if (quantidade <= 1) {
        return;
    }

    for (i = 0; i < quantidade - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < quantidade; j++) {
            if (usuarios[j].matricula < usuarios[minIdx].matricula) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            trocarUsuarios(&usuarios[i], &usuarios[minIdx]);
        }
    }
}

/* Parte 2: Selection Sort - ordena usuarios por nome (ordem alfabetica). */
void ordenarUsuariosPorNome(Usuario usuarios[], int quantidade) {
    int i, j;
    int minIdx;

    if (quantidade <= 1) {
        return;
    }

    for (i = 0; i < quantidade - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < quantidade; j++) {
            if (strcmp(usuarios[j].nome, usuarios[minIdx].nome) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            trocarUsuarios(&usuarios[i], &usuarios[minIdx]);
        }
    }
}
