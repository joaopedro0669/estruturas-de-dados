#ifndef FILALSLI_H
#define FILALSLI_H

#include <stdlib.h>
#include <stdio.h>
#include "noSLI.h"

typedef struct filaLSLI {
    NoSLI * inicio;
    NoSLI * fim;
    int tamanho;
} FilaLSLI;

FilaLSLI * criarFilaLSLI();
void inserirFilaLSLI(int valor, FilaLSLI * pontFila);
void mostrarFilaLSLI(FilaLSLI * pontFila);
int proximoFilaLSLI(FilaLSLI * pontFila);
int obterTamanhoFilaLSLI(FilaLSLI * pontFila);
int estahVaziaFilaLSLI(FilaLSLI * pontFila);
int removerFilaLSLI(FilaLSLI * pontFila);
void limparFilaLSLI(FilaLSLI * pontFila);
void destruirFilaLSLI(FilaLSLI * pontFila);

#endif