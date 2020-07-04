#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

struct Cliente{
    char nome[256];
    char cpf[12];
};
struct ContaCliente{
    unsigned int numero_da_Conta;
    struct Cliente cliente;
    float saldo;
};
void verificarAberturaArquivos(){
    clientes = fopen("Arquivos\\clientes.txt", "rb");
    if(clientes == NULL){
        printf("Erro na abertura1\n");
        system("pause");
        exit(1);
    }
    fclose(clientes);
    transacoes = fopen("Arquivos\\transacoes.txt", "r");
    if(transacoes == NULL){
        printf("Erro na abertura2\n");
        system("pause");
        exit(1);
    }
    fclose(transacoes);
}
void inicializarVetor(){
    int i=0;
    for(i=0; i<T; i++)
        vContasCliente[i] = NULL;
    clientes = fopen("Arquivos\\clientes.txt", "rb");
    while(!feof(clientes)){
        fseek(clientes, i*sizeof(struct ContaCliente), SEEK_SET);
        fread(&vContasCliente[i], sizeof(struct ContaCliente), 1, clientes);
        i++;
    }
    fclose(clientes);
}
int encontrarPosicaoVazia(){
    int i=0;
    do{
        i++;
    }while(vContasCliente[i] != NULL);
    return i;
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
void imprimirAviso(){
    system("cls");
    printf("\n\tAVISO\n\n");
    printf("  Para que a sua conta possa ser aberta\n");
    printf("  voce devera fazer um deposito inicial\n");
    printf("  com o valor minimo de R$1000.00.\n\n");
    system("pause");
}
void cadastrarNovoCliente(int posicao){
    imprimirAviso();
    system("cls");
    struct ContaCliente novoCliente;
    printf("\n\tCADASTRO\n\n");
    if(vContasCliente[posicao]==NULL){
        vContasCliente[posicao] = (p_contasCliente) malloc(sizeof(struct ContaCliente));
    }
    fflush(stdin);
    printf("  Digite o seu nome completo:\n  ");
    gets(novoCliente.cliente.nome);
    fflush(stdin);
    printf("\n  Digite o seu CPF:\n  ");
    gets(novoCliente.cliente.cpf);
    novoCliente.numero_da_Conta = criarNumeroContaCliente(novoCliente.cliente.cpf);
    printf("\n  Digite um valor para deposito inicial:\n  R$ ");
    scanf("%f", &novoCliente.saldo);
    if(novoCliente.saldo < 1000.00){
        printf("\n  * Valor minimo de deposito inicial e de R$ 1000.00 *\n");
        printf("\n  Digite um valor para deposito inicial:\n  R$ ");
        scanf("%f", &novoCliente.saldo);
    }
    fContaClientes = fopen("Arquivos\\fContaClientes.txt", "a");
    fprintf(fContaClientes,"%d ", novoCliente.numero_da_Conta);
    fprintf(fContaClientes,"%s ", novoCliente.cliente.nome);
    fprintf(fContaClientes,"%s\n", novoCliente.cliente.cpf);
    fclose(fContaClientes);
    transacoes = fopen("Arquivos\\transacoes.txt", "a");
    fprintf(transacoes, "%d realizou um deposito no valor de R$ %.2f , Saldo resultante = R$ %.2f\n", novoCliente.numero_da_Conta, novoCliente.saldo, novoCliente.saldo);
    fclose(transacoes);
    clientes = fopen("Arquivos\\clientes.txt", "ab");
    fwrite(&vContasCliente[posicao], sizeof(struct ContaCliente), 1, clientes);
    fclose(clientes);
}
int criarNumeroContaCliente(char *numero_cpf){
    int somaChar_cpf=0;
    char *cpf = numero_cpf;
    while (*cpf!='\0'){
        somaChar_cpf += *cpf;
        cpf++;
    }
    return somaChar_cpf;
}
void acessarContaCliente(){
    char cpfInformado[13];
    int cont=0;
    do{
        system("cls");
        printf("\n\tACESSAR CONTA\n\n");
        fflush(stdin);
        printf("  Digite o seu CPF:\n  ");
        gets(cpfInformado);
        acessarCPF(cpfInformado);
        cont++;
    }while(cont!=3);
}
void acessarCPF(char *cpf){
    int somaChar_cpfInformado=0;
    int numero_conta_cpfinformado, nContaCliente_lido;
    char nome_lido[256], cpf_lido[12];
    char *c = cpf;
    while (*c != '\0'){
        somaChar_cpfInformado += *c;
        c++;
    }
    numero_conta_cpfinformado = somaChar_cpfInformado;
    fContaClientes = fopen("Arquivos\\fContaClientes.txt", "a");
    if(fContaClientes != NULL){
        fscanf(fContaClientes, "%d %s %s", &nContaCliente_lido, nome_lido, cpf_lido);
        if(numero_conta_cpfinformado == nContaCliente_lido){
            fclose(fContaClientes);
            MenuContaCliente(nome_lido, nContaCliente_lido, cpf_lido);
            return;
        }
    }
    printf("\n  *  CPF nao encontrado!  *\n\n");
    system("pause");
}
void MenuContaCliente(char *nome, int nConta, char *cpf){
    int escolha;
    struct ContaCliente clienteAcessado;
    clienteAcessado.cliente.nome = nome;
    clienteAcessado.cliente.cpf = cpf;
    clienteAcessado.numero_da_Conta = nConta;

    transacoes = fopen("Arquivos\\transacoes.txt", "r");
    int nContaCliente_lido;
    char texto[256], texto2[256];
    float valor, saldo_lido;
    do{
        fscanf(transacoes, "%d %s %f %s %f", &nContaCliente_lido, texto, &valor, texto2, &saldo_lido);
    }while(!(nContaCliente_lido == clienteAcessado.numero_da_Conta));
    fclose(transacoes);

    clienteAcessado.saldo = saldo_lido;

    do{
        imprimirMenuContaCliente();
        escolha = lerEscolha();
        switch(escolha){
            case 1:
                //vContasCliente[posicao]->saldo = fazerDeposito();
                printf("\n\n  1\n");
                break;
            case 2:
                //vContasCliente[posicao]->saldo = fazerSaque();
                printf("\n\n  2\n");
                break;
            case 3:
                exibirSaldo(clienteAcessado.saldo);
                break;
            case 9:
                printf("\n\n  Ate a proxima!\n");
                clientes = fopen("Arquivos\\clientes.txt", "wb");
                fwrite(&vContasCliente, sizeof(struct ContaCliente), T, clientes);
                fclose(clientes);
                return;
                break;
            default:
                printf("\n  Opcao invalida!\n\n");
                system("pause");
                //MenuContaCliente();
                break;
        }
    }while(escolha!=9);
}
void imprimirMenuContaCliente(){
    system("cls");
    printf("\n");
    printf("  Ola, o que voce precisa?\n\n");
    printf("  1. Fazer Deposito\n");
    printf("  2. Fazer Saque\n");
    printf("  3. Exibir Saldo\n\n");
    printf("  9. SAIR DA SUA CONTA\n\n\n");
}
/*float fazerDeposito(){
    system("cls");
    printf("\n");
    float valorDeposito=0;
    float saldoAnterior = cliente.saldo;
    float saldoResultante=0;
    fflush(stdin);
    printf("  Digite o valor que deseja depositar:\n  R$ ");
    scanf("%f", &valorDeposito);
    while(valorDeposito < 0){
        printf("  * ERRO, impossivel fazer deposito de um valor negativo! *\n\n");
        system("pause");
        system("cls");
        printf("\n");
        fflush(stdin);
        printf("  Digite o valor que deseja depositar:\n  R$ ");
        scanf("%f", &valorDeposito);
    }
    saldoResultante = saldoAnterior + valorDeposito;
    cliente.saldo = saldoResultante;
    printf("\n  Deposito realizado com sucesso!\n\n");
    transacoes = fopen("Arquivos\\transacoes.txt", "a");
    fprintf(transacoes, "[%d] realizou um deposito no valor de R$%.2f, Saldo resultante = R$%.2f\n\n", cliente.numero_da_Conta, valorDeposito, cliente.saldo);
    fclose(transacoes);
    system("pause");
    return saldoResultante;
}*/
/*float fazerSaque(struct ContaCliente cliente){
    system("cls");
    printf("\n");
    float valorSaque=0;
    float saldoAnterior = cliente.saldo;
    float saldoResultante=0;
    if(cliente.saldo == 0){
        printf("  Voce não possui saldo para sacar!\n\n");
        system("pause");
        return saldoAnterior;
    }
    fflush(stdin);
    printf("  Digite o valor a ser sacado:\n  R$ ");
    scanf("%f", &valorSaque);
    saldoResultante = saldoAnterior - valorSaque;
    cliente.saldo = saldoResultante;
    printf("\n  Saque realizado com sucesso!\n\n");
    transacoes = fopen("Arquivos\\transacoes.txt", "a");
    fprintf(transacoes, "[%d] realizou um saque no valor de R$%.2f, ", cliente.numero_da_Conta, valorSaque);
    fprintf(transacoes, "Saldo resultante = R$%.2f\n\n", cliente.saldo);
    fclose(transacoes);
    system("pause");
    return saldoResultante;
}*/
void exibirSaldo(float valor){
    system("cls");
    printf("\n");
    printf("  Saldo atual:\n\n\tR$ %.2f\n\n", valor);
    system("pause");
}
