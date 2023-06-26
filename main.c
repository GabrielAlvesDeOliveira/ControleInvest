/******************************************************************************
Grupo 1;
Aluno 1: Emily Vitorya de Moura;
RA....1: 2575337;
Aluno 2: Gabriel Alves de Oliveira;
RA....2: 2575353;
Aluno 3: Pedro Henrique Sauné;
RA....3: 2564572;
Turma: C11;
Projeto Final;
*******************************************************************************/

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Registros do programa
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

// Definindo variaveis globais
Data data_atual={25,06,2023};
Data data_nula={0,0,0000};
Cliente cliente_nulo={"~~","000.000.000-00",{0,0},{0,0,0}};
Cliente clientes[100];
int numero_de_clientes=0;

// Prototipos das funções
int validar_data(Data data);
int validar_data_resgate(Data resgate);
void exibir_data(Data a);
Data criar_data(void);
int validar_cpf(char cpf[15]);
int validar_telefone(Telefone a);
Investimento cadastrar_investimento(void);
Transacao comprar_investimento(int id, Cliente c, Investimento i);
void criar_cliente (void);
void exibir_clientes(void);
void alfabetica(Cliente a[]);
void excluir_cliente(char cpf[]);
int dias_entre_datas(Data p, Data q);

// Criando as funções
int validar_data(Data data){
    if(1<=data.dia&&data.dia<=30){
        if(1<=data.mes&&data.mes<=12){
            if(1900<=data.ano&&data.ano<=2023) return 1;
        }
    }
    return 0;
}
int validar_data_resgate(Data data_resgate){
    if(1<=data_resgate.dia&&data_resgate.dia<=30){
        if(1<=data_resgate.mes&&data_resgate.mes<=12){
            if(data_resgate.ano>=data_atual.ano) return 1;
        }
    }
    return 0;
}
// Formatador de datas:
void exibir_data(Data data){
    printf("Data:");
    printf(data.dia<10 ? "0%d/" : "%d/", data.dia);
    printf(data.mes<10 ? "0%d/" : "%d/", data.mes);
    printf("%d\n",data.ano);
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
    int ncpf[11];
    int k=0, num=0, dif_dig=1;
    ncpf[0]=cpf[0]-'0';
    ncpf[1]=cpf[1]-'0';
    ncpf[2]=cpf[2]-'0';
    ncpf[3]=cpf[4]-'0';
    ncpf[4]=cpf[5]-'0';
    ncpf[5]=cpf[6]-'0';
    ncpf[6]=cpf[8]-'0';
    ncpf[7]=cpf[9]-'0';
    ncpf[8]=cpf[10]-'0';
    ncpf[9]=cpf[12]-'0';
    ncpf[10]=cpf[13]-'0';
    ncpf[11]=cpf[14]-'0';
    for(int l=0; l<11; l++){
        if(ncpf[l]!=ncpf[0]){
            dif_dig*=0;
        }
    }
    for(int q=0; q<9; q++){
        num+=ncpf[q]*(10-q);
    }
    num=((num*10)%11)%10;
    if(num!=ncpf[9]||(dif_dig!=0)){
        return 0;
    }else{
        num=0;
        for(int q=0; q<10; q++){
        num+=ncpf[q]*(11-q);
        }
        num=((num*10)%11)%10;
        if(num!=ncpf[10]){
            return 0;
        }else{
            return 1;}
        }
}
int validar_telefone(Telefone fone){
    int aux=fone.numero/pow(10,7); // <- Variavel auxiliar
    if(11<=fone.DDD&&fone.DDD<=91){
        if ((aux>=1 && aux<=9) || (aux >= 91 && aux <= 99)){
            return 1;
        }
    }
    return 0;
}
Investimento cadastrar_investimento(void){
    Investimento investimento;
    getchar();
    printf("Banco emissor: ");
    fgets(investimento.emissor, 100, stdin);
    printf("Qual o tipo de aplicação (1 / 2 / 3): ");
    scanf("%d", &investimento.tipoAplicacao);
    printf("Qual a porcentagem da taxa sobre o investimento: (sem %%, apenas o número)");
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
    transacao.dataAplicacao = data_atual;
    printf("quanto gostaria de investir nessa ação: ");
    scanf("%f", &transacao.valorAplicacao);
    transacao.dataResgate = data_nula;
    transacao.valorResgate = 0.0;
    return transacao;
}
void criar_cliente (void){
    for(int p=0; p<1; p++){
        Cliente usuario;
        Telefone t;
        char Cpf[15];
        printf("Nome do Cliente.: ");
        getchar();
        fgets(usuario.nome, 50, stdin);
        usuario.nome[strlen(usuario.nome)-1]='\0';
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
            strcpy(usuario.CPF, cpf_formatado);
            printf("Digitar o Telefone do Cliente (ex: xx xxxxxxxx).: ");
            scanf("%d%ld", &t.DDD ,&t.numero);
            while(validar_telefone(t)==0){
                printf("Número Inválido!\nDigite novamente.: ");
                scanf("%d%ld", &t.DDD, &t.numero);
            }
            usuario.fone=t;
            printf("Digitar data do nascimento do Cliente (ex: dd mm yyyy)\n");
            Data d;
            do{
                d=criar_data();
                if(validar_data(d)==0){
                    printf("Data inválida\n");
                }
            }while(validar_data(d)==0);
            usuario.nascimento=d;
            clientes[numero_de_clientes]=usuario;
            numero_de_clientes++;
        }else{
            printf("Já existe um cliente cadastrado com esse CPF, cadastro cancelado\n");
        }
    }
    printf("\n");
}
void exibir_clientes(void){
    for(int i=0; i<numero_de_clientes; i++){
        printf("Nome.: %s | Telefone.: %d %ld ", clientes[i].nome, clientes[i].fone.DDD, clientes[i].fone.numero);
    }
}
void alfabetica(Cliente cliente_ordenado[]){
    Cliente aux={}; // <- Variavel auxiliar
    for (int j=0; j<100; j++){
        for (int i=0; i<98; i++){
            if((cliente_ordenado[i+1].nome[0]>65)&&(cliente_ordenado[i].nome[0]>65)&&strcmp(cliente_ordenado[i].nome, cliente_ordenado[i+1].nome)>0){
                aux=cliente_ordenado[i+1];
                cliente_ordenado[i+1]=cliente_ordenado[i];
                cliente_ordenado[i]=aux;
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
int dias_entre_datas(Data data_antiga, Data data_nova){
    return (-(data_antiga.ano*365+data_antiga.mes*30+data_antiga.dia)+(data_nova.ano*365+data_nova.mes*30+data_nova.dia));
}
// Função responsável por fazer o calculo dos impostos e dos lucros
float lucro_real(float valor, float taxa, int num, int dif_data){
    float imposto = 0, lucro = 0;
    switch(num){
        case 1:
            lucro = valor * (taxa / 100);
            break;
        case 2:
            lucro = valor * (taxa / 100);
            if(dif_data<=180){
                imposto = lucro * 0.225;
            }
            if(181<dif_data&&dif_data<=360){
                imposto = lucro * 0.2;
            }
            if(361<dif_data&&dif_data<=720){
                imposto = lucro * 0.175;
            }
            if(720<dif_data){
                imposto = lucro * 0.15;
            }
            break;
        case 3:
            lucro = valor * ((taxa / 100) + 0.01);
            if(dif_data<=180){
                imposto = lucro * 0.225;
            }
            if(181<dif_data&&dif_data<=360){
                imposto = lucro * 0.2;
            }
            if(361<dif_data&&dif_data<=720){
                imposto = lucro * 0.175;
            }
            if(720<dif_data){
                imposto = lucro * 0.15;
            }
            break;
        default:
            return 0;
    }
    
    return lucro - imposto;
}
int main()
{
    Investimento investimentos[30];
    Transacao transacao[100];
    char cpf_cliente[15];
    char cpf_formatado[15];
    int count = 0, digito, id_transacao = 0, id_investimento = 0;
    float montante_usuario = 0.0, lci = 0.0, cdb = 0.0, fundos = 0.0;
    while(1){
        alfabetica(clientes);
        printf("\nDigite\n1 Para cadastrar um novo cliente.\n2 Para exibir todos os clientes.\n3 Para excluir um cliente (pelo CPF).\n4 Para criar investimentos\n5 Comprar Investimentos\n6 Desativar investimentos\n7 Vender investimentos\n8 Mostrar Quanto que o cliente já resgatou\n9 Mostrar quanto de dinheiro possui cada investimento\n\n");
        scanf("%d", &digito);
        if (digito==1){
           criar_cliente();
        }
        if (digito==2){
           exibir_clientes();
           printf("\n");
        }
        if (digito==3){
            char cpf_a_ser_excluido[15];
            getchar();
            fgets(cpf_a_ser_excluido, 15, stdin);
            excluir_cliente(cpf_a_ser_excluido);
            printf("\n\n");
       }
       if(digito == 4){
        do {
            printf("quantos investimentos gostaria de realizar? ");
            scanf("%d", &count);
        } while (count < 1 || count > 30);

        for(int i = 0; i < count; i++){
            investimentos[i] = cadastrar_investimento();
        }
       }
       if(digito == 5){ 
            int n = sizeof(investimentos)/sizeof(investimentos[0]), qtd = 0;
            for(int index = 0; index < n; index++){
                if(investimentos[index].ativo == 'S') {
                    printf("ID: %d | Tipo de aplicação: %d | emissor: %s | taxa: %.2f\n", index, investimentos[index].tipoAplicacao, investimentos[index].emissor, investimentos[index].taxa);
                    qtd++;
                }
            }
            if(qtd > 0){
            printf("Digite o CPF do cliente: ");
            getchar();
            fgets(cpf_cliente, 15, stdin);
            for(int i=0; i<3; i++){
                cpf_formatado[i]=cpf_cliente[i];
            }
            for(int i=4; i<7; i++){
                cpf_formatado[i]=cpf_cliente[i];
            }
            for(int i=8; i<11; i++){
                cpf_formatado[i]=cpf_cliente[i];
            }
            for(int i=12; i<14; i++){
                cpf_formatado[i]=cpf_cliente[i];
            }
            cpf_formatado[3]='.';
            cpf_formatado[7]='.';
            cpf_formatado[11]='-';
            if (validar_cpf(cpf_formatado)==0){
                printf("CPF inválido");
            } 
            for(int q=0; q<numero_de_clientes; q++){
                if(strcmp(clientes[q].CPF, cpf_formatado)==0){
                    printf("Digite o id de investimento: ");
                    scanf("%d", &id_investimento);
                    transacao[id_transacao] = comprar_investimento(id_transacao+1, clientes[q], investimentos[id_investimento]);
                    id_transacao++;
                }
            }
            qtd = 0;
            }else {
                printf("\nSem Investimentos para comprar\n");
            }
       }
       if( digito == 6) {
           int n = sizeof(investimentos)/sizeof(investimentos[0]);
           for(int index = 0; index < n; index++){
                if(investimentos[index].ativo == 'S') printf("ID: %d | Tipo de aplicação: %d | emissor: %s | taxa: %f\n", index, investimentos[index].tipoAplicacao, investimentos[index].emissor, investimentos[index].taxa);
            }
            printf("\nDigite o ID do investimento desejado para desativar\n");
            scanf("%d", &id_investimento);
            
            for(int index = 0; index < n; index++){
                if(index == id_investimento) investimentos[index].ativo = 'N';
            }
       }
       if( digito == 7){
           size_t length_transacao = sizeof(transacao)/sizeof(transacao[0]);
           int id = 0, diferenca_data = 0, qtd_investimentos = 0;
           float lucro = 0.0;
           Data data_resgate;
           for(int index = 0; index < length_transacao; index++){
              if(transacao[index].valorAplicacao >= 1 && transacao[index].dataAplicacao.dia >= 1 && transacao[index].investimento.taxa >= 0.1 && transacao[index].dataResgate.dia <= 0){
                  printf("\nId da transacao: %d", transacao[index].idTransacao);
                  printf("\nCpf do cliente: %s", transacao[index].cliente.CPF);
                  printf("\nCódigo de aplicação: %d", transacao[index].investimento.tipoAplicacao);
                  printf("\nTaxa: %f", transacao[index].investimento.taxa);
                  printf("\nValor investido: %f", transacao[index].valorAplicacao);
                  printf("\n---------------------------------------------------------------------------------\n");
                  qtd_investimentos++;
              }
           }
           if(qtd_investimentos > 0){
           printf("\nDigite o ID da transacao que gostaria de vender: ");
           scanf("%d", &id);
            do {
                    printf("digite o dia do resgate: ");
                    scanf("%d", &data_resgate.dia);
                    printf("digite o mes do resgate: ");
                    scanf("%d", &data_resgate.mes);
                    printf("digite o ano do resgate: ");
                    scanf("%d", &data_resgate.ano);
            } while(validar_data_resgate(data_resgate) == 0);
           for(int index = 0; index < length_transacao; index++){
              if(transacao[index].valorAplicacao >= 1 && transacao[index].dataAplicacao.dia >= 1){
                diferenca_data = dias_entre_datas(transacao[index].dataAplicacao, data_resgate);
                transacao[index].dataResgate.dia = data_resgate.dia;
                transacao[index].dataResgate.mes = data_resgate.mes;
                transacao[index].dataResgate.ano = data_resgate.ano;
                transacao[index].valorResgate = transacao[index].valorAplicacao + lucro_real(transacao[index].valorAplicacao, transacao[index].investimento.taxa, transacao[index].investimento.tipoAplicacao, diferenca_data);
                }
            }
           qtd_investimentos = 0;
           }else {
               printf("\nSem transacoes cadastradas!\n");
           }
    }
       if(digito == 8){
           printf("Digite o cpf do cliente: ");
            getchar();
            fgets(cpf_cliente, 15, stdin);

            for(int i=0; i<3; i++){
                cpf_formatado[i]=cpf_cliente[i];
            }
            for(int i=4; i<7; i++){
                cpf_formatado[i]=cpf_cliente[i];
            }
            for(int i=8; i<11; i++){
                cpf_formatado[i]=cpf_cliente[i];
            }
            for(int i=12; i<14; i++){
                cpf_formatado[i]=cpf_cliente[i];
            }
            cpf_formatado[3]='.';
            cpf_formatado[7]='.';
            cpf_formatado[11]='-';
            
            if (validar_cpf(cpf_formatado)==0){
                printf("CPF inválido");
            }
            
            for(int q=0; q<numero_de_clientes; q++){
                if(strcmp(clientes[q].CPF, cpf_formatado)==0){
                    for(int index = 0;index < (sizeof(transacao)/sizeof(transacao[0])); index++){
                        if(strcmp(transacao[index].cliente.CPF, cpf_formatado) == 0 && transacao[index].investimento.taxa >=0.1 && transacao[index].valorResgate > 0.0 && transacao[index].dataResgate.dia >= 1){
                           montante_usuario += transacao[index].valorResgate;
                        }
                    }
                    
                    if(montante_usuario == 0) printf("esse usuário ainda não tem nenhum valor resgatado ou valor investido");
                    else printf("Valor Total: %.2f", montante_usuario);
                }
            }
            montante_usuario = 0;
       }
       if(digito == 9){
        size_t length_transacao = sizeof(transacao)/sizeof(transacao[0]);
        for(int index = 0; index < length_transacao; index++){
              if(transacao[index].valorAplicacao >= 1 && transacao[index].dataAplicacao.dia >= 1 && transacao[index].investimento.taxa >= 0.1 && transacao[index].valorResgate == 0.0){
                  if(transacao[index].investimento.tipoAplicacao == 1){ lci += transacao[index].valorAplicacao; }
                  if(transacao[index].investimento.tipoAplicacao == 2){ cdb += transacao[index].valorAplicacao; }
                  if(transacao[index].investimento.tipoAplicacao == 3){ fundos += transacao[index].valorAplicacao; }
              }
           }
        if(lci == 0 && cdb == 0 && fundos == 0){
            printf("Ainda não há nenhum tipo de ativo!");
        }else{
            printf("\nLCI: R$%.2f", lci);
            printf("\nCDB: R$%.2f", cdb);
            printf("\nFundos: R$%.2f\n", fundos);
        }
        lci = 0;
        cdb = 0;
        fundos = 0;
       }
   }
    return 0;
}