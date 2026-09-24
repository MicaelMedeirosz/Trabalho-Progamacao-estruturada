/* usuario.h - struct Usuario e prototipos das funcoes de usuarios. */
#ifndef USUARIO_H
#define USUARIO_H

#define MAX_USUARIOS 100
#define TAM_NOME 100
#define TAM_CURSO 100

/* Micael: struct que representa um usuario da biblioteca. */
typedef struct {
    int matricula;
    char nome[TAM_NOME];
    char curso[TAM_CURSO];
} Usuario;

void cadastrarUsuario(Usuario usuarios[], int *quantidade);

void listarUsuarios(Usuario usuarios[], int quantidade);

/* Micael: mostra os dados de um usuario na tela. */
void mostrarUsuario(Usuario usuario);

/* Micael: busca sequencial de usuario pela matricula. Retorna a posicao ou -1. */
int buscarUsuarioPorMatricula(Usuario usuarios[], int quantidade, int matricula);

#endif
