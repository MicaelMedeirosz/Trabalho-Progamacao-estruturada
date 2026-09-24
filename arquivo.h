/* arquivo.h - prototipos das funcoes de persistencia em arquivos de texto. */
#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

void carregarLivros(Livro livros[], int *quantidade);
void salvarLivros(Livro livros[], int quantidade);

void carregarUsuarios(Usuario usuarios[], int *quantidade);
void salvarUsuarios(Usuario usuarios[], int quantidade);

void carregarEmprestimos(Emprestimo emprestimos[], int *quantidade);
void salvarEmprestimos(Emprestimo emprestimos[], int quantidade);

#endif
