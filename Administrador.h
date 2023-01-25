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
    Lista<LazoDeConexion*>* listaDeConexiones = new Lista<LazoDeConexion*>();
    //Lista<Terminal>* terminalesConectados = new Lista<Terminal>();
    
public:
    Administrador(){};
    void generarRouters(int);
    void imprimirListadoDeRouters();
    void imprimirListadosDeTerminales();
    void conectarTerminales(int);
    void establecerLazo(int, int ,int);
    void establecerConexiones();
    void imprimirConexiones();
    void leerFile();
    void examinarRouterPorID(int, int);
    void imprex();
    void imprimirLazos();
    void crearPaginas();
    void segmentarPaginas();



};


#endif