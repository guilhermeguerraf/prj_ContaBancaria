#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main()
{
    verificarAberturaArquivos();
    inicializarVetor();
    int posicaoVetor;
    posicaoVetor = encontrarPosicaoVazia();
    int escolha;
    do{
        imprimirMenuPrincipal();
        escolha = lerEscolha();
        switch(escolha){
            case 1:
                cadastrarNovoCliente(posicaoVetor);
                posicaoVetor++;
                break;
            case 2:
                acessarContaCliente();
                break;
            case 9:
                printf("\n\n  Saindo...\n");

                exit(0);
            default:
                printf("\n  Opcao invalida!\n\n");
                system("pause");
                break;
        }
    }while(escolha!=9);
    return 0;
}
