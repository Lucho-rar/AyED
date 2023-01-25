#ifndef PAGINA_H
#define PAGINA_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
//#include "Terminal.h"
#include "Paquete.h"

using namespace std;
class Terminal;
class Pagina{
private:
    int identificadorDePag;
    double tamanioDePag;
    int origen;
    int destino;
public:
    Pagina(){};
    Pagina(int identif, int tamanio, int o , int d){
        this->identificadorDePag = identif;
        this->tamanioDePag = tamanio;
        this->origen = o;
        this->destino = d;
    }
    int getidentificadorDePag(){return identificadorDePag;};
    int getTamanioDePag(){return tamanioDePag;};
    int getOrigen(){return origen;};
    int getDestino(){return destino;};
};


#endif