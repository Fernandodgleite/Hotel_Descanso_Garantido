#include "../include/funcionario.h"
#include <stdio.h>
#include <string.h>

void cadastrarFuncionario(Funcionario funcionarios[], int *totalFuncionarios) {
    Funcionario funcionario;
    printf("Nome do funcionário: ");
    scanf(" %[^\n]", funcionario.nome);
    printf("Telefone do funcionário: ");
    scanf(" %[^\n]", funcionario.telefone);
    printf("Cargo do funcionário: ");
    scanf(" %[^\n]", funcionario.cargo);
    printf("Salário do funcionário: ");
    scanf("%f", &funcionario.salario);

    funcionario.codigo = *totalFuncionarios + 1;
    funcionarios[(*totalFuncionarios)++] = funcionario;
    printf("Funcionário cadastrado com sucesso!\n");
}

void listarFuncionarios(Funcionario funcionarios[], int totalFuncionarios) {
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

void pesquisarFuncionario(Funcionario funcionarios[], int totalFuncionarios) {
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
