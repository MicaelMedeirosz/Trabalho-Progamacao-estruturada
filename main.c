/* main.c - ponto de entrada e menu principal do sistema de biblioteca. */
#include <stdio.h>
#include <stdlib.h>

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"
#include "arquivo.h"
#include "relatorio.h"

/* Micael: le a opcao do menu e trata o caso do usuario digitar letras.
   Se a entrada nao for um numero, limpa o buffer e devolve -1,
   que cai no default do switch como opcao invalida. */
int lerOpcao(void) {
    int opcao;
    int c;

    if (scanf("%d", &opcao) != 1) {
        while ((c = getchar()) != '\n' && c != EOF) {
        }
        return -1;
    }

    return opcao;
}

int main(void) {
    /* Micael: arrays dinamicos de livros, usuarios e emprestimos. */
    Livro *livros = NULL;
    Usuario *usuarios = NULL;
    Emprestimo *emprestimos = NULL;
    int quantidadeLivros = 0;
    int quantidadeUsuarios = 0;
    int quantidadeEmprestimos = 0;
    int capacidadeLivros = CAPACIDADE_INICIAL_LIVROS;
    int capacidadeUsuarios = CAPACIDADE_INICIAL_USUARIOS;
    int capacidadeEmprestimos = CAPACIDADE_INICIAL_EMPRESTIMOS;
    int opcao;
    int posicao;
    int matriculaBusca;
    char textoBusca[TAM_TITULO];

    /* Micael: carrega os livros salvos no arquivo de texto ao iniciar. */
    carregarLivros(&livros, &quantidadeLivros, &capacidadeLivros);
    carregarUsuarios(&usuarios, &quantidadeUsuarios, &capacidadeUsuarios);
    carregarEmprestimos(&emprestimos, &quantidadeEmprestimos, &capacidadeEmprestimos);
    do {
        printf("\n");
        printf("========================================\n");
        printf("     SISTEMA DE BIBLIOTECA\n");
        printf("========================================\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro por titulo\n");
        printf("4 - Buscar livro por autor\n");
        printf("\n");
        printf("5 - Cadastrar usuario\n");
        printf("6 - Listar usuarios\n");
        printf("7 - Buscar usuario por matricula\n");
        printf("\n");
        printf("8 - Registrar emprestimo\n");
        printf("9 - Registrar devolucao\n");
        printf("10 - Listar emprestimos\n");
        printf("11 - Consultar multa de emprestimo\n");
        printf("\n");
        printf("12 - Ordenar livros por titulo\n");
        printf("13 - Ordenar livros por autor\n");
        printf("14 - Ordenar livros por ano\n");
        printf("15 - Ordenar usuarios por matricula\n");
        printf("16 - Ordenar usuarios por nome\n");
        printf("17 - Buscar livro por titulo (binaria)\n");
        printf("18 - Buscar usuario por matricula (binaria)\n");
        printf("\n");
        printf("19 - Salvar dados em arquivo binario\n");
        printf("20 - Carregar dados de arquivo binario\n");
        printf("21 - Gerar relatorio de desempenho\n");
        printf("22 - Historico de emprestimos por usuario\n");
        printf("\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                cadastrarLivro(&livros, &quantidadeLivros, &capacidadeLivros);
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
                cadastrarUsuario(&usuarios, &quantidadeUsuarios, &capacidadeUsuarios);
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
                registrarEmprestimo(&emprestimos, &quantidadeEmprestimos, &capacidadeEmprestimos,
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
            case 11:
                consultarMultaEmprestimo(emprestimos, quantidadeEmprestimos);
                break;
            case 12:
                ordenarLivrosPorTitulo(livros, quantidadeLivros);
                printf("Livros ordenados por titulo.\n");
                break;
            case 13:
                ordenarLivrosPorAutor(livros, quantidadeLivros);
                printf("Livros ordenados por autor.\n");
                break;
            case 14:
                ordenarLivrosPorAno(livros, quantidadeLivros);
                printf("Livros ordenados por ano.\n");
                break;
            case 15:
                ordenarUsuariosPorMatricula(usuarios, quantidadeUsuarios);
                printf("Usuarios ordenados por matricula.\n");
                break;
            case 16:
                ordenarUsuariosPorNome(usuarios, quantidadeUsuarios);
                printf("Usuarios ordenados por nome.\n");
                break;
            case 17:
                printf("\nTitulo: ");
                scanf(" %[^\n]", textoBusca);
                posicao = buscarLivroPorTituloBinario(livros, quantidadeLivros, textoBusca);
                if (posicao == -1) {
                    printf("Livro nao encontrado (ou livros nao estao ordenados por titulo).\n");
                } else {
                    mostrarLivro(livros[posicao]);
                }
                break;
            case 18:
                printf("\nMatricula: ");
                scanf("%d", &matriculaBusca);
                posicao = buscarUsuarioPorMatriculaBinario(usuarios, quantidadeUsuarios, matriculaBusca);
                if (posicao == -1) {
                    printf("Usuario nao encontrado (ou usuarios nao estao ordenados por matricula).\n");
                } else {
                    mostrarUsuario(usuarios[posicao]);
                }
                break;
            case 19:
                salvarLivrosBinario(livros, quantidadeLivros);
                salvarUsuariosBinario(usuarios, quantidadeUsuarios);
                salvarEmprestimosBinario(emprestimos, quantidadeEmprestimos);
                printf("Dados salvos em arquivos binarios.\n");
                break;
            case 20:
                carregarLivrosBinario(&livros, &quantidadeLivros, &capacidadeLivros);
                carregarUsuariosBinario(&usuarios, &quantidadeUsuarios, &capacidadeUsuarios);
                carregarEmprestimosBinario(&emprestimos, &quantidadeEmprestimos, &capacidadeEmprestimos);
                printf("Dados carregados de arquivos binarios.\n");
                break;
            case 21:
                gerarRelatorioDesempenho(livros, quantidadeLivros,
                                         usuarios, quantidadeUsuarios,
                                         emprestimos, quantidadeEmprestimos);
                break;
            case 22:
                listarHistoricoUsuario(emprestimos, quantidadeEmprestimos,
                                       usuarios, quantidadeUsuarios,
                                       livros, quantidadeLivros);
                break;
            case 0:
                /* Micael: salva os dados nos arquivos antes de encerrar. */
                salvarLivros(livros, quantidadeLivros);
                salvarUsuarios(usuarios, quantidadeUsuarios);
                salvarEmprestimos(emprestimos, quantidadeEmprestimos);
                /* Micael: libera a memoria alocada dinamicamente. */
                free(livros);
                free(usuarios);
                free(emprestimos);
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
