# Sistema de Gerenciamento de Biblioteca

## Descrição

Projeto acadêmico desenvolvido em linguagem C para a disciplina de Programação Estruturada. O sistema permite o gerenciamento de uma biblioteca universitária: cadastro de livros e usuários, registro de empréstimos e devoluções, listagens, buscas sequenciais e persistência dos dados em arquivos de texto.

## Funcionalidades

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

## Como compilar

Com um compilador C padrão, por exemplo o gcc:

```bash
gcc main.c livro.c usuario.c emprestimo.c arquivo.c -o biblioteca
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
