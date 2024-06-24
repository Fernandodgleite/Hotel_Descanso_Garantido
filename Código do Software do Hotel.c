#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 50
#define MAX_QUARTOS 50
#define MAX_ESTADIAS 100

typedef struct {
    int codigo;
    char nome[100];
    char endereco[150];
    char telefone[20];
} Cliente;

typedef struct {
    int codigo;
    char nome[100];
    char telefone[20];
    char cargo[50];
    float salario;
} Funcionario;

typedef struct {
    int numero;
    int quantidadeHospedes;
    float valorDiaria;
    char status[20]; // "ocupado" ou "desocupado"
} Quarto;

typedef struct {
    int codigo;
    int clienteCodigo;
    int quartoNumero;
    char dataEntrada[11];
    char dataSaida[11];
    int quantidadeDiarias;
} Estadia;

Cliente clientes[MAX_CLIENTES];
Funcionario funcionarios[MAX_FUNCIONARIOS];
Quarto quartos[MAX_QUARTOS];
Estadia estadias[MAX_ESTADIAS];

int totalClientes = 0;
int totalFuncionarios = 0;
int totalQuartos = 0;
int totalEstadias = 0;

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    carregarDados(); // Carrega os dados dos arquivos binários

    int opcao;
    do {
        // Menu de opções
        printf("\nMenu:\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Funcionário\n");
        printf("3. Cadastrar Quarto\n");
        printf("4. Cadastrar Estadia\n");
        printf("5. Dar Baixa em Estadia\n");
        printf("6. Pesquisar Cliente\n");
        printf("7. Pesquisar Funcionário\n");
        printf("8. Mostrar Estadias de Cliente\n");
        printf("9. Calcular Pontos de Fidelidade\n");
        printf("10. Listar Clientes\n");
        printf("11. Listar Funcionários\n");
        printf("12. Listar Quartos\n");
        printf("13. Listar Estadias\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarFuncionario();
                break;
            case 3:
                cadastrarQuarto();
                break;
            case 4:
                cadastrarEstadia();
                break;
            case 5:
                darBaixaEstadia();
                break;
            case 6:
                pesquisarCliente();
                break;
            case 7:
                pesquisarFuncionario();
                break;
            case 8:
                mostrarEstadiasCliente();
                break;
            case 9:
                calcularPontosFidelidade();
                break;
            case 10:
                listarClientes();
                break;
            case 11:
                listarFuncionarios();
                break;
            case 12:
                listarQuartos();
                break;
            case 13:
                listarEstadias();
                break;
            case 0:
                salvarDados(); // Salva os dados nos arquivos binários
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

// Função para carregar dados dos arquivos binários
void carregarDados() {
    FILE *file;

    // Carregar clientes
    file = fopen("clientes.dat", "rb");
    if (file) {
        fread(&totalClientes, sizeof(int), 1, file);
        fread(clientes, sizeof(Cliente), totalClientes, file);
        fclose(file);
    } else {
        printf("Arquivo clientes.dat não encontrado, iniciando com base vazia.\n");
    }

    // Carregar funcionários
    file = fopen("funcionarios.dat", "rb");
    if (file) {
        fread(&totalFuncionarios, sizeof(int), 1, file);
        fread(funcionarios, sizeof(Funcionario), totalFuncionarios, file);
        fclose(file);
    } else {
        printf("Arquivo funcionarios.dat não encontrado, iniciando com base vazia.\n");
    }

    // Carregar quartos
    file = fopen("quartos.dat", "rb");
    if (file) {
        fread(&totalQuartos, sizeof(int), 1, file);
        fread(quartos, sizeof(Quarto), totalQuartos, file);
        fclose(file);
    } else {
        printf("Arquivo quartos.dat não encontrado, iniciando com base vazia.\n");
    }

    // Carregar estadias
    file = fopen("estadias.dat", "rb");
    if (file) {
        fread(&totalEstadias, sizeof(int), 1, file);
        fread(estadias, sizeof(Estadia), totalEstadias, file);
        fclose(file);
    } else {
        printf("Arquivo estadias.dat não encontrado, iniciando com base vazia.\n");
    }
}

// Função para salvar dados nos arquivos binários
void salvarDados() {
    FILE *file;

    // Salvar clientes
    file = fopen("clientes.dat", "wb");
    if (file) {
        fwrite(&totalClientes, sizeof(int), 1, file);
        fwrite(clientes, sizeof(Cliente), totalClientes, file);
        fclose(file);
    } else {
        printf("Erro ao salvar clientes.dat\n");
    }

    // Salvar funcionários
    file = fopen("funcionarios.dat", "wb");
    if (file) {
        fwrite(&totalFuncionarios, sizeof(int), 1, file);
        fwrite(funcionarios, sizeof(Funcionario), totalFuncionarios, file);
        fclose(file);
    } else {
        printf("Erro ao salvar funcionarios.dat\n");
    }

    // Salvar quartos
    file = fopen("quartos.dat", "wb");
    if (file) {
        fwrite(&totalQuartos, sizeof(int), 1, file);
        fwrite(quartos, sizeof(Quarto), totalQuartos, file);
        fclose(file);
    } else {
        printf("Erro ao salvar quartos.dat\n");
    }

    // Salvar estadias
    file = fopen("estadias.dat", "wb");
    if (file) {
        fwrite(&totalEstadias, sizeof(int), 1, file);
        fwrite(estadias, sizeof(Estadia), totalEstadias, file);
        fclose(file);
    } else {
        printf("Erro ao salvar estadias.dat\n");
    }
}

// Função para cadastrar um cliente
// Entrada: nome, endereço, telefone
// Saída: cliente cadastrado na lista de clientes
void cadastrarCliente() {
    Cliente cliente;
    printf("Nome do cliente: ");
    scanf(" %[^\n]", cliente.nome); // Leitura de string com espaços
    printf("Endereço do cliente: ");
    scanf(" %[^\n]", cliente.endereco); // Leitura de string com espaços
    printf("Telefone do cliente: ");
    scanf(" %[^\n]", cliente.telefone); // Leitura de string com espaços

    cliente.codigo = totalClientes + 1; // Código gerado automaticamente
    clientes[totalClientes++] = cliente;
    printf("Cliente cadastrado com sucesso!\n");
}

// Função para cadastrar um funcionário
// Entrada: nome, telefone, cargo, salário
// Saída: funcionário cadastrado na lista de funcionários
void cadastrarFuncionario() {
    Funcionario funcionario;
    printf("Nome do funcionário: ");
    scanf(" %[^\n]", funcionario.nome); // Leitura de string com espaços
    printf("Telefone do funcionário: ");
    scanf(" %[^\n]", funcionario.telefone); // Leitura de string com espaços
    printf("Cargo do funcionário: ");
    scanf(" %[^\n]", funcionario.cargo); // Leitura de string com espaços
    printf("Salário do funcionário: ");
    scanf("%f", &funcionario.salario);

    funcionario.codigo = totalFuncionarios + 1; // Código gerado automaticamente
    funcionarios[totalFuncionarios++] = funcionario;
    printf("Funcionário cadastrado com sucesso!\n");
}

// Função para cadastrar um quarto
// Entrada: número, quantidade de hóspedes, valor da diária
// Saída: quarto cadastrado na lista de quartos
void cadastrarQuarto() {
    Quarto quarto;
    printf("Número do quarto: ");
    scanf("%d", &quarto.numero);
    printf("Quantidade de hóspedes: ");
    scanf("%d", &quarto.quantidadeHospedes);
    printf("Valor da diária: ");
    scanf("%f", &quarto.valorDiaria);
    strcpy(quarto.status, "desocupado");

    quartos[totalQuartos++] = quarto;
    printf("Quarto cadastrado com sucesso!\n");
}

// Função para calcular a quantidade de diárias
// Entrada: data de entrada, data de saída
// Saída: quantidade de diárias
int calcularQuantidadeDiarias(char* dataEntrada, char* dataSaida) {
    int diaEntrada, mesEntrada, anoEntrada;
    int diaSaida, mesSaida, anoSaida;
    sscanf(dataEntrada, "%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
    sscanf(dataSaida, "%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);

    int diasEntrada = anoEntrada * 365 + mesEntrada * 30 + diaEntrada;
    int diasSaida = anoSaida * 365 + mesSaida * 30 + diaSaida;

    return diasSaida - diasEntrada;
}

// Função para cadastrar uma estadia
// Entrada: código do cliente, quantidade de hóspedes, data de entrada, data de saída
// Saída: estadia cadastrada na lista de estadias
void cadastrarEstadia() {
    Estadia estadia;
    int codigoCliente, quantidadeHospedes;
    char dataEntrada[11], dataSaida[11];

    printf("Código do cliente: ");
    scanf("%d", &codigoCliente);

    int clienteEncontrado = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigoCliente) {
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente não encontrado!\n");
        return;
    }

    printf("Quantidade de hóspedes: ");
    scanf("%d", &quantidadeHospedes);
    printf("Data de entrada (DD/MM/AAAA): ");
    scanf(" %[^\n]", dataEntrada);
    printf("Data de saída (DD/MM/AAAA): ");
    scanf(" %[^\n]", dataSaida);

    int quartoDisponivel = -1;
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].quantidadeHospedes >= quantidadeHospedes && strcmp(quartos[i].status, "desocupado") == 0) {
            quartoDisponivel = i;
            break;
        }
    }

    if (quartoDisponivel == -1) {
        printf("Nenhum quarto disponível para a quantidade de hóspedes!\n");
        return;
    }

    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].quartoNumero == quartos[quartoDisponivel].numero &&
            strcmp(estadias[i].dataEntrada, dataEntrada) == 0 && strcmp(estadias[i].dataSaida, dataSaida) == 0) {
            printf("Já existe uma estadia para este quarto no mesmo período!\n");
            return;
        }
    }

    estadia.codigo = totalEstadias + 1;
    estadia.clienteCodigo = codigoCliente;
    estadia.quartoNumero = quartos[quartoDisponivel].numero;
    strcpy(estadia.dataEntrada, dataEntrada);
    strcpy(estadia.dataSaida, dataSaida);
    estadia.quantidadeDiarias = calcularQuantidadeDiarias(dataEntrada, dataSaida);

    estadias[totalEstadias++] = estadia;
    strcpy(quartos[quartoDisponivel].status, "ocupado");

    printf("Estadia cadastrada com sucesso!\n");
}

// Função para dar baixa em uma estadia
// Entrada: código da estadia
// Saída: estadia removida e valor total a ser pago calculado
void darBaixaEstadia() {
    int codigoEstadia;
    printf("Código da estadia: ");
    scanf("%d", &codigoEstadia);

    int estadiaEncontrada = 0;
    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].codigo == codigoEstadia) {
            estadiaEncontrada = 1;

            int quartoNumero = estadias[i].quartoNumero;
            float valorTotal = estadias[i].quantidadeDiarias * quartos[quartoNumero - 1].valorDiaria;

            printf("Valor total a ser pago: %.2f\n", valorTotal);
            strcpy(quartos[quartoNumero - 1].status, "desocupado");
            break;
        }
    }

    if (!estadiaEncontrada) {
        printf("Estadia não encontrada!\n");
    }
}

// Função para pesquisar um cliente pelo nome
// Entrada: nome do cliente
// Saída: informações do cliente
void pesquisarCliente() {
    char nome[100];
    printf("Nome do cliente: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
            return;
        }
    }
    printf("Cliente não encontrado!\n");
}

// Função para pesquisar um funcionário pelo nome
// Entrada: nome do funcionário
// Saída: informações do funcionário
void pesquisarFuncionario() {
    char nome[100];
    printf("Nome do funcionário: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < totalFuncionarios; i++) {
        if (strcmp(funcionarios[i].nome, nome) == 0) {
            printf("Código: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSalário: %.2f\n", funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
            return;
        }
    }
    printf("Funcionário não encontrado!\n");
}

// Função para mostrar todas as estadias de um cliente pelo código do cliente
// Entrada: código do cliente
// Saída: informações das estadias do cliente
void mostrarEstadiasCliente() {
    int codigoCliente;
    printf("Código do cliente: ");
    scanf("%d", &codigoCliente);

    int estadiaEncontrada = 0;
    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].clienteCodigo == codigoCliente) {
            printf("Estadia Código: %d\nQuarto Número: %d\nData de Entrada: %s\nData de Saída: %s\nQuantidade de Diárias: %d\n",
                   estadias[i].codigo, estadias[i].quartoNumero, estadias[i].dataEntrada, estadias[i].dataSaida, estadias[i].quantidadeDiarias);
            estadiaEncontrada = 1;
        }
    }

    if (!estadiaEncontrada) {
        printf("Nenhuma estadia encontrada para este cliente!\n");
    }
}

// Função para calcular pontos de fidelidade de um cliente
// Entrada: código do cliente
// Saída: pontos de fidelidade do cliente
void calcularPontosFidelidade() {
    int codigoCliente;
    printf("Código do cliente: ");
    scanf("%d", &codigoCliente);

    int pontosFidelidade = 0;
    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].clienteCodigo == codigoCliente) {
            pontosFidelidade += estadias[i].quantidadeDiarias * 10;
        }
    }

    printf("Total de pontos de fidelidade: %d\n", pontosFidelidade);
}

// Função para listar todos os clientes
// Saída: lista de clientes cadastrados
void listarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        printf("Lista de Clientes:\n");
        for (int i = 0; i < totalClientes; i++) {
            printf("Código: %d, Nome: %s, Endereço: %s, Telefone: %s\n",
                   clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
        }
    }
}

// Função para listar todos os funcionários
// Saída: lista de funcionários cadastrados
void listarFuncionarios() {
    if (totalFuncionarios == 0) {
        printf("Nenhum funcionário cadastrado.\n");
    } else {
        printf("Lista de Funcionários:\n");
        for (int i = 0; i < totalFuncionarios; i++) {
            printf("Código: %d, Nome: %s, Telefone: %s, Cargo: %s, Salário: %.2f\n",
                   funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
        }
    }
}

// Função para listar todos os quartos
// Saída: lista de quartos cadastrados
void listarQuartos() {
    if (totalQuartos == 0) {
        printf("Nenhum quarto cadastrado.\n");
    } else {
        printf("Lista de Quartos:\n");
        for (int i = 0; i < totalQuartos; i++) {
            printf("Número: %d, Quantidade de Hóspedes: %d, Valor da Diária: %.2f, Status: %s\n",
                   quartos[i].numero, quartos[i].quantidadeHospedes, quartos[i].valorDiaria, quartos[i].status);
        }
    }
}

// Função para listar todas as estadias
// Saída: lista de estadias cadastradas
void listarEstadias() {
    if (totalEstadias == 0) {
        printf("Nenhuma estadia cadastrada.\n");
    } else {
        printf("Lista de Estadias:\n");
        for (int i = 0; i < totalEstadias; i++) {
            printf("Código: %d, Cliente: %d, Quarto: %d, Data de Entrada: %s, Data de Saída: %s, Quantidade de Diárias: %d\n",
                   estadias[i].codigo, estadias[i].clienteCodigo, estadias[i].quartoNumero, estadias[i].dataEntrada, estadias[i].dataSaida, estadias[i].quantidadeDiarias);
        }
    }
}
