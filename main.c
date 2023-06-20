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

Cliente cliente_nulo={"~","000.000.000-00",{0,0},{0,0,0}};
Cliente clientes[100];
int numero_de_clientes=0;

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
    int ncpf[11]={0,0,0,0,0,0,0,0,0,0,0};
    int num=0;
    for(int i=0; i<3; i++){
        ncpf[i]=cpf[i]-48;
    }
    for(int i=4; i<7; i++){
        ncpf[i-1]=cpf[i]-48;
    }
    for(int i=8; i<11; i++){
        ncpf[i-2]=cpf[i]-48;
    }
    for (int i=0; i<9; i++){
        num+=(ncpf[i])*(i+1);
    }
    num=num%11;
    if(num<2){
        num=0;
    }
    if(num!=cpf[12]-48){
        return 0;
    } else{
        ncpf[9]=num;
        num=0;
        for (int i=0; i<9; i++){
            num+=(ncpf[i+1])*(10-i);
        }
        num=num%11;
        num=11-num;
        if(num!=cpf[13]-48){
            return 0;
        }else{
            return 1;
        }
    }
}

int validar_telefone(Telefone a){
    int aux=a.numero/pow(10,7);
    if(11<=a.DDD&&a.DDD<=91){
        if ((aux>=1 && aux<=9) || (aux >= 91 && aux <= 99)){
            return 1;
        }
    }
    return 0;
}

Investimento cadastrar_invenstimento(void){
    Investimento investimento;
    
    getchar();
    printf("Banco emissor: ");
    gets(investimento.emissor);
    printf("Qual o tipo de aplicação (1 / 2 / 3): ");
    scanf("%d", &investimento.tipoAplicacao);
    printf("Qual a porcentagem da taxa sobre o investimento: ");
    scanf("%f", &investimento.taxa);
    investimento.ativo = 'S';
    printf("\n\n");
    return investimento;
}

Transacao comprar_investimento(int id, Cliente c, Investimento i){
    Transacao transacao;
    transacao.idTransacao = id;
    transacao.cliente = c;
    transacao.investimento = i;
    transacao.dataAplicacao = {19, 06, 2023};
    printf("quanto gostaria de investir nessa ação: ");
    scanf("%f", &transacao.valorAplicacao);
    transacao.dataResgate = {0, 0, 0};
    transacao.valorResgate = 0.0;
    return transacao;
}

void Criar_cliente (void){
    for(int p=0; p<1; p++){
        Cliente b;
        Telefone t;
        char Cpf[15];
        printf("Nome do Cliente.: ");
        getchar();
        fgets(b.nome, 50, stdin);
        b.nome[strlen(b.nome)-1]='\0';
        char cpf_formatado[15];
        int ver=0;
        while(ver==0){
            printf("Digitar CPF do Cliente (ex: xxx.xxx.xxx-xx).: ");
            fgets(Cpf, 15, stdin);
            for(int i=0; i<3; i++){
                cpf_formatado[i]=Cpf[i];
            }
            for(int i=4; i<7; i++){
                cpf_formatado[i]=Cpf[i];
            }
            for(int i=8; i<11; i++){
                cpf_formatado[i]=Cpf[i];
            }
            for(int i=12; i<14; i++){
                cpf_formatado[i]=Cpf[i];
            }
            cpf_formatado[3]='.';
            cpf_formatado[7]='.';
            cpf_formatado[11]='-';
            
            ver=validar_cpf(cpf_formatado);
            if(ver==0){
                printf("CPF inválido!\n");
                getchar();
            }
        }
        int cpf_repetido=0;
        for(int q=0; q<numero_de_clientes; q++){
            if(strcmp(clientes[q].CPF, cpf_formatado)==0){
                cpf_repetido=1;
            }
        }
        if(cpf_repetido==0){
            strcpy(b.CPF, cpf_formatado);
            printf("Digitar o Telefone do Cliente (ex: xx xxxxxxxx).: ");
            scanf("%d%ld", &t.DDD ,&t.numero);
            while(validar_telefone(t)==0){
                printf("Número Inválido!\nDigite novamente.: ");
                scanf("%d%ld", &t.DDD, &t.numero);
            }
            b.fone=t;
            printf("Digitar data do nascimento do Cliente (ex: dd mm yyyy)\n");
            Data d;
            do{
                d=criar_data();
                if(validar_data(d)==0){
                    printf("Data inválida\n");
                }
            }while(validar_data(d)==0);
            b.nascimento=d;
            clientes[numero_de_clientes]=b;
            numero_de_clientes++;
        }else{
            printf("Já existe um cliente cadastrado com esse CPF, cadastro cancelado\n");
        }
    }
    printf("\n");
}

void exibir_clientes(){
    for(int i=0; i<numero_de_clientes; i++){
        printf("Nome.: %s | Telefone.: %d %ld | CPF.: %s | ", clientes[i].nome, clientes[i].fone.DDD, clientes[i].fone.numero, clientes[i].CPF);
        exibir_data(clientes[i].nascimento);
    }
}

void alfabetica(Cliente a[]){
    Cliente aux={};
    for (int j=0; j<100; j++){
        for (int i=0; i<98; i++){
            if((a[i+1].nome[0]>65)&&(a[i].nome[0]>65)&&strcmp(a[i].nome, a[i+1].nome)>0){
                aux=a[i+1];
                a[i+1]=a[i];
                a[i]=aux;
            }
        }
    }
}

void excluir_cliente(char cpf[]){
    char cpf_formatado[15];
    for(int i=0; i<3; i++){
        cpf_formatado[i]=cpf[i];
    }
    for(int i=4; i<7; i++){
        cpf_formatado[i]=cpf[i];
    }
    for(int i=8; i<11; i++){
        cpf_formatado[i]=cpf[i];
    }
    for(int i=12; i<14; i++){
        cpf_formatado[i]=cpf[i];
    }
    cpf_formatado[3]='.';
    cpf_formatado[7]='.';
    cpf_formatado[11]='-';
    
    if (validar_cpf(cpf_formatado)==0){
        printf("CPF inválido");
    } 
    
    for(int q=0; q<numero_de_clientes; q++){
        if(strcmp(clientes[q].CPF, cpf_formatado)==0){
            clientes[q]=cliente_nulo;
            numero_de_clientes--;
        }
    }
}

int main()
{
    Investimento investimentos[30];
    int count = 0, texto, id_transacao = 0;

    
    while(1){
        alfabetica(clientes);
        printf("Digite\n1 para cadastrar um novo cliente.\n2 para exibir todos os clientes.\n3 para excluir um cliente (pelo CPF).\n4 para criar investimentos\n5 Compra Investimentos\n\n");
        scanf("%d", &texto);
        if (texto==1){
           Criar_cliente();
        }
        if (texto==2){
           exibir_clientes();
           printf("\n");
        }
        if (texto==3){
            char cpf_a_ser_excluido[15];
            getchar();
            fgets(cpf_a_ser_excluido, 15, stdin);
            excluir_cliente(cpf_a_ser_excluido);
            printf("\n\n");
       }
       if(texto == 4){
        do {
            printf("quantos investimentos gostaria de realizar? ");
            scanf("%d", &count);
        } while (count < 1 || count > 30);

        for(int i = 0; i < count; i++){
            investimentos[i] = cadastrar_invenstimento();
        }
       }
       if(texto == 5){
            
            // printf("");

            // comprar_investimento(id_transacao, );
            // id_transacao++;
       }
   }

    return 0;
}