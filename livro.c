/* livro.c - funcoes de cadastro, listagem e busca de livros. */
#include <stdio.h>
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
    /* Implementacao na etapa 2. */
}

/* Micael: percorre o array comparando o titulo informado. */
int buscarLivroPorTitulo(Livro livros[], int quantidade, char titulo[]) {
    /* Implementacao na etapa 4. */
    return -1;
}

/* Micael: percorre o array comparando o autor informado. */
int buscarLivroPorAutor(Livro livros[], int quantidade, char autor[]) {
    /* Implementacao na etapa 4. */
    return -1;
}
