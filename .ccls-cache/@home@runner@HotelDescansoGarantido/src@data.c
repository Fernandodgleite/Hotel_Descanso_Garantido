#include "../include/data.h"
#include <stdio.h>

void carregarDados(Cliente clientes[], int *totalClientes, Funcionario funcionarios[], int *totalFuncionarios, Quarto quartos[], int *totalQuartos, Estadia estadias[], int *totalEstadias) {
    FILE *file;

    // Carregar clientes
    file = fopen("data/clientes.dat", "rb");
    if (file == NULL) {
        printf("Arquivo clientes.dat não encontrado, iniciando com base vazia.\n");
    } else {
        fread(totalClientes, sizeof(int), 1, file);
        fread(clientes, sizeof(Cliente), *totalClientes, file);
        fclose(file);
    }

    // Carregar funcionários
    file = fopen("data/funcionarios.dat", "rb");
    if (file == NULL) {
        printf("Arquivo funcionarios.dat não encontrado, iniciando com base vazia.\n");
    } else {
        fread(totalFuncionarios, sizeof(int), 1, file);
        fread(funcionarios, sizeof(Funcionario), *totalFuncionarios, file);
        fclose(file);
    }

    // Carregar quartos
    file = fopen("data/quartos.dat", "rb");
    if (file == NULL) {
        printf("Arquivo quartos.dat não encontrado, iniciando com base vazia.\n");
    } else {
        fread(totalQuartos, sizeof(int), 1, file);
        fread(quartos, sizeof(Quarto), *totalQuartos, file);
        fclose(file);
    }

    // Carregar estadias
    file = fopen("data/estadias.dat", "rb");
    if (file == NULL) {
        printf("Arquivo estadias.dat não encontrado, iniciando com base vazia.\n");
    } else {
        fread(totalEstadias, sizeof(int), 1, file);
        fread(estadias, sizeof(Estadia), *totalEstadias, file);
        fclose(file);
    }
}

void salvarDados(Cliente clientes[], int totalClientes, Funcionario funcionarios[], int totalFuncionarios, Quarto quartos[], int totalQuartos, Estadia estadias[], int totalEstadias) {
    FILE *file;

    // Salvar clientes
    file = fopen("data/clientes.dat", "wb");
    fwrite(&totalClientes, sizeof(int), 1, file);
    fwrite(clientes, sizeof(Cliente), totalClientes, file);
    fclose(file);

    // Salvar funcionários
    file = fopen("data/funcionarios.dat", "wb");
    fwrite(&totalFuncionarios, sizeof(int), 1, file);
    fwrite(funcionarios, sizeof(Funcionario), totalFuncionarios, file);
    fclose(file);

    // Salvar quartos
    file = fopen("data/quartos.dat", "wb");
    fwrite(&totalQuartos, sizeof(int), 1, file);
    fwrite(quartos, sizeof(Quarto), totalQuartos, file);
    fclose(file);

    // Salvar estadias
    file = fopen("data/estadias.dat", "wb");
    fwrite(&totalEstadias, sizeof(int), 1, file);
    fwrite(estadias, sizeof(Estadia), totalEstadias, file);
    fclose(file);
}
