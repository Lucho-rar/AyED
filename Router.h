#ifndef ROUTER_H
#define ROUTER_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Lista.h"
#include "Nodo.h"
//#include "Terminal.h"
//#include "Paquete.h"
#include "Cola.h"
#include "Router.h"
#include "Pagina.h"


using namespace std;



/*                           CLASE ROUTER                              */
class Terminal;
class Paquete;
class Pagina;
class Router{
private:
    int id;
   // int bw;
    Lista<Terminal*>* terminalesConectados = new Lista<Terminal*>();
    Lista<Router*>* listaDeVecinos = new Lista<Router*>();
    Lista<Pagina*>* listaDePaginas = new Lista<Pagina*>();
    Cola<Paquete*>* colaDeEnvio = new Cola<Paquete*>(); 

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
    void agregarPagina(Pagina* p);
    void segmentarPag();
    void agregarTerminal(Terminal*);    
    void agregarVecino(int);
    void imprimirTerminales();
    void imprimirVecinos();
    void imprimirPaginas();
    void imprimirPaquetes();

    

};


#endif 