#include "Email.h"

Email::Email()
// Descricao: cria um email com dados padrão
// Entrada: nenhuma
// Saida: Email
{
    id_email = -1;
    id_usuario = -1;
    esq = NULL;
    dir = NULL;
};

Email::Email(int _id_usuario, int _id_email, int _qt_palavras)
// Descricao: cria um email com dados passados pelo usuario
// Entrada: _id_usuario, _id_email, _qt_palavras
// Saida: Email
{
    id_usuario = _id_usuario;
    id_email = _id_email;
    palavras = new std::string[_qt_palavras];
    qt_palavras = _qt_palavras;
    esq = NULL;
    dir = NULL;
};

void Email::Imprime(std::ofstream& saida)
// Descricao: imprime no arquivo de saida os dados de um email
// Entrada: saida
// Saida: impressao num arquivo de texto
{
    for (int i = 0; i < qt_palavras; i++) {
        saida << palavras[i] << " ";
    }
    saida << std::endl;
};

Email* Email::SetPalavras(std::ifstream& entrada)
// Descricao: defini o conteudo de texto de um email
// Entrada: entrada
// Saida: counteúdo do email
{
    for (int i = 0; i < qt_palavras; i++) {
        entrada >> palavras[i];
    }
    return this;
};