#include "pilhaLSLI.h"

PilhaLSLI * criarPilhaLSLI() {
    PilhaLSLI * nova = (PilhaLSLI *) malloc(sizeof(PilhaLSLI));
    nova->tamanho = 0;
    nova->topo = NULL;
    return nova;
}

void empilharPLSLI(int valor, PilhaLSLI *pontPilha) {
    pontPilha->topo = criarNoSLI(valor, pontPilha->topo);
    pontPilha->tamanho++;
}

// T[]
// T[10]
// T[30 <- 20 <- 10]
void mostrarPLSLI(PilhaLSLI *pontPilha) {
    if (pontPilha->topo == NULL) {  // VAZIA
        printf("T[]\n");
    } else {  // 1 OU + DE 1 ELEM
        printf("T[");
        NoSLI * aux = pontPilha->topo;
        while (aux->proximo != NULL) {
            printf("%d <- ", aux->valor);
            aux = aux->proximo;
        }
        printf("%d]\n", aux->valor);
    }
}

void limparPLSLI(PilhaLSLI *pontPilha) {
    if (pontPilha->topo != NULL) {
        if (pontPilha->topo->proximo == NULL) {  // 1 ELEM
            free(pontPilha->topo);
        } else {  // + DE 1 ELEM
            NoSLI *pont = pontPilha->topo, *pont2 = NULL;
            while (pont != NULL) {
                pont2 = pont->proximo;
                free(pont);
                pont = pont2;
            }
        }
        pontPilha->topo = NULL;
        pontPilha->tamanho = 0;
    }
}

void destruirPLSLI(PilhaLSLI *pontPilha) {
    limparPLSLI(pontPilha);
    free(pontPilha);
}

int obterTopo(PilhaLSLI *pontPilha) {
    if (pontPilha->topo == NULL) {  // VAZIA
        printf("Impossivel obter o topo de uma pilha vazia\n");
        return -1;
    } else { // 1 OU + DE 1 ELEM
        return pontPilha->topo->valor;
    }
}

int obterTamanhoPLSLI(PilhaLSLI *pontPilha) {
    return pontPilha->tamanho;
}

int estahVaziaPLSLI(PilhaLSLI *pontPilha) {
    if (pontPilha->tamanho == 0) {
        return 1;
    } else {
        return 0;
    }
}

int desempilharPLSLI(PilhaLSLI *pontPilha) {
    int valor = -1;
    if(pontPilha->topo == NULL) {
        printf("Impossivel desempilhar de uma Pilha Vazia\n");
    } else {
        NoSLI *pont = pontPilha->topo->proximo;
        valor = pontPilha->topo->valor;
        free(pontPilha->topo);
        pontPilha->topo = pont;
        pontPilha->tamanho--;
    }
    return valor;
}