#ifndef ESTADIA_H
#define ESTADIA_H

#include "structs.h"

void cadastrarEstadia(Cliente clientes[], int totalClientes, Quarto quartos[], int totalQuartos, Estadia estadias[], int *totalEstadias);
void listarEstadias(Estadia estadias[], int totalEstadias);
void darBaixaEstadia(Quarto quartos[], int totalQuartos, Estadia estadias[], int *totalEstadias);
void calcularPontosFidelidade(Cliente clientes[], int totalClientes, Estadia estadias[], int totalEstadias);
void mostrarEstadiasCliente(Estadia estadias[], int totalEstadias);

#endif // ESTADIA_H
