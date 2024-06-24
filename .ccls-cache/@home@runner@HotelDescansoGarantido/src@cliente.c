#include "../include/cliente.h"
#include <stdio.h>
#include <string.h>

void cadastrarCliente(Cliente clientes[], int *totalClientes) {
    Cliente cliente;
    printf("Nome do cliente: ");
    scanf(" %[^\n]", cliente.nome);
    printf("Endereço do cliente: ");
    scanf(" %[^\n]", cliente.endereco);
    printf("Telefone do cliente: ");
    scanf(" %[^\n]", cliente.telefone);

    cliente.codigo = *totalClientes + 1;
    clientes[(*totalClientes)++] = cliente;
    printf("Cliente cadastrado com sucesso!\n");
}

void listarClientes(Cliente clientes[], int totalClientes) {
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

void pesquisarCliente(Cliente clientes[], int totalClientes) {
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
