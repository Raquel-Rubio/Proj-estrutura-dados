#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//cria estrutura do tipo nó
typedef struct no{

    int CodSol;
    char CodEqui[7];
    char NomeEqui[21];
    int Prioridade; //prioridade, de 1 (maior) a 3 (menor)
    int Periodo; //periodo de tempo que o equipamento pode ficar no reparo;

    struct no *prox;

}No

//cria strutura tipo lista
typedef struct lista{

    No *inicio;

}Lista


Lista* CriaLista(){

    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    aux->inicio = NULL;
    return aux;

}

//imprime um unico item, recebe fila e o indice (definido pelo AchaItem
void ImprimeItem(No *aux){

    printf("\nImpressão de um único nó");
    printf("\nCódigo de Solicitação: %d\n", aux->CodSol);
    printf("Código do Equipamento: %s\n", aux->CodEqui);
    printf("Nome do Equipamento: %s\n", aux->NomeEqui);
    printf("Prioridade do Reparo do Equipamento: %d\n", aux->Prioridade);
    printf("Periodo do Reparo do Equipamento: %d dias\n", aux->Periodo);

}

// verifica se a lista ta vazia
int vaziaLista (Lista *l)
{
    if(l != NULL)
    {
        if(l->inicio == NULL)
        {
            return 1;
        }
        return 0;
    }
    printf("\n\n\nERRO\n\n\n\n");
    exit(1);
}

//esvasia td a lista, devolve apenas uma fila sem inicio
Lista* liberaLista (Lista* l)
{
    No *aux = l -> inicio;

    if(!vaziaLista(l))
    {
        while(l->inicio!=NULL){
            aux = l->inicio;
            l->inicio = l->inicio->prox;
            free(aux);
        }
        free(l);
    }
}

#endif // LISTA_H_INCLUDED
