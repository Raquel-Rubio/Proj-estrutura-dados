#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Lista.h"
#include<locale.h>


void limpando_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int PegarInteiro(){
    int extra, loop=0;
    while(loop==0){
        if(scanf(" %d", &extra)==0){
                printf("\nPor favor insira um valor válido\n\t");
                limpando_buffer();
        }
        else{
            loop=1;
            return extra;
        }
    }
}

int main(){
    setlocale(LC_ALL, "portuguese");

    int loop = 1, seletor;
    Lista *L = CriaLista();


    while(loop != 0) {
        printf("\n\tSistema de Cadastro de Manutenção\n\n");

        printf("Escolha o procedimento:\n\t");
        printf("1 – Inserir uma Solicitação de Manutenção\n\t");
        printf("2 – Remover uma Solicitação\n\t");
        printf("3 – Consultar uma Solicitação\n\t");
        printf("4 – Alterar a prioridade e/ou período de uma Solicitação\n\t");
        printf("5 – Exibir a ordem da realização da manutenção\n\t");
        printf("6 – Exibir todas as solicitações\n\t");
        printf("0 – Finalizar\n\n\t");


        seletor = PegarInteiro();
        limpando_buffer();

            switch(seletor){

            case 0:
                loop = 0;
                printf("\n\n\t\tObrigado por usar nosso sistema\n\n");
                break;

            case 1:
                printf("\nINSERIR UMA SOLICITAÇÃO\n");
                No *aux;
                int extra;
                     do{
                        printf("Por favor insira o Código de Solicitação válido: ");
                        extra = PegarInteiro();
                    }while(extra<999 || extra>9999);
                printf("\n\nTESTE");
                //aux->info.CodSoli = extra;
                printf("\n\n\n\nTESTE");

                break;

            case 2:
                printf("caso n2");
                break;

            case 3:
                printf("caso n3");
                break;

            case 4:
                printf("caso n4");
                break;

            case 5:
                printf("caso n5");
                break;

            case 6:
                ImprimeLista(L);
                break;
            }

    }
    return 0;
}
