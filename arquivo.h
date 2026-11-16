/* arquivo.h - prototipos das funcoes de persistencia em arquivos de texto. */
#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

void carregarLivros(Livro **livros, int *quantidade, int *capacidade);
void salvarLivros(Livro livros[], int quantidade);

void carregarUsuarios(Usuario **usuarios, int *quantidade, int *capacidade);
void salvarUsuarios(Usuario usuarios[], int quantidade);

void carregarEmprestimos(Emprestimo **emprestimos, int *quantidade, int *capacidade);
void salvarEmprestimos(Emprestimo emprestimos[], int quantidade);

/* Parte 2: persistencia em arquivos binarios. */
void salvarLivrosBinario(Livro livros[], int quantidade);

void carregarLivrosBinario(Livro **livros, int *quantidade, int *capacidade);

void salvarUsuariosBinario(Usuario usuarios[], int quantidade);

void carregarUsuariosBinario(Usuario **usuarios, int *quantidade, int *capacidade);

void salvarEmprestimosBinario(Emprestimo emprestimos[], int quantidade);

void carregarEmprestimosBinario(Emprestimo **emprestimos, int *quantidade, int *capacidade);

#endif
