#include <stdio.h>
#include <stdlib.h>
#include "pilhaLSLI.h"
#include "filaLSLI.h"

// =============================================================================
// QUESTÕES DE PROVA (35 PONTOS)
// =============================================================================

/**
 * Q1: Implemente uma função que receba duas pilhas e verifica se elas são
 * idênticas (mesmo tamanho e mesmos elementos na mesma ordem).
 * As pilhas originais devem ser preservadas ao final da execução 
 * (não podem terminar vazias ou alteradas). Não é permitido criar vetores ou 
 * filas auxiliares. Pilhas podem ser criadas.
 * Retorno: 1 se iguais, 0 se diferentes.
 */
int saoIguais(PilhaLSLI *p1, PilhaLSLI *p2) {
    // TODO: Implementar
    if(p1->tamanho != p2->tamanho){ //se tiverem tamanhos diferentes
        return 0;
    }
    else if(!p1->topo && !p2->topo){ //se ambas não existirem, são iguais
        return 1;
    }
    else if ( (!p1->topo && p2->topo) || (p1->topo && !p2->topo) ){//se uma existir e a outra não, não são iguais
        return 0;
    }
    else if (p1->topo && p2->topo) { //se as duas existirem...
        NoSLI *aux1 = p1->topo;
        NoSLI *aux2 = p2->topo;
        
        while(aux1 || aux2){
            if(aux1->valor != aux2->valor){ //se for diferentes, não são iguais
                return 0;
            }
            aux1 = aux1->proximo;
            aux2 = aux2->proximo;
        }
        return 1;
    }
    return 0;
}

/**
 * Q2: Implemente uma função que rotaciona a fila 'f' 'n' vezes.
 * Uma rotação consiste em remover o primeiro elemento e inseri-lo no fim.
 * Ex: Entrada P[1, 2, 3, 4, 5], n=2 → Saída P[3, 4, 5, 1, 2]
 */
void rotacionarFila(int n, FilaLSLI *f) {
    // TODO: Implementar
    int valor;
    if(f->inicio){
        for(int i = 0; i < n; i++){
            valor = removerFilaLSLI(f);
            inserirFilaLSLI(valor, f);
        }
    }
}

/**
 * Q3: Implemente uma função que inverte a ordem dos elementos de uma fila.
 * Ex: Fila P[1, 2, 3, 4] vira P[4, 3, 2, 1].
 * Não é permitido criar vetores ou filas auxiliares. Pilhas podem ser criadas.
 */
void inverterFila(FilaLSLI *f) {
    // TODO: Implementar
    PilhaLSLI *aux = criarPilhaLSLI();
    int valor;
    while(f->inicio){
        valor = removerFilaLSLI(f);
        empilharPLSLI(valor, aux);
    }
    while(aux->topo){
        valor = desempilharPLSLI(aux);
        inserirFilaLSLI(valor, f);
    }
    free(aux);
}
