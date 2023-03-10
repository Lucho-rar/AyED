#ifndef COLA_H
#define COLA_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Lista.h"
#include "Nodo.h"
using namespace std;

/*                         CLASE COLA UTILZIADA EN CLASES               */
template <class T> class Cola :public Lista<T> {
public:
    Cola(void) { Lista<T>(); };
    //~Cola(void);
    T tope() { return this->last(); };
    bool colavacia(void) { return this->esvacia(); };
    void encolar(T a) { this->add(a); };
    void desencolar(void) { this->borrar_last(); };
    T ultimo(void) { return this->cabeza(); };
    string imprimir(string s) { return this->toPrint(s); };
};


#endif