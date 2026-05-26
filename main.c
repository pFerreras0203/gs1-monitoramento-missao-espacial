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

void verificar_alertas(int i){
    int alerta = 0;

    if (temperatura[i] > 80) {
        printf("ALERTA: Temperatura elevada! **%.1fC**\n", temperatura[i]);
        alerta = 1;
    }
    if (energia[i] < 20) {
        printf("ALERTA: Energia baixa! **%.1fkWh**\n", energia[i]);
        alerta = 1;
    }
    if (comunicacao[i] == 0) {
        printf("ALERTA: Falha na comunicacao!\n");
        alerta = 1;
    }
    if (!alerta) {
        printf("Status: Normal\n");
    }
}

void executar_analise(){
    if (total_leituras ==0){
        printf("Nenhuma leitura registrada!\n");
        return;
    }

    printf("\n ***** ANALISE DAS LEITURAS *****\n");
    for (int i = 0; i < total_leituras; i++){
        printf("\nLeitura %d:\n", i + 1);
        verificar_alertas(i);
    }
}

int main(){
    
    int opcao;

    do{
        printf("\n****** SISTEMA DE MONITORAMNETO ESPACIAL *****\n");
        printf("1. Inserir dados\n");
        printf("2. Executar analise\n");
        printf("3. Visualizar status\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                inserir_dados();
                break;
            case 2:
                executar_analise();
                break; 
            case 3:
                printf("Visualizar status\n");
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