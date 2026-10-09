#include "listaSLI.h"

ListaSLI * criarListaSLI() {
    ListaSLI * nova = (ListaSLI *) malloc(sizeof(ListaSLI));
    // Verificação de segurança
    if (nova == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para a ListaSLI.\n");
        exit(1); // Encerra o programa
    }
    nova->tamanho = 0;
    nova->inicio = nova->fim = NULL;
    return nova;
}

// .  NA ESTRUTURA
// -> NO ENDERECO DA ESTRUTURA
// ENDERECO->CAMPO ==> (*ENDERECO).CAMPO ==> ESTRUTURA.CAMPO
void inserirFimLSLI(int valor, ListaSLI * pontLista) {
    if (pontLista->inicio == NULL) {  // VAZIA
        pontLista->inicio = pontLista->fim = criarNoSLI(valor, NULL);
    } else { // 1 OU + DE 1 ELEM
        NoSLI * novo = criarNoSLI(valor, NULL);
        pontLista->fim->proximo = novo;
        pontLista->fim = novo;
    }
    pontLista->tamanho++;
}

// []
// [10]
// [10, 20, 30]
void mostrarLSLI(ListaSLI * pontLista) {
    if (pontLista->inicio == NULL) {  // VAZIA
        printf("[]\n");
    } else {  // 1 OU + DE 1 ELEM
        printf("[");
        NoSLI * pontAux = pontLista->inicio;
        while (pontAux->proximo != NULL) {
            printf("%d, ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
        printf("%d]\n", pontAux->valor);
    }
    printf("Tamanho = %d\n", pontLista->tamanho);
}


int getValorFimLSLI(ListaSLI * pontLista) {
    if (pontLista->inicio == NULL) {  // VAZIA
        printf("Impossivel devolver o ultimo valor de uma lista vazia\n");
        return -1;
    } else { // 1 OU + DE 1 ELEM
        return pontLista->fim->valor;
    }
}

int removerFimLSLI(ListaSLI * pontLista) {
    if (pontLista->inicio == NULL) {  // VAZIA
        printf("Impossivel remover o ultimo valor de uma lista vazia\n");
        return -1;
    } else {
        int valor;
        if (pontLista->inicio->proximo == NULL) {  // 1 ELEM
            valor = pontLista->inicio->valor;
            free(pontLista->inicio);
            pontLista->inicio = NULL;
            pontLista->fim = NULL;
        } else {  // + DE 1 ELEM
            NoSLI *pontAux;
            pontAux = pontLista->inicio;
            while (pontAux->proximo != pontLista->fim) {
                pontAux = pontAux->proximo;
            }
            valor = pontLista->fim->valor;
            free(pontLista->fim);
            pontAux->proximo = NULL;
            pontLista->fim = pontAux;
        }
        pontLista->tamanho--;
        return valor;
    }
}

void limparLSLI(ListaSLI * pontLista) {
    if (pontLista->inicio == NULL) {  // VAZIA
        printf("Impossivel limpar uma lista vazia\n");
    } else {
        NoSLI *pont = pontLista->inicio, *pont2 = NULL;
        while (pont != NULL) {
            pont2 = pont->proximo;
            free(pont);
            pont = pont2;
        }
        pontLista->inicio = pontLista->fim = NULL;
        pontLista->tamanho = 0;
    }
}

void destruirLSLI(ListaSLI * pontLista) {
    limparLSLI(pontLista);
    free(pontLista);
}

void inserirInicioLSLI(int valor, ListaSLI * pontLista) {
    NoSLI *novo = criarNoSLI(valor, pontLista->inicio);
    if (pontLista->tamanho == 0) {
        pontLista->fim = novo;
    } 
    pontLista->inicio = novo;
    pontLista->tamanho++;
}

int getValorInicioLSLI(ListaSLI * pontLista) {
    if (pontLista->inicio == NULL) {  // VAZIA
        printf("Impossivel obter o valor do inicio de uma lista vazia\n");
        return -1;
    } else { // 1 OU + DE 1 ELEM
        return pontLista->inicio->valor;
    }
}

int removerInicioLSLI(ListaSLI * pontLista) {
    int valor = -1;
    if(pontLista->inicio == NULL) {
        printf("Impossivel remover o inicio de uma Lista Vazia\n");
    } else {
        NoSLI *pont = pontLista->inicio->proximo;
        valor = pontLista->inicio->valor;
        free(pontLista->inicio);
        pontLista->inicio = pont;
        if (pontLista->tamanho == 1) {
            pontLista->fim = NULL;
        }
        pontLista->tamanho--;
    }
    return valor;
}

// Caso a posição seja < 0 deve avisar o usuario e fazer nada
// Caso a posição seja >= tamanho deve avisar o usuario e fazer nada
// Caso a posição seja válida, deve inserir o valor recebido na 
//   posição desejada
void inserirPosicaoLSLI(int valor, int posicao, ListaSLI * pontLista) {
    if (pontLista->inicio == NULL) {  // VAZIA
        printf("Impossivel inserir o valor %d na posicao %d de uma lista vazia.\n", valor, posicao);
    } else {
        if (posicao < 0) {
            printf("Impossivel inserir o valor %d na posicao negativa %d\n", valor, posicao);
        }
        else { 
            if (posicao >= pontLista->tamanho) {
                printf("Impossivel inserir o valor %d na posicao fora do vetor %d. Posicoes validas: 0 a %d.\n", valor, posicao, pontLista->tamanho - 1);
            } else {  // POSICAO VALIDA, 1 OU + DE 1 ELEM
                if (posicao == 0) {  // POSICAO 0
                    pontLista->inicio = criarNoSLI(valor, pontLista->inicio);
                } else {  // DEMAIS POSICOES}
                    NoSLI * pont = pontLista->inicio;
                    int cont = 1;
                    while (cont < posicao) {
                        cont++;
                        pont = pont->proximo;
                    }
                    pont->proximo = criarNoSLI(valor, pont->proximo);
                }
                pontLista->tamanho++;
            }
        }
    }
}

// Caso a lista esteja vazia deve avisar o usuário e retornar -1
// Caso a posição seja < 0 deve avisar o usuário e retornar -1
// Caso a posição seja >= tamanho deve avisar o usuário e retornar -1
// Caso a posição seja válida, deve retornar o valor da posição desejada
int getValorPosicaoLSLI(int posicao, ListaSLI * pontLista) {
    if (pontLista->inicio == NULL) {  // VAZIA
        printf("Impossivel retornar o valor de uma posicao de uma lista vazia\n");
        return -1;
    } else if (posicao < 0) {
        printf("Impossivel retornar o valor de uma posicao negativa %d\n", posicao);
        return -1;
    } else {
        if (posicao >= pontLista->tamanho) {
            printf("Impossivel retornar o valor da posicao fora do vetor %d. Posicoes validas: 0 a %d.\n", posicao, pontLista->tamanho - 1);
            return -1;
        } else { // 1 OU + DE 1 ELEM
            int cont = 0;
            NoSLI * pont = pontLista->inicio;
            while (cont < posicao) {
                cont++;
                pont = pont->proximo;
            }
            return pont->valor;
        }
    }
}

// EXERCICIO
//int removerPosicaoLSLI(int posicao, ListaSLI * pontLista);
