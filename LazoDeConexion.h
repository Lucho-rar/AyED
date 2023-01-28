#ifndef LAZODECONEXION_H
#define LAZODECONEXION_H
#include <iostream>
#include "Router.h"
#include "Terminal.h"
#include "Lista.h"
#include "Cola.h"
#include "Nodo.h"
//#include "Paquete.h"
using namespace std;
class Paquete;
class LazoDeConexion{
private:
    int terminal1;  // Defino los nodos como enteros para trabajar con los ID  y no  
    int terminal2;  // con los tipos "router" "terminal"
    int peso;
    int anchoDeBanda;
    Cola<Paquete*>* colaConectora = new Cola<Paquete*>();

public:
    LazoDeConexion(){};
    LazoDeConexion(int p, int d, int a){
        this->terminal1=p;
        this->terminal2=d;
        this->anchoDeBanda=a;

    }
    int getTerminal1(){return terminal1;}; 
    int getTerminal2(){return terminal2;};
    int getPeso(){return peso;};
    int getBW() { return anchoDeBanda;};
    Cola<Paquete*>* getcolaconectora(){return colaConectora;};
    


};



#endif