#include <stdio.h>
#include <stdlib.h>
#include "filaLSLI.h"
#include "pilhaLSLI.h"

int saoIguais(PilhaLSLI *p1, PilhaLSLI *p2) ;
void rotacionarFila(int n, FilaLSLI *f);
void inverterFila(FilaLSLI *f);

int main() {
    PilhaLSLI *p1 = criarPilhaLSLI();
    PilhaLSLI *p2 = criarPilhaLSLI();
    PilhaLSLI *p3 = criarPilhaLSLI();

    empilharPLSLI(1, p1);
    empilharPLSLI(2, p1);
    empilharPLSLI(3, p1);
    empilharPLSLI(4, p1);
    
    empilharPLSLI(1, p2);
    empilharPLSLI(2, p2);
    empilharPLSLI(3, p2);
    empilharPLSLI(4, p2);
    
    //printf("Retorno: %d\n", saoIguais(p1, p2));

    FilaLSLI *f = criarFilaLSLI();
    
    inserirFilaLSLI(1, f);
    inserirFilaLSLI(2, f);
    inserirFilaLSLI(3, f);
    inserirFilaLSLI(4, f);
    inserirFilaLSLI(5, f);
    inserirFilaLSLI(6, f);
    inserirFilaLSLI(7, f);
    inserirFilaLSLI(8, f);
    inserirFilaLSLI(9, f);
    inserirFilaLSLI(10, f);
    
    
    
    mostrarFilaLSLI(f);
    //rotacionarFila(2, f);
    inverterFila(f);
    mostrarFilaLSLI(f);



    return 0;
}
