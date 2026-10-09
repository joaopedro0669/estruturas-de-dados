#include "listaPrioridade.h"

void adicionarTarefa(ListaPrioridades *lp, int nivel, int idTarefa);
int processarTarefaDoNivel(ListaPrioridades *lp, int nivel) ;

int main() {
    ListaPrioridades* lista = criarListaPrioridades();
    while(1){
        //system("clear");
        mostrarListaPrioridades(lista);
        printf("1 - Inserir\n2 - Remover\n");
        int escolha = 0;
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("Nivel: ");
                int nivel;
                scanf("%d", &nivel);
                printf("Id: ");
                int id;
                scanf("%d", &id);

                adicionarTarefa(lista, nivel, id);
                break;
            case 2:
                printf("Nivel: ");
                int nivel2;
                scanf("%d", &nivel2);

                printf("Retorno: %d\n", processarTarefaDoNivel(lista, nivel2));
                
                break;
        }
    }
    return 0;
}
