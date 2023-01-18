#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>
#include "Router.h"
#include "Pagina.h"
#include "Lista.h"

using namespace std;

class Terminal{
private: 
    int ip;
    Router routerConectado;
    Lista<Pagina>* paginasAEnviar = new Lista<Pagina>();
    Lista<Pagina>* paginasRecibidas = new Lista<Pagina>();

public:
    Terminal();
    void enviarPagina();
    void recibirPagina();

};






#endif