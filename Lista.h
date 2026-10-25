#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct dados{
    int CodSoli;
    char CodEqui[7];
    char NomeEqui[21];
    int Prioridade;
    int Periodo;
}Dados;

typedef struct no{
    Dados info;
    struct no *prox;
}No;

typedef struct lista{
    No *inicio;
}Lista;

Lista* CriaLista(void){
     Lista *l;
     l=(Lista*)malloc(sizeof(Lista));
     l->inicio = NULL;
   return l;
}

Lista* liberaLista (Lista* l)
{
    No *aux;
    while(l->inicio!=NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    free(l);
    return NULL;

}


void ImprimeItem(Dados info){
    printf("\nCódigo de Solicitação: %d\n", info.CodSoli);
    printf("Código do Equipamento: %s\n", info.CodEqui);
    printf("Nome do Equipamento: %s\n", info.NomeEqui);
    printf("Prioridade do Reparo do Equipamento: %d\n", info.Prioridade);
    printf("Periodo do Reparo do Equipamento: %d dias\n", info.Periodo);

}

void ImprimeLista(Lista *l){
    printf("\n\nImprimir Lista\n");
    No* aux;
    aux = l->inicio;
    if (aux==NULL){
        printf("\nA lista está vazia\n");
    }else{
        while(aux != NULL){
            ImprimeItem(aux->info);
            aux = aux->prox;
        }
    }
}

void inserir (Lista *L, Dados Infos){
    No *novo = (No*)malloc(sizeof(No));
    novo->info = Infos;
    novo->prox = NULL;


    No *aux;
    No *aux2=NULL;
    aux = L ->inicio;
    while(aux!=NULL && aux->info.CodSoli < Infos.CodSoli){
        aux2 = aux;
        aux = aux->prox;
    }


    novo->prox = aux;
    if(aux2 == NULL){
        L->inicio = novo;
    }
    else{
        aux2->prox = novo;
    }
}


int DisponivelCod(Lista *l, int codigo){

    No *aux = l->inicio;
    while(aux != NULL){
        if(aux->info.CodSoli == codigo){
            printf("\nEsse código ja está em uso\n");
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

int AchaItemNo(Lista *l, int codigo){

    printf("\nSolicitação código %d\t", codigo);
    No *aux = l->inicio;
    while(aux!=NULL && aux->info.CodSoli != codigo){
        aux = aux->prox;
    }
    if (aux == NULL){
        printf("\tNão existe solicitação com este código\n");
        return 0;
    }
    else{
        printf("\n");
        ImprimeItem(aux->info);
        return 1;
    }
}

int AchaPrioPeri (int Q, Lista *l, int codigo){
     printf("\nSolicitação código %d\t", codigo);
    No *aux = l->inicio;
    while(aux!=NULL && aux->info.CodSoli != codigo){
        aux = aux->prox;
    }
    if (aux == NULL){
        printf("Nao existe solicitacao com este código\n");
        return 0;
    }
    else{
        printf("\n");
        ImprimeItem(aux->info);
        if(Q==1){
            return aux->info.Periodo;
        }
        else{
            return aux->info.Prioridade;
        }
    }
}

void Modifica(Lista *l, int codigo, int Prioridade, int Periodo){
    No *aux = l->inicio;
    while(aux!=NULL && aux->info.CodSoli != codigo){
        aux = aux->prox;
    }
    aux->info.Prioridade=Prioridade;
    aux->info.Periodo=Periodo;

    ImprimeItem(aux->info);
}

void RemoverSoli(Lista *l, int codigo){
    No *aux = l->inicio;
    No *anterior = NULL;
    while(aux!=NULL && aux->info.CodSoli != codigo){
        anterior = aux;
        aux = aux->prox;
    }
    if(anterior == NULL){
        l->inicio = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }

    free(aux);
    printf("\nSolicitação removida!\n");
}

void OrdemManutencao(Lista *L){
    if(L == NULL){
        printf("Erro: Lista inválida.\n");
        return;
    }
    Lista *Ordem = CriaLista();
    No *orig = L->inicio;

    while(orig != NULL){
        No *novo = (No*)malloc(sizeof(No));

        novo->info = orig->info;
        novo->prox = NULL;

        No *anterior = NULL;
        No *aux = Ordem->inicio;
        while(aux != NULL &&
              (aux->info.Prioridade < novo->info.Prioridade ||
               (aux->info.Prioridade == novo->info.Prioridade &&
                (aux->info.Periodo < novo->info.Periodo ||
                 (aux->info.Periodo == novo->info.Periodo &&
                  aux->info.CodSoli <= novo->info.CodSoli))))){
            anterior = aux;
            aux = aux->prox;
        }

        novo->prox = aux;
        if(anterior == NULL){
            Ordem->inicio = novo;
        } else {
            anterior->prox = novo;
        }

        orig = orig->prox;
    }

    ImprimeLista(Ordem);
    liberaLista(Ordem);
}

#endif // LISTA_H_INCLUDED
