/* livro.h - struct Livro e prototipos das funcoes de livros. */
#ifndef LIVRO_H
#define LIVRO_H

#define MAX_LIVROS 100
#define TAM_TITULO 100
#define TAM_AUTOR 100

/* Micael: struct que representa um livro da biblioteca. */
typedef struct {
    int codigo;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano;
    int quantidade;
} Livro;

void cadastrarLivro(Livro livros[], int *quantidade);

void listarLivros(Livro livros[], int quantidade);

/* Micael: busca sequencial de livro pelo titulo. Retorna a posicao ou -1. */
int buscarLivroPorTitulo(Livro livros[], int quantidade, char titulo[]);

/* Micael: busca sequencial de livro pelo autor. Retorna a posicao ou -1. */
int buscarLivroPorAutor(Livro livros[], int quantidade, char autor[]);

#endif
