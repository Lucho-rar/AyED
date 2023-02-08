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
    int origen[2];
    int destino[2];
    bool estado = false;
public:
    Paquete(){};
    Paquete(int n , Pagina* pag,int o[2], int d[2], int tam){
        this->numeroDePaquete = n;
        this->paginaMadre = pag;
        this->origen[0]= o[0];
        this->origen[1]= o[1];
        this->destino[0] = d[0];
        this->destino[1] = d[1];
        this->tamanioDePaquete = tam;
    }
    int getNumeroDePaquete(){return numeroDePaquete;};
    int getTamanioDePaquete(){return tamanioDePaquete;};
    Pagina* getPaginaMadre(){return paginaMadre;};
    int * getOrigen(){return origen;};
    int * getDestino(){return destino;};
    void setEstado(){estado=true;};
    void setEstado1(){estado = false;};
    bool getEstado(){return estado;};
    int getTerm(){return destino[0];};
    
};




#endif