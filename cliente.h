/* Definindo o tamanho do vetor para 100 clientes */
#define T 100

FILE *clientes;

FILE *fContaClientes;

FILE *transacoes;

typedef struct ContaCliente *p_contasCliente;

p_contasCliente vContasCliente[T];

void verificarAberturaArquivos();
/* Inicializar o vetor com NULL para desalocar os lixos da memória */
void inicializarVetor();

int encontrarPosicaoVazia();

void imprimirMenuPrincipal();

int lerEscolha();

void imprimirAviso();

void cadastrarNovoCliente(int posicao);

int criarNumeroContaCliente(char *numero_cpf);

void acessarContaCliente();

void acessarCPF(char *cpf);

void MenuContaCliente(char *nome, int nConta, char *cpf);

void imprimirMenuContaCliente();

float fazerDeposito();

float fazerSaque();

void exibirSaldo(float valor);
