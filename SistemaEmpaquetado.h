#ifndef SISTEMAEMPAQUETADO_H
#define SISTEMAEMPAQUETADO_H

#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "Paquete.h"

#include <iostream>
    
using namespace std; 
class Paquete;
class SistemaEmpaquetado {
private:
   Lista<Paquete*>* listadepaquetes = new Lista<Paquete*>();
   int j=0;

public:
    SistemaEmpaquetado(){};

    void addPaquete(Paquete*);
    void imprimir();    


};


#endif