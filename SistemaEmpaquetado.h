#ifndef SISTEMAEMPAQUETADO_H
#define SISTEMAEMPAQUETADO_H
#include "SistemaEmpaquetado.h"
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "Paquete.h"
#include "Pagina.h"
#include "Router.h"
#include <iostream>
    
using namespace std; 

class SistemaEmpaquetado{
private:
   Lista<Paquete*>* listadepaquetes = new Lista<Paquete*>();
   int j;

public:
    SistemaEmpaquetado(){};

    void addPaquete(Paquete*);
    void imprimir();    


};


#endif