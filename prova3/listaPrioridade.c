#include "listaPrioridade.h"

ListaPrioridades* criarListaPrioridades() {
    ListaPrioridades *novo = (ListaPrioridades*) malloc(sizeof(ListaPrioridades));
    novo->inicio = NULL;
    novo->qtdNiveis = 0;
    return novo;
}

void mostrarListaPrioridades(ListaPrioridades *lp) {
    if (lp->inicio == NULL) {
        printf("Sistema Vazio.\n");
        return;
    }
    printf("=== STATUS DO SISTEMA ===\n");
    NoPrio *aux = lp->inicio;
    while (aux != NULL) {
        printf(">> [Nivel %d]: ", aux->nivel);
        mostrarFilaLSLI(aux->filaTarefas);
        aux = aux->proximo;
    }
    printf("=========================\n");
}

void destruirListaPrioridades(ListaPrioridades *lp) {
    NoPrio *atual = lp->inicio, *temp;
    while (atual != NULL) {
        temp = atual;
        atual = atual->proximo;
        destruirFilaLSLI(temp->filaTarefas);
        free(temp);
    }
    free(lp);
}