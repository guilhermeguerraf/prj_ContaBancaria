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
        vContaCliente[i] = NULL;
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

int lerEscolha(){
    int escolha;
    printf("  Escolha sua opcao: ");
    scanf("%d", &escolha);
    return escolha;
}

void cadastroCliente(int posicao){
    imprimirAviso();
    system("cls");
    printf("\n\tCADASTRO\n\n");
    if(vContaCliente[posicao]==NULL){
        vContaCliente[posicao] = (p_contaCliente) malloc(sizeof(struct ContaCliente));
    }
    fflush(stdin);
    printf("  Digite o seu nome completo:\n  ");
    gets(vContaCliente[posicao]->cliente.nome);
    fflush(stdin);
    printf("\n  Digite o seu CPF:\n  ");
    scanf("%d", &vContaCliente[posicao]->cliente.cpf);
    printf("\n  Digite um valor para deposito inicial:\n  R$ ");
    scanf("%f", &vContaCliente[posicao]->saldo);
    if(vContaCliente[posicao]->saldo < 1000.00){
        printf("\n  * O valor minimo para deposito inicial e de R$1000.00 *\n");
        printf("\n  Digite um valor para deposito inicial:\n  R$ ");
        scanf("%f", &vContaCliente[posicao]->saldo);
    }
}

void imprimirAviso(){
    system("cls");
    printf("\n\tAVISO\n\n");
    printf("  Para que a sua conta possa ser aberta\n");
    printf("  voce devera fazer um deposito inicial\n");
    printf("  com o valor minimo de R$1000.00.\n\n");
    system("pause");
}

void acessoContaCliente(){
    int cpfInformado, posicao;
    int cont=0;
    do{
        system("cls");
        printf("\n\tACESSAR CONTA\n\n");
        fflush(stdin);
        printf("  Digite o seu CPF:\n  ");
        scanf("%d", &cpfInformado);
        int i;
        for(i=0; i<T; i++){
            if(vContaCliente[i] != NULL){
                if(cpfInformado == vContaCliente[i]->cliente.cpf){
                    posicao = i;
                    MenuContaCliente(posicao);
                    return;
                }
            }
        }
        printf("\n  *  CPF invalido!  *\n\n");
        system("pause");
        cont++;
    }while(cont!=3);
}

void MenuContaCliente(int posicao){
    int escolhaMenuContaCliente=0;
    do{
        imprimirMenuContaCliente(posicao);
        escolhaMenuContaCliente = lerEscolha();
        switch(escolhaMenuContaCliente){
            case 1:
                fazerDeposito(posicao);
                break;
            case 2:
                fazerSaque(posicao);
                break;
            case 3:
                exibirSaldo(posicao);
                break;
            case 9:
                printf("\n\n  Ate a proxima!\n");
                exit(0);
                break;
            default:
                printf("\n  Opcao invalida!\n\n");
                system("pause");
                MenuContaCliente(posicao);
                break;
        }
    }while(escolhaMenuContaCliente!=9);
}

void imprimirMenuContaCliente(int posicao){
    system("cls");
    printf("\n");
    printf("  Ola, o que voce precisa?\n\n");
    printf("  1. Fazer Deposito\n");
    printf("  2. Fazer Saque\n");
    printf("  3. Exibir Saldo\n\n");
    printf("  9. SAIR DA SUA CONTA\n\n\n");
}

void fazerDeposito(int posicao){
    system("cls");
    printf("\n");
    float valorDeposito=0;
    float saldoAnterior = vContaCliente[posicao]->saldo;
    float saldoResultante=0;
    fflush(stdin);
    printf("  Digite o valor que deseja depositar:\n  R$ ");
    scanf("%f", &valorDeposito);
    while(valorDeposito < 0){
        vContaCliente[posicao]->saldo+= valorDeposito;
        printf("  * ERRO, impossivel fazer deposito de um valor negativo! *\n\n");
        system("pause");
        system("cls");
        printf("\n");
        fflush(stdin);
        printf("  Digite o valor que deseja depositar:\n  R$ ");
        scanf("%f", &valorDeposito);
    }
    saldoResultante = saldoAnterior + valorDeposito;
    vContaCliente[posicao]->saldo = saldoResultante;
    if(vContaCliente[posicao]->saldo == saldoResultante){
        printf("\n  Deposito realizado com sucesso!\n\n");
        system("pause");
        return;
    }else{
        printf("\n  Falha ao depositar, tente novamente!\n\n");
        system("pause");
        vContaCliente[posicao]->saldo = saldoAnterior;
    }
    return;
}

void fazerSaque(int posicao){
    system("cls");
    printf("\n");
    float valorSaque=0;
    float saldoAnterior = vContaCliente[posicao]->saldo;
    float saldoResultante=0;
    fflush(stdin);
    printf("  Digite o valor a ser sacado:\n  R$ ");
    scanf("%f", &valorSaque);
    if(vContaCliente[posicao]->saldo <= 0){
        printf("  Voce não possui saldo para sacar!\n\n");
        system("pause");
        return;
    }
    saldoResultante = saldoAnterior - valorSaque;
    vContaCliente[posicao]->saldo = saldoResultante;
    if(vContaCliente[posicao]->saldo == saldoResultante){
        printf("\n  Saque realizado com sucesso!\n\n");
        system("pause");
    }else{
        printf("\n  Falha ao sacar, tente novamente!\n\n");
        system("pause");
        vContaCliente[posicao]->saldo = saldoAnterior;
    }
}

void exibirSaldo(int posicao){
    system("cls");
    printf("\n");
    printf("  Saldo atual:\n\n\tR$ %.2f\n\n", vContaCliente[posicao]->saldo);
    system("pause");
}
