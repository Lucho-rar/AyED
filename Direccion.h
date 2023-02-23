#ifndef DIRECCION_H
#define DIRECCION_H
#include <iostream>

using namespace std;
 /*              CLASE  Direccion            */
class Direccion {
private:
    int destino, camino, peso;
public:
    Direccion(){};              //constructor
    Direccion(int, int);    
    int getDestino_D(){return destino;};            //getters y setters
    int getCamino_D(){return camino;};
    int peso_D(){return peso;};
    void setpeso(int p){this->peso = p;};
    void setCamino(int x){this->camino=x;};
    void imprimir();
};





#endif