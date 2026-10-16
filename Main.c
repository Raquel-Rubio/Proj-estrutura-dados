#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include "Lista.h"
#include<locale.h>


void limpando_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int PegarInteiros(){
    int PI, voltaInteiros=0;
    while(voltaInteiros==0){
        if(scanf(" %d", &PI)==0){
                limpando_buffer();
                printf("\nPor favor insira um valor válido: \t");
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
                voltaChar = 1;
                return c;
            }
            if(c==13){
                return '\0';
            }
            printf("\nÉ necessário que seja uma letra \t");
        }
    }
    else{
        while(voltaChar == 0){
            c = getch();
            if(isalpha(c)!= 0 || c==32){
                voltaChar = 1;
                return c;
            }
            if(c==13){
                return '\0';
            }
            printf("\nÉ necessário que seja uma letra \t");
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
            return c;
        }
        printf("\nÉ necessário que seja um número \t");
    }

}


int main(){
    setlocale(LC_ALL, "Portuguese");

    int loop = 1, seletor;
    Lista *L = CriaLista();


    while(loop != 0) {
        printf("\n\tSistema de Cadastro de Manutenção\n\n");

        printf("Escolha o procedimento:\n\t");
        printf("1 - Inserir uma Solicitação de Manutenção\n\t");
        printf("2 - Remover uma Solicitação\n\t");
        printf("3 - Consultar uma Solicitação\n\t");
        printf("4 - Alterar a prioridade e/ou período de uma Solicitação\n\t");
        printf("5 - Exibir a ordem da realização da manutenção\n\t");
        printf("6 - Exibir todas as solicitações\n\t");
        printf("0 - Finalizar\n\n\t");


        seletor = PegarInteiros();
        limpando_buffer();

            switch(seletor){

            case 0:
                loop = 0;
                printf("\n\n\t\tObrigado por usar nosso sistema\n\n");
                break;

            case 1:
                printf("\nINSERIR UMA SOLICITAÇÃO\n\n");
                No *aux;
                int extra,extra1,extra2,i;
                char h;

                do{
                   printf("Por favor insira o Código de Solicitação: \t");
                   extra = PegarInteiros();
                   limpando_buffer();
                }while(extra<999 || extra>9999);
                aux->info.CodSoli = extra;


                printf("\n\nPor favor insira o Código do Equipamento (LLL000): \t");
                for(i=0; i<3; i++){
                    h = PegarCaracter(0);
                    aux->info.CodEqui[i]=h;
                }
                for(i=3; i<6; i++){
                    h = PegarUMInteiro();
                    aux->info.CodEqui[i]=h;
                }
                aux->info.CodEqui[6]='\0';

                printf("\n\nPor favor insira o Nome do Equipamento: \t");
                for(i=0; i<20; ){
                    h = PegarCaracter(1);
                    if(h=='\0'){
                        break;
                    }
                    aux->info.NomeEqui[i]=h;
                    i++;
                }
                for(i; i<21; i++){
                    aux->info.NomeEqui[i]='\0';
                }


                do{
                   printf("\n\nPor favor insira o nível de Prioridade (1 a 3): \t");
                   extra1 = PegarInteiros();
                   limpando_buffer();
                }while(extra1<1 || extra1>3);
                aux->info.Prioridade=extra1;


                if(aux->info.Prioridade==3){
                    do{
                        printf("\n\nPor favor insira o Período (1 a 20): \t");
                        extra2 = PegarInteiros();
                    }while(extra2 < 1 || extra2 > 20);
                    aux->info.Periodo=extra2;
                }else{
                    if(aux->info.Prioridade==2){
                        do{
                            printf("\n\nPor favor insira o Período (1 a 15): \t");
                            extra2 = PegarInteiros();
                        }while(extra2 < 1 || extra2 > 15);
                        aux->info.Periodo=extra2;
                    }else{
                        do{
                            printf("\n\nPor favor insira o Período (1 a 7): \t");
                            extra2 = PegarInteiros();
                        }while(extra2 < 1 || extra2 > 7);
                        aux->info.Periodo=extra2;
                    }
                }

                inserir(L, aux->info);
                ImprimeItem(aux->info);

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
