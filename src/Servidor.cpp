#include <Servidor.h>

Servidor::Servidor(int M)
// Descricao: cria uma tabela hash de dados para usuarios
// Entrada: M
// Saida: tabela hash com tamanho M
{
    Tabela = new Usuario[M];
    size = M;
};

Email* Servidor::Pesquisa(int id_usuario, int id_email)
// Descricao: busca por um email de um usuario contido na tabela de dados
// Entrada: id_usuario, id_email
// Saida: item que contem o email procurado caso ele exista
{
    int pos = Hash(id_usuario);
    Email* item = Tabela[pos].Pesquisa(id_email);
    return item;
};

Email* Servidor::PesquisaDado(std::ifstream& entrada, std::ofstream& saida)
// Descricao: busca por um email de usuario contido na tabela de dados
// Entrada: entrada, saida
// Saida: item que contem o email procurando, alem disso imprime o conteudo do email do documento de saida
{
    int id_usuario;
    int id_email;
    entrada >> id_usuario >> id_email;

    int pos = Hash(id_usuario);
    Email* item = Tabela[pos].Pesquisa(id_email);

    if (item != NULL && item->id_usuario == id_usuario) {
        saida << "CONSULTA " << id_usuario << " " << id_email << ": ";
        item->Imprime(saida);
    } else {
        saida << "CONSULTA " << id_usuario << " " << id_email << ": "
              << "MENSAGEM INEXISTENTE" << std::endl;
    }
    return item;
};

void Servidor::InsereDado(std::ifstream& entrada, std::ofstream& saida)
// Descricao: insere um email na tabela hash de dados
// Entrada: entrada, saida
// Saida: tabela hash atualizada e confirmação da anexadão do email imprimido no documento de saida
{
    int id_usuario;
    int id_email;
    int quant_palavras;
    entrada >> id_usuario >> id_email >> quant_palavras;

    int pos = Hash(id_usuario);
    Tabela[pos].Insere((new Email(id_usuario, id_email, quant_palavras))->SetPalavras(entrada));
    saida << "OK: MENSAGEM " << id_email << " PARA " << id_usuario << " ARMAZENADA EM " << pos << std::endl;
}

void Servidor::RemoveDado(std::ifstream& entrada, std::ofstream& saida)
// Descricao: remove um email da tabela de dados
// Entrada: entrada, saida
// Saida: tabela hash atualizada
{
    int id_usuario;
    int id_email;
    entrada >> id_usuario >> id_email;

    int pos = Hash(id_usuario);
    Email* item = Tabela[pos].Pesquisa(id_email);

    if (item != NULL && item->id_usuario == id_usuario) {
        saida << "OK: MENSAGEM APAGADA" << std::endl;
        Tabela[pos].Remove(id_email);
    } else {
        saida << "ERRO: MENSAGEM INEXISTENTE" << std::endl;
    }
}

int Servidor::Hash(int id)
// Descricao: localiza a posicao na tabela has dado um id
// Entrada: id
// Saida: posicao da tabela hash
{
    return id % size;
};

void Servidor::Limpar()
// Descricao: percorre a tabela hash desalocando suas posições
// Entrada: nenhuma
// Saida: tabela hash vazia
{
    for (int i = 0; i < size; i++) {
        Tabela[i].Limpa();
    }
}