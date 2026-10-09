#include <stdio.h>
#include <stdlib.h>
#include "listaSLI.h"
#include "listaDLI.h"

// =============================================================================
// QUESTÕES SOBRE LISTA SIMPLESMENTE LIGADA
// =============================================================================

/**
 * Q1: Percorre a lista simplesmente ligada e retorna o índice da primeira ocorrência de 'valor'.
 * Retorna -1 se não encontrar ou a lista estiver vazia.
 */
int buscarIndice(ListaSLI *lista, int valor) {
    // TODO: Implementar
    int indice = -1;
    if(lista->inicio){
        int tam = lista->tamanho;
        NoSLI* aux = lista->inicio;

        for(int i = 0; i < tam && aux; i++){
            if(aux->valor == valor){
                indice = i;
                break;
            }
            aux = aux->proximo;
        }
    }
        return indice;
    
}

/**
 * Q2: Cria e retorna uma NOVA lista contendo os elementos da lista original
 * mas SEM valores repetidos.
 * A lista original não deve ser alterada.
 */
ListaSLI* copiarListaSemRepeticao(ListaSLI *lista) {
    // TODO: Implementar
    ListaSLI* novaLista = criarListaSLI();
    NoSLI* aux = lista->inicio;
    int verificacao = 0;
    while(aux){
        verificacao = buscarIndice(novaLista, aux->valor);
        if(verificacao == -1){
            inserirFimLSLI(aux->valor, novaLista);
        }
        aux = aux->proximo;
    }

    return novaLista;
}

// =============================================================================
// QUESTÃO SOBRE LISTA DUPLAMENTE LIGADA
// =============================================================================

/**
 * Q3: Encontra o nó com 'valor' e o move para a primeira posição.
 * Não crie novos nós nem troque os valores inteiros, manipule apenas os ponteiros.
 * Se o valor já estiver no início ou não existir ou a lista estiver vazia, não faça nada.
 */
void moverParaInicio(ListaDLI *lista, int valor) {
    // TODO: Implementar
    if(lista->inicio){
        NoDLI* aux = lista->inicio;
        int encontrou = 0;
        if(aux->valor != valor){
            aux = aux->proximo;
            for(int i = 1; aux; i++){
                if(aux->valor == valor){
                    break;
                }
                aux = aux->proximo;
            }
            if(aux){
                if(aux->proximo)
                    aux->proximo->anterior = aux->anterior;
                else
                    lista->fim = aux->anterior;

                aux->anterior->proximo = aux->proximo;
                aux->anterior = NULL;
                aux->proximo = lista->inicio;
                lista->inicio->anterior = aux;
                lista->inicio = aux;
            }
        }
    }
}