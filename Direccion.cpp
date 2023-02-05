#include "Direccion.h"

Direccion::Direccion(int o, int d, int p){
    this->destino = o;
    this->camino = d;
    this->peso =p;
}

void Direccion::imprimir(){
    cout<<"["<<this->destino<<"|"<<this->camino<<"|"<<this->peso<<"]";
}
