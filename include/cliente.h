#ifndef CLIENTE_H
#define CLIENTE_H

#include "structs.h"

void cadastrarCliente(Cliente clientes[], int *totalClientes);
void listarClientes(Cliente clientes[], int totalClientes);
void pesquisarCliente(Cliente clientes[], int totalClientes);

#endif // CLIENTE_H
