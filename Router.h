#ifndef ROUTER_H
#define ROUTER_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Lista.h"
#include "Nodo.h"

//#include "Paquete.h"
#include "Cola.h"
#include "Router.h"
#include "Pagina.h"
#include "LazoDeConexion.h"
#include "SistemaEmpaquetado.h"

using namespace std;



/*                           CLASE ROUTER                              */
class SistemaEmpaquetado;
class Terminal;
class Paquete;
class Pagina;
class LazoDeConexion;

class Router {
private:
    int id;
   // int bw;
    Lista<Terminal*>* terminalesConectados = new Lista<Terminal*>();
    Lista<Router*>* listaDeVecinos = new Lista<Router*>();
    Lista<Pagina*>* listaDePaginas = new Lista<Pagina*>();
    Cola<Paquete*>* colaDeEnvio = new Cola<Paquete*>(); 
    Lista<LazoDeConexion*>* ida = new Lista<LazoDeConexion*>();
    Lista<LazoDeConexion*>* vuelta = new Lista<LazoDeConexion*>();
    SistemaEmpaquetado * empaquetador;

    //listas de destino.
public:
    Router(int direccion){
        
        this->id = direccion;
        
    }
    int getID(){return this->id;};
    Cola<Paquete*>* getcoladeenvio(){return colaDeEnvio;};
    //int getBW(){return this->bw;};
    void recibirPag(Pagina*);
    void enviarPag();
    void enviarPaquete();
    void enlazarVecinos();
    void agregarPagina(Pagina* p);
    void segmentarPag();
    void agregarTerminal(Terminal*);    
    void agregarVecino(int);
    void imprimirTerminales();
    void imprimirVecinos();
    void imprimirPaginas();
    void imprimirPaquetes();
    void agregarLazoIda(LazoDeConexion* f){this->ida->addFinal(f);};
    void agregarLazoVuelta(LazoDeConexion* f){this->vuelta->addFinal(f);};
    void imprimirLazosConectados();
   // Lista<LazoDeConexion*>* getLazos(){return lazos;};

    

};


#endif 