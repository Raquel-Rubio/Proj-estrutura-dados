#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct dados{
    int CodSoli; //codigo de solicitação
    char CodEqui[7]; //codigo do equipamento
    char NomeEqui[21]; //nome do equipamento
    int Prioridade; //Prioridade, nível de 1 (maior) a 3 (menor)
    int Periodo; //Definido apartir da prioridade
}Dados;

typedef struct no{
    Dados info;
    struct no *prox;
}No;

typedef struct lista{
    No *inicio;
}Lista

Lista* CriaLista(void){
     Lista *l;
     l=(Lista*)malloc(sizeof(Lista));
     l->inicio = NULL;
   return l;
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

void ImprimeItem(Dados info){
    printf("\nCódigo de Solicitação: %d\n", info.CodSoli);
    printf("Código do Equipamento: %s\n", info.CodEqui);
    printf("Nome do Equipamento: %s\n", info.NomeEqui);
    printf("Prioridade do Reparo do Equipamento: %d\n", info.Prioridade);
    printf("Periodo do Reparo do Equipamento: %d dias\n", info.Periodo);

}

void ImprimeLista(Lista *l){
    printf("\n\nIMPRIME LISTA.");
    No* aux;
    aux = l->inicio;
    while(aux != NULL){
        ImprimeItem(aux->info);
        aux = aux->prox;
    }
}

//funçao que insere
void inserir (Fila *F, Dados Infos){ //tras a fila e um item do tipo no que deve ter tds as informações a serem inseridas
    No *novo = (No*)malloc(sizeof(No)); //aloca espaço de novo nó e transfere tds as suas informações
    novo->info = Infos;
    novo->prox = NULL;
    //ImprimeItem(novo->info);

    No *aux;
    No *aux2=NULL;
    aux = F ->inicio;
    while(aux!=NULL && aux->info.CodSoli < Infos.CodSoli){
        aux2 = aux;
        aux = aux->prox;
    }


    novo->prox = aux;
    if(aux2 == NULL){
        F->inicio = novo;
    }
    else{
        aux2->prox = novo;
    }
}

//esvasia td a fila, devolve apenas uma fila sem inicio
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
//verifica se um codigo de solicitação ja está sendo usado, se tiver devolve 1, se estiver liberado devolve 0
int DisponivelCod(Lista *l, int codigo){

    No *aux = l->inicio;
    int indice=0;
    while(aux->info.CodSoli == codigo){
        indice = 1;
        aux = aux->prox;
    }
    return indice;

}

//encontra onde esta um item pelo codigo de solicitação, devolve no, se n tiver devolve NULL
void AchaItemNo(Lista *f, int codigo){

    printf("\nAcha no");
    No *aux = f->inicio;
    while(aux!=NULL && aux->info.CodSoli != codigo){
        aux = aux->prox;
    }
    if (aux->info.CodSoli != codigo){
        printf("Nao existe soliciacao com este no");
    }
    else{
        ImprimeItem(aux->info);
    }
}

#endif // LISTA_H_INCLUDED
