#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include <signal.h>
#include "Nodo.h"
#include "Lista.h"
#include "Router.h"
#include "Terminal.h"
#include "Pagina.h"
#include "Cola.h"
#include "Paquete.h"
#include "Administrador.h"
#include "SistemaEmpaquetado.h"
#include "hash.h"

using namespace std;
int main (int argc, char **argv){

   
    


    system("read -p 'Press Enter to continue...' var");



    signal(SIGINT,SIG_DFL);
    
    
    
    /*
    
    
    
    
    
    
    Terminal* f = new Terminal(3);
    Terminal* x = new Terminal(4);
    Terminal* k = new Terminal(5);
    Router* r = new Router(2,2);
    Router* vecino = new Router(3,3);
    r->agregarTerminal(f);
    r->agregarTerminal(x);
    vecino->agregarTerminal(k);
    r->agregarVecino(vecino);
    r->imprimirTerminales();
    vecino->imprimirTerminales();
    r->imprimirVecinos();
    Pagina* page = new Pagina(0,50,f, k);
    cout<<"La pagina "<<page->getidentificadorDePag()<<" pesa "<< page->getTamanioDePag()<< "bytes y va desde el router "
    <<page->getOrigen()->getIP()<<" hacia el router "<< page->getDestino()->getIP()<<endl;
    //cout<<"\npagina "<<page->getidentificadorDePag()<<" tamanio "<<page->getTamanioDePag();
    */
    Administrador* admin = new Administrador();
    admin->simular();
    /*
    admin->generarRouters();
    admin->generarTerminales();
    //admin->imprimirListadoDeRouters();
    //admin->imprimirListadosDeTerminales();
    admin->establecerConexiones();
    admin->imprimirConexiones();
    */
                        //Router* r = new Router(0);
                            //Router* x = new Router(1);
                        ///admin->leerFile();
                            ///admin->paseAlg();
   // admin->imprimirListadoDeRouters();
    //admin->imprimirsListadosDeTerminales();
                            //admin->crearPaginas();
                    /// admin->crearPaginas();
    //admin->crearPaginas();
    //admin->crearPaginas();
    //admin->crearPaginas();
    //admin->crearPaginas();
                            /// admin->paquetes();
   // admin->paseAlg();
    //admin->pruebaIndice();
    //admin->imprex();
    //admin->calcularTablaDeEnrutamiento();
    
                        ///    admin->imprimirLazos();
                    /// admin->enviarPaquetes();
    
                                ///admin->recibirPaquetes();
                            ///  admin->mostrarTablas();
                ////  admin->paquetes();
   // admin->crearPaginas();
   // admin->imprimirPaginasPorRouter();
   // admin->segmentarPaginas();
   // admin->insertarPaquetesEnLosLazos();
      

    
  
    

}