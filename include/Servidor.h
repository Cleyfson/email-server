#ifndef _SERVIDOR_
#define _SERVIDOR_

#include "Usuario.h"
#include <fstream>

class Servidor {
public:
    Servidor(int M);
    Email* Pesquisa(int id_usuario, int id_email);
    Email* PesquisaDado(std::ifstream& entrada, std::ofstream& saida);
    void InsereDado(std::ifstream& entrada, std::ofstream& saida);
    void RemoveDado(std::ifstream& entrada, std::ofstream& saida);
    void Limpar();

private:
    int size;
    int Hash(int id);
    Usuario* Tabela;
};

#endif