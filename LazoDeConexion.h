#ifndef LAZODECONEXION_H
#define LAZODECONEXION_H
#include <iostream>
#include "Router.h"
#include "Terminal.h"

using namespace std;

class LazoDeConexion{
private:
    int puntoDePartida;  // Defino los nodos como enteros para trabajar con los ID  y no  
    int puntoDeDestino;  // con los tipos "router" "terminal"
    int costo;

public:
    LazoDeConexion(){};
    LazoDeConexion(int p, int d, int c){
        this->puntoDePartida=p;
        this->puntoDeDestino=d;
        this->costo = c;
    }
    int getPuntoDePartida(){return puntoDePartida;}; 
    int getPuntoDePartida(){return puntoDeDestino;};
    int getPeso(){return costo;};


};



#endif