#ifndef NOSLI_H
#define NOSLI_H

#include <stdlib.h>
#include <stdio.h>

typedef struct noSLI {
    int valor;
    struct noSLI * proximo;
} NoSLI;

NoSLI * criarNoSLI(int v, NoSLI *p);

#endif