#ifndef LAZODECONEXION_H
#define LAZODECONEXION_H
#include <iostream>
#include "Router.h"
#include "Terminal.h"

using namespace std;

class LazoDeConexion{
private:
    int terminal1;  // Defino los nodos como enteros para trabajar con los ID  y no  
    int terminal2;  // con los tipos "router" "terminal"
    int costo;
    int anchoDeBanda;

public:
    LazoDeConexion(){};
    LazoDeConexion(int p, int d, int a){
        this->terminal1=p;
        this->terminal2=d;
        //this->costo = c;
        this->anchoDeBanda=a;
    }

    int getTerminal1(){return terminal1;}; 
    int getTerminal2(){return terminal2;};
    int getPeso(){return costo;};
    int getBW() { return anchoDeBanda;};


};



#endif