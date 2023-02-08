#ifndef TERMINAL_H
#define TERMINAL_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
//#include "Router.h"
//#include "Router.cpp"
#include "Pagina.h"
#include "Lista.h"

using namespace std;
class Router;
class Pagina;
class Terminal{
private: 
    int ip[2];
    Router* routerConectado;
    //Lista<Pagina>* paginasAEnviar = new Lista<Pagina>();
    Lista<Pagina*>* paginasRecibidas = new Lista<Pagina*>();

public:
    Terminal(){};
    Terminal(int[2]);
    int * getIP();
    void conectarseAUnRouter(Router* );
    void enviarPagina();
    void recibirPagina(Pagina*);
    

};






#endif