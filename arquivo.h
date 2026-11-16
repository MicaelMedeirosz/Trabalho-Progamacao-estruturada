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

#endif
