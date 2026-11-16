/* usuario.h - struct Usuario e prototipos das funcoes de usuarios. */
#ifndef USUARIO_H
#define USUARIO_H

#define MAX_USUARIOS 100
#define TAM_NOME 100
#define TAM_CURSO 100

/* Capacidade inicial do array dinamico de usuarios. */
#define CAPACIDADE_INICIAL_USUARIOS 10

/* Micael: struct que representa um usuario da biblioteca. */
typedef struct {
    int matricula;
    char nome[TAM_NOME];
    char curso[TAM_CURSO];
} Usuario;

void cadastrarUsuario(Usuario **usuarios, int *quantidade, int *capacidade);

void listarUsuarios(Usuario usuarios[], int quantidade);

/* Micael: mostra os dados de um usuario na tela. */
void mostrarUsuario(Usuario usuario);

/* Micael: busca sequencial de usuario pela matricula. Retorna a posicao ou -1. */
int buscarUsuarioPorMatricula(Usuario usuarios[], int quantidade, int matricula);

/* Parte 2: ordenacao manual (Selection Sort) de usuarios. */
void ordenarUsuariosPorMatricula(Usuario usuarios[], int quantidade);

void ordenarUsuariosPorNome(Usuario usuarios[], int quantidade);

/* Micael: busca binaria de usuario por matricula (requer usuarios ordenados por matricula). */
int buscarUsuarioPorMatriculaBinario(Usuario usuarios[], int quantidade, int matricula);

#endif
