#include <stdio.h>
#define MAX_LEITURAS 10

float temperatura[MAX_LEITURAS];
float energia[MAX_LEITURAS];
int comunicacao[MAX_LEITURAS];
int total_leituras = 0;

void inserir_dados(){
    if (total_leituras >= MAX_LEITURAS) {
        printf("Limite de leituras atingido!\n");
        return;
    }

    int i = total_leituras;

    printf("***** INSERIR DADOS *****\n");

    printf("Tempertaura (C):");
    scanf("%f", &temperatura[i]);

    printf("Energia (kWh):");
    scanf("%f", &energia[i]);

    printf("Comunicacao (0 = FALHA/1 = OK):");
    scanf("%d", &comunicacao[i]);

    total_leituras++;
    printf("Leitura %d registrada com sucesso!\n", total_leituras);
}


int main(){
    
    int opcao;

    do{
        printf("\n****** SISTEMA DE MONITORAMNETO ESPACIAL *****\n");
        printf("1. Inserir dados\n");
        printf("2. Visualizar status\n");
        printf("3. Executar analise\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                inserir_dados();
                break;
            case 2:
                printf("Visualizar status\n");
                break; 
            case 3:
                printf("Executar analise\n");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção invalida!\n");

        }
    } while (opcao != 0);



    return 0;
}