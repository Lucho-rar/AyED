#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream> 
#include "Router.h"
#include "Pagina.h"

using namespace std;
class Paquete{
private:
    int numeroDePaquete;
    Pagina paginaMadre;
    Router origen;
    Router destino;

};




#endif