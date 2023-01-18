#ifndef PAGINA_H
#define PAGINA_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Terminal.h"

using namespace std;

class Pagina{
private:
    int identificadorDePag;
    int tamanioDePag;
    //Terminal* origen = new Terminal();
    //Terminal destino;
public:
    Pagina(){};
    int getidentificadorDePag();
    int getTamanioDePag();
    //Terminal getOrigen();
    //Terminal getDestino();
};


#endif