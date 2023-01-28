#include "Router.h"

/*          Metodos Router      */

void Router::enviarPaquete(){

}

void Router::recibirPag(Pagina* p){
    this->listaDePaginas->add(p);
}


void Router::agregarPagina(Pagina* p){
    this->listaDePaginas->addFinal(p);
}

void Router::segmentarPag(){
    Nodo<Pagina*>* aux;
    aux = listaDePaginas->comienzo();
    int identificador;
    for (int i = 0 ; i < listaDePaginas->size();i++){
        int tamanioDePaquetes = (10 * aux->get_dato()->getTamanioDePag())/100;
        int cantidadDePaquetes = aux->get_dato()->getTamanioDePag()/tamanioDePaquetes;    
        for (int j = 0 ; j < cantidadDePaquetes;j++){
            
            Paquete* paq = new Paquete(j,aux->get_dato(), aux->get_dato()->getOrigen(),aux->get_dato()->getDestino(),tamanioDePaquetes );
               
            colaDeEnvio->addFinal(paq);    
            
        }
        aux = aux->get_next();
    }
}

void Router::agregarTerminal(Terminal* t){
   // cout<<"Reconocido desde el router"<<endl;
    t->conectarseAUnRouter(this);
    terminalesConectados->addFinal(t);
}

void Router::agregarVecino(int id) {
    Router* r = new Router(id);
    //cout<<"Tengo un vecino nuevo y es el router de id "<<id<<endl;
    listaDeVecinos->addFinal(r);
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

void Router::imprimirPaginas(){
    Nodo<Pagina*>* aux;
    aux = listaDePaginas->comienzo();

    for(int i = 0; i < listaDePaginas->size(); i++)
    {
        cout<<"\nDatos de pagina: "<<endl;
        cout<<"identificador: "<<aux->get_dato()->getidentificadorDePag()<<endl;
        cout<<"tamanio: "<<aux->get_dato()->getTamanioDePag()<<endl;
        cout<<"origen: "<<aux->get_dato()->getOrigen()<<endl;
        cout<<"destino: "<<aux->get_dato()->getDestino()<<endl;
    }
    
}

void Router::imprimirPaquetes(){
    Nodo<Paquete*>* aux;
    aux = colaDeEnvio->comienzo();
    for (int i =0; i <colaDeEnvio->size();i++){
        cout<<"\nDatos de paquete: "<<endl;
        cout<<"identificador: "<<aux->get_dato()->getNumeroDePaquete()<<endl;
        cout<<"tamanio: "<<aux->get_dato()->getTamanioDePaquete()<<endl;
        cout<<"origen: "<<aux->get_dato()->getOrigen()<<endl;
        cout<<"destino: "<<aux->get_dato()->getDestino()<<endl;
        cout<<"id de pagina madre: "<<aux->get_dato()->getPaginaMadre()->getidentificadorDePag()<<endl;
        aux = aux->get_next();
    }
}

void Router::imprimirLazosConectados(){
    Nodo<LazoDeConexion*>* aux;
    aux = this->ida->comienzo();
    cout<<"\nSoy el router "<<this->getID()<<" y estos son los lazos:"<<endl;
    cout<<"de ida: "<<endl;
    for (int i =0;i<ida->size();i++){
        cout<<aux->get_dato()->getTerminal1()<<" ----> "<<aux->get_dato()->getTerminal2()<<endl;
        aux = aux->get_next();
    }
    aux = this->vuelta->comienzo();
    cout<<"de veulta"<<endl;
    for (int i =0;i<vuelta->size();i++){
        cout<<aux->get_dato()->getTerminal1()<<" ----> "<<aux->get_dato()->getTerminal2()<<endl;
        aux=aux->get_next();
    }

}