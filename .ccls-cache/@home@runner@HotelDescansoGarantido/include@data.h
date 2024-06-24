#ifndef DATA_H
#define DATA_H

#include "structs.h"

void carregarDados(Cliente clientes[], int *totalClientes, Funcionario funcionarios[], int *totalFuncionarios, Quarto quartos[], int *totalQuartos, Estadia estadias[], int *totalEstadias);
void salvarDados(Cliente clientes[], int totalClientes, Funcionario funcionarios[], int totalFuncionarios, Quarto quartos[], int totalQuartos, Estadia estadias[], int totalEstadias);

#endif // DATA_H
