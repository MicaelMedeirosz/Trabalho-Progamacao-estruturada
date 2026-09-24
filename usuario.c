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
    /* Implementacao na etapa 3. */
}

/* Micael: percorre o array comparando a matricula informada. */
int buscarUsuarioPorMatricula(Usuario usuarios[], int quantidade, int matricula) {
    /* Implementacao na etapa 4. */
    return -1;
}
