/* Definindo o tamanho do vetor para 100 clientes */
#define T 100

/* Criando um ponteiro para evitar consumo excessivo de memória do tipo struct Aluno */
typedef struct Cliente *p_cliente;

/* Definindo um vetor vCliente do tipo struct Cliente para armazenar ponteiro  */
p_cliente vCliente[T];

/* Inicializar o vetor com NULL para desalocar os lixos da memória */
void inicializarVetor();

void imprimirMenuPrincipal();

void MenuContaCliente();

void imprimirMenuContaCliente();

void cadastroCliente(int posicao);
