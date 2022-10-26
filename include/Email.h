#ifndef _EMAIL_
#define _EMAIL_

#include <fstream>
#include <iostream>

class Email {
public:
    Email();
    Email(int _id_usuario, int _id_email, int qt_palavras);
    void Imprime(std::ofstream& saida);
    Email* SetPalavras(std::ifstream& entrada);
    std::string* palavras;

private:
    int id_usuario;
    int id_email;
    int qt_palavras;
    Email* esq;
    Email* dir;

    friend class Usuario;
    friend class Servidor;
};

#endif