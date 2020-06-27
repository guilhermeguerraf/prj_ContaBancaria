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
        escolhaMenu = lerEscolha();
        switch(escolhaMenu){
            case 1:
                cadastroCliente(posicaoVetor);
                posicaoVetor++;
                break;
            case 2:
                acessoContaCliente();
                break;
            case 9:
                printf("\n\n  Saindo...\n");
                exit(0);
            default:
                printf("\n  Opcao invalida!\n\n");
                system("pause");
                break;
        }
    }while(escolhaMenu!=9);
    return 0;
}
