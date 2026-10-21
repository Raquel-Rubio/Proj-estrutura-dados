#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include "Lista.h"
#include<locale.h>
#include<windows.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    unsigned int CPAGE_UTF8 = 65001;
    unsigned int CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

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
                printf("\n\n\t\tObrigado por usar nosso sistema\n\n");
                liberaLista(L);
                loop = 0;
                break;

            case 1:
                printf("\nINSERIR UMA SOLICITAÇÃO\n\n");
                No *aux = (No*) malloc (sizeof(No));
                int extra,extra1,extra2,i;
                char h;

                do{
                    extra = VerificaSoli();
                }while(!DisponivelCod(L, extra));
                aux->info.CodSoli = extra;


                printf("\n\nPor favor insira o Código do Equipamento (LLL000):   ");
                for(i=0; i<3; i++){
                    h = PegarCaracter(0);
                    aux->info.CodEqui[i] = h;
                }
                for(i=3; i<6; i++){
                    h = PegarUMInteiro();
                    aux->info.CodEqui[i] = h;
                }

                printf("\n\nPor favor insira o Nome do Equipamento:   ");
                for(i=0; i<20; ){
                    h = PegarCaracter(1);
                    if(h=='\0'){
                        break;
                    }
                    aux->info.NomeEqui[i] = h;
                    i++;
                }

                aux->info.Prioridade = VerificaPriori();


                aux->info.Periodo = VerificaPeriodo(aux->info.Prioridade);


                inserir(L, aux->info);
                ImprimeItem(aux->info);

                break;

            case 2:
                printf("\nRemover uma Solicitação de Manutenção");
                int rmv = VerificaSoli();
                break;

            case 3:
                int encon = VerificaSoli();

                AchaItemNo(L, encon);

                break;

            case 4:
                int Mprio, Mperi;
                printf("\nAlterar Prioridade e/ou Periodo");

                int altera = VerificaSoli();

                if(!AchaItemNo(L, altera)){
                    break;
                }
                else{
                    Mprio = VerificaPriori();
                    Mperi = VerificaPeriodo(Mprio);
                }

                Modifica(L, altera, Mprio, Mperi);
                break;

            case 5:
                OrdemManutencao(L);
                printf("\n");
                system("pause");
                break;

            case 6:
                ImprimeLista(L);
                printf("\n");
                system("pause");
                break;
            }

    }
    return 0;
    SetConsoleOutputCP(CPAGE_DEFAULT);
}
