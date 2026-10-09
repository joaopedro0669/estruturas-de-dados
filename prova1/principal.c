#include <stdio.h>
#include <stdlib.h>
#include "listaSLI.h"
#include "listaDLI.h"

int buscarIndice(ListaSLI *lista, int valor);
ListaSLI* copiarListaSemRepeticao(ListaSLI *lista);
void moverParaInicio(ListaDLI *lista, int valor);

int main() {
    //Lista Simplesmente Ligada
    
    ListaSLI* head = criarListaSLI();
    int posicao, valor, escolha = 0;
    while(1){
        system("clear");
        mostrarLSLI(head);
        printf("1 - Adicionar no final\n2 - Buscar indice\n3 - Copiar sem repetições\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("Valor: ");
            scanf("%d", &valor);
            inserirFimLSLI(valor, head);
            break;

        case 2:
            printf("Valor: ");
            scanf("%d", &valor);
            posicao = buscarIndice(head, valor);
            printf("Posicao: %d", posicao);
            scanf("%d", &posicao);
            break;

        case 3:
            ListaSLI* novaLista = copiarListaSemRepeticao(head);
            //head = copiarListaSemRepeticao(head);
            mostrarLSLI(novaLista);
            scanf("%d", &posicao);
            break;
        default:
            break;
        }
    }
    

    //Lista Duplamente Ligada
    /*
    ListaDLI* head = criarListaDLI();
    int valor, escolha = 0;
    while(1){
        system("clear");
        mostrarLDLI(head);
        printf("1 - Adicionar no final\n2 - Mover Para Início\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("Valor: ");
            scanf("%d", &valor);
            inserirFimLDLI(valor, head);
            break;

        case 2:
            printf("Valor: ");
            scanf("%d", &valor);
            moverParaInicio(head, valor);
            break;

        default:
            break;
        }
    }
    */
    return 0;
}