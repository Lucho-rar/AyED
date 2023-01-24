#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Router.h"
#include "Lista.h"
#include "Nodo.h"
#include "Terminal.h"
#include "LazoDeConexion.h"

using namespace std;


class Administrador{
private:
    Lista<Terminal*>* terminalesDisponibles = new Lista<Terminal*>();
    Lista<Router*>* routersDisponibles = new Lista<Router*>();
    //Lista<Terminal>* terminalesConectados = new Lista<Terminal>();
    
public:
    Administrador(){};
    void generarRouters(int);
    void imprimirListadoDeRouters();
    void generarTerminales();
    void imprimirListadosDeTerminales();
    void conectarTerminales(int);
    void establecerLazo(int, int ,int);
    void establecerConexiones();
    void imprimirConexiones();
    void RecalcularRutas();
    void leerFile();



};


#endif