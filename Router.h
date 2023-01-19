#ifndef ROUTER_H
#define ROUTER_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Lista.h"
#include "Nodo.h"
#include "Terminal.h"
#include "Paquete.h"
#include "Cola.h"
#include "Router.h"

using namespace std;



/*                           CLASE ROUTER                              */

class Router{
private:
    int id;
    int bw;
    Lista<Terminal*>* terminalesConectados = new Lista<Terminal*>();
    Lista<Router*>* listaDeVecinos = new Lista<Router*>();
    //Cola<Paquete>* colaDeEnvio = new Cola<Paquete>(); 

    //listas de destino.
public:
    Router(int direccion , int ancho){
        
        this->id = direccion;
        this->bw = ancho;
        
    }
    int getID(){return this->id;};
    void recibirPag();
    void enviarPag();
    void segmentarPag(Pagina*);
    void agregarTerminal(Terminal*);    
    void agregarVecino(Router*);
    void imprimirTerminales();
    void imprimirVecinos();
    

};


#endif 