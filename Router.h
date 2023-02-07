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
#include "Pagina.h"
#include "LazoDeConexion.h"
#include "SistemaEmpaquetado.h"
#include "Direccion.h"
#define MAX 5
using namespace std;



/*                           CLASE ROUTER                              */

class Terminal;
class Paquete;
class Pagina;
class LazoDeConexion;
class SistemaEmpaquetado;



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
    //listas de destino.
public:
    Router(int direccion){
        
        this->id = direccion;
       // empaquetador = new SistemaEmpaquetado();

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
    Lista<LazoDeConexion*>* getIda(){return this->ida;};
    Lista<LazoDeConexion*>* getVuelta(){return this->vuelta;}
    void imprimirLazosConectados();
    void crearTabla();
    void cargarPaquete(int, Paquete*);
    void enviarPaquetes();
    void recibirPaquetes();
    void buscarEnTabla(int);
    void vincularConKey(Paquete *);
    Lista<Router*>* getvecinos(){return listaDeVecinos;};
    bool esVecino(int);
    void setTabla(Lista<Direccion*>*);
    void imprimirTabla();
   // Lista<LazoDeConexion*>* getLazos(){return lazos;};
    
    

};


#endif 