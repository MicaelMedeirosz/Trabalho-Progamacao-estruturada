/* main.c - ponto de entrada e menu principal do sistema de biblioteca. */
#include <stdio.h>

#include "livro.h"

int main(void) {
    /* Micael: array estatico de livros e contador de quantos estao cadastrados. */
    Livro livros[MAX_LIVROS];
    int quantidadeLivros = 0;
    int opcao;

    do {
        printf("========================================\n");
        printf("     SISTEMA DE BIBLIOTECA\n");
        printf("========================================\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarLivro(livros, &quantidadeLivros);
                break;
            case 2:
                listarLivros(livros, quantidadeLivros);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
