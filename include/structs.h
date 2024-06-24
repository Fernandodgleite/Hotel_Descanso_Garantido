#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 50
#define MAX_QUARTOS 50
#define MAX_ESTADIAS 100

typedef struct {
    int codigo;
    char nome[100];
    char endereco[150];
    char telefone[20];
} Cliente;

typedef struct {
    int codigo;
    char nome[100];
    char telefone[20];
    char cargo[50];
    float salario;
} Funcionario;

typedef struct {
    int numero;
    int quantidadeHospedes;
    float valorDiaria;
    char status[20]; // "ocupado" ou "desocupado"
} Quarto;

typedef struct {
    int codigo;
    int clienteCodigo;
    int quartoNumero;
    char dataEntrada[11];
    char dataSaida[11];
    int quantidadeDiarias;
} Estadia;

#endif // STRUCTS_H
