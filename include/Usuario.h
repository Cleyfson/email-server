#ifndef _USUARIO_
#define _USUARIO_

#include "Email.h"

class Usuario {
public:
    Usuario();
    ~Usuario();
    void Insere(Email* email);
    Email* Pesquisa(int id_email);
    void Remove(int id_email);
    void Limpa();

private:
    void InsereRecursivo(Email*& p, Email* chave);
    void ApagaRecursivo(Email* p);
    Email* PesquisaRecursivo(Email* p, int id_email);
    void RemoveRecursivo(Email*& p, int id_email);
    void Antecessor(Email* q, Email*& r);
    Email* raiz;
};

#endif