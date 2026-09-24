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
