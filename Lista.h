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
}Lista;

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

//funçao que insere
void inserir (Lista *L, Dados Infos){ //tras a fila e um item do tipo no que deve ter tds as informações a serem inseridas
    No *novo = (No*)malloc(sizeof(No)); //aloca espaço de novo nó e transfere tds as suas informações
    novo->info = Infos;
    novo->prox = NULL;
    //ImprimeItem(novo->info);

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

//esvazia td a fila, devolve apenas uma fila sem inicio
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
//verifica se um codigo de solicitação ja está sendo usado, se tiver devolve 1, se estiver liberado devolve 0
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

//encontra onde esta um item pelo codigo de solicitação, devolve no, se n tiver devolve NULL
int AchaItemNo(Lista *l, int codigo){

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
        return 1;
    }
}

void Modifica(Lista *l, int codigo, int Prioridade, int Periodo){
    No *aux = l->inicio;
    while(aux!=NULL && aux->info.CodSoli != codigo){
        aux = aux->prox;
    }
    aux->info.Prioridade=Prioridade;
    aux->info.Periodo=Periodo;
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
void limpando_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int PegarInteiros(){
    int PI, voltaInteiros=0;
    while(voltaInteiros==0){
        if(scanf(" %d", &PI)==0){
                limpando_buffer();
                printf("\nPor favor insira um valor válido:   ");
        }
        else{
            voltaInteiros=1;
            //printf("\n PegaInt dentro de PegarInteiro: %d\n\n", PI);
            return PI;
        }
    }
}

char PegarCaracter(int i){
    int voltaChar=0;
    char c;
    if(i==0){
        while(voltaChar == 0){
            c = getch();
            if(isalpha(c)!= 0){
                printf("%c", c);
                voltaChar = 1;
                return c;
            }
            if(c==13){
                return '\0';
            }
            printf("\nÉ necessário que seja uma letra:   ");
        }
    }
    else{
        while(voltaChar == 0){
            c = getch();
            if(isalpha(c)!= 0 || c==32){
                printf("%c", c);
                voltaChar = 1;
                return c;
            }
            if(c==13){
                return '\0';
            }
            printf("\nÉ necessário que seja uma letra:   ");
        }
    }
}

char PegarUMInteiro(){
        int voltaUMInt=0;
    char c;
    while(voltaUMInt == 0){
        c = getch();
        if(isdigit(c)!= 0){
            voltaUMInt = 1;
            printf("%c", c);
            return c;
        }
        printf("\nÉ necessário que seja um número:   ");
    }

}

int VerificaSoli(){
int verif;
    do{
        printf("\nInsira o Código de Solicitação:   ");
        verif = PegarInteiros();
        limpando_buffer();
    }while(verif<999 || verif>9999);
    return verif;
}

int VerificaPriori(){
    int verif;
    do{
        printf("\n\nPor favor insira o nível de Prioridade (1 a 3):   ");
        verif = PegarInteiros();
        limpando_buffer();
    }while(verif<1 || verif>3);
    return verif;
}

int VerificaPeriodo(int priori){
    int verif;
    if(priori==3){
        do{
            printf("\nPor favor insira o Período (1 a 20):   ");
            verif = PegarInteiros();
        }while(verif < 1 || verif > 20);

        return verif;

    }else{
        if(priori==2){
            do{
                printf("\nPor favor insira o Período (1 a 15):   ");
                verif = PegarInteiros();
            }while(verif < 1 || verif > 15);

            return verif;

        }else{
            do{
                printf("\nPor favor insira o Período (1 a 7):   ");
                verif = PegarInteiros();
            }while(verif < 1 || verif > 7);

          return verif;

        }
    }
}
#endif // LISTA_H_INCLUDED
