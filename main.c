/******************************************************************************
Grupo 1;
Aluno 1: Emily Vitorya de Moura;
Aluno 2: Gabriel Alves de Oliveira;
Aluno 3: Pedro Henrique Sauné;
Turma: C11;
Projeto Final;
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct data {
    int dia,
    mes,
    ano;
} Data;

typedef struct telefone {
    int DDD;
    long int numero;
} Telefone;

typedef struct cliente {
    char nome[50];
    char CPF[15];
    Telefone fone;
    Data nascimento;
} Cliente;

typedef struct investimento {
    int tipoAplicacao;
    char emissor[100];
    float taxa;
    char ativo;
} Investimento;

typedef struct transacao{
    int idTransacao;
    Cliente cliente;
    Investimento investimento;
    Data dataAplicacao;
    float valorAplicacao;
    Data dataResgate;
    float valorResgate;
    
} Transacao;

int main()
{
    
    printf("Hello World");

    return 0;
}
