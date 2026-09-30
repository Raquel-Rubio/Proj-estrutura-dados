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
    testar = (No*)malloc(sizeof(No));

    testar->info.CodSoli = 1001;
    strcpy(testar->info.CodEqui, "string");
    strcpy(testar->info.NomeEqui, "nomess");
    testar->info.Prioridade = 2;
    testar->info.Periodo = 15;
    testar->prox = NULL;

    //ImprimeItem(testar);

    inserir(F, testar);
    ImprimeLista(F);
    No *aux = (No*)malloc(sizeof(No));
    aux = AchaItemNo(F, 1001);

    //ImprimeItem(aux);


    F = liberaFila(F);
    free(testar);
    free(aux);
    return 0;
}
