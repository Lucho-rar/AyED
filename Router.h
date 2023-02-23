#ifndef ROUTER_H
#define ROUTER_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include "Lista.h"
#include "Nodo.h"


//#include "Paquete.h"
#include "Cola.h"
#include "Pagina.h"
#include "LazoDeConexion.h"
#include "Direccion.h"
#define MAX 20
#define TAMPAG 10
using namespace std;



/*                           CLASE ROUTER                              */

class Terminal;
class Paquete;
class Pagina;
class LazoDeConexion;




class Router{
private:
    int id;
   // int bw;
   

    Lista<Terminal*>* terminalesConectados = new Lista<Terminal*>();
    Lista<Router*>* listaDeVecinos = new Lista<Router*>();
    Lista<Pagina*>* listaDePaginas = new Lista<Pagina*>();
    Cola<Paquete*>* colaDeEnvio = new Cola<Paquete*>(); 
    Lista<LazoDeConexion*>* ida = new Lista<LazoDeConexion*>();
    Lista<LazoDeConexion*>* vuelta = new Lista<LazoDeConexion*>();
    Lista<Paquete*>* paquetes = new Lista<Paquete*>();
    Lista<Direccion*>* tabla = new Lista<Direccion*>();
    Lista<Paquete*> D[MAX];
    
    
public:
    Router(int direccion){
        
        this->id = direccion;
     

    }
   
    int getID(){return this->id;};
    Cola<Paquete*>* getcoladeenvio(){return colaDeEnvio;};
    void recibirPag(Pagina*);
    void enviarPag(Pagina*);
    void agregarTerminal(Terminal*);    
    void agregarVecino(int);
    void imprimirTerminales();
    void imprimirVecinos();
    void imprimirPaginas();
    void imprimirPaquetes();
    void agregarLazoIda(LazoDeConexion* f){this->ida->addFinal(f);};
    void agregarLazoVuelta(LazoDeConexion* f){this->vuelta->addFinal(f);};
    Lista<LazoDeConexion*>* getIda(){return this->ida;};
    Lista<LazoDeConexion*>* getVuelta(){return this->vuelta;}
    void imprimirLazosConectados();
    void enviarPaquetes();
    void recibirPaquetes();
    int buscarEnTabla(int);
    void vincularConKey(Paquete *);
    Lista<Router*>* getvecinos(){return listaDeVecinos;};
    bool esVecino(int);
    void setTabla(Lista<Direccion*>*);
    void imprimirTabla();
    int comprobarDestino(int);
    int buscarlazo(int);
};


#endif 