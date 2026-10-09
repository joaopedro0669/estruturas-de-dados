#include "filaLSLI.h"

FilaLSLI * criarFilaLSLI() {
    FilaLSLI * nova = (FilaLSLI *) malloc(sizeof(FilaLSLI));
    nova->tamanho = 0;
    nova->inicio = nova->fim = NULL;
    return nova;
}

void inserirFilaLSLI(int valor, FilaLSLI * pontFila) {
    if (pontFila->tamanho == 0) {  // VAZIA
        pontFila->inicio = pontFila->fim = criarNoSLI(valor, NULL);
    } else { // 1 OU + DE 1 ELEM
        NoSLI * novo = criarNoSLI(valor, NULL);
        pontFila->fim->proximo = novo;
        pontFila->fim = novo;
    }
    pontFila->tamanho++;
}

// P[]
// P[10]
// P[10 <- 20 <- 30]
void mostrarFilaLSLI(FilaLSLI * pontFila) {
    if (pontFila->inicio == NULL) {  // VAZIA
        printf("P[]\n");
    } else {  // 1 OU + DE 1 ELEM
        printf("P[");
        NoSLI * aux = pontFila->inicio;
        while (aux->proximo != NULL) {
            printf("%d <- ", aux->valor);
            aux = aux->proximo;
        }
        printf("%d]\n", aux->valor);
    }
}

int proximoFilaLSLI(FilaLSLI * pontFila) {
    if (pontFila->tamanho == 0) { // VAZIA
        printf("Impossivel obter o próximo de uma fila vazia\n");
        return -1;
    } else { // 1 OU + DE 1 ELEM
        return pontFila->inicio->valor;
    }
}

int obterTamanhoFilaLSLI(FilaLSLI * pontFila) {
    return pontFila->tamanho;
}

int estahVaziaFilaLSLI(FilaLSLI * pontFila) {
    return pontFila->tamanho == 0;
}

int removerFilaLSLI(FilaLSLI * pontFila) {
    int valor = -1;
    if(pontFila->tamanho == 0) {
        printf("Impossivel remover de uma Fila Vazia\n");
    } else {
        NoSLI *pont = pontFila->inicio->proximo;
        valor = pontFila->inicio->valor;
        free(pontFila->inicio);
        pontFila->inicio = pont;
        if (pontFila->tamanho == 1) { // 1 ELEM
            pontFila->fim = NULL;
        }
        pontFila->tamanho--;
    }
    return valor;
}

void limparFilaLSLI(FilaLSLI * pontFila) {
    if (pontFila->tamanho != 0) {  // NAO VAZIA, 1 OU + DE 1 ELEM
        NoSLI *pont = pontFila->inicio, *pont2 = NULL;
        while (pont != NULL) {
            pont2 = pont->proximo;
            free(pont);
            pont = pont2;
        }
    }
    pontFila->inicio = pontFila->fim = NULL;
    pontFila->tamanho = 0;
}

void destruirFilaLSLI(FilaLSLI * pontFila) {
    limparFilaLSLI(pontFila);
    free(pontFila);
}