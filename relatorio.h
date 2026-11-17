/* relatorio.h - prototipos das funcoes de relatorio de desempenho (Parte 2). */
#ifndef RELATORIO_H
#define RELATORIO_H

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

/* Gera relatorio de desempenho comparando busca sequencial vs binaria
   e bubble sort vs selection sort. Salva resultado em arquivo .txt. */
void gerarRelatorioDesempenho(Livro livros[], int quantidadeLivros,
                              Usuario usuarios[], int quantidadeUsuarios,
                              Emprestimo emprestimos[], int quantidadeEmprestimos);

#endif
