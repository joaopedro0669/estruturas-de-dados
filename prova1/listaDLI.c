#include "listaDLI.h"

ListaDLI * criarListaDLI() {
    ListaDLI * nova = (ListaDLI *) malloc(sizeof(ListaDLI));
    if (nova == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para a ListaDLI.\n");
        exit(1);
    }
    nova->tamanho = 0;
    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}

void inserirInicioLDLI(int valor, ListaDLI *pontLista) {
    NoDLI *novo;
    if (pontLista->tamanho == 0) {  // VAZIA   pontLista->inicio == NULL
        novo = criarNoDLI(valor, NULL, NULL);
        pontLista->fim = novo;
    } else {  // 1 OU + DE 1 ELEM
        novo = criarNoDLI(valor, NULL, pontLista->inicio);
        pontLista->inicio->anterior = novo;
    }
    pontLista->inicio = novo;
    pontLista->tamanho++;
}

void mostrarLDLI(ListaDLI *pontLista) {
    if (pontLista->tamanho == 0) {  // VAZIA
        printf("[]\n");
    } else { // 1 OU + DE 1 ELEM
        NoDLI *aux = pontLista->inicio;
        printf("[");
        while (aux->proximo != NULL)
        {
            printf("%d, ", aux->valor);
            aux = aux->proximo;
        }
        printf("%d]\n", aux->valor);
    }
    printf("Tamanho = %d\n", pontLista->tamanho);
}

void limparLDLI(ListaDLI *pontLista) {
    if (pontLista->tamanho != 0) {  // NAO VAZIA
        // 1 OU + DE 1 ELEM
        NoDLI * aux = pontLista->inicio->proximo; // apontar para 2o noh
        while (aux != NULL) {
            free(aux->anterior);
            aux = aux->proximo;
        }
        free(pontLista->fim);
        pontLista->inicio = NULL;
        pontLista->fim = NULL;
        pontLista->tamanho = 0;
    }
}

void destruirLDLI(ListaDLI *pontLista) {
    limparLDLI(pontLista);
    free(pontLista);
}

void mostrarReversoLDLI(ListaDLI *pontLista) {
    if (pontLista->tamanho == 0) {  // VAZIA
        printf("[]\n");
    } else { // 1 OU + DE 1 ELEM
        NoDLI *aux = pontLista->fim;
        printf("[");
        while (aux->anterior != NULL)
        {
            printf("%d, ", aux->valor);
            aux = aux->anterior;
        }
        printf("%d]\n", aux->valor);
    }
    printf("Tamanho = %d\n", pontLista->tamanho);
}

void inserirFimLDLI(int valor, ListaDLI *pontLista) {
    NoDLI *novo;
    if (pontLista->tamanho == 0) {  // VAZIA   pontLista->inicio == NULL
        novo = criarNoDLI(valor, NULL, NULL);
        pontLista->inicio = novo;
    } else {  // 1 OU + DE 1 ELEM
        novo = criarNoDLI(valor, pontLista->fim, NULL);
        pontLista->fim->proximo = novo;
    }
    pontLista->fim = novo;
    pontLista->tamanho++;
}

int getValorInicioLDLI(ListaDLI *pontLista) {
    if (pontLista->tamanho == 0) {  // VAZIA
        printf("Impossivel retornar o valor do inicio de uma lista vazia. Retornando -1\n");
        return -1;
    } else {  // 1 OU + DE 1 ELEM
        return pontLista->inicio->valor;
        // return (*pontLista).inicio->valor;
        // return (*(*pontLista).inicio).valor;
    }
}

int getValorFimLDLI(ListaDLI *pontLista) {
    if (pontLista->tamanho == 0) {  // VAZIA
        printf("Impossivel retornar o valor do fim de uma lista vazia. Retornando -1\n");
        return -1;
    } else {  // 1 OU + DE 1 ELEM
        return pontLista->fim->valor;
        // return (*pontLista).fim->valor;
        // return (*(*pontLista).fim).valor;
    }
}

