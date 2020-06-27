/* Definindo o tamanho do vetor para 100 clientes */
#define T 100

/* Criando um ponteiro para evitar consumo excessivo de memória do tipo struct Aluno */
typedef struct ContaCliente *p_contaCliente;

/* Definindo um vetor vCliente do tipo struct Cliente para armazenar ponteiro  */
p_contaCliente vContaCliente[T];

/* Inicializar o vetor com NULL para desalocar os lixos da memória */
void inicializarVetor();

void imprimirMenuPrincipal();

int lerEscolha();

void cadastroCliente(int posicao);

void imprimirAviso();

void acessoContaCliente();

void MenuContaCliente(int posicao);

void imprimirMenuContaCliente(int posicao);

void fazerDeposito(int posicao);

void fazerSaque(int posicao);

void exibirSaldo(int posicao);
