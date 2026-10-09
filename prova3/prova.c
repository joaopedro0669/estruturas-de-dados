#include "listaPrioridade.h"

/**
 * QUESTÃO 1 (Adicionar Tarefa):
 * Recebe a ListaPrioridades, o nível de prioridade e o ID da tarefa.
 * 1. Procure na ListaPrioridades se já existe um nó com este 'nivel'.
 * 2. Se existir, insira a tarefa na fila desse nó.
 * 3. Se NÃO existir:
 * - Crie um novo nó (NoPrio).
 * - Insira a tarefa na fila desse nó.
 * - Adicione o novo nó no INÍCIO da ListaPrioridades.
 */
void adicionarTarefa(ListaPrioridades *lp, int nivel, int idTarefa) {
    // TODO: Implementar sua solução aqui
    NoPrio* aux_prio = lp->inicio;
    while(aux_prio){
        if(aux_prio->nivel == nivel)
            break;
        aux_prio = aux_prio->proximo;
    }
    if(aux_prio) { //achou o nível
        inserirFilaLSLI(idTarefa, aux_prio->filaTarefas);
    }
    else {
        NoPrio* novo = malloc(sizeof(NoPrio));
        novo->filaTarefas = NULL;
        novo->nivel = nivel;
        novo->proximo = lp->inicio;
        lp->inicio = novo;
        novo->filaTarefas = criarFilaLSLI();
        inserirFilaLSLI(idTarefa, novo->filaTarefas);
    }
}

/**
 * QUESTÃO 2 (Processar Tarefa):
 * Remove e retorna a próxima tarefa de um nível específico da ListaPrioridades.
 * 1. Busque o nó correspondente ao 'nivel' desejado na ListaPrioridades.
 * - Se não achar, retorne -1.
 * - Se achar, remova o próximo elemento da fila desse nó.
 * 2. LIMPEZA: Se, após a remoção, a fila deste nível ficar VAZIA, remova o nó
 * deste nível da ListaPrioridades, cuidando para não "quebrar" a ListaPrioridades.
 * Retorno: O ID da tarefa removida ou -1 em caso de não encontrar.
 */
int processarTarefaDoNivel(ListaPrioridades *lp, int nivel){
    // TODO: Implementar sua solução aqui
    NoPrio* aux_prio = lp->inicio;
    while(aux_prio){
        if(aux_prio->nivel == nivel)
            break;
        aux_prio = aux_prio->proximo;
    }
    if(aux_prio){
        int valor = removerFilaLSLI(aux_prio->filaTarefas); //remove o elemento
        
        if(!aux_prio->filaTarefas->inicio){ //se não existir mais elementos na fila
            //apagar o nó prio
            NoPrio* aux_prio_2 = lp->inicio;
            if(aux_prio_2 == aux_prio){ //se o nó for o primeiro
                NoPrio* apagar = aux_prio;
                lp->inicio = aux_prio->proximo;
                free(apagar);
            }
            else{ //caso não estejamos no primeiro nó...
                while(aux_prio_2->proximo){
                    if(aux_prio_2->proximo == aux_prio) //...pega um anterior ao nó que queremos remover...
                        break; //break é vida
                    aux_prio_2 = aux_prio_2->proximo;
                }
                NoPrio* apagar = aux_prio; //...fala qual vamos apagar...
                aux_prio_2->proximo = aux_prio->proximo; //...fala que o próximo do anterior é o próximo do que vamos apagar...
                free(apagar); //...apaga
            }
        }

        return valor;
    }
    else
        return -1; 
}
