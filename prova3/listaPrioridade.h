#ifndef LISTA_PRIORIDADES
#define LISTA_PRIORIDADES

#include <stdio.h>
#include <stdlib.h>
#include "filaLSLI.h"

typedef struct noPrio {
    int nivel;              // Identificador da prioridade
    FilaLSLI *filaTarefas;  // A fila de tarefas deste nível
    struct noPrio *proximo; // Próximo nível existente no sistema
} NoPrio;

typedef struct {
    NoPrio *inicio;
    int qtdNiveis;
} ListaPrioridades;

ListaPrioridades* criarListaPrioridades();
void mostrarListaPrioridades(ListaPrioridades *lp);
void destruirListaPrioridades(ListaPrioridades *lp);

#endif