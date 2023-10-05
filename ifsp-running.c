#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int numeroPeito;
    char nome[50];
    int idade;
    char sexo[10];
    float tempoProva;
} Corredor;

Corredor corredores[MAX];
int numeroDeCorredores = 0;

void menu();
void cadastrarCorredor();
void dados_num_peito();
void localizarPorNome();
void relatorio();
void mediaTempo();
void corredoresIdosos();
void corredorasMulheres();

int main() {
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarCorredor();
                break;
            case 2:
                dados_num_peito();
                break;
            case 3:
                localizarPorNome();
                break;
            case 4:
                relatorio();
                break;
            case 5:
                mediaTempo();
                break;
            case 6:
                corredoresIdosos();
                break;
            case 7:
                corredorasMulheres();
                break;
            case 8:
                printf("Programa encerrado\n");
                break;
            default:
                printf("A opcao informada é inválida\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}

void menu() {
    printf("***** IFSP Running 2023 - Etapa Araraquara *****\n");

    printf("1 - Cadastrar corredor(a)\n");
    printf("2 - Consultar dados do corredor pelo número do peito\n");
    printf("3 - Consultar dados do corredor pelo nome\n");
    printf("4 - Gerar relatório de classificação\n");
    printf("5 - Calcular a média do tempo de prova entre todos os corredores\n");
    printf("6 - Apresentar a quantidade de corredores acima dos 60 anos e a média do tempo de prova deles\n");
    printf("7 - Apresentar a quantidade de corredoras e a média de idade delas\n");
    printf("8 - Sair\n");
    printf("Escolha uma das opções: \n");
}

void cadastrarCorredor() {
    Corredor novoCorredor;

    novoCorredor.numeroPeito = numeroDeCorredores + 1;

    printf("Número de peito: %d\n", novoCorredor.numeroPeito);

    printf("Nome: ");
    getchar();
    fgets(novoCorredor.nome, 50, stdin);
    novoCorredor.nome[strcspn(novoCorredor.nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &novoCorredor.idade);
    getchar(); 

    printf("Sexo - masculino ou feminino: ");
    fgets(novoCorredor.sexo, 10, stdin);
    novoCorredor.sexo[strcspn(novoCorredor.sexo, "\n")] = '\0';

    printf("Tempo de prova em minutos: ");
    scanf("%f", &novoCorredor.tempoProva);
    getchar(); 
    numeroDeCorredores++;

    printf("Corredor cadastrado com sucesso!\n");
}

void dados_num_peito() {
    int numeroPeito;

    printf("Digite o número do peito do corredor: ");
    scanf("%d", &numeroPeito);
    getchar(); 

    int i;

    for (i = 0; i < numeroDeCorredores; i++) {
        if (corredores[i].numeroPeito == numeroPeito) {
            printf("Número de peito: %d\n", corredores[i].numeroPeito);
            printf("Nome: %s\n", corredores[i].nome);
            printf("Idade: %d\n", corredores[i].idade);
            printf("Sexo: %s\n", corredores[i].sexo);
            printf("Tempo de prova: %f minutos\n", corredores[i].tempoProva);
            return;
        }
    }

    printf("Corredor não encontrado(a).\n");
}

void localizarPorNome() {
    char nome[50];

    printf("Digite o nome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int i;

    for (i = 0; i < numeroDeCorredores; i++) {
        if (strcmp(corredores[i].nome, nome) == 0) {
            printf("Corredor:\n");
            printf("Número do peito: %d\n", corredores[i].numeroPeito);
            printf("Nome: %s\n", corredores[i].nome);
            printf("Idade: %d\n", corredores[i].idade);
            printf("Sexo: %s\n", corredores[i].sexo);
            printf("Tempo de prova: %.2f minutos\n", corredores[i].tempoProva);
            return;
        }
    }

    printf("Corredor não encontrado\n");
}

void relatorio() {
    if (numeroDeCorredores == 0) {
        printf("Sem corredores cadastrados\n");
    }

    printf("Relatório\n");

    int i, j;
    for (i = 0; i < numeroDeCorredores - 1; i++) {
        for (j = 0; j < numeroDeCorredores - i - 1; j++) {
            if (corredores[j].tempoProva > corredores[j + 1].tempoProva) {
                Corredor temp = corredores[j];
                corredores[j] = corredores[j + 1];
                corredores[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < numeroDeCorredores; i++) {
        printf("%d, %d, %s, %d, %s, %.2f\n", i + 1, corredores[i].numeroPeito, corredores[i].nome,
               corredores[i].idade, corredores[i].sexo, corredores[i].tempoProva);
    }
}

void mediaTempo() {
    if (numeroDeCorredores == 0) {
        printf("Não há corredores cadastrados.\n");
    }

    float somaTempos = 0;
    int i;

    for (i = 0; i < numeroDeCorredores; i++){
        somaTempos += corredores[i].tempoProva;
    }

    float media = somaTempos / numeroDeCorredores;
    printf("Média do tempo de prova: %.2f minutos\n", media);
}

void corredoresIdosos() {
    int quantidade = 0;
    float somaTempos = 0;

    int i;

    for (i = 0; i < numeroDeCorredores; i++) {
        if (corredores[i].idade > 60) {
            quantidade++;
            somaTempos += corredores[i].tempoProva;
        }
    }

    if (quantidade == 0) {
        printf("Não existem cadastros de corredores com idade acima de 60 anos\n");
    }

    float media = somaTempos / quantidade;
    printf("Quantidade de corredores acima de 60 anos: %d\n", quantidade);
    printf("Média tempo de prova corredores acima de 60 anos: %.2f\n", media);
}

void corredorasMulheres() {
    int quantidade = 0;
    float somaIdades = 0;

    int i;

    for (i = 0; i < numeroDeCorredores; i++) {
        if (strcmp(corredores[i].sexo, "feminino") == 0) {
            quantidade++;
            somaIdades += corredores[i].idade;
        }
    }

    if (quantidade == 0) {
        printf("Não foi encontrado corredoras cadastradas.\n");
    }

    float media = somaIdades / quantidade;
    printf("Quantidade de mulheres corredoras: %d\n", quantidade);
    printf("Média de idade das mulheres corredoras: %.2f\n", media);
}
