#ifndef PAQUETE_H
#define PAQUETE_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Router.h"
#include "Pagina.h"

using namespace std;
class Paquete{
private:
    int numeroDePaquete;
    Pagina* paginaMadre;
    Router* origen;
    Router* destino;
public:
    Paquete(){};
    Paquete(int n , Pagina* pag){
        this->numeroDePaquete = n;
        this->paginaMadre = P

    }
    int getNumeroDePaquete();
    //Pagina getPaginaMadre();
    //Router getOrigen();
    //Router getDestino();
};




#endif