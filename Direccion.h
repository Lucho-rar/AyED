#ifndef DIRECCION_H
#define DIRECCION_H
#include <iostream>

using namespace std;
        /* Es la clase lazo pero con enteros para mezclar los lazos de ida y vuelta*/
class Direccion {
private:
    int destino, camino, peso;
public:
    Direccion(){};
    Direccion(int, int, int);
    int getDestino_D(){return destino;};
    int getCamino_D(){return camino;};
    int peso_D(){return peso;};
    void setpeso(int p){this->peso = p;};
    void setCamino(int x){this->camino=x;};
    void imprimir();
};





#endif