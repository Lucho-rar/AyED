#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include "Router.h"
#include "Lista.h"
#include "Terminal.h"

using namespace std;


class Administrador{
private:
    Lista<Router>* routersDisponibles = new Lista<Router>();
    Lista<Terminal>* terminalesConectados = new Lista<Terminal>();
    
public:
    void RecalcularRutas();
    void informarCaminos();


};


#endif