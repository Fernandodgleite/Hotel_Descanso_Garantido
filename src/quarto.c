#include "../include/quarto.h"
#include <stdio.h>
#include <string.h>

void cadastrarQuarto(Quarto quartos[], int *totalQuartos) {
    Quarto quarto;
    printf("Número do quarto: ");
    scanf("%d", &quarto.numero);
    printf("Quantidade de hóspedes: ");
    scanf("%d", &quarto.quantidadeHospedes);
    printf("Valor da diária: ");
    scanf("%f", &quarto.valorDiaria);
    strcpy(quarto.status, "desocupado");

    quartos[(*totalQuartos)++] = quarto;
    printf("Quarto cadastrado com sucesso!\n");
}

void listarQuartos(Quarto quartos[], int totalQuartos) {
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
