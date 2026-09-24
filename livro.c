/* livro.c - funcoes de cadastro, listagem e busca de livros. */
#include <stdio.h>
#include <string.h>
#include "livro.h"

/* Micael: cadastra um novo livro no array de livros. */
void cadastrarLivro(Livro livros[], int *quantidade) {
    /* Micael: verifica se o array de livros ja esta cheio. */
    if (*quantidade >= MAX_LIVROS) {
        printf("Nao e possivel cadastrar mais livros. Limite alcancado.\n");
        return;
    }

    printf("\nCodigo: ");
    scanf("%d", &livros[*quantidade].codigo);

    printf("Titulo: ");
    scanf(" %[^\n]", livros[*quantidade].titulo);

    printf("Autor: ");
    scanf(" %[^\n]", livros[*quantidade].autor);

    printf("Ano: ");
    scanf("%d", &livros[*quantidade].ano);

    printf("Quantidade disponivel: ");
    scanf("%d", &livros[*quantidade].quantidade);

    (*quantidade)++;
    printf("Livro cadastrado com sucesso.\n");
}

/* Micael: lista todos os livros cadastrados. */
void listarLivros(Livro livros[], int quantidade) {
    int i;

    /* Micael: se nenhum livro foi cadastrado, avisa e volta pro menu. */
    if (quantidade == 0) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    printf("\n%-8s %-30s %-25s %-6s %s\n", "Codigo", "Titulo", "Autor", "Ano", "Quantidade");
    printf("------------------------------------------------------------------------------\n");

    for (i = 0; i < quantidade; i++) {
        printf("%-8d %-30s %-25s %-6d %d\n",
               livros[i].codigo,
               livros[i].titulo,
               livros[i].autor,
               livros[i].ano,
               livros[i].quantidade);
    }
}

/* Micael: mostra os dados de um livro na tela. */
void mostrarLivro(Livro livro) {
    printf("\nCodigo: %d\n", livro.codigo);
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano: %d\n", livro.ano);
    printf("Quantidade disponivel: %d\n", livro.quantidade);
}

/* Micael: percorre o array comparando o titulo informado.
   Busca sequencial: comeca no primeiro livro e vai ate o final do array. */
int buscarLivroPorTitulo(Livro livros[], int quantidade, char titulo[]) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            return i;
        }
    }

    return -1;
}

/* Micael: percorre o array comparando o autor informado.
   Busca sequencial: retorna a posicao do primeiro livro encontrado. */
int buscarLivroPorAutor(Livro livros[], int quantidade, char autor[]) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (strcmp(livros[i].autor, autor) == 0) {
            return i;
        }
    }

    return -1;
}
