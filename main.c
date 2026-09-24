/* main.c - ponto de entrada e menu principal do sistema de biblioteca. */
#include <stdio.h>

#include "livro.h"
#include "usuario.h"

int main(void) {
    /* Micael: arrays estaticos de livros e usuarios com seus contadores. */
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    int quantidadeLivros = 0;
    int quantidadeUsuarios = 0;
    int opcao;

    do {
        printf("========================================\n");
        printf("     SISTEMA DE BIBLIOTECA\n");
        printf("========================================\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("5 - Cadastrar usuario\n");
        printf("6 - Listar usuarios\n");
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
            case 5:
                cadastrarUsuario(usuarios, &quantidadeUsuarios);
                break;
            case 6:
                listarUsuarios(usuarios, quantidadeUsuarios);
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
