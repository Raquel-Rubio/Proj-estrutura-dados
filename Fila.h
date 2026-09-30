#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

//Cria estrutura de no
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

//Cria estrutura fila
typedef struct fila{
    No *inicio;
}Fila;

//Inicializa estrutura fila
Fila* CriaFila (void)
{
     Fila *f;
     f=(Fila*)malloc(sizeof(Fila));
     f->inicio = NULL;
   return f;
}

// verifica se a fila ta vazia
int vaziaFila (Fila *f)
{
    if(f != NULL)
    {
        if(f->inicio == NULL)
        {
            return 1;
        }
        return 0;
    }
    printf("\n\n\nERRO\n\n\n\n");
    exit(1);
}

//imprime um unico item, recebe o no (tem que estar alocado)
void ImprimeItem(Dados info){

    printf("\nImpressão de um único nó");
    printf("\nCódigo de Solicitação: %d\n", info.CodSoli);
    printf("Código do Equipamento: %s\n", info.CodEqui);
    printf("Nome do Equipamento: %s\n", info.NomeEqui);
    printf("Prioridade do Reparo do Equipamento: %d\n", info.Prioridade);
    printf("Periodo do Reparo do Equipamento: %d dias\n", info.Periodo);

}

void ImprimeLista(Fila *F){
    printf("NEM TENTEI.");
    No* aux;
    aux = F->inicio;
    while(aux != NULL){
        ImprimeItem(aux->info);
        aux = aux->prox;
        printf("TENTEI.");
    }
    printf("EU TENTEI!2");
}

//funçao que insere, nao verifica nada (INCOMPLETA)
void inserir (Fila *F, No *Infos){ //tras a fila e um item do tipo no que deve ter tds as informações a serem inseridas

    No *novo = (No*)malloc(sizeof(No)); //aloca espaço de novo nó e transfere tds as suas informações
    novo->info = Infos->info;
    novo->prox = NULL;
    ImprimeItem(novo->info);

    No *aux;
    No *aux2=NULL;
    aux = F ->inicio;
    while(aux!=NULL && aux->info.CodSoli < Infos->info.CodSoli){
        aux2 = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if(aux2 == NULL){
        F->inicio->prox = novo;
    }
    else{
        aux2->prox = novo;
    }
}

//esvasia td a fila, devolve apenas uma fila sem inicio
Fila* liberaFila (Fila* f)
{
    No *aux = f -> inicio;

    if(!vaziaFila(f))
    {
        while(f->inicio!=NULL){
            aux = f->inicio;
            f->inicio = f->inicio->prox;
            free(aux);
        }
        free(f);
    }
}
//verifica se um codigo de solicitação ja está sendo usado, se tiver devolve 1, se estiver liberado devolve 0
int DisponivelCod(Fila *f, int codigo){

    No *aux = f->inicio;
    int indice=0;
    while(aux->info.CodSoli == codigo){
        indice = 1;
        aux = aux->prox;
    }
    return indice;

}

//encontra onde esta um item pelo codigo de solicitação, devolve no, se n tiver devolve NULL
No* AchaItemNo(Fila *f, int codigo){

    No *aux = f->inicio;
    while(aux!=NULL || aux->info.CodSoli != codigo){
        aux = aux->prox;
    }
    if (aux->info.CodSoli != codigo){
        aux = NULL;
    }
    ImprimeItem(aux->info);
    return aux;
}



#endif // FILA_H_INCLUDED
