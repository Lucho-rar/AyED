#include "Router.h"

/*          Metodos Router      */



void Router::recibirPag(Pagina* p){
    this->listaDePaginas->add(p);
}


void Router::segmentarPag(Pagina* p){
  /*  double tamanioDePaquetes;
    if(p->getTamanioDePag() == 0){
        //descartar pagina
    }else{
        tamanioDePaquetes = p->getTamanioDePag()/10;
    }
    for (int i=0;i<10;i++){
        Paquete* paquete 
    }*/
}

void Router::enviarPag(){

}


void Router::agregarTerminal(Terminal* t){
   // cout<<"Reconocido desde el router"<<endl;
    t->conectarseAUnRouter(this);
    terminalesConectados->add(t);
}

void Router::agregarVecino(Router* r){
    cout<<"Tengo un vecino nuevo y es el router de id "<<r->getID()<<endl;
    listaDeVecinos->add(r);
}

void Router::imprimirTerminales(){
    Nodo<Terminal*>* aux;
    aux= terminalesConectados->comienzo();
    cout<<"\nSOY EL ROUTER "<<id<<" y estos son los terminales que tengo conectados: "<<endl;

    for (int i =0; i< terminalesConectados->size() ; i++){
        cout<< aux->get_dato()->getIP()<<endl;
        aux = aux->get_next();
    }
}

void Router::imprimirVecinos(){
    Nodo<Router*>* aux;
    aux = listaDeVecinos->comienzo();
    cout<<"\nSoy el router "<<id<<" y estos son mis vecinos: "<<endl;
    for (int i =0;i <listaDeVecinos->size();i++){
        cout<<aux->get_dato()->getID()<<endl;
        aux = aux->get_next();
    }

}