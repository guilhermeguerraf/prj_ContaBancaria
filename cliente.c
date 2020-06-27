#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

struct Cliente{
    char nome[256];
    unsigned int cpf;
};
struct ContaCliente{
    unsigned int numero_da_Conta;
    struct Cliente cliente;
    float saldo;
};

void inicializarVetor(){
    int i;
    for (i=0; i<T; i++){
        vCliente[i] = NULL;
    }
}

void imprimirMenuPrincipal(){
    system("cls");
    printf("\n");
    printf("  Bem vindo, o que voce deseja fazer?\n\n");
    printf("  1. Abrir conta\n");
    printf("  2. Acessar conta\n\n");
    printf("  9. SAIR\n\n\n");
}

void MenuContaCliente(){
    int escolhaMenuContaCliente=0;
    do{
        imprimirMenuContaCliente();
        printf("  Escolha sua opcao: ");
        scanf("%d", &escolhaMenuContaCliente);
        switch(escolhaMenuContaCliente){
            case 1:
                printf("  vc escolheu Fazer Deposito\n");
                system("pause");
                break;
            case 2:
                printf("  vc escolheu Fazer Saque\n");
                system("pause");
                break;
            case 3:
                printf("  vc escolheu Exibir Saldo\n");
                system("pause");
                break;
            case 9:
                printf("\n\n  Ate a proxima!\n");
                exit(0);
                break;
            default:
                printf("\n  Opcao invalida!\n");
                system("pause");
                MenuContaCliente();
                break;
        }
    }while(escolhaMenuContaCliente!=9);
}

void imprimirMenuContaCliente(int numeroContaCliente){
    system("cls");
    printf("\n");
    printf("  Ola (nome), o que voce precisa?\n\n");
    printf("  1. Fazer Deposito\n");
    printf("  2. Fazer Saque\n");
    printf("  3. Exibir Saldo\n\n");
    printf("  9. SAIR DA SUA CONTA\n\n\n");
}

void cadastroCliente(int posicao){
    if(vCliente[posicao]==NULL){
        vCliente[posicao] = (p_cliente) malloc(sizeof(struct Cliente));
    }
    fflush(stdin);
    printf("  Digite o seu nome completo:\n  ");
    gets(vCliente[posicao]->nome);
    fflush(stdin);
    printf("\n  Digite o seu CPF:\n  ");
    scanf("%d", &vCliente[posicao]->cpf);
}
