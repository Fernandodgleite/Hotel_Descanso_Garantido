#include "../include//estadia.h"
#include <stdio.h>
#include <string.h>

int calcularQuantidadeDiarias(char* dataEntrada, char* dataSaida) {
    int diaEntrada, mesEntrada, anoEntrada;
    int diaSaida, mesSaida, anoSaida;
    sscanf(dataEntrada, "%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
    sscanf(dataSaida, "%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);

    int diasEntrada = anoEntrada * 365 + mesEntrada * 30 + diaEntrada;
    int diasSaida = anoSaida * 365 + mesSaida * 30 + diaSaida;

    return diasSaida - diasEntrada;
}

void cadastrarEstadia(Cliente clientes[], int totalClientes, Quarto quartos[], int totalQuartos, Estadia estadias[], int *totalEstadias) {
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

    for (int i = 0; i < *totalEstadias; i++) {
        if (estadias[i].quartoNumero == quartos[quartoDisponivel].numero &&
            strcmp(estadias[i].dataEntrada, dataEntrada) == 0 && strcmp(estadias[i].dataSaida, dataSaida) == 0) {
            printf("Já existe uma estadia para este quarto no mesmo período!\n");
            return;
        }
    }

    estadia.codigo = *totalEstadias + 1;
    estadia.clienteCodigo = codigoCliente;
    estadia.quartoNumero = quartos[quartoDisponivel].numero;
    strcpy(estadia.dataEntrada, dataEntrada);
    strcpy(estadia.dataSaida, dataSaida);
    estadia.quantidadeDiarias = calcularQuantidadeDiarias(dataEntrada, dataSaida);

    estadias[(*totalEstadias)++] = estadia;
    strcpy(quartos[quartoDisponivel].status, "ocupado");

    printf("Estadia cadastrada com sucesso!\n");
}

void darBaixaEstadia(Quarto quartos[], int totalQuartos, Estadia estadias[], int *totalEstadias) {
    int codigoEstadia;
    printf("Código da estadia: ");
    scanf("%d", &codigoEstadia);

    int estadiaEncontrada = 0;
    for (int i = 0; i < *totalEstadias; i++) {
        if (estadias[i].codigo == codigoEstadia) {
            estadiaEncontrada = 1;

            int quartoNumero = estadias[i].quartoNumero;
            float valorTotal = estadias[i].quantidadeDiarias * quartos[quartoNumero - 1].valorDiaria;

            printf("Valor total a ser pago: %.2f\n", valorTotal);
            strcpy(quartos[quartoNumero - 1].status, "desocupado");

            // Remover a estadia
            for (int j = i; j < *totalEstadias - 1; j++) {
                estadias[j] = estadias[j + 1];
            }
            (*totalEstadias)--;

            break;
        }
    }

    if (!estadiaEncontrada) {
        printf("Estadia não encontrada!\n");
    }
}

void calcularPontosFidelidade(Cliente clientes[], int totalClientes, Estadia estadias[], int totalEstadias) {
    int codigoCliente;
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

    int pontosFidelidade = 0;
    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].clienteCodigo == codigoCliente) {
            pontosFidelidade += estadias[i].quantidadeDiarias * 10;
        }
    }

    printf("Total de pontos de fidelidade: %d\n", pontosFidelidade);
}

void listarEstadias(Estadia estadias[], int totalEstadias) {
    if (totalEstadias == 0) {
        printf("Nenhuma estadia cadastrada.\n");
    } else {
        printf("Lista de Estadias:\n");
        for (int i = 0; i < totalEstadias; i++) {
            printf("Código: %d, Cliente: %d, Quarto: %d, Entrada: %s, Saída: %s, Diárias: %d\n",
                   estadias[i].codigo, estadias[i].clienteCodigo, estadias[i].quartoNumero,
                   estadias[i].dataEntrada, estadias[i].dataSaida, estadias[i].quantidadeDiarias);
        }
    }
}

void mostrarEstadiasCliente(Estadia estadias[], int totalEstadias) {
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
