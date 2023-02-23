#ifndef PAGINA_H
#define PAGINA_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
//#include "Terminal.h"
#include "Paquete.h"

using namespace std;

/*                          CLASE PAGINA            */
class Terminal;
class Pagina{
private:
    int identificadorDePag;
    double tamanioDePag;
    int origen[2];
    int destino[2];
public:
    Pagina(){};
    Pagina(int identif, int tamanio, int o[] , int d[]){        //constructor
        this->identificadorDePag = identif;
        this->tamanioDePag = tamanio;
        this->origen[0] = o[0];
        this->origen[1] = o[1];
        this->destino[0] = d[0];
        this->destino[1] = d[0];
    }
    int getidentificadorDePag(){return identificadorDePag;};        //getters y setters
    int getTamanioDePag(){return tamanioDePag;};
    int * getOrigen(){return origen;};
    int * getDestino(){return destino;};
};


#endif