/* usuario.c - funcoes de cadastro, listagem e busca de usuarios. */
#include <stdio.h>
#include "usuario.h"

/* Micael: cadastra um novo usuario no array de usuarios. */
void cadastrarUsuario(Usuario usuarios[], int *quantidade) {
    /* Micael: verifica se o array de usuarios ja esta cheio. */
    if (*quantidade >= MAX_USUARIOS) {
        printf("Nao e possivel cadastrar mais usuarios. Limite alcancado.\n");
        return;
    }

    printf("\nMatricula: ");
    scanf("%d", &usuarios[*quantidade].matricula);

    printf("Nome: ");
    scanf(" %[^\n]", usuarios[*quantidade].nome);

    printf("Curso: ");
    scanf(" %[^\n]", usuarios[*quantidade].curso);

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

/* Micael: percorre o array comparando a matricula informada. */
int buscarUsuarioPorMatricula(Usuario usuarios[], int quantidade, int matricula) {
    /* Implementacao na etapa 4. */
    return -1;
}
