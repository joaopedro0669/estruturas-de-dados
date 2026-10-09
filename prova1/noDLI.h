#ifndef NODLI_H
#define NODLI_H

#include <stdlib.h>
#include <stdio.h>

typedef struct noDLI {
    int valor;
    struct noDLI * anterior;
    struct noDLI * proximo;
} NoDLI;

NoDLI * criarNoDLI(int valor, NoDLI * ant, NoDLI * prox);

#endif