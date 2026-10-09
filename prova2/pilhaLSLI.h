#ifndef PILHALSLI_H
#define PILHALSLI_H

#include "noSLI.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct pilhaLSLI {
    NoSLI * topo;
    int tamanho;
} PilhaLSLI;

PilhaLSLI * criarPilhaLSLI();
void empilharPLSLI(int valor, PilhaLSLI *pontPilha);  // EMPILHAR
void mostrarPLSLI(PilhaLSLI *pontPilha);
void limparPLSLI(PilhaLSLI *pontPilha);
void destruirPLSLI(PilhaLSLI *pontPilha);
int obterTopo(PilhaLSLI *pontPilha);  // OBTERTOPO
int obterTamanhoPLSLI(PilhaLSLI *pontPilha);  // TAMANHOPILHA
int estahVaziaPLSLI(PilhaLSLI *pontPilha);  // ESTAHVAZIA
int desempilharPLSLI(PilhaLSLI *pontPilha);  // DESEMPILHAR

#endif