int removerInicioLDLI(ListaDLI *pontLista) {
    if (pontLista->tamanho == 0) {  // VAZIA
        printf("Impossivel remover o noh do inicio de uma lista vazia. Retornando -1\n");
        return -1;
    } else {
        int valor = pontLista->inicio->valor;
        if (pontLista->tamanho == 1) {  // 1 ELEM
            free(pontLista->inicio);  //  free(pontLista->fim);
            pontLista->inicio = NULL;
            pontLista->fim = NULL;
        } else {  // + DE 1 ELEM
            pontLista->inicio = pontLista->inicio->proximo;
            free(pontLista->inicio->anterior);
            pontLista->inicio->anterior = NULL;
        }
        pontLista->tamanho--;
        return valor;
    }
}

int removerFimLDLI(ListaDLI *pontLista){
    if(pontLista->tamanho == 0){ //lista vazia
        printf("impossivel remover um noh do fim de uma lista vazia, Retornando -1\n");
        return -1;
    }else{
        int valor = pontLista->fim->valor;
        if(pontLista->tamanho == 1){ //lista com apenas 1 elemento
            free(pontLista->fim);
            pontLista->inicio = NULL;
            pontLista->fim = NULL;
        }else{ //lista com mais de 1 elemento
            pontLista->fim = pontLista->fim->anterior;
            free(pontLista->fim->proximo);
            pontLista->fim->proximo = NULL;
        }
        pontLista->tamanho--;
        return valor;
    }
}


// Caso a lista esteja vazia deve avisar o usuário e fazer nada
// Caso a posição seja < 0 deve avisar o usuario e fazer nada
// Caso a posição seja >= tamanho deve avisar o usuario e fazer nada
// Caso a posição seja válida, deve inserir o valor recebido na 
//   posição desejada

// ver se pedir inserir posicao 0 e no fim (tamanho - 1) funcionam

void inserirPosicaoLDLI(int valor, int posicao, ListaDLI *pontLista) {
    if (pontLista->tamanho == 0) {  // VAZIA
        printf("Impossivel inserir o valor %d na posicao %d de uma lista vazia.\n", valor, posicao);
    } else {
        if (posicao < 0) {
            printf("Impossivel inserir o valor %d na posicao negativa %d. Valores validos entre 0 e %d.\n", 
                                valor, posicao, pontLista->tamanho - 1);
        } else {
            if (posicao >= pontLista->tamanho) {
                printf("Impossivel inserir o valor %d na posicao %d. Valores validos entre 0 e %d.\n", 
                                valor, posicao, pontLista->tamanho - 1);
            } else {  // POSICAO VALIDA
                // 1 OU + DE 1 ELEM
                NoDLI* aux = pontLista->inicio;
                int cont = 0;
                while (cont < posicao) {
                    aux = aux->proximo;
                    cont++;
                }
                NoDLI* novo = criarNoDLI(valor, aux->anterior, aux);
                if (aux != pontLista->inicio) {  // aux nao estah no 1o noh
                    aux->anterior->proximo = novo;
                } else { // aux estah no 1o noh
                    pontLista->inicio = novo;
                }
                aux->anterior = novo;
                pontLista->tamanho++;
            }
        }
    }
}


// Caso a lista esteja vazia deve avisar o usuário e retornar -1
// Caso a posição seja < 0 deve avisar o usuário e retornar -1
// Caso a posição seja >= tamanho deve avisar o usuário e retornar -1
// Caso a posição seja válida, deve retornar o valor da posição desejada
int getValorPosicaoLDLI(int posicao, ListaDLI *pontLista) {
    int retorno = -1;
    if (pontLista->tamanho == 0) {  // VAZIA
        printf("Impossivel pegar o valor da posicao %d de uma lista vazia. \
            Retornando -1.", posicao);
    } else {
        if (posicao < 0) {
            printf("Impossivel pegar o valor da posicao negativa %d. \
                        Valores validos entre 0 e %d. Retornando -1.", 
                                posicao, pontLista->tamanho - 1);
        } else {
            if (posicao >= pontLista->tamanho) {
                printf("Impossivel pegar o valor da posicao %d. \
                        Valores validos entre 0 e %d. Retornando -1.", 
                                posicao, pontLista->tamanho - 1);
            } else {  // POSICAO VALIDA
                // 1 OU + DE 1 ELEM
                NoDLI * aux = pontLista->inicio;
                int cont = 0;
                while (cont < posicao) {
                    aux = aux->proximo;
                    cont++;
                }
                retorno =  aux->valor;
            }
        }
    }
    return retorno;
}