#ifndef SISTEMAEMPAQUETADO_H
#define SISTEMAEMPAQUETADO_H
#include "SistemaEmpaquetado.h"
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "Paquete.h"

class SistemaEmpaquetado{
private:
   Cola<Paquete*> f;

public: 
    SistemaEmpaquetado(){}; 
    void addPaquete(Paquete*);
    


};


#endif