#include <stdio.h>
#include <locale.h>
#include "../include/structs.h"
#include "../include/cliente.h"
#include "../include/funcionario.h"
#include "../include/quarto.h"
#include "../include/estadia.h"
#include "../include/data.h"

Cliente clientes[MAX_CLIENTES];
Funcionario funcionarios[MAX_FUNCIONARIOS];
Quarto quartos[MAX_QUARTOS];
Estadia estadias[MAX_ESTADIAS];

int totalClientes = 0;
int totalFuncionarios = 0;
int totalQuartos = 0;
int totalEstadias = 0;

int main() {
    setlocale(LC_ALL, "Portuguese");

    carregarDados(clientes, &totalClientes, funcionarios, &totalFuncionarios, quartos, &totalQuartos, estadias, &totalEstadias);

    int opcao;
    do {
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
                cadastrarCliente(clientes, &totalClientes);
                salvarDados(clientes, totalClientes, funcionarios, totalFuncionarios, quartos, totalQuartos, estadias, totalEstadias);
                break;
            case 2:
                cadastrarFuncionario(funcionarios, &totalFuncionarios);
                salvarDados(clientes, totalClientes, funcionarios, totalFuncionarios, quartos, totalQuartos, estadias, totalEstadias);
                break;
            case 3:
                cadastrarQuarto(quartos, &totalQuartos);
                salvarDados(clientes, totalClientes, funcionarios, totalFuncionarios, quartos, totalQuartos, estadias, totalEstadias);
                break;
            case 4:
                cadastrarEstadia(clientes, totalClientes, quartos, totalQuartos, estadias, &totalEstadias);
                salvarDados(clientes, totalClientes, funcionarios, totalFuncionarios, quartos, totalQuartos, estadias, totalEstadias);
                break;
            case 5:
                darBaixaEstadia(quartos, totalQuartos, estadias, &totalEstadias);
                salvarDados(clientes, totalClientes, funcionarios, totalFuncionarios, quartos, totalQuartos, estadias, totalEstadias);
                break;
            case 6:
                pesquisarCliente(clientes, totalClientes);
                break;
            case 7:
                pesquisarFuncionario(funcionarios, totalFuncionarios);
                break;
            case 8:
                mostrarEstadiasCliente(estadias, totalEstadias);
                break;
            case 9:
                calcularPontosFidelidade(clientes, totalClientes, estadias, totalEstadias);
                break;
            case 10:
                listarClientes(clientes, totalClientes);
                break;
            case 11:
                listarFuncionarios(funcionarios, totalFuncionarios);
                break;
            case 12:
                listarQuartos(quartos, totalQuartos);
                break;
            case 13:
                listarEstadias(estadias, totalEstadias);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}