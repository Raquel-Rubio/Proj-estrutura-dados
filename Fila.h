#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

//Cria estrutura de no
typedef struct no{

    int CodSoli; //codigo de solicitação
    char CodEqui[7]; //codigo do equipamento
    char NomeEqui[21]; //nome do equipamento
    int Prioridade; //Prioridade, nível de 1 (maior) a 3 (menor)
    int Periodo; //Definido apartir da prioridade

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
void ImprimeItem(No *aux){

    printf("\nImpressão de um único nó");
    printf("\nCódigo de Solicitação: %d\n", aux->CodSoli);
    printf("Código do Equipamento: %s\n", aux->CodEqui);
    printf("Nome do Equipamento: %s\n", aux->NomeEqui);
    printf("Prioridade do Reparo do Equipamento: %d\n", aux->Prioridade);
    printf("Periodo do Reparo do Equipamento: %d dias\n", aux->Periodo);

}

void ImprimeLista(Fila){}

//funcçao que insere, nao verifica nada (INCOMPLETA)
void inserir (Fila *F, No *Infos){ //tras a fila e um item do tipo no que deve ter tds as informações a serem inseridas

    No *novo = (No*)malloc(sizeof(No)); //aloca espaço de novo nó e transfere tds as suas informações
    novo->CodSoli = Infos->CodSoli;
    strcpy(novo->CodEqui, Infos->CodEqui);
    strcpy(novo->NomeEqui, Infos->NomeEqui);
    novo->Prioridade = Infos->Prioridade;
    novo->Periodo = Infos->Periodo;
    novo->prox = NULL;

    ImprimeItem(novo);

    No *aux;
    No *aux2;
    aux = F ->inicio;
    while(aux!=NULL || aux->CodSoli < Infos->CodSoli){
        aux2 = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    aux2->prox = novo;
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
    while(aux->CodSoli == codigo){
        indice = 1;
        aux = aux->prox;
    }
    return indice;

}

//encontra onde esta um item pelo codigo de solicitação, devolve no, se n tiver devolve NULL
No* AchaItemNo(Fila *f, int codigo){

    No *aux = f->inicio;
    while(aux!=NULL || aux->CodSoli != codigo){
        aux = aux->prox;
    }
    if (aux->CodSoli != codigo){
        aux = NULL;
    }
    ImprimeItem(aux);
    return aux;
}



#endif // FILA_H_INCLUDED
