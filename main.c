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

int validar_data(Data a){
    if(1<=a.dia&&a.dia<=30){
        if(1<=a.mes&&a.mes<=12){
            if(1900<=a.ano&&a.ano<=2023) return 1;
        }
    }
    return 0;
}

void exibir_data(Data a){
    printf("Data:");
    printf(a.dia<10 ? "0%d/" : "%d/", a.dia);
    printf(a.mes<10 ? "0%d/" : "%d/", a.mes);
    printf("%d\n",a.ano);
}

Data criar_data(void){
    Data datap;
    printf("Data.:");
    scanf("%d%d%d", &datap.dia,&datap.mes,&datap.ano);
    if (validar_data(datap)==1){
        exibir_data(datap);
        return datap;
    }
    return(Data) {0,0,0};
}

int validar_cpf(char cpf[15]){
    int soma = 0;
    int resto = 0;

    for(int c = 0; c < 9; c++){

        soma += ((cpf[c] - 48) * (10-c));
    }
    resto = soma % 11;

    if (resto < 2){     
        if(cpf[10]-48 != 0){
            return 0;
        }

    }else{
        if(cpf[10]-48 != 11-resto){
            return 0;   
        }
    }

    soma = (cpf[10] - 48) * 2;

    for(int c = 0; c < 9; c++){

        soma += ((cpf[c] - 48) * (11-c));
    }

    resto = soma % 11;

    if (resto < 2){     
        if(cpf[11] != 0){
            return 0;
        }

    }else{
        if(cpf[11]-48 != 11-resto){
            return 0;   
        }
    }
    return 1;
}

int main()
{
    int valido = validar_cpf("444.934.918-09");
    printf("%d", valido);

    return 0;
}