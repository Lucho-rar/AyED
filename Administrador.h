#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Router.h"
#include "Lista.h"
#include "Nodo.h"
#include "Terminal.h"

using namespace std;


class Administrador{
private:
    Lista<Router*>* liss = new Lista<Router*>();
    Lista<Router*>* routersDisponibles = new Lista<Router*>();
    //Lista<Terminal>* terminalesConectados = new Lista<Terminal>();
    
public:
    Administrador(){};
    void generarRouters();
    void imprimirListadoDeRouters();
    void RecalcularRutas();
    void informarCaminos();



};


#endif