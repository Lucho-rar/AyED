#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include "Nodo.h"
#include "Lista.h"
#include "Router.h"
#include "Terminal.h"
#include "Pagina.h"
#include "Cola.h"
#include "Paquete.h"
#include "Administrador.h"


using namespace std;
int main(){
    Terminal* f = new Terminal(3);
    Terminal* x = new Terminal(4);
    Terminal* k = new Terminal(5);
    Router* r = new Router(2,2);
    Router* vecino = new Router(3,3);
    r->agregarTerminal(f);
    r->agregarTerminal(x);
    vecino->agregarTerminal(k);
    r->agregarVecino(vecino);
    r->imprimirTerminales();
    vecino->imprimirTerminales();
    r->imprimirVecinos();
    Pagina* page = new Pagina(0,50,f, k);
    cout<<"La pagina "<<page->getidentificadorDePag()<<" pesa "<< page->getTamanioDePag()<< "bytes y va desde el router "
    <<page->getOrigen()->getIP()<<" hacia el router "<< page->getDestino()->getIP()<<endl;
    //cout<<"\npagina "<<page->getidentificadorDePag()<<" tamanio "<<page->getTamanioDePag();




}