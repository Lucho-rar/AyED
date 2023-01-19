#ifndef PAGINA_H
#define PAGINA_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
//#include "Terminal.h"

using namespace std;
class Terminal;
class Pagina{
private:
    int identificadorDePag;
    int tamanioDePag;
    Terminal* origen;
    Terminal* destino;
public:
    Pagina(){};
    Pagina(int identif, int tamanio, Terminal* o, Terminal* d){
        this->identificadorDePag = identif;
        this->tamanioDePag = tamanio;
        this->origen = o;
        this->destino = d;
    }
    int getidentificadorDePag(){return identificadorDePag;};
    int getTamanioDePag(){return tamanioDePag;};
    Terminal* getOrigen(){return origen;};
    Terminal* getDestino(){return destino;};
    //Terminal getOrigen();
    //Terminal getDestino();
};


#endif