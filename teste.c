#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Fila.h"

int main(){

    //printf("\n24\n");
    Fila *F;
    F = CriaFila();

    //No testar = {1001, "string", "nomess", 2, 14, NULL};



    No *testar;
    //testar = (No*)malloc(sizeof(No));

    testar->CodSoli = 1001;
    strcpy(testar->CodEqui, "string");
    strcpy(testar->NomeEqui, "nomess");
    testar->Prioridade = 2;
    testar->Periodo = 15;
    testar->prox = NULL;

    ImprimeItem(testar);

    inserir(F, testar);

    No *aux = (No*)malloc(sizeof(No));
    aux = AchaItemNo(F, 1001);

    ImprimeItem(aux);

    F = liberaFila(F);
    free(testar);
    free(aux);
    return 0;
}
