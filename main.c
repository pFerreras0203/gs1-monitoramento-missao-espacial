#include <stdio.h>
#include <stdlib.h>
#define MAX_LEITURAS 10

float temperatura[MAX_LEITURAS];
float energia[MAX_LEITURAS];
int comunicacao[MAX_LEITURAS];
int total_leituras = 0;

void inserir_dados(){
    if (total_leituras >= MAX_LEITURAS) {
        printf("Limite de leituras atingido!\n");
        system("pause");
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
    system("pause");
}

void verificar_alertas(int i){
    int alerta = 0;

    if (temperatura[i] > 80) {
        printf("ALERTA: Superaquecimento! **%.1fC**\n", temperatura[i]);
        alerta = 1;
    }
    if (energia[i] < 20) {
        printf("ALERTA: Economia de energia! **%.1fkWh**\n", energia[i]);
        alerta = 1;
    }
    if (comunicacao[i] == 0) {
        printf("ALERTA: Falha de comunicacao!\n");
        alerta = 1;
    }
    if (!alerta) {
        printf("Status: Normal\n");
    }
}

void executar_analise(){
    if (total_leituras ==0){
        printf("Nenhuma leitura registrada!\n");
        system("pause");
        return;
    }

    printf("\n ***** ANALISE DAS LEITURAS *****\n");
    for (int i = 0; i < total_leituras; i++){
        printf("\nLeitura %d:\n", i + 1);
        verificar_alertas(i);
    }
    system("pause");
}

void visualizar_status() {
    if (total_leituras == 0) {
        printf("Nenhuma leitura registrada!\n");
        system("pause");
        return;
    }

    printf("\n***** HISTORICO DE LEITURAS *****\n");
    printf("%-8s %-15s %-10s %-15s\n", "Leitura", "Temperatura(C)", "Energia(kWh)", "Comunicacao");
    printf("**************************************************\n");

    for (int i = 0; i < total_leituras; i++) {
        printf("%-8d %-15.1f %-10.1f %-15s\n",
            i + 1,
            temperatura[i],
            energia[i],
            comunicacao[i] ? "OK" : "FALHA");
    }

    printf("\nUltima leitura (leitura %d):\n", total_leituras);
    verificar_alertas(total_leituras - 1);
    system("pause");
}

int main(){
    
    int opcao;

    do{
        printf("\n****** SISTEMA DE MONITORAMENTO ESPACIAL *****\n");
        printf("1. Inserir dados\n");
        printf("2. Executar analise\n");
        printf("3. Visualizar status\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao){
            case 1:
                inserir_dados();
                break;
            case 2:
                executar_analise();
                break; 
            case 3:
                visualizar_status();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção invalida!\n");
                system("pause");

        }
    } while (opcao != 0);



    return 0;
}