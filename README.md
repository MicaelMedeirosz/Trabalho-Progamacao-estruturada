# Sistema de Gerenciamento de Biblioteca

## Descrição

Projeto acadêmico desenvolvido em linguagem C para a disciplina de Programação Estruturada. O sistema permite o gerenciamento de uma biblioteca universitária: cadastro de livros e usuários, registro de empréstimos e devoluções, listagens, buscas sequenciais e binárias, ordenação, persistência em arquivos de texto e binário, relatório de desempenho, controle de atrasos e multas, e histórico de empréstimos por usuário.

## Funcionalidades

### Parte 1 (já existentes)
- Cadastro de livros
- Cadastro de usuários
- Registro de empréstimos
- Registro de devoluções
- Listagem de livros
- Listagem de usuários
- Listagem de empréstimos
- Busca sequencial de livro por título
- Busca sequencial de livro por autor
- Busca sequencial de usuário por matrícula
- Persistência em arquivos de texto (livros.txt, usuarios.txt, emprestimos.txt)

### Parte 2 (novas funcionalidades)
- Alocação dinâmica de memória (malloc, realloc, free) para livros, usuários e empréstimos
- Ordenação manual de livros por título, autor e ano (Bubble Sort)
- Ordenação manual de usuários por matrícula e nome (Selection Sort)
- Busca sequencial (mantida da Parte 1)
- Busca binária de livro por título (requer ordenação prévia por título)
- Busca binária de usuário por matrícula (requer ordenação prévia por matrícula)
- Persistência em arquivos binários (livros.bin, usuarios.bin, emprestimos.bin) com fread/fwrite
- Relatório de desempenho comparando busca sequencial vs binária e Bubble Sort vs Selection Sort
- Controle de atrasos e multa por devolução tardia (taxa diária configurável)
- Histórico completo de empréstimos por usuário

## Como compilar

Com um compilador C padrão, por exemplo o gcc:

```bash
gcc main.c livro.c usuario.c emprestimo.c arquivo.c relatorio.c -o biblioteca
```

## Como executar

Linux/Mac:

```bash
./biblioteca
```

Windows (executável gerado pelo gcc/MinGW):

```bash
biblioteca.exe
```

## Estrutura dos arquivos

| Arquivo | Descrição |
|---------|-----------|
| `main.c` | Ponto de entrada e menu principal do sistema |
| `livro.h` / `livro.c` | Struct Livro, cadastro, listagem, busca, ordenação (Bubble Sort) e busca binária por título |
| `usuario.h` / `usuario.c` | Struct Usuario, cadastro, listagem, busca, ordenação (Selection Sort) e busca binária por matrícula |
| `emprestimo.h` / `emprestimo.c` | Struct Emprestimo, empréstimo, devolução, listagem, consulta de multa, histórico por usuário e empréstimos atrasados |
| `arquivo.h` / `arquivo.c` | Persistência em arquivos de texto e binários (salvar/carregar) |
| `relatorio.h` / `relatorio.c` | Relatório de desempenho (comparação de busca e ordenação) |
| `README.md` | Documentação do projeto |
| `.gitignore` | Arquivos ignorados pelo Git (executáveis, .txt, .bin, relatório) |

## Algoritmos de ordenação utilizados

- **Bubble Sort**: ordena livros por título, autor e ano
- **Selection Sort**: ordena usuários por matrícula e nome

Ambos implementados manualmente, sem uso de `qsort()`.

## Busca

- **Busca sequencial**: percorre o array do início até o final (mantida da Parte 1)
- **Busca binária**: divide o array ordenado ao meio a cada iteração; disponível para livro por título e usuário por matrícula. Requer que os dados estejam ordenados pelo mesmo critério antes da busca.

## Persistência em arquivos

- **Arquivos de texto** (Parte 1): `livros.txt`, `usuarios.txt`, `emprestimos.txt` — salvos ao encerrar o sistema e carregados ao iniciar
- **Arquivos binários** (Parte 2): `livros.bin`, `usuarios.bin`, `emprestimos.bin` — salvos/carregados sob demanda através do menu (opções 19 e 20)

## Relatório de desempenho

Disponível na opção 21 do menu. Compara:
- Busca sequencial vs busca binária (tempo de execução real)
- Bubble Sort vs Selection Sort (tempo de execução real)

O resultado é exibido na tela e salvo em `relatorio_desempenho.txt`.

## Funcionalidades extras

- **Controle de atrasos e multa**: calcula dias de atraso e valor da multa (taxa diária configurável em `TAXA_MULTA_DIARIA`) para empréstimos vencidos, acessível na opção 23 do menu
- **Histórico por usuário**: lista todos os empréstimos registrados de um usuário informado, acessível na opção 22 do menu

## Menu

O menu contém 23 opções numeradas (0 a 23), cobrindo todas as funcionalidades da Parte 1 e Parte 2.
