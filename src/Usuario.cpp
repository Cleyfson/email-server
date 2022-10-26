#include "Usuario.h"

Usuario::Usuario()
// Descricao: cria uma arvore do tipo usuario
// Entrada: nenhuma
// Saida: arvore com raiz do tipoEmail
{
    raiz = NULL;
};

Usuario::~Usuario()
// Descricao: destrutor padrão do Usuario
// Entrada: nenhuma
// Saida: desaloca toda arvore de usuario
{
    Limpa();
};

void Usuario::Insere(Email* email)
// Descricao: insere um email na arvore de usuario
// Entrada: email
// Saida: arvore de usuario preenchida com mais um email
{
    InsereRecursivo(raiz, email);
};

void Usuario::InsereRecursivo(Email*& p, Email* email)
// Descricao: percorre a arvore do usario, buscando por um nodulo vazio pra prencher com email
// Entrada: p(raiz) , email
// Saida: arvore de usuario preenchida com mais um email
{
    if (p == NULL) {
        p = email;
    } else {
        if (email->id_email < p->id_email)
            InsereRecursivo(p->esq, email);
        else
            InsereRecursivo(p->dir, email);
    }
};

Email* Usuario::Pesquisa(int id_email)
// Descricao: busca por um email na arvore de usuario
// Entrada: id_email
// Saida: email procurado, caso ele mesmo exista
{
    return PesquisaRecursivo(raiz, id_email);
};

Email* Usuario::PesquisaRecursivo(Email* no, int id_email)
// Descricao: percorre pela arvore de usuario, buscando por um email
// Entrada:  no(raiz), id_email
// Saida: email procurado, caso ele exista
{
    Email* aux = NULL;
    if (no == NULL) {
        return aux;
    }
    if (id_email < no->id_email)
        return PesquisaRecursivo(no->esq, id_email);
    else if (id_email > no->id_email)
        return PesquisaRecursivo(no->dir, id_email);
    else
        return no;
};

void Usuario::Remove(int id_email)
// Descricao: remove um email da arvore de usuario
// Entrada: id_email
// Saida: arvore de usuario atualizada
{
    return RemoveRecursivo(raiz, id_email);
};

void Usuario::RemoveRecursivo(Email*& no, int id_email)
// Descricao: percorre a arvore de usuario buscando por um email para deletar
// Entrada: no(raiz), id_email
// Saida: arvore de usuario atualizada
{
    if (no == NULL) {
        throw("Item nao está presente");
    }
    if (id_email < no->id_email)
        return RemoveRecursivo(no->esq, id_email);
    else if (id_email > no->id_email)
        return RemoveRecursivo(no->dir, id_email);
    else {
        if (no->dir == NULL) {
            no = no->esq;
        } else if (no->esq == NULL) {
            no = no->dir;
        } else
            Antecessor(no, no->esq);
    }
};

void Usuario::Antecessor(Email* q, Email*& r)
// Descricao: percorre pela arvore de usuario buscando pelo antecessor de um no
// Entrada: q, r
// Saida: no antecessor de outro
{
    if (r->dir != NULL) {
        Antecessor(q, r->dir);
        return;
    }
    q->id_email = r->id_email;
    q = r;
    r = r->esq;
    delete q;
}

void Usuario::Limpa()
// Descricao: deleta a arvore de usuario
// Entrada: nenhuma
// Saida: arvore de usuario vazia
{
    ApagaRecursivo(raiz);
    raiz = NULL;
};

void Usuario::ApagaRecursivo(Email* p)
// Descricao: percorre a arvore de usuario apagando email por email
// Entrada: p(raiz)
// Saida: arvore de usuario vazia
{
    if (p != NULL) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
};