#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include "Lista.h"
#include<windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

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


                printf("\nPor favor insira o Código do Equipamento (LLL000):   ");
                for(i=0; i<3; i++){
                    h = PegarCaracter(0);
                    aux->info.CodEqui[i] = h;
                }
                for(i=3; i<6; i++){
                    h = PegarUMInteiro();
                    aux->info.CodEqui[i] = h;
                }
                printf("\n\tCódigo de Equipamento informado: %s\n", aux->info.CodEqui);

                printf("\nPor favor insira o Nome do Equipamento:   ");
                for(i=0; i<20; ){
                    h = PegarCaracter(1);
                    if(h=='\0'){
                        break;
                    }
                    aux->info.NomeEqui[i] = h;
                    i++;
                }
                printf("\n\tNome do Equipamento informado: %s\n", aux->info.NomeEqui);

                aux->info.Prioridade = VerificaPriori();


                aux->info.Periodo = VerificaPeriodo(aux->info.Prioridade);


                inserir(L, aux->info);
                ImprimeItem(aux->info);

                break;

            case 2:
                printf("\nRemover uma Solicitação de Manutenção");
                int rmv = VerificaSoli();
                RemoverSoli(L, rmv);
                break;

            case 3:
                int encon = VerificaSoli();

                AchaItemNo(L, encon);

                break;

            case 4:
                int Mprio, Mperi, mudar;
                printf("\nAlterar Prioridade e/ou Periodo:");
                printf("\n\t1-Mudar apenas a Prioridade \n\t2-Mudar apenas o Periodo\n\t3-Mudar Prioridade e Periodo\n\n\t");
                do{
                    mudar = PegarInteiros();
                }while(mudar<0 || mudar>3);

                int altera = VerificaSoli();

                int Q = AchaPrioPeri(mudar, L, altera);
                if(Q == 0){
                    break;
                }
                else{
                    switch(mudar){
                        case 1:
                            do{
                                Mprio = VerificaPriori();
                            }while(!VPInterno(Mprio, Q));
                            Mperi = Q;
                            break;

                        case 2:
                            Mperi = VerificaPeriodo(Q);
                            Mprio = Q;
                            break;

                        case 3:
                            Mprio = VerificaPriori();
                            Mperi = VerificaPeriodo(Mprio);
                            break;
                    }

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
}
