#ifndef LISTADLI_H
#define LISTADLI_H

#include <stdio.h>
#include <stdlib.h>
#include "noDLI.h"

typedef struct lDLI {
    NoDLI * inicio;
    NoDLI * fim;
    int tamanho;
} ListaDLI;

ListaDLI * criarListaDLI();
void inserirInicioLDLI(int valor, ListaDLI *pontLista);
int getValorInicioLDLI(ListaDLI *pontLista);
int removerInicioLDLI(ListaDLI *pontLista);
void inserirFimLDLI(int valor, ListaDLI *pontLista);
int getValorFimLDLI(ListaDLI *pontLista);
int removerFimLDLI(ListaDLI *pontLista);
void inserirPosicaoLDLI(int valor, int posicao, ListaDLI *pontLista);
int getValorPosicaoLDLI(int posicao, ListaDLI *pontLista);
void mostrarLDLI(ListaDLI *pontLista);
void mostrarReversoLDLI(ListaDLI *pontLista);
void limparLDLI(ListaDLI *pontLista);
void destruirLDLI(ListaDLI *pontLista);

//EXERCICIOS
// Caso a lista esteja vazia deve avisar o usuário e retornar -1
// Caso a posição seja < 0 deve avisar o usuário e retornar -1
// Caso a posição seja >= tamanho deve avisar o usuário e retornar -1
// Caso a posição seja válida, deve remover e retornar o valor da posição desejada
//int removerPosicaoLDLI(int posicao, ListaDLI * pontLista);
//void substituirValorInicioLDLI(int valor, ListaDLI *pontLista);
//void substituirValorFimLDLI(int valor, ListaDLI *pontLista);
//void substituirValorPosicaoLDLI(int valor, int posicao, ListaDLI *pontLista);


#endif
