#include "noSLI.h"

NoSLI * criarNoSLI(int v, NoSLI *p) {
    NoSLI * novo = (NoSLI *) malloc(sizeof(NoSLI));
    // Verificação de segurança
    if (novo == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para o No.\n");
        exit(1); // Encerra o programa
    }
    novo->valor = v;
    novo->proximo = p;
    return novo;
}
