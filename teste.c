#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Fila.h"
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    //printf("\n24\n");
    Fila *F;
    F = CriaFila();

    //No testar = {1001, "string", "nomess", 2, 14, NULL};



    No *testar;
    //testar = (No*)malloc(sizeof(No));

    testar->info.CodSoli = 1001;
    strcpy(testar->info.CodEqui, "string");
    strcpy(testar->info.NomeEqui, "nomess");
    testar->info.Prioridade = 2;
    testar->info.Periodo = 15;
    testar->prox = NULL;

    testar->info.CodSoli = 1005;
    strcpy(testar->info.CodEqui, "string");
    strcpy(testar->info.NomeEqui, "nomess");
    testar->info.Prioridade = 2;
    testar->info.Periodo = 15;
    testar->prox = NULL;

    testar->info.CodSoli = 1003;
    strcpy(testar->info.CodEqui, "string");
    strcpy(testar->info.NomeEqui, "nomess");
    testar->info.Prioridade = 2;
    testar->info.Periodo = 15;
    testar->prox = NULL;

   // ImprimeItem(testar->info);

    inserir(F, testar->info);

    ImprimeLista(F);
    AchaItemNo(F, 1001);
    printf("NEM TENTEI.");
    //ImprimeItem(aux);


    F = liberaFila(F);
    free(testar);
    return 0;
}
