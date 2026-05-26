#include <stdio.h>

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
                printf("Inserir dados\n");
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