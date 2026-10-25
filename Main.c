#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#include "Lista.h"

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
    }while(verif<1000 || verif>9999);
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

int VPInterno(int priori, int perio){
    if(priori==3){
        if(perio < 1 || perio > 20){
            printf("\nNova prioridade não condiz com periodo já existente\n");
            return 0;
        }
        return 1;
    }else{
        if(priori==2){
            if(perio < 1 || perio > 15){
                printf("\nNova prioridade não condiz com periodo já existente\n");
                return 0;
            }
            return 1;
        }else{
            if(perio < 1 || perio > 7){
                printf("\nNova prioridade não condiz com periodo já existente\n");
                return 0;
            }
            return 1;
        }
    }
}

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
                int extra,i;
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
                aux->info.CodEqui[6] = '\0';
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
                for(; i<21; i++){
                    aux->info.NomeEqui[i] = '\0';
                }
                printf("\n\tNome do Equipamento informado: %s\n", aux->info.NomeEqui);

                aux->info.Prioridade = VerificaPriori();


                aux->info.Periodo = VerificaPeriodo(aux->info.Prioridade);


                inserir(L, aux->info);
                ImprimeItem(aux->info);
                free(aux);
                break;

            case 2:
                printf("\nRemover uma Solicitação de Manutenção");
                int rmv = VerificaSoli();
                if(AchaItemNo(L, rmv)){
                    RemoverSoli(L, rmv);
                }

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
