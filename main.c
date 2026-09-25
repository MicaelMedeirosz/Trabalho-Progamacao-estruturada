/* main.c - ponto de entrada e menu principal do sistema de biblioteca. */
#include <stdio.h>

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"
#include "arquivo.h"

int main(void) {
    /* Micael: arrays estaticos de livros e usuarios com seus contadores. */
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    Emprestimo emprestimos[MAX_EMPRESTIMOS];
    int quantidadeLivros = 0;
    int quantidadeUsuarios = 0;
    int quantidadeEmprestimos = 0;
    int opcao;
    int posicao;
    int matriculaBusca;
    char textoBusca[TAM_TITULO];

    /* Micael: carrega os livros salvos no arquivo de texto ao iniciar. */
    carregarLivros(livros, &quantidadeLivros);

    do {
        printf("========================================\n");
        printf("     SISTEMA DE BIBLIOTECA\n");
        printf("========================================\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro por titulo\n");
        printf("4 - Buscar livro por autor\n");
        printf("5 - Cadastrar usuario\n");
        printf("6 - Listar usuarios\n");
        printf("7 - Buscar usuario por matricula\n");
        printf("8 - Registrar emprestimo\n");
        printf("9 - Registrar devolucao\n");
        printf("10 - Listar emprestimos\n");
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
            case 3:
                printf("\nTitulo: ");
                scanf(" %[^\n]", textoBusca);
                posicao = buscarLivroPorTitulo(livros, quantidadeLivros, textoBusca);
                if (posicao == -1) {
                    printf("Livro nao encontrado.\n");
                } else {
                    mostrarLivro(livros[posicao]);
                }
                break;
            case 4:
                printf("\nAutor: ");
                scanf(" %[^\n]", textoBusca);
                posicao = buscarLivroPorAutor(livros, quantidadeLivros, textoBusca);
                if (posicao == -1) {
                    printf("Livro nao encontrado.\n");
                } else {
                    mostrarLivro(livros[posicao]);
                }
                break;
            case 5:
                cadastrarUsuario(usuarios, &quantidadeUsuarios);
                break;
            case 6:
                listarUsuarios(usuarios, quantidadeUsuarios);
                break;
            case 7:
                printf("\nMatricula: ");
                scanf("%d", &matriculaBusca);
                posicao = buscarUsuarioPorMatricula(usuarios, quantidadeUsuarios, matriculaBusca);
                if (posicao == -1) {
                    printf("Usuario nao encontrado.\n");
                } else {
                    mostrarUsuario(usuarios[posicao]);
                }
                break;
            case 8:
                registrarEmprestimo(emprestimos, &quantidadeEmprestimos,
                                   livros, quantidadeLivros,
                                   usuarios, quantidadeUsuarios);
                break;
            case 9:
                registrarDevolucao(emprestimos, quantidadeEmprestimos,
                                   livros, quantidadeLivros);
                break;
            case 10:
                listarEmprestimos(emprestimos, quantidadeEmprestimos);
                break;
            case 0:
                /* Micael: salva os dados nos arquivos antes de encerrar. */
                salvarLivros(livros, quantidadeLivros);
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
