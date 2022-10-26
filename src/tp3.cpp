#include "Servidor.h"
#include "msgassert.h"
#include <getopt.h>
#include <iostream>
#include <string.h>

// variaveis globais
char log_arq[100];
char entrada_arq[100];
char saida_arq[100];
int regmem;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
    fprintf(stderr, "tp3\n");
    fprintf(stderr, "\t-i ou -I <arq>\t(arquivo de entrada(input))\n");
    fprintf(stderr, "\t-o ou -O <arq>\t(arquivo de saida(output))\n");
    fprintf(stderr, "\t-p <arq>\t(arquivo de registro de acesso)\n");
    fprintf(stderr, "\t-l \t(registrar acessos a memoria)\n");
    erroAssert(strlen(log_arq) > 0, "tp3 - nome de arquivo de registro de acesso tem que ser definido");
}

void parse_args(int argc, char** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, regmem, lognome, m1nome, m2nome, m3nome
{
    // variaveis externas do getopt
    extern char* optarg;

    // variavel auxiliar
    int c;

    // inicializacao variaveis globais para opcoes
    regmem = 0;
    log_arq[0] = 0;
    entrada_arq[0] = 0;
    saida_arq[0] = 0;

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "i:I:o:O:p:l")) != EOF) {
        if (c == 'i' || c == 'I') {
            strcpy(entrada_arq, optarg);
        } else if (c == 'o' || c == 'O') {
            strcpy(saida_arq, optarg);
        } else if (c == 'p') {
            strcpy(log_arq, optarg);
        } else if (c == 'l') {
            regmem = 1;
        } else {
            uso();
            exit(1);
        }
    }
    // verificacao da consistencia das opcoes
    erroAssert(strlen(entrada_arq) > 0, "tp3 - nome do arquivo de entrada precisa ser definido");
    erroAssert(strlen(saida_arq) > 0, "tp3 - nome do arquivo de saida precisa ser definido");
}

int main(int argc, char** argv)
// Descricao: programa principal para execucao de operacoes
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
    // faz a captura dos argumentos passados na execução do arquivo
    parse_args(argc, argv);

    // abre o arquivo de entra e checa seu estado
    std::ifstream entrada;
    entrada.open(entrada_arq);
    erroAssert(entrada.is_open(), "tp3 - erro ao abrir arquivo de entrada");

    // abre o arquivo de saida e checa seu estado
    std::ofstream saida;
    saida.open(saida_arq);
    erroAssert(saida.is_open(), "tp3 - erro ao abrir arquivo de saida");

    // variaveis auxiliares
    std::string operacao;
    int tamanho_hash;

    // criação da tabela hash de tamanho lido do arquivo de entrada
    entrada >> tamanho_hash;
    Servidor Servidor(tamanho_hash);

    // leitura da entra e realização das operações possiveis
    while (entrada >> operacao) {
        if (operacao == "ENTREGA") {
            Servidor.InsereDado(entrada, saida);
        } else if (operacao == "CONSULTA") {
            Servidor.PesquisaDado(entrada, saida);
        } else if (operacao == "APAGA") {
            Servidor.RemoveDado(entrada, saida);
        }
    }

    // fechamento dos arquivos de entrada e saida
    entrada.close();
    saida.close();

    return 0;
}