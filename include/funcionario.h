#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "structs.h"

void cadastrarFuncionario(Funcionario funcionarios[], int *totalFuncionarios);
void listarFuncionarios(Funcionario funcionarios[], int totalFuncionarios);
void pesquisarFuncionario(Funcionario funcionarios[], int totalFuncionarios);

#endif // FUNCIONARIO_H
