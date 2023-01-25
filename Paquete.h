#ifndef PAQUETE_H
#define PAQUETE_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Router.h"
#include "Pagina.h"
#include "Terminal.h"

using namespace std;

class Pagina;
class Terminal;
class Paquete{
private:
    int numeroDePaquete;
    int tamanioDePaquete;
    Pagina* paginaMadre;
    int origen;
    int destino;
public:
    Paquete(){};
    Paquete(int n , Pagina* pag,int o, int d, int tam){
        this->numeroDePaquete = n;
        this->paginaMadre = pag;
        this->origen = o;
        this->destino =d;
        this->tamanioDePaquete = tam;
    }
    int getNumeroDePaquete(){return numeroDePaquete;};
    int getTamanioDePaquete(){return tamanioDePaquete;};
    Pagina* getPaginaMadre(){return paginaMadre;};
    int getOrigen(){return origen;};
    int getDestino(){return destino;};
    
};




#endif