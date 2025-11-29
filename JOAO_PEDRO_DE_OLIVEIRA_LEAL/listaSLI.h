#ifndef LISTASLI_H
#define LISTASLI_H

#include <stdlib.h>
#include <stdio.h>
#include "noSLI.h"

typedef struct lSLI {
    NoSLI * inicio;
    NoSLI * fim;
    int tamanho;
} ListaSLI;

ListaSLI * criarListaSLI();
void inserirFimLSLI(int valor, ListaSLI * pontLista);
int getValorFimLSLI(ListaSLI * pontLista);
int removerFimLSLI(ListaSLI * pontLista);
void mostrarLSLI(ListaSLI * pontLista);
void limparLSLI(ListaSLI * pontLista);
void destruirLSLI(ListaSLI * pontLista);
void inserirInicioLSLI(int valor, ListaSLI * pontLista);
int getValorInicioLSLI(ListaSLI * pontLista);
int removerInicioLSLI(ListaSLI * pontLista);
void inserirPosicaoLSLI(int valor, int posicao, ListaSLI * pontLista);
int getValorPosicaoLSLI(int posicao, ListaSLI * pontLista);

// EXERCICIO
//int removerPosicaoLSLI(int posicao, ListaSLI * pontLista);

#endif
