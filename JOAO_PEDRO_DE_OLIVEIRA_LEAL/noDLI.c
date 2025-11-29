#include "noDLI.h"

NoDLI *criarNoDLI(int valor, NoDLI *ant, NoDLI *prox)
{
    NoDLI *novo = (NoDLI *)malloc(sizeof(NoDLI));
    if (novo == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para o No.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->anterior = ant;
    novo->proximo = prox;
    return novo;
}
