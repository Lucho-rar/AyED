#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <signal.h>
#include "Lista.h"
#include "Nodo.h"
#include "Terminal.h"
#include "LazoDeConexion.h"
#include "Direccion.h"
#include "Paquete.h"
#define INFI  999
#define MIEMBRO 1
#define NO_MIEMBRO 0
#define MAXNODOS 12
using namespace std;

/*                                    Clase administrador                       */
class Administrador{
private:
    Lista<Terminal*>* terminalesDisponibles = new Lista<Terminal*>();
    Lista<Router*>* routersDisponibles = new Lista<Router*>();
    Lista<LazoDeConexion*>* listaDeConexiones = new Lista<LazoDeConexion*>();
    Lista<int>* p = new Lista<int>();

    int T[MAXNODOS][MAXNODOS];
    int terminalesPorRouter;
    int cantidadDeRouters;
    int simPag=0;
    int cantSimulaciones=0;
    int glb;
   // int T[cantidadDeRouters][cantidadDeRouters];
    //Lista<Terminal>* terminalesConectados = new Lista<Terminal>();
    
public:
    Administrador(){};
    void generarRouters(int);
    void matchDeLazos();
    void imprimirListadoDeRouters();
    void imprimirListadosDeTerminales();
    void conectarTerminales(int);
    void establecerLazo(int, int ,int);
    void handlerC(int);
    void establecerConexiones();
    void imprimirConexiones();
    void leerFile();
    void examinarRouterPorID(int, int);
    void imprex();
    void imprimirLazos();
    void crearPaginas();
    void AlgAlt(int);
    void enviarPaquetes();
    void paquetes();
    void recibirPaquetes();
    void simularEscenarioPrincipal();
    void simularSegundoEscenario();
    void simularTercerEscenario();
    void paseAlg();
    void imprimirtabla();
    int * dijkstra(int C[][MAXNODOS], int, int, int Pre[]);
    void camino(int P[], int s, int t,Lista<Direccion*>*);
    void mostrarTablas();
    //void cleaner();
    void flek(int,int);
    void crearPagManual(int,int);
};


#endif