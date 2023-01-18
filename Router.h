#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include "Lista.h"
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
    Lista<Terminal>* terminalesConectados = new Lista<Terminal>();
    Lista<Router>* vecinos = new Lista<Router>();
    Cola<Paquete>* colaDeEnvio = new Cola<Paquete>(); 

    //listas de destino.
public:
    void recibirPag();
    void enviarPag();
    void segmentarPag();
    
    

};


#endif 