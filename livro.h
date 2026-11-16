/* livro.h - struct Livro e prototipos das funcoes de livros. */
#ifndef LIVRO_H
#define LIVRO_H

#define MAX_LIVROS 100
#define TAM_TITULO 100
#define TAM_AUTOR 100

/* Capacidade inicial do array dinamico de livros. */
#define CAPACIDADE_INICIAL_LIVROS 10

/* Micael: struct que representa um livro da biblioteca. */
typedef struct {
    int codigo;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano;
    int quantidade;
} Livro;

void cadastrarLivro(Livro **livros, int *quantidade, int *capacidade);

void listarLivros(Livro livros[], int quantidade);

/* Micael: mostra os dados de um livro na tela. */
void mostrarLivro(Livro livro);

/* Micael: busca sequencial de livro pelo titulo. Retorna a posicao ou -1. */
int buscarLivroPorTitulo(Livro livros[], int quantidade, char titulo[]);

/* Micael: busca sequencial de livro pelo codigo. Retorna a posicao ou -1. */
int buscarLivroPorCodigo(Livro livros[], int quantidade, int codigo);

/* Micael: busca sequencial de livro pelo autor. Retorna a posicao ou -1. */
int buscarLivroPorAutor(Livro livros[], int quantidade, char autor[]);

/* Parte 2: ordenacao manual (Bubble Sort) de livros. */
void ordenarLivrosPorTitulo(Livro livros[], int quantidade);

void ordenarLivrosPorAutor(Livro livros[], int quantidade);

void ordenarLivrosPorAno(Livro livros[], int quantidade);

/* Micael: busca binaria de livro por titulo (requer livros ordenados por titulo). */
int buscarLivroPorTituloBinario(Livro livros[], int quantidade, char titulo[]);

#endif
