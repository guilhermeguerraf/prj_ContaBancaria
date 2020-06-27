#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main()
{
    int posicaoVetor=0;
    int escolhaMenu=0;
    inicializarVetor();
    do{
        imprimirMenuPrincipal();
        printf("  Escolha sua opcao: ");
        scanf("%d", &escolhaMenu);
        switch(escolhaMenu){
            case 1:
                system("cls");
                printf("\n\tCADASTRO\n\n");
                cadastroCliente(posicaoVetor);
                break;
            case 2:
                MenuContaCliente();
                break;
            case 9:
                printf("\n\n  Saindo...\n");
                break;
            default:
                printf("\n  Opcao invalida!\n");
                system("pause");
                main();
                break;
        }
    }while(escolhaMenu!=9);
    return 0;
}
