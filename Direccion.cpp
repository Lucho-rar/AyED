#include "Direccion.h"

Direccion::Direccion(int o, int d){
    this->destino = o;
    this->camino = d;
   
}

void Direccion::imprimir(){
    cout<<"["<<this->destino<<"|"<<this->camino<<"]";
}
